#include "clang-ex/CXSema.h"
#include "clang/Basic/SourceLocation.h"
#include "clang/Sema/Lookup.h"
#include "clang/Sema/Sema.h"

void clang_Sema_setCollectStats(CXSema S, bool ShouldCollect) {
  static_cast<clang::Sema *>(S)->CollectStats = ShouldCollect;
}

void clang_Sema_PrintStats(CXSema S) { static_cast<clang::Sema *>(S)->PrintStats(); }

void clang_Sema_RestoreNestedNameSpecifierAnnotation(
    CXSema S, void *Annotation, CXSourceLocation_ AnnotationRange_begin,
    CXSourceLocation_ AnnotationRange_end, CXCXXScopeSpec SS) {
  static_cast<clang::Sema *>(S)->RestoreNestedNameSpecifierAnnotation(
      Annotation,
      clang::SourceRange(clang::SourceLocation::getFromPtrEncoding(AnnotationRange_begin),
                         clang::SourceLocation::getFromPtrEncoding(AnnotationRange_end)),
      *static_cast<clang::CXXScopeSpec *>(SS));
}

bool clang_Sema_LookupParsedName(CXSema S, CXLookupResult R, CXScope Sp, CXCXXScopeSpec SS,
                                 bool AllowBuiltinCreation, bool EnteringContext) {
  return static_cast<clang::Sema *>(S)->LookupParsedName(
      *static_cast<clang::LookupResult *>(R), static_cast<clang::Scope *>(Sp),
      static_cast<clang::CXXScopeSpec *>(SS), AllowBuiltinCreation, EnteringContext);
}

bool clang_Sema_LookupName(CXSema S, CXLookupResult R, CXScope Sp,
                           bool AllowBuiltinCreation) {
  return static_cast<clang::Sema *>(S)->LookupName(*static_cast<clang::LookupResult *>(R),
                                                   static_cast<clang::Scope *>(Sp),
                                                   AllowBuiltinCreation);
}

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

void clang_CXXScopeSpec_dispose(CXCXXScopeSpec SS) {
  delete static_cast<clang::CXXScopeSpec *>(SS);
}

void clang_CXXScopeSpec_clear(CXCXXScopeSpec SS) {
  static_cast<clang::CXXScopeSpec *>(SS)->clear();
}

CXNestedNameSpecifier clang_CXXScopeSpec_getScopeRep(CXCXXScopeSpec SS) {
  return static_cast<clang::CXXScopeSpec *>(SS)->getScopeRep();
}

CXSourceLocation_ clang_CXXScopeSpec_getBeginLoc(CXCXXScopeSpec SS) {
  return static_cast<clang::CXXScopeSpec *>(SS)->getBeginLoc().getPtrEncoding();
}

CXSourceLocation_ clang_CXXScopeSpec_getEndLoc(CXCXXScopeSpec SS) {
  return static_cast<clang::CXXScopeSpec *>(SS)->getEndLoc().getPtrEncoding();
}

void clang_CXXScopeSpec_setBeginLoc(CXCXXScopeSpec SS, CXSourceLocation_ Loc) {
  static_cast<clang::CXXScopeSpec *>(SS)->setBeginLoc(
      clang::SourceLocation::getFromPtrEncoding(Loc));
}

void clang_CXXScopeSpec_setEndLoc(CXCXXScopeSpec SS, CXSourceLocation_ Loc) {
  static_cast<clang::CXXScopeSpec *>(SS)->setEndLoc(
      clang::SourceLocation::getFromPtrEncoding(Loc));
}

bool clang_CXXScopeSpec_isEmpty(CXCXXScopeSpec SS) {
  return static_cast<clang::CXXScopeSpec *>(SS)->isEmpty();
}

bool clang_CXXScopeSpec_isNotEmpty(CXCXXScopeSpec SS) {
  return static_cast<clang::CXXScopeSpec *>(SS)->isNotEmpty();
}

bool clang_CXXScopeSpec_isInvalid(CXCXXScopeSpec SS) {
  return static_cast<clang::CXXScopeSpec *>(SS)->isInvalid();
}

bool clang_CXXScopeSpec_isValid(CXCXXScopeSpec SS) {
  return static_cast<clang::CXXScopeSpec *>(SS)->isValid();
}

// Scope
void clang_Scope_dump(CXScope S) { static_cast<clang::Scope *>(S)->dump(); }

CXScope clang_Scope_getParent(CXScope S) {
  return static_cast<clang::Scope *>(S)->getParent();
}

unsigned clang_Scope_getDepth(CXScope S) {
  return static_cast<clang::Scope *>(S)->getDepth();
}

// Lookup
CXLookupResult clang_LookupResult_create(CXSema S, CXDeclarationName Name,
                                         CXSourceLocation_ NameLoc,
                                         CXLookupNameKind LookupKind,
                                         CXInit_Error *ErrorCode) {
  CXInit_Error Err = CXInit_NoError;
  std::unique_ptr<clang::LookupResult> ptr = std::make_unique<clang::LookupResult>(
      *static_cast<clang::Sema *>(S), clang::DeclarationName::getFromOpaquePtr(Name),
      clang::SourceLocation::getFromPtrEncoding(NameLoc),
      static_cast<clang::Sema::LookupNameKind>(LookupKind));

  if (!ptr) {
    fprintf(stderr, "LIBCLANGEX ERROR: failed to create `clang::LookupResult`\n");
    Err = CXInit_CanNotCreate;
  }

  if (ErrorCode)
    *ErrorCode = Err;

  return ptr.release();
}

void clang_LookupResult_dispose(CXLookupResult LR) {
  delete static_cast<clang::LookupResult *>(LR);
}

void clang_LookupResult_clear(CXLookupResult LR, CXLookupNameKind LookupKind) {
  static_cast<clang::LookupResult *>(LR)->clear(
      static_cast<clang::Sema::LookupNameKind>(LookupKind));
}

void clang_LookupResult_setLookupName(CXLookupResult LR, CXDeclarationName DN) {
  static_cast<clang::LookupResult *>(LR)->setLookupName(
      clang::DeclarationName::getFromOpaquePtr(DN));
}

CXDeclarationName clang_LookupResult_getLookupName(CXLookupResult LR) {
  return static_cast<clang::LookupResult *>(LR)->getLookupName().getAsOpaquePtr();
}

void clang_LookupResult_dump(CXLookupResult LR) {
  static_cast<clang::LookupResult *>(LR)->dump();
}

bool clang_LookupResult_empty(CXLookupResult LR) {
  return static_cast<clang::LookupResult *>(LR)->empty();
}

CXNamedDecl clang_LookupResult_getRepresentativeDecl(CXLookupResult LR) {
  return static_cast<clang::LookupResult *>(LR)->getRepresentativeDecl();
}
