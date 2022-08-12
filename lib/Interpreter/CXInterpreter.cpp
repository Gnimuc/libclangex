#include "clang-ex/Interpreter/CXInterpreter.h"
#include "clang/Frontend/CompilerInstance.h"
#include "clang/Interpreter/Interpreter.h"
#include <cstdio>
#include <vector>

CXCompilerInstance clang_IncrementalCompilerBuilder_create(const char **Args, int N) {
  std::vector<const char *> arr(Args, Args + N);
  auto CI = clang::IncrementalCompilerBuilder::create(arr);
  if (auto E = CI.takeError()) {
    llvm::errs() << "LIBCLANGEX ERROR: " << llvm::toString(std::move(E)) << "\n";
    return nullptr;
  }
  return CI->release();
}

CXInterpreter clang_Interpreter_create(CXCompilerInstance CI) {
  auto ptr = clang::Interpreter::create(
      std::unique_ptr<clang::CompilerInstance>(static_cast<clang::CompilerInstance *>(CI)));

  if (auto E = ptr.takeError()) {
    llvm::errs() << "LIBCLANGEX ERROR: " << llvm::toString(std::move(E)) << "\n";
    return nullptr;
  }

  return ptr->release();
}

void clang_Interpreter_dispose(CXInterpreter Interp) {
  delete static_cast<clang::Interpreter *>(Interp);
}

CXCompilerInstance clang_Interpreter_getCompilerInstance(CXInterpreter Interp) {
  return const_cast<clang::CompilerInstance *>(
      static_cast<clang::Interpreter *>(Interp)->getCompilerInstance());
}

CXPartialTranslationUnit clang_Interpreter_Parse(CXInterpreter Interp, const char *Code) {
  auto PTU = static_cast<clang::Interpreter *>(Interp)->Parse(llvm::StringRef(Code));
  if (auto E = PTU.takeError()) {
    llvm::errs() << "LIBCLANGEX ERROR: " << llvm::toString(std::move(E)) << "\n";
    return nullptr;
  }
  return &*PTU;
}

void clang_Interpreter_Execute(CXInterpreter Interp, CXPartialTranslationUnit PTU) {
  auto err = static_cast<clang::Interpreter *>(Interp)->Execute(
      *static_cast<clang::PartialTranslationUnit *>(PTU));
  if (err)
    llvm::errs() << "LIBCLANGEX ERROR: " << llvm::toString(std::move(err)) << "\n";
}

void clang_Interpreter_ParseAndExecute(CXInterpreter Interp, const char *Code) {
  auto err =
      static_cast<clang::Interpreter *>(Interp)->ParseAndExecute(llvm::StringRef(Code));
  if (err)
    llvm::errs() << "LIBCLANGEX ERROR: " << llvm::toString(std::move(err)) << "\n";
}
