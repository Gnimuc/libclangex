#include "CXPreprocessor.h"
#include "clang/Basic/Builtins.h"
#include "clang/Lex/HeaderSearch.h"
#include "clang/Lex/Preprocessor.h"

CXHeaderSearch clang_Preprocessor_getHeaderSearchInfo(CXPreprocessor PP) {
  return &static_cast<clang::Preprocessor *>(PP)->getHeaderSearchInfo();
}

void clang_HeaderSearch_PrintStats(CXHeaderSearch HS) {
  static_cast<clang::HeaderSearch *>(HS)->PrintStats();
}

void clang_Preprocessor_EnterMainSourceFile(CXPreprocessor PP) {
  static_cast<clang::Preprocessor *>(PP)->EnterMainSourceFile();
}

void clang_Preprocessor_PrintStats(CXPreprocessor PP) {
  static_cast<clang::Preprocessor *>(PP)->PrintStats();
}

void clang_Preprocessor_InitializeBuiltins(CXPreprocessor PP) {
  auto Prep = static_cast<clang::Preprocessor *>(PP);
  Prep->getBuiltinInfo().initializeBuiltins(Prep->getIdentifierTable(),
                                            Prep->getLangOpts());
}
