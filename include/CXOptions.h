#ifndef LIBCLANGEX_CXOPTIONS_H
#define LIBCLANGEX_CXOPTIONS_H

#include "CXTypes.h"
#include "clang-c/Platform.h"

#ifdef __cplusplus
extern "C" {
#endif

CINDEX_LINKAGE const char *clang_CodeGenOptions_getArgv0(CXCodeGenOptions CGO);

#ifdef __cplusplus
}
#endif
#endif