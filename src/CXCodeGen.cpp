#include "CXCodeGen.h"
#include "clang/CodeGen/ModuleBuilder.h"
#include "clang/Frontend/CompilerInstance.h"
#include "llvm/IR/LLVMContext.h"

CXCodeGenerator clang_CreateLLVMCodeGen(CXCompilerInstance CI, LLVMContextRef LLVMCtx,
                                        const char *ModuleName) {
  auto compiler = static_cast<clang::CompilerInstance *>(CI);
  return clang::CreateLLVMCodeGen(compiler->getDiagnostics(), llvm::StringRef(ModuleName),
                                  compiler->getHeaderSearchOpts(),
                                  compiler->getPreprocessorOpts(),
                                  compiler->getCodeGenOpts(), *llvm::unwrap(LLVMCtx));
}