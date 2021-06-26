#include "CXASTUnit.h"
#include "clang/Frontend/ASTUnit.h"

CXASTUnit clang_TranslationUnit_getASTUnit(CXTranslationUnit TU) {
  return clang::cxtu::getASTUnit(TU);
}

CXASTContext clang_ASTUnit_getASTContext(CXASTUnit ASTU) {
  auto &Ctx = static_cast<clang::ASTUnit *>(ASTU)->getASTContext();
  return &Ctx;
}

CXHeaderSearchOptions clang_ASTUnit_getHeaderSearchOpts(CXASTUnit ASTU) {
  auto &HSOpts = static_cast<clang::ASTUnit *>(ASTU)->getHeaderSearchOpts();
  return const_cast<clang::HeaderSearchOptions *>(&HSOpts);
}

CXPreprocessorOptions clang_ASTUnit_getPreprocessorOpts(CXASTUnit ASTU) {
  auto &PPOpts = static_cast<clang::ASTUnit *>(ASTU)->getPreprocessorOpts();
  return const_cast<clang::PreprocessorOptions *>(&PPOpts);
}

CXDiagnosticsEngine clang_ASTUnit_getDiagnostics(CXASTUnit ASTU) {
  auto &Diagnostics = static_cast<clang::ASTUnit *>(ASTU)->getDiagnostics();
  return &Diagnostics;
}