#ifndef LIBCLANGEX_H
#define LIBCLANGEX_H

#include "CIndexer.h"
#include "CXTranslationUnit.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void *CXASTUnit;

CINDEX_LINKAGE CXASTUnit
clang_get_ASTUnit_from_TranslationUnit(CXTranslationUnit TU);

#ifdef __cplusplus
}
#endif
#endif
