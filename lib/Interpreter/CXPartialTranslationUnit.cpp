#include "clang-ex/Interpreter/CXPartialTranslationUnit.h"
#include "clang/Interpreter/PartialTranslationUnit.h"
#include "llvm/IR/Module.h"

CXTranslationUnitDecl
clang_PartialTranslationUnit_get_TUPart(CXPartialTranslationUnit PTU) {
  return static_cast<clang::PartialTranslationUnit *>(PTU)->TUPart;
}

LLVMModuleRef clang_PartialTranslationUnit_get_TheModule(CXPartialTranslationUnit PTU) {
  return llvm::wrap(static_cast<clang::PartialTranslationUnit *>(PTU)->TheModule.get());
}
