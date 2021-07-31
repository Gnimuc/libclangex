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

CINDEX_LINKAGE CXCodeGenModule clang_CodeGenerator_CGM(CXCodeGenerator CG);

CINDEX_LINKAGE LLVMModuleRef clang_CodeGenerator_GetModule(CXCodeGenerator CG);

CINDEX_LINKAGE LLVMModuleRef clang_CodeGenerator_ReleaseModule(CXCodeGenerator CG);

CINDEX_LINKAGE CXDecl clang_CodeGenerator_GetDeclForMangledName(CXCodeGenerator CG,
                                                                const char *MangledName);

CINDEX_LINKAGE LLVMModuleRef clang_CodeGenerator_StartModule(CXCodeGenerator CG,
                                                             LLVMContextRef LLVMCtx,
                                                             const char *ModuleName);

// CodeGenActions
CINDEX_LINKAGE CXCodeGenAction clang_EmitAssemblyAction_create(CXInit_Error *ErrorCode,
                                                               LLVMContextRef LLVMCtx);
CINDEX_LINKAGE CXCodeGenAction clang_EmitBCAction_create(CXInit_Error *ErrorCode,
                                                         LLVMContextRef LLVMCtx);
CINDEX_LINKAGE CXCodeGenAction clang_EmitLLVMAction_create(CXInit_Error *ErrorCode,
                                                           LLVMContextRef LLVMCtx);
CINDEX_LINKAGE CXCodeGenAction clang_EmitLLVMOnlyAction_create(CXInit_Error *ErrorCode,
                                                               LLVMContextRef LLVMCtx);
CINDEX_LINKAGE CXCodeGenAction clang_EmitCodeGenOnlyAction_create(CXInit_Error *ErrorCode,
                                                                  LLVMContextRef LLVMCtx);
CINDEX_LINKAGE CXCodeGenAction clang_EmitObjAction_create(CXInit_Error *ErrorCode,
                                                          LLVMContextRef LLVMCtx);

CINDEX_LINKAGE void clang_CodeGenAction_dispose(CXCodeGenAction CA);

CINDEX_LINKAGE LLVMModuleRef clang_CodeGenAction_takeModule(CXCodeGenAction CA);

#ifdef __cplusplus
}
#endif
#endif