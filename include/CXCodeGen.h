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

CINDEX_LINKAGE void clang_CodeGenerator_HandleTranslationUnit(CXCodeGenerator CG, CXASTContext Ctx);

#ifdef __cplusplus
}
#endif
#endif