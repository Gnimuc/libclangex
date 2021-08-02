#include "clang-ex/CXParser.h"
#include "clang/Parse/ParseAST.h"
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

CXToken_ clang_Parser_getCurToken(CXParser P) {
  return const_cast<clang::Token *>(&static_cast<clang::Parser *>(P)->getCurToken());
}

CXSourceLocation_ clang_Parser_ConsumeToken(CXParser P) {
  return static_cast<clang::Parser *>(P)->ConsumeToken().getPtrEncoding();
}

bool clang_Parser_TryAnnotateCXXScopeToken(CXParser P, bool EnteringContext) {
  return static_cast<clang::Parser *>(P)->TryAnnotateCXXScopeToken(EnteringContext);
}

CXDeclGroupRef clang_Parser_parseOneTopLevelDecl(CXParser Parser, bool IsFirstDecl) {
  clang::Parser::DeclGroupPtrTy ADecl;
  static_cast<clang::Parser *>(Parser)->ParseTopLevelDecl(ADecl, IsFirstDecl);
  if (ADecl)
    return ADecl.get().getAsOpaquePtr();
  else
    return nullptr;
}

void clang_ParseAST(CXSema Sema, bool PrintStats, bool SkipFunctionBodies) {
  clang::ParseAST(*static_cast<clang::Sema *>(Sema), PrintStats, SkipFunctionBodies);
}