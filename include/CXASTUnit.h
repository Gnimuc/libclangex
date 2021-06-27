#ifndef LIBCLANGEX_CXASTUNIT_H
#define LIBCLANGEX_CXASTUNIT_H

#include "CIndexer.h"
#include "CXCodeGenOptions.h"
#include "CXDiagnostic.h"
#include "CXTranslationUnit.h"
#include "clang-c/Platform.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void *CXASTUnit;
typedef void *CXASTContext;
typedef void *CXHeaderSearchOptions;
typedef void *CXPreprocessorOptions;

CINDEX_LINKAGE CXASTUnit clang_TranslationUnit_getASTUnit(CXTranslationUnit TU);

CINDEX_LINKAGE CXASTContext clang_ASTUnit_getASTContext(CXASTUnit ASTU);

CINDEX_LINKAGE CXHeaderSearchOptions
clang_ASTUnit_getHeaderSearchOpts(CXASTUnit ASTU);

CINDEX_LINKAGE CXPreprocessorOptions
clang_ASTUnit_getPreprocessorOpts(CXASTUnit ASTU);

CINDEX_LINKAGE CXDiagnosticsEngine clang_ASTUnit_getDiagnostics(CXASTUnit ASTU);

#ifdef __cplusplus
}
#endif
#endif