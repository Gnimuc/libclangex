#include "CXCodeGen.h"
#include "clang/CodeGen/ModuleBuilder.h"
#include "clang/Frontend/CompilerInstance.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"

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

void clang_CodeGenerator_HandleTranslationUnit(CXCodeGenerator CG, CXASTContext Ctx) {
  static_cast<clang::CodeGenerator *>(CG)->HandleTranslationUnit(
      *static_cast<clang::ASTContext *>(Ctx));
}