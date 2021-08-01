#include "clang-ex/CXSema.h"
#include "clang/Sema/Sema.h"

void clang_Sema_setCollectStats(CXSema S, bool ShouldCollect) {
  static_cast<clang::Sema *>(S)->CollectStats = ShouldCollect;
}

void clang_Sema_PrintStats(CXSema S) { static_cast<clang::Sema *>(S)->PrintStats(); }