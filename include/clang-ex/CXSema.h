#ifndef LIBCLANGEX_CXSEMA_H
#define LIBCLANGEX_CXSEMA_H

#include "clang-ex/CXError.h"
#include "clang-ex/CXTypes.h"
#include "clang-c/Platform.h"

#ifdef __cplusplus
extern "C" {
#endif

CINDEX_LINKAGE void clang_Sema_setCollectStats(CXSema S, bool ShouldCollect);

CINDEX_LINKAGE void clang_Sema_PrintStats(CXSema S);

// CXXScopeSpec
CINDEX_LINKAGE CXCXXScopeSpec clang_CXXScopeSpec_create(CXInit_Error *ErrorCode);

CINDEX_LINKAGE void clang_CXXScopeSpec_dispose(CXXScopeSpec SS);

CINDEX_LINKAGE CXNestedNameSpecifier clang_CXXScopeSpec_getScopeRep(CXXScopeSpec SS);

CINDEX_LINKAGE CXSourceLocation_ clang_CXXScopeSpec_getBeginLoc(CXXScopeSpec SS);

CINDEX_LINKAGE CXSourceLocation_ clang_CXXScopeSpec_getEndLoc(CXXScopeSpec SS);

CINDEX_LINKAGE void clang_CXXScopeSpec_setBeginLoc(CXXScopeSpec SS, CXSourceLocation_ Loc);

CINDEX_LINKAGE void clang_CXXScopeSpec_setEndLoc(CXXScopeSpec SS, CXSourceLocation_ Loc);

CINDEX_LINKAGE bool clang_CXXScopeSpec_isEmpty(CXXScopeSpec SS);

CINDEX_LINKAGE bool clang_CXXScopeSpec_isNotEmpty(CXXScopeSpec SS);

CINDEX_LINKAGE bool clang_CXXScopeSpec_isInvalid(CXXScopeSpec SS);

CINDEX_LINKAGE bool clang_CXXScopeSpec_isValid(CXXScopeSpec SS);


#ifdef __cplusplus
}
#endif
#endif