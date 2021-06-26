#ifndef LIBCLANGEX_CXCOMPILERINVOCATION_H
#define LIBCLANGEX_CXCOMPILERINVOCATION_H

#include "clang-c/Platform.h"
#include "CXError.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void *CXCompilerInvocation;

CINDEX_LINKAGE CXCompilerInvocation
clang_CompilerInvocation_create(CXInit_Error *ErrorCode);

CINDEX_LINKAGE void clang_CompilerInvocation_dispose(CXCompilerInvocation CI);

#ifdef __cplusplus
}
#endif
#endif
