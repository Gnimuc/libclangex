#ifndef LIBCLANGEX_CXPREPROCESSOR_H
#define LIBCLANGEX_CXPREPROCESSOR_H

#include "CXError.h"
#include "CXTypes.h"
#include "clang-c/Platform.h"

#ifdef __cplusplus
extern "C" {
#endif

CINDEX_LINKAGE CXHeaderSearch clang_Preprocessor_getHeaderSearchInfo(CXPreprocessor PP);

CINDEX_LINKAGE void clang_HeaderSearch_PrintStats(CXHeaderSearch HS);

CINDEX_LINKAGE void clang_Preprocessor_EnterMainSourceFile(CXPreprocessor PP);

CINDEX_LINKAGE void clang_Preprocessor_PrintStats(CXPreprocessor PP);

CINDEX_LINKAGE void clang_Preprocessor_InitializeBuiltins(CXPreprocessor PP);

#ifdef __cplusplus
}
#endif
#endif