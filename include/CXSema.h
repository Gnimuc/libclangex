#ifndef LIBCLANGEX_CXSEMA_H
#define LIBCLANGEX_CXSEMA_H

#include "CXTypes.h"
#include "clang-c/Platform.h"

#ifdef __cplusplus
extern "C" {
#endif

CINDEX_LINKAGE void clang_Sema_setCollectStats(CXSema S, bool ShouldCollect);

CINDEX_LINKAGE void clang_Sema_processWeakTopLevelDecls(CXSema Sema, CXCodeGenerator CodeGen);

#ifdef __cplusplus
}
#endif
#endif