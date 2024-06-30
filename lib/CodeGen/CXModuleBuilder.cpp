#include "clang-ex/CodeGen/CXModuleBuilder.h"
#include "clang/CodeGen/ModuleBuilder.h"
#include "clang/Frontend/CompilerInstance.h"
#include "clang/AST/GlobalDecl.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/Support/Casting.h"
#include "libclang/CXString.h"

CXCodeGenerator clang_CreateLLVMCodeGen(CXCompilerInstance CI, LLVMContextRef LLVMCtx,
                                        const char *ModuleName) {
  auto compiler = static_cast<clang::CompilerInstance *>(CI);
  return clang::CreateLLVMCodeGen(compiler->getDiagnostics(), llvm::StringRef(ModuleName),
                                  compiler->getHeaderSearchOpts(),
                                  compiler->getPreprocessorOpts(),
                                  compiler->getCodeGenOpts(), *llvm::unwrap(LLVMCtx));
}

CXCodeGenModule clang_CodeGenerator_CGM(CXCodeGenerator CG) {
  return &static_cast<clang::CodeGenerator *>(CG)->CGM();
}

LLVMModuleRef clang_CodeGenerator_GetModule(CXCodeGenerator CG) {
  return llvm::wrap(static_cast<clang::CodeGenerator *>(CG)->GetModule());
}

LLVMModuleRef clang_CodeGenerator_ReleaseModule(CXCodeGenerator CG) {
  return llvm::wrap(static_cast<clang::CodeGenerator *>(CG)->ReleaseModule());
}

CXDecl clang_CodeGenerator_GetDeclForMangledName(CXCodeGenerator CG,
                                                 const char *MangledName) {
  return const_cast<clang::Decl *>(
      static_cast<clang::CodeGenerator *>(CG)->GetDeclForMangledName(
          llvm::StringRef(MangledName)));
}

LLVMModuleRef clang_CodeGenerator_StartModule(CXCodeGenerator CG, LLVMContextRef LLVMCtx,
                                              const char *ModuleName) {
  return llvm::wrap(static_cast<clang::CodeGenerator *>(CG)->StartModule(
      llvm::StringRef(ModuleName), *llvm::unwrap(LLVMCtx)));
}

// TODO: Introduce CXGlobalDecl
#if LLVM_VERSION_MAJOR >= 14
CXString clang_CodeGenerator_GetMangledName(CXCodeGenerator CG, CXNamedDecl D) {
  clang::GlobalDecl GD = clang::GlobalDecl(static_cast<clang::NamedDecl *>(D));
  llvm::StringRef name = static_cast<clang::CodeGenerator *>(CG)->GetMangledName(GD);

  return clang::cxstring::createDup(name);
}
#else
CXString clang_CodeGenerator_GetMangledName(CXCodeGenerator CG, CXNamedDecl D) {
  return clang::cxstring::createNull();
}
#endif


