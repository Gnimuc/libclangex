#include "clang-ex/CXSema.h"
#include "clang/Sema/Sema.h"

void clang_Sema_setCollectStats(CXSema S, bool ShouldCollect) {
  static_cast<clang::Sema *>(S)->CollectStats = ShouldCollect;
}

void clang_Sema_PrintStats(CXSema S) { static_cast<clang::Sema *>(S)->PrintStats(); }

// CXXScopeSpec
CXCXXScopeSpec clang_CXXScopeSpec_create(CXInit_Error *ErrorCode) {
  CXInit_Error Err = CXInit_NoError;
  std::unique_ptr<clang::CXXScopeSpec> ptr = std::make_unique<clang::CXXScopeSpec>();

  if (!ptr) {
    fprintf(stderr, "LIBCLANGEX ERROR: failed to create `clang::CXXScopeSpec`\n");
    Err = CXInit_CanNotCreate;
  }

  if (ErrorCode)
    *ErrorCode = Err;

  return ptr.release();
}

void clang_CXXScopeSpec_dispose(CXXScopeSpec SS) {
  delete static_cast<clang::CXXScopeSpec *>(SS);
}

CXNestedNameSpecifier clang_CXXScopeSpec_getScopeRep(CXXScopeSpec SS) {
  return static_cast<clang::CXXScopeSpec *>(SS)->getScopeRep();
}

CXSourceLocation_ clang_CXXScopeSpec_getBeginLoc(CXXScopeSpec SS) {
  return static_cast<clang::CXXScopeSpec *>(SS)->getBeginLoc().getPtrEncoding();
}

CXSourceLocation_ clang_CXXScopeSpec_getEndLoc(CXXScopeSpec SS) {
  return static_cast<clang::CXXScopeSpec *>(SS)->getEndLoc().getPtrEncoding();
}

void clang_CXXScopeSpec_setBeginLoc(CXXScopeSpec SS, CXSourceLocation_ Loc) {
  static_cast<clang::CXXScopeSpec *>(SS)->setBeginLoc(
      clang::SourceLocation::getFromPtrEncoding(Loc));
}

void clang_CXXScopeSpec_setEndLoc(CXXScopeSpec SS, CXSourceLocation_ Loc) {
  static_cast<clang::CXXScopeSpec *>(SS)->setEndLoc(
      clang::SourceLocation::getFromPtrEncoding(Loc));
}

bool clang_CXXScopeSpec_isEmpty(CXXScopeSpec SS) {
  return static_cast<clang::CXXScopeSpec *>(SS)->isEmpty();
}

bool clang_CXXScopeSpec_isNotEmpty(CXXScopeSpec SS) {
  return static_cast<clang::CXXScopeSpec *>(SS)->isNotEmpty();
}

bool clang_CXXScopeSpec_isInvalid(CXXScopeSpec SS) {
  return static_cast<clang::CXXScopeSpec *>(SS)->isInvalid();
}

bool clang_CXXScopeSpec_isValid(CXXScopeSpec SS) {
  return static_cast<clang::CXXScopeSpec *>(SS)->isValid();
}