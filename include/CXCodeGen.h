#ifndef LIBCLANGEX_CXCODEGEN_H
#define LIBCLANGEX_CXCODEGEN_H

#include "CXTypes.h"
#include "clang-c/Platform.h"
#include "llvm-c/Types.h"

#ifdef __cplusplus
extern "C" {
#endif

CINDEX_LINKAGE CXCodeGenerator clang_CreateLLVMCodeGen(CXCompilerInstance CI,
                                                       LLVMContextRef LLVMCtx,
                                                       const char *ModuleName);

#ifdef __cplusplus
}
#endif
#endif