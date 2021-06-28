#ifndef LIBCLANGEX_CXASTUNIT_H
#define LIBCLANGEX_CXASTUNIT_H

#include "CXTypes.h"
#include "clang-c/Platform.h"
#include "clang-c/Index.h"

#ifdef __cplusplus
extern "C" {
#endif

CINDEX_LINKAGE CXASTUnit clang_TranslationUnit_getASTUnit(CXTranslationUnit TU);

CINDEX_LINKAGE CXASTContext clang_ASTUnit_getASTContext(CXASTUnit ASTU);

CINDEX_LINKAGE CXHeaderSearchOptions clang_ASTUnit_getHeaderSearchOpts(CXASTUnit ASTU);

CINDEX_LINKAGE CXPreprocessorOptions clang_ASTUnit_getPreprocessorOpts(CXASTUnit ASTU);

CINDEX_LINKAGE CXDiagnosticsEngine clang_ASTUnit_getDiagnostics(CXASTUnit ASTU);

CINDEX_LINKAGE CXSema clang_ASTUnit_getSema(CXASTUnit ASTU);

CINDEX_LINKAGE CXFileManager clang_ASTUnit_getFileManager(CXASTUnit ASTU);

CINDEX_LINKAGE CXSourceManager clang_ASTUnit_getSourceManager(CXASTUnit ASTU);

CINDEX_LINKAGE CXPreprocessor clang_ASTUnit_getPreprocessor(CXASTUnit ASTU);

#ifdef __cplusplus
}
#endif
#endif