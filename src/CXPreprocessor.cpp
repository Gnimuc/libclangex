#include "CXPreprocessor.h"
#include "clang/Lex/HeaderSearch.h"
#include "clang/Lex/Preprocessor.h"

CXHeaderSearch clang_Preprocessor_getHeaderSearchInfo(CXPreprocessor PP) {
  return &static_cast<clang::Preprocessor *>(PP)->getHeaderSearchInfo();
}

void clang_HeaderSearch_PrintStats(CXHeaderSearch HS) {
  static_cast<clang::HeaderSearch *>(HS)->PrintStats();
}
