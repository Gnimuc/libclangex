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

CINDEX_LINKAGE void clang_Sema_RestoreNestedNameSpecifierAnnotation(
    CXSema S, void *Annotation, CXSourceLocation_ AnnotationRange_begin,
    CXSourceLocation_ AnnotationRange_end, CXCXXScopeSpec SS);

// CXXScopeSpec
CINDEX_LINKAGE CXCXXScopeSpec clang_CXXScopeSpec_create(CXInit_Error *ErrorCode);

CINDEX_LINKAGE void clang_CXXScopeSpec_dispose(CXCXXScopeSpec SS);

CINDEX_LINKAGE CXNestedNameSpecifier clang_CXXScopeSpec_getScopeRep(CXCXXScopeSpec SS);

CINDEX_LINKAGE CXSourceLocation_ clang_CXXScopeSpec_getBeginLoc(CXCXXScopeSpec SS);

CINDEX_LINKAGE CXSourceLocation_ clang_CXXScopeSpec_getEndLoc(CXCXXScopeSpec SS);

CINDEX_LINKAGE void clang_CXXScopeSpec_setBeginLoc(CXCXXScopeSpec SS, CXSourceLocation_ Loc);

CINDEX_LINKAGE void clang_CXXScopeSpec_setEndLoc(CXCXXScopeSpec SS, CXSourceLocation_ Loc);

CINDEX_LINKAGE bool clang_CXXScopeSpec_isEmpty(CXCXXScopeSpec SS);

CINDEX_LINKAGE bool clang_CXXScopeSpec_isNotEmpty(CXCXXScopeSpec SS);

CINDEX_LINKAGE bool clang_CXXScopeSpec_isInvalid(CXCXXScopeSpec SS);

CINDEX_LINKAGE bool clang_CXXScopeSpec_isValid(CXCXXScopeSpec SS);

#ifdef __cplusplus
}
#endif
#endif