#include "CXSema.h"
#include "clang/Sema/Sema.h"
#include "clang/CodeGen/ModuleBuilder.h"

void clang_Sema_setCollectStats(CXSema S, bool ShouldCollect) {
  static_cast<clang::Sema *>(S)->CollectStats = ShouldCollect;
}

void clang_Sema_processWeakTopLevelDecls(CXSema Sema, CXCodeGenerator CodeGen) {
  auto S = static_cast<clang::Sema *>(Sema);
  auto CG = static_cast<clang::CodeGenerator *>(CodeGen);
  for (clang::Decl *D : S->WeakTopLevelDecls())
    CG->HandleTopLevelDecl(clang::DeclGroupRef(D));
}

void clang_Sema_PrintStats(CXSema S) {
  static_cast<clang::Sema *>(S)->PrintStats();
}