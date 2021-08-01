#include "clang-ex/CXPreprocessor.h"
#include "clang/Basic/Builtins.h"
#include "clang/Lex/HeaderSearch.h"
#include "clang/Lex/Lexer.h"
#include "clang/Lex/Preprocessor.h"
#include "llvm/Support/MemoryBuffer.h"

// Lexer

CXLexer clang_Lexer_create(CXFileID FID, LLVMMemoryBufferRef FromFile, CXSourceManager SM,
                           CXLangOptions langOpts, CXInit_Error *ErrorCode) {
  CXInit_Error Err = CXInit_NoError;
  std::unique_ptr<clang::Lexer> ptr = std::make_unique<clang::Lexer>(
      *static_cast<clang::FileID *>(FID), llvm::MemoryBufferRef(*llvm::unwrap(FromFile)),
      *static_cast<clang::SourceManager *>(SM),
      *static_cast<clang::LangOptions *>(langOpts));

  if (!ptr) {
    fprintf(stderr, "LIBCLANGEX ERROR: failed to create `clang::Lexer`\n");
    Err = CXInit_CanNotCreate;
  }

  if (ErrorCode)
    *ErrorCode = Err;

  return ptr.release();
}

void clang_Lexer_dispose(CXLexer Lex) { delete static_cast<clang::Lexer *>(Lex); }

// Preprocessor

CXHeaderSearch clang_Preprocessor_getHeaderSearchInfo(CXPreprocessor PP) {
  return &static_cast<clang::Preprocessor *>(PP)->getHeaderSearchInfo();
}

void clang_HeaderSearch_PrintStats(CXHeaderSearch HS) {
  static_cast<clang::HeaderSearch *>(HS)->PrintStats();
}

void clang_Preprocessor_EnterMainSourceFile(CXPreprocessor PP) {
  static_cast<clang::Preprocessor *>(PP)->EnterMainSourceFile();
}

bool clang_Preprocessor_EnterSourceFile(CXPreprocessor PP, CXFileID FID,
                                        CXSourceLocation_ Loc) {
  return static_cast<clang::Preprocessor *>(PP)->EnterSourceFile(
      *static_cast<clang::FileID *>(FID), nullptr,
      clang::SourceLocation::getFromPtrEncoding(Loc));
}

void clang_Preprocessor_EndSourceFile(CXPreprocessor PP) {
  static_cast<clang::Preprocessor *>(PP)->EndSourceFile();
}

void clang_Preprocessor_PrintStats(CXPreprocessor PP) {
  static_cast<clang::Preprocessor *>(PP)->PrintStats();
}

void clang_Preprocessor_InitializeBuiltins(CXPreprocessor PP) {
  auto Prep = static_cast<clang::Preprocessor *>(PP);
  Prep->getBuiltinInfo().initializeBuiltins(Prep->getIdentifierTable(),
                                            Prep->getLangOpts());
}

void clang_Preprocessor_enableIncrementalProcessing(CXPreprocessor PP) {
  static_cast<clang::Preprocessor *>(PP)->enableIncrementalProcessing();
}

bool clang_Preprocessor_isIncrementalProcessingEnabled(CXPreprocessor PP) {
  return static_cast<clang::Preprocessor *>(PP)->isIncrementalProcessingEnabled();
}

// Token