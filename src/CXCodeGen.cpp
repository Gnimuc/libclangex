#include "CXCodeGen.h"
#include "clang/Basic/CodeGenOptions.h"
#include "clang/CodeGen/ModuleBuilder.h"
#include "clang/Frontend/CompilerInstance.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include <cstdio>

CXCodeGenerator clang_CreateLLVMCodeGen(CXCompilerInstance CI, LLVMContextRef LLVMCtx,
                                        const char *ModuleName) {
  auto compiler = static_cast<clang::CompilerInstance *>(CI);
  return clang::CreateLLVMCodeGen(compiler->getDiagnostics(), llvm::StringRef(ModuleName),
                                  compiler->getHeaderSearchOpts(),
                                  compiler->getPreprocessorOpts(),
                                  compiler->getCodeGenOpts(), *llvm::unwrap(LLVMCtx));
}

LLVMModuleRef clang_CodeGenerator_getLLVMModule(CXCodeGenerator CG) {
  return llvm::wrap(static_cast<clang::CodeGenerator *>(CG)->GetModule());
}

CXCodeGenOptions clang_CodeGenOptions_create(CXInit_Error *ErrorCode) {
  CXInit_Error Err = CXInit_NoError;
  std::unique_ptr<clang::CodeGenOptions> ptr = std::make_unique<clang::CodeGenOptions>();

  if (!ptr) {
    fprintf(stderr, "LIBCLANGEX ERROR: failed to create `clang::CodeGenOptions`\n");
    Err = CXInit_CanNotCreate;
  }

  if (ErrorCode)
    *ErrorCode = Err;

  return ptr.release();
}

void clang_CodeGenOptions_dispose(CXCodeGenOptions DO) {
  delete static_cast<clang::CodeGenOptions *>(DO);
}