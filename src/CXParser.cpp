#include "CXParser.h"
#include "clang/CodeGen/ModuleBuilder.h"
#include "clang/Lex/Lexer.h"
#include "clang/Parse/Parser.h"

CXParser clang_Parser_create(CXPreprocessor PP, CXSema Actions, bool SkipFunctionBodies,
                             CXInit_Error *ErrorCode) {
  CXInit_Error Err = CXInit_NoError;
  std::unique_ptr<clang::Parser> ptr = std::make_unique<clang::Parser>(
      *static_cast<clang::Preprocessor *>(PP), *static_cast<clang::Sema *>(Actions),
      SkipFunctionBodies);

  if (!ptr) {
    fprintf(stderr, "LIBCLANGEX ERROR: failed to create `clang::Parser`\n");
    Err = CXInit_CanNotCreate;
  }

  if (ErrorCode)
    *ErrorCode = Err;

  return ptr.release();
}

void clang_Parser_dispose(CXParser P) { delete static_cast<clang::Parser *>(P); }

void clang_Parser_Initialize(CXParser P) { static_cast<clang::Parser *>(P)->Initialize(); }

bool clang_Parser_tryParseAndSkipInvalidOrParsedDecl(CXParser Parser,
                                                     CXCodeGenerator CodeGen) {
  auto P = static_cast<clang::Parser *>(Parser);
  auto CG = static_cast<clang::CodeGenerator *>(CodeGen);
  clang::Parser::DeclGroupPtrTy ADecl;
  for (bool AtEOF = P->ParseFirstTopLevelDecl(ADecl); !AtEOF;
       AtEOF = P->ParseTopLevelDecl(ADecl)) {
    if (ADecl && !CG->HandleTopLevelDecl(ADecl.get()))
      return false;
  }
  return true;
}

CXDeclGroupRef clang_Parser_parseOneTopLevelDecl(CXParser Parser, bool IsFirstDecl) {
  clang::Parser::DeclGroupPtrTy ADecl;
  static_cast<clang::Parser *>(Parser)->ParseTopLevelDecl(ADecl, IsFirstDecl);
  if (ADecl)
    return ADecl.get().getAsOpaquePtr();
  else
    return nullptr;
}

CXDeclGroupRef clang_DeclGroupRef_fromeDecl(CXDecl D) {
  return clang::DeclGroupRef(static_cast<clang::Decl *>(D)).getAsOpaquePtr();
}

bool clang_DeclGroupRef_isNull(CXDeclGroupRef DG) {
  return clang::DeclGroupRef::getFromOpaquePtr(DG).isNull();
}

bool clang_DeclGroupRef_isSingleDecl(CXDeclGroupRef DG) {
  return clang::DeclGroupRef::getFromOpaquePtr(DG).isSingleDecl();
}

bool clang_DeclGroupRef_isDeclGroup(CXDeclGroupRef DG) {
  return clang::DeclGroupRef::getFromOpaquePtr(DG).isDeclGroup();
}

CXDecl clang_DeclGroupRef_getSingleDecl(CXDeclGroupRef DG) {
  return clang::DeclGroupRef::getFromOpaquePtr(DG).getSingleDecl();
}

// class ScopeSpecifierParser {
//   clang::Lexer &L;
//   clang::Token Tok;

//   clang::SourceLocation ConsumeToken() {
//     clang::SourceLocation Loc = Tok.getLocation();
//     L.LexFromRawLexer(Tok);
//     return Loc;
//   }

// public:
//   ScopeSpecifierParser(clang::Lexer &Lex) : L(Lex){};
// };

// CXScopeSpecifierParser clang_ScopeSpecifierParser_create(CXLexer Lex,
//                                                          CXInit_Error *ErrorCode) {
//   CXInit_Error Err = CXInit_NoError;
//   std::unique_ptr<ScopeSpecifierParser> ptr =
//       std::make_unique<ScopeSpecifierParser>(*static_cast<clang::Lexer *>(Lex));

//   if (!ptr) {
//     fprintf(stderr, "LIBCLANGEX ERROR: failed to create `ScopeSpecifierParser`\n");
//     Err = CXInit_CanNotCreate;
//   }

//   if (ErrorCode)
//     *ErrorCode = Err;

//   return ptr.release();
// }

// void clang_ScopeSpecifierParser_dispose(CXScopeSpecifierParser P) {
//   delete static_cast<ScopeSpecifierParser *>(P);
// }