#ifndef LIBCLANGEX_CXCODEGENOPTIONS_H
#define LIBCLANGEX_CXCODEGENOPTIONS_H

#include "clang-c/Platform.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void *CXCodeGenOptions;

typedef enum {
  CXCodeGenOptions_NoError = 0,
  CXCodeGenOptions_CanNotCreate = 1
} CXCodeGenOptions_Error;

CINDEX_LINKAGE CXCodeGenOptions
clang_CodeGenOptions_create(CXCodeGenOptions_Error *ErrorCode);

CINDEX_LINKAGE void clang_CodeGenOptions_dispose(CXCodeGenOptions DO);

#ifdef __cplusplus
}
#endif
#endif
