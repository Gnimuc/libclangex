#include "clang-ex/CXQualType.h"
#include "clang/AST/Type.h"

CXType_ clang_QualType_getTypePtr(CXQualType OpaquePtr) {
  return const_cast<clang::Type *>(
      clang::QualType::getFromOpaquePtr(OpaquePtr).getTypePtr());
}

CXType_ clang_QualType_getTypePtrOrNull(CXQualType OpaquePtr) {
  return const_cast<clang::Type *>(
      clang::QualType::getFromOpaquePtr(OpaquePtr).getTypePtrOrNull());
}

bool clang_QualType_isCanonical(CXQualType OpaquePtr) {
  return clang::QualType::getFromOpaquePtr(OpaquePtr).isCanonical();
}

bool clang_QualType_isNull(CXQualType OpaquePtr) {
  return clang::QualType::getFromOpaquePtr(OpaquePtr).isNull();
}

bool clang_QualType_isConstQualified(CXQualType OpaquePtr) {
  return clang::QualType::getFromOpaquePtr(OpaquePtr).isConstQualified();
}

bool clang_QualType_isRestrictQualified(CXQualType OpaquePtr) {
  return clang::QualType::getFromOpaquePtr(OpaquePtr).isRestrictQualified();
}

bool clang_QualType_isVolatileQualified(CXQualType OpaquePtr) {
  return clang::QualType::getFromOpaquePtr(OpaquePtr).isVolatileQualified();
}

bool clang_QualType_hasQualifiers(CXQualType OpaquePtr) {
  return clang::QualType::getFromOpaquePtr(OpaquePtr).hasQualifiers();
}

CXQualType clang_QualType_withConst(CXQualType OpaquePtr) {
  return clang::QualType::getFromOpaquePtr(OpaquePtr).withConst().getAsOpaquePtr();
}

CXQualType clang_QualType_withVolatile(CXQualType OpaquePtr) {
  return clang::QualType::getFromOpaquePtr(OpaquePtr).withVolatile().getAsOpaquePtr();
}

CXQualType clang_QualType_withRestrict(CXQualType OpaquePtr) {
  return clang::QualType::getFromOpaquePtr(OpaquePtr).withRestrict().getAsOpaquePtr();
}

void clang_QualType_addConst(CXQualType OpaquePtr) {
  clang::QualType::getFromOpaquePtr(OpaquePtr).addConst();
}

void clang_QualType_addVolatile(CXQualType OpaquePtr) {
  clang::QualType::getFromOpaquePtr(OpaquePtr).addVolatile();
}

void clang_QualType_addRestrict(CXQualType OpaquePtr) {
  clang::QualType::getFromOpaquePtr(OpaquePtr).addRestrict();
}

bool clang_QualType_isLocalConstQualified(CXQualType OpaquePtr) {
  return clang::QualType::getFromOpaquePtr(OpaquePtr).isLocalConstQualified();
}

bool clang_QualType_isLocalRestrictQualified(CXQualType OpaquePtr) {
  return clang::QualType::getFromOpaquePtr(OpaquePtr).isLocalRestrictQualified();
}

bool clang_QualType_isLocalVolatileQualified(CXQualType OpaquePtr) {
  return clang::QualType::getFromOpaquePtr(OpaquePtr).isLocalVolatileQualified();
}

bool clang_QualType_hasLocalQualifiers(CXQualType OpaquePtr) {
  return clang::QualType::getFromOpaquePtr(OpaquePtr).hasLocalQualifiers();
}

unsigned clang_QualType_getCVRQualifiers(CXQualType OpaquePtr) {
  return clang::QualType::getFromOpaquePtr(OpaquePtr).getCVRQualifiers();
}

char *clang_QualType_getAsString(CXQualType OpaquePtr) {
  auto str = clang::QualType::getFromOpaquePtr(OpaquePtr).getAsString();
  std::unique_ptr<char[]> ptr = std::make_unique<char[]>(str.size() + 1);
  ptr[str.size() + 1] = '\0';
  std::copy(str.begin(), str.end(), ptr.get());
  return ptr.release();
}

void clang_QualType_disposeString(char *Str) { delete[] Str; }

void clang_QualType_dump(CXQualType OpaquePtr) {
  clang::QualType::getFromOpaquePtr(OpaquePtr).dump();
}

CXQualType clang_QualType_getCanonicalType(CXQualType OpaquePtr) {
  return clang::QualType::getFromOpaquePtr(OpaquePtr).getCanonicalType().getAsOpaquePtr();
}

CXQualType clang_QualType_getLocalUnqualifiedType(CXQualType OpaquePtr) {
  return clang::QualType::getFromOpaquePtr(OpaquePtr)
      .getLocalUnqualifiedType()
      .getAsOpaquePtr();
}

CXQualType clang_QualType_getUnqualifiedType(CXQualType OpaquePtr) {
  return clang::QualType::getFromOpaquePtr(OpaquePtr).getUnqualifiedType().getAsOpaquePtr();
}

// Type
bool clang_Type_isFromAST(CXType_ T) { return static_cast<clang::Type *>(T)->isFromAST(); }

bool clang_Type_isCanonicalUnqualified(CXType_ T) {
  return static_cast<clang::Type *>(T)->isCanonicalUnqualified();
}

bool clang_Type_isSizelessType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isSizelessType();
}

bool clang_Type_isSizelessBuiltinType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isSizelessBuiltinType();
}

bool clang_Type_isBuiltinType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isBuiltinType();
}

// bool clang_Type_isIntegerType(CXType_ T) {
//   return static_cast<clang::Type *>(T)->isIntegerType();
// }

bool clang_Type_isEnumeralType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isEnumeralType();
}

bool clang_Type_isScopedEnumeralType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isScopedEnumeralType();
}

bool clang_Type_isBooleanType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isBooleanType();
}

bool clang_Type_isCharType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isCharType();
}

bool clang_Type_isWideCharType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isWideCharType();
}

bool clang_Type_isChar8Type(CXType_ T) {
  return static_cast<clang::Type *>(T)->isChar8Type();
}

bool clang_Type_isChar16Type(CXType_ T) {
  return static_cast<clang::Type *>(T)->isChar16Type();
}

bool clang_Type_isChar32Type(CXType_ T) {
  return static_cast<clang::Type *>(T)->isChar32Type();
}

bool clang_Type_isAnyCharacterType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isAnyCharacterType();
}

// bool clang_Type_isIntegralOrEnumerationType(CXType_ T) {
//   return static_cast<clang::Type *>(T)->isIntegralOrEnumerationType();
// }

bool clang_Type_isIntegralOrUnscopedEnumerationType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isIntegralOrUnscopedEnumerationType();
}

bool clang_Type_isUnscopedEnumerationType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isUnscopedEnumerationType();
}

bool clang_Type_isRealFloatingType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isRealFloatingType();
}

bool clang_Type_isComplexType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isComplexType();
}

bool clang_Type_isAnyComplexType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isAnyComplexType();
}

bool clang_Type_isFloatingType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isFloatingType();
}

bool clang_Type_isHalfType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isHalfType();
}

bool clang_Type_isFloat16Type(CXType_ T) {
  return static_cast<clang::Type *>(T)->isFloat16Type();
}

bool clang_Type_isBFloat16Type(CXType_ T) {
  return static_cast<clang::Type *>(T)->isBFloat16Type();
}

bool clang_Type_isFloat128Type(CXType_ T) {
  return static_cast<clang::Type *>(T)->isFloat128Type();
}

bool clang_Type_isRealType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isRealType();
}

bool clang_Type_isArithmeticType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isArithmeticType();
}

bool clang_Type_isVoidType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isVoidType();
}

// bool clang_Type_isScalarType(CXType_ T) {
//   return static_cast<clang::Type *>(T)->isScalarType();
// }

bool clang_Type_isAggregateType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isAggregateType();
}

bool clang_Type_isFundamentalType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isFundamentalType();
}

bool clang_Type_isCompoundType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isCompoundType();
}

bool clang_Type_isFunctionType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isFunctionType();
}

bool clang_Type_isFunctionNoProtoType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isFunctionNoProtoType();
}

bool clang_Type_isFunctionProtoType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isFunctionProtoType();
}

bool clang_Type_isPointerType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isPointerType();
}

bool clang_Type_isAnyPointerType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isAnyPointerType();
}

bool clang_Type_isBlockPointerType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isBlockPointerType();
}

bool clang_Type_isVoidPointerType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isVoidPointerType();
}

bool clang_Type_isReferenceType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isReferenceType();
}

bool clang_Type_isLValueReferenceType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isLValueReferenceType();
}

bool clang_Type_isRValueReferenceType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isRValueReferenceType();
}

bool clang_Type_isObjectPointerType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isObjectPointerType();
}

bool clang_Type_isFunctionPointerType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isFunctionPointerType();
}

bool clang_Type_isFunctionReferenceType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isFunctionReferenceType();
}

bool clang_Type_isMemberPointerType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isMemberPointerType();
}

bool clang_Type_isMemberFunctionPointerType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isMemberFunctionPointerType();
}

bool clang_Type_isMemberDataPointerType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isMemberDataPointerType();
}

bool clang_Type_isArrayType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isArrayType();
}

bool clang_Type_isConstantArrayType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isConstantArrayType();
}

bool clang_Type_isIncompleteArrayType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isIncompleteArrayType();
}

bool clang_Type_isVariableArrayType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isVariableArrayType();
}

bool clang_Type_isDependentSizedArrayType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isDependentSizedArrayType();
}

bool clang_Type_isRecordType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isRecordType();
}

bool clang_Type_isClassType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isClassType();
}

bool clang_Type_isStructureType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isStructureType();
}

bool clang_Type_isObjCBoxableRecordType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isObjCBoxableRecordType();
}

bool clang_Type_isInterfaceType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isInterfaceType();
}

bool clang_Type_isStructureOrClassType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isStructureOrClassType();
}

bool clang_Type_isUnionType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isUnionType();
}

bool clang_Type_isComplexIntegerType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isComplexIntegerType();
}

bool clang_Type_isVectorType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isVectorType();
}

bool clang_Type_isExtVectorType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isExtVectorType();
}

bool clang_Type_isMatrixType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isMatrixType();
}

bool clang_Type_isConstantMatrixType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isConstantMatrixType();
}

bool clang_Type_isDependentAddressSpaceType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isDependentAddressSpaceType();
}

bool clang_Type_isDecltypeType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isDecltypeType();
}

bool clang_Type_isTemplateTypeParmType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isTemplateTypeParmType();
}

bool clang_Type_isNullPtrType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isNullPtrType();
}

bool clang_Type_isNothrowT(CXType_ T) {
  return static_cast<clang::Type *>(T)->isNothrowT();
}

bool clang_Type_isAlignValT(CXType_ T) {
  return static_cast<clang::Type *>(T)->isAlignValT();
}

bool clang_Type_isStdByteType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isStdByteType();
}

bool clang_Type_isAtomicType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isAtomicType();
}

bool clang_Type_isUndeducedAutoType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isUndeducedAutoType();
}

bool clang_Type_isTypedefNameType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isTypedefNameType();
}

bool clang_Type_isDependentType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isDependentType();
}

bool clang_Type_isInstantiationDependentType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isInstantiationDependentType();
}

bool clang_Type_isUndeducedType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isUndeducedType();
}

bool clang_Type_isVariablyModifiedType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isVariablyModifiedType();
}

bool clang_Type_hasSizedVLAType(CXType_ T) {
  return static_cast<clang::Type *>(T)->hasSizedVLAType();
}

bool clang_Type_hasUnnamedOrLocalType(CXType_ T) {
  return static_cast<clang::Type *>(T)->hasUnnamedOrLocalType();
}

bool clang_Type_isOverloadableType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isOverloadableType();
}

bool clang_Type_isElaboratedTypeSpecifier(CXType_ T) {
  return static_cast<clang::Type *>(T)->isElaboratedTypeSpecifier();
}

bool clang_Type_canDecayToPointerType(CXType_ T) {
  return static_cast<clang::Type *>(T)->canDecayToPointerType();
}

bool clang_Type_hasPointerRepresentation(CXType_ T) {
  return static_cast<clang::Type *>(T)->hasPointerRepresentation();
}

bool clang_Type_hasObjCPointerRepresentation(CXType_ T) {
  return static_cast<clang::Type *>(T)->hasObjCPointerRepresentation();
}

// bool clang_Type_hasIntegerRepresentation(CXType_ T) {
//   return static_cast<clang::Type *>(T)->hasIntegerRepresentation();
// }

bool clang_Type_hasSignedIntegerRepresentation(CXType_ T) {
  return static_cast<clang::Type *>(T)->hasSignedIntegerRepresentation();
}

bool clang_Type_hasUnsignedIntegerRepresentation(CXType_ T) {
  return static_cast<clang::Type *>(T)->hasUnsignedIntegerRepresentation();
}

bool clang_Type_hasFloatingRepresentation(CXType_ T) {
  return static_cast<clang::Type *>(T)->hasFloatingRepresentation();
}

CXRecordType clang_Type_getAsStructureType(CXType_ T) {
  return const_cast<clang::RecordType *>(
      static_cast<clang::Type *>(T)->getAsStructureType());
}

CXRecordType clang_Type_getAsUnionType(CXType_ T) {
  return const_cast<clang::RecordType *>(static_cast<clang::Type *>(T)->getAsUnionType());
}

// CXComplexType clang_Type_getAsComplexIntegerType(CXType_ T) {
//   return const_cast<clang::ComplexType *>(
//       static_cast<clang::Type *>(T)->getAsComplexIntegerType());
// }

CXCXXRecordDecl clang_Type_getAsCXXRecordDecl(CXType_ T) {
  return static_cast<clang::Type *>(T)->getAsCXXRecordDecl();
}

CXRecordDecl clang_Type_getAsRecordDecl(CXType_ T) {
  return static_cast<clang::Type *>(T)->getAsRecordDecl();
}

CXTagDecl clang_Type_getAsTagDecl(CXType_ T) {
  return static_cast<clang::Type *>(T)->getAsTagDecl();
}

CXCXXRecordDecl clang_Type_getPointeeCXXRecordDecl(CXType_ T) {
  return const_cast<clang::CXXRecordDecl *>(
      static_cast<clang::Type *>(T)->getPointeeCXXRecordDecl());
}

CXDeducedType clang_Type_getContainedDeducedType(CXType_ T) {
  return static_cast<clang::Type *>(T)->getContainedDeducedType();
}

bool clang_Type_hasAutoForTrailingReturnType(CXType_ T) {
  return static_cast<clang::Type *>(T)->hasAutoForTrailingReturnType();
}

CXType_ clang_Type_getArrayElementTypeNoTypeQual(CXType_ T) {
  return const_cast<clang::Type *>(
      static_cast<clang::Type *>(T)->getArrayElementTypeNoTypeQual());
}

CXType_ clang_Type_getPointeeOrArrayElementType(CXType_ T) {
  return const_cast<clang::Type *>(
      static_cast<clang::Type *>(T)->getPointeeOrArrayElementType());
}

CXQualType clang_Type_getPointeeType(CXType_ T) {
  return static_cast<clang::Type *>(T)->getPointeeType().getAsOpaquePtr();
}

CXType_ clang_Type_getUnqualifiedDesugaredType(CXType_ T) {
  return const_cast<clang::Type *>(
      static_cast<clang::Type *>(T)->getUnqualifiedDesugaredType());
}

bool clang_Type_isPromotableIntegerType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isPromotableIntegerType();
}

bool clang_Type_isSignedIntegerType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isSignedIntegerType();
}

bool clang_Type_isUnsignedIntegerType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isUnsignedIntegerType();
}

bool clang_Type_isSignedIntegerOrEnumerationType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isSignedIntegerOrEnumerationType();
}

bool clang_Type_isUnsignedIntegerOrEnumerationType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isUnsignedIntegerOrEnumerationType();
}

bool clang_Type_isFixedPointType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isFixedPointType();
}

// bool clang_Type_isFixedPointOrIntegerType(CXType_ T) {
//   return static_cast<clang::Type *>(T)->isFixedPointOrIntegerType();
// }

bool clang_Type_isSaturatedFixedPointType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isSaturatedFixedPointType();
}

bool clang_Type_isUnsaturatedFixedPointType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isUnsaturatedFixedPointType();
}

bool clang_Type_isSignedFixedPointType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isSignedFixedPointType();
}

bool clang_Type_isUnsignedFixedPointType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isUnsignedFixedPointType();
}

bool clang_Type_isConstantSizeType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isConstantSizeType();
}

bool clang_Type_isSpecifierType(CXType_ T) {
  return static_cast<clang::Type *>(T)->isSpecifierType();
}

bool clang_Type_isVisibilityExplicit(CXType_ T) {
  return static_cast<clang::Type *>(T)->isVisibilityExplicit();
}

bool clang_Type_isLinkageValid(CXType_ T) {
  return static_cast<clang::Type *>(T)->isLinkageValid();
}

CXQualType clang_Type_getCanonicalTypeInternal(CXType_ T) {
  return static_cast<clang::Type *>(T)->getCanonicalTypeInternal().getAsOpaquePtr();
}

void clang_Type_dump(CXType_ T) { return static_cast<clang::Type *>(T)->dump(); }
