#include "CXParser.h"
#include "clang/CodeGen/ModuleBuilder.h"
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
