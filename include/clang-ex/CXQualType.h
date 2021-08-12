#ifndef LIBCLANGEX_CXQUALTYPE_H
#define LIBCLANGEX_CXQUALTYPE_H

#include "clang-ex/CXTypes.h"
#include "clang-c/Platform.h"

#ifdef __cplusplus
extern "C" {
#endif

CINDEX_LINKAGE CXType_ clang_QualType_getTypePtr(CXQualType OpaquePtr);

CINDEX_LINKAGE CXType_ clang_QualType_getTypePtrOrNull(CXQualType OpaquePtr);

CINDEX_LINKAGE bool clang_QualType_isCanonical(CXQualType OpaquePtr);

CINDEX_LINKAGE bool clang_QualType_isNull(CXQualType OpaquePtr);

CINDEX_LINKAGE bool clang_QualType_isConstQualified(CXQualType OpaquePtr);
CINDEX_LINKAGE bool clang_QualType_isRestrictQualified(CXQualType OpaquePtr);
CINDEX_LINKAGE bool clang_QualType_isVolatileQualified(CXQualType OpaquePtr);
CINDEX_LINKAGE bool clang_QualType_hasQualifiers(CXQualType OpaquePtr);

CINDEX_LINKAGE CXQualType clang_QualType_withConst(CXQualType OpaquePtr);
CINDEX_LINKAGE CXQualType clang_QualType_withVolatile(CXQualType OpaquePtr);
CINDEX_LINKAGE CXQualType clang_QualType_withRestrict(CXQualType OpaquePtr);

CINDEX_LINKAGE void clang_QualType_addConst(CXQualType OpaquePtr);
CINDEX_LINKAGE void clang_QualType_addVolatile(CXQualType OpaquePtr);
CINDEX_LINKAGE void clang_QualType_addRestrict(CXQualType OpaquePtr);

CINDEX_LINKAGE bool clang_QualType_isLocalConstQualified(CXQualType OpaquePtr);
CINDEX_LINKAGE bool clang_QualType_isLocalRestrictQualified(CXQualType OpaquePtr);
CINDEX_LINKAGE bool clang_QualType_isLocalVolatileQualified(CXQualType OpaquePtr);
CINDEX_LINKAGE bool clang_QualType_hasLocalQualifiers(CXQualType OpaquePtr);

CINDEX_LINKAGE char *clang_QualType_getAsString(CXQualType OpaquePtr);
CINDEX_LINKAGE void clang_QualType_disposeString(char *Str);

CINDEX_LINKAGE void clang_QualType_dump(CXQualType OpaquePtr);

CINDEX_LINKAGE CXQualType clang_QualType_getCanonicalType(CXQualType OpaquePtr);

CINDEX_LINKAGE CXQualType clang_QualType_getLocalUnqualifiedType(CXQualType OpaquePtr);

CINDEX_LINKAGE CXQualType clang_QualType_getUnqualifiedType(CXQualType OpaquePtr);

#ifdef __cplusplus
}
#endif
#endif