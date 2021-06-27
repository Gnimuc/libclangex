#ifndef LIBCLANGEX_CXCODEGENOPTIONS_H
#define LIBCLANGEX_CXCODEGENOPTIONS_H

#include "CXError.h"
#include "clang-c/Platform.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void *CXCodeGenOptions;

CINDEX_LINKAGE CXCodeGenOptions clang_CodeGenOptions_create(CXInit_Error *ErrorCode);

CINDEX_LINKAGE void clang_CodeGenOptions_dispose(CXCodeGenOptions DO);

#ifdef __cplusplus
}
#endif
#endif
