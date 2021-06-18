#include "libclangex.h"

CXASTUnit clang_get_ASTUnit_from_TranslationUnit(CXTranslationUnit TU) {
  return clang::cxtu::getASTUnit(TU);
}