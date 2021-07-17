#ifndef LIBCLANGEX_CXCODEGEN_H
#define LIBCLANGEX_CXCODEGEN_H

#include "CXError.h"
#include "CXTypes.h"
#include "clang-c/Platform.h"
#include "llvm-c/Types.h"

#ifdef __cplusplus
extern "C" {
#endif

CINDEX_LINKAGE CXCodeGenerator clang_CreateLLVMCodeGen(CXCompilerInstance CI,
                                                       LLVMContextRef LLVMCtx,
                                                       const char *ModuleName);

CINDEX_LINKAGE LLVMModuleRef clang_CodeGenerator_getLLVMModule(CXCodeGenerator CG);

// CodeGenActions
CINDEX_LINKAGE CXCodeGenAction clang_EmitAssemblyAction_create(CXInit_Error *ErrorCode, LLVMContextRef LLVMCtx);
CINDEX_LINKAGE CXCodeGenAction clang_EmitBCAction_create(CXInit_Error *ErrorCode, LLVMContextRef LLVMCtx);
CINDEX_LINKAGE CXCodeGenAction clang_EmitLLVMAction_create(CXInit_Error *ErrorCode, LLVMContextRef LLVMCtx);
CINDEX_LINKAGE CXCodeGenAction clang_EmitLLVMOnlyAction_create(CXInit_Error *ErrorCode, LLVMContextRef LLVMCtx);
CINDEX_LINKAGE CXCodeGenAction clang_EmitCodeGenOnlyAction_create(CXInit_Error *ErrorCode, LLVMContextRef LLVMCtx);
CINDEX_LINKAGE CXCodeGenAction clang_EmitObjAction_create(CXInit_Error *ErrorCode, LLVMContextRef LLVMCtx);

CINDEX_LINKAGE void clang_CodeGenAction_dispose(CXCodeGenAction CA);

CINDEX_LINKAGE LLVMModuleRef clang_CodeGenAction_takeModule(CXCodeGenAction CA);

#ifdef __cplusplus
}
#endif
#endif