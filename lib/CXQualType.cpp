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
