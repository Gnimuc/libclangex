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

CINDEX_LINKAGE unsigned clang_QualType_getCVRQualifiers(CXQualType OpaquePtr);

CINDEX_LINKAGE char *clang_QualType_getAsString(CXQualType OpaquePtr);
CINDEX_LINKAGE void clang_QualType_disposeString(char *Str);

CINDEX_LINKAGE void clang_QualType_dump(CXQualType OpaquePtr);

CINDEX_LINKAGE CXQualType clang_QualType_getCanonicalType(CXQualType OpaquePtr);

CINDEX_LINKAGE CXQualType clang_QualType_getLocalUnqualifiedType(CXQualType OpaquePtr);

CINDEX_LINKAGE CXQualType clang_QualType_getUnqualifiedType(CXQualType OpaquePtr);

// Type
CINDEX_LINKAGE bool clang_Type_isFromAST(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isCanonicalUnqualified(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isSizelessType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isSizelessBuiltinType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isBuiltinType(CXType_ T);

// CINDEX_LINKAGE bool clang_Type_isIntegerType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isEnumeralType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isScopedEnumeralType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isBooleanType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isCharType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isWideCharType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isChar8Type(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isChar16Type(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isChar32Type(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isAnyCharacterType(CXType_ T);

// CINDEX_LINKAGE bool clang_Type_isIntegralOrEnumerationType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isIntegralOrUnscopedEnumerationType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isUnscopedEnumerationType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isRealFloatingType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isComplexType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isAnyComplexType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isFloatingType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isHalfType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isFloat16Type(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isBFloat16Type(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isFloat128Type(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isRealType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isArithmeticType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isVoidType(CXType_ T);

// CINDEX_LINKAGE bool clang_Type_isScalarType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isAggregateType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isFundamentalType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isCompoundType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isFunctionType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isFunctionNoProtoType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isFunctionProtoType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isPointerType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isAnyPointerType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isBlockPointerType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isVoidPointerType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isReferenceType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isLValueReferenceType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isRValueReferenceType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isObjectPointerType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isFunctionPointerType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isFunctionReferenceType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isMemberPointerType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isMemberFunctionPointerType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isMemberDataPointerType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isArrayType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isConstantArrayType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isIncompleteArrayType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isVariableArrayType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isDependentSizedArrayType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isRecordType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isClassType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isStructureType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isObjCBoxableRecordType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isInterfaceType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isStructureOrClassType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isUnionType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isComplexIntegerType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isVectorType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isExtVectorType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isMatrixType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isConstantMatrixType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isDependentAddressSpaceType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isDecltypeType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isTemplateTypeParmType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isNullPtrType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isNothrowT(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isAlignValT(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isStdByteType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isAtomicType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isUndeducedAutoType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isTypedefNameType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isDependentType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isInstantiationDependentType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isUndeducedType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isVariablyModifiedType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_hasSizedVLAType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_hasUnnamedOrLocalType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isOverloadableType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isElaboratedTypeSpecifier(CXType_ T);

CINDEX_LINKAGE bool clang_Type_canDecayToPointerType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_hasPointerRepresentation(CXType_ T);

CINDEX_LINKAGE bool clang_Type_hasObjCPointerRepresentation(CXType_ T);

// CINDEX_LINKAGE bool clang_Type_hasIntegerRepresentation(CXType_ T);

CINDEX_LINKAGE bool clang_Type_hasSignedIntegerRepresentation(CXType_ T);

CINDEX_LINKAGE bool clang_Type_hasUnsignedIntegerRepresentation(CXType_ T);

CINDEX_LINKAGE bool clang_Type_hasFloatingRepresentation(CXType_ T);

CINDEX_LINKAGE CXRecordType clang_Type_getAsStructureType(CXType_ T);

CINDEX_LINKAGE CXRecordType clang_Type_getAsUnionType(CXType_ T);

// CINDEX_LINKAGE CXComplexType clang_Type_getAsComplexIntegerType(CXType_ T);

CINDEX_LINKAGE CXCXXRecordDecl clang_Type_getAsCXXRecordDecl(CXType_ T);

CINDEX_LINKAGE CXRecordDecl clang_Type_getAsRecordDecl(CXType_ T);

CINDEX_LINKAGE CXTagDecl clang_Type_getAsTagDecl(CXType_ T);

CINDEX_LINKAGE CXCXXRecordDecl clang_Type_getPointeeCXXRecordDecl(CXType_ T);

CINDEX_LINKAGE CXDeducedType clang_Type_getContainedDeducedType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_hasAutoForTrailingReturnType(CXType_ T);

CINDEX_LINKAGE CXType_ clang_Type_getArrayElementTypeNoTypeQual(CXType_ T);

CINDEX_LINKAGE CXType_ clang_Type_getPointeeOrArrayElementType(CXType_ T);

CINDEX_LINKAGE CXQualType clang_Type_getPointeeType(CXType_ T);

CINDEX_LINKAGE CXType_ clang_Type_getUnqualifiedDesugaredType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isPromotableIntegerType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isSignedIntegerType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isUnsignedIntegerType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isSignedIntegerOrEnumerationType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isUnsignedIntegerOrEnumerationType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isFixedPointType(CXType_ T);

// CINDEX_LINKAGE bool clang_Type_isFixedPointOrIntegerType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isSaturatedFixedPointType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isUnsaturatedFixedPointType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isSignedFixedPointType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isUnsignedFixedPointType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isConstantSizeType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isSpecifierType(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isVisibilityExplicit(CXType_ T);

CINDEX_LINKAGE bool clang_Type_isLinkageValid(CXType_ T);

CINDEX_LINKAGE CXQualType clang_Type_getCanonicalTypeInternal(CXType_ T);

CINDEX_LINKAGE void clang_Type_dump(CXType_ T);

#ifdef __cplusplus
}
#endif
#endif