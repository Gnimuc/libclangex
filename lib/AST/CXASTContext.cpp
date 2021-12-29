#include "clang-ex/AST/CXASTContext.h"
#include "clang/AST/ASTContext.h"

CXTranslationUnitDecl clang_ASTContext_getTranslationUnitDecl(CXASTContext Ctx) {
  return static_cast<clang::ASTContext *>(Ctx)->getTranslationUnitDecl();
}

void clang_ASTContext_PrintStats(CXASTContext Ctx) {
  static_cast<clang::ASTContext *>(Ctx)->PrintStats();
}

CXQualType clang_ASTContext_getPointerType(CXASTContext Ctx, CXQualType OpaquePtr) {
  return static_cast<clang::ASTContext *>(Ctx)
      ->getPointerType(clang::QualType::getFromOpaquePtr(OpaquePtr))
      .getAsOpaquePtr();
}

CXQualType clang_ASTContext_getLValueReferenceType(CXASTContext Ctx, CXQualType OpaquePtr) {
  return static_cast<clang::ASTContext *>(Ctx)
      ->getLValueReferenceType(clang::QualType::getFromOpaquePtr(OpaquePtr))
      .getAsOpaquePtr();
}

CXQualType clang_ASTContext_getRValueReferenceType(CXASTContext Ctx, CXQualType OpaquePtr) {
  return static_cast<clang::ASTContext *>(Ctx)
      ->getRValueReferenceType(clang::QualType::getFromOpaquePtr(OpaquePtr))
      .getAsOpaquePtr();
}

CXQualType clang_ASTContext_getMemberPointerType(CXASTContext Ctx, CXQualType OpaquePtr,
                                                 CXType_ Cls) {
  return static_cast<clang::ASTContext *>(Ctx)
      ->getMemberPointerType(clang::QualType::getFromOpaquePtr(OpaquePtr),
                             static_cast<clang::Type *>(Cls))
      .getAsOpaquePtr();
}

CXIdentifierTable clang_ASTContext_getIdents(CXASTContext Ctx) {
  return &static_cast<clang::ASTContext *>(Ctx)->Idents;
}

uint64_t clang_ASTContext_getTypeSize(CXASTContext Ctx, CXType_ T) {
  return static_cast<clang::ASTContext *>(Ctx)->getTypeSize(static_cast<clang::Type *>(T));
}

CXQualType clang_ASTContext_getTypeDeclType(CXASTContext Ctx, CXTypeDecl Decl,
                                            CXTypeDecl PrevDecl) {
  return static_cast<clang::ASTContext *>(Ctx)
      ->getTypeDeclType(static_cast<clang::TypeDecl *>(Decl),
                        static_cast<clang::TypeDecl *>(PrevDecl))
      .getAsOpaquePtr();
}

CXQualType clang_ASTContext_getRecordType(CXASTContext Ctx, CXRecordDecl Decl) {
  return static_cast<clang::ASTContext *>(Ctx)
      ->getRecordType(static_cast<clang::RecordDecl *>(Decl))
      .getAsOpaquePtr();
}

// Builtin Types
CXQualType clang_ASTContext_VoidTy_getAsQualType(CXASTContext Ctx) {
  return static_cast<clang::ASTContext *>(Ctx)->VoidTy.getAsOpaquePtr();
}

CXQualType clang_ASTContext_BoolTy_getAsQualType(CXASTContext Ctx) {
  return static_cast<clang::ASTContext *>(Ctx)->BoolTy.getAsOpaquePtr();
}

CXQualType clang_ASTContext_CharTy_getAsQualType(CXASTContext Ctx) {
  return static_cast<clang::ASTContext *>(Ctx)->CharTy.getAsOpaquePtr();
}

CXQualType clang_ASTContext_WCharTy_getAsQualType(CXASTContext Ctx) {
  return static_cast<clang::ASTContext *>(Ctx)->WCharTy.getAsOpaquePtr();
}

CXQualType clang_ASTContext_WideCharTy_getAsQualType(CXASTContext Ctx) {
  return static_cast<clang::ASTContext *>(Ctx)->WideCharTy.getAsOpaquePtr();
}

CXQualType clang_ASTContext_WIntTy_getAsQualType(CXASTContext Ctx) {
  return static_cast<clang::ASTContext *>(Ctx)->WIntTy.getAsOpaquePtr();
}

CXQualType clang_ASTContext_Char8Ty_getAsQualType(CXASTContext Ctx) {
  return static_cast<clang::ASTContext *>(Ctx)->Char8Ty.getAsOpaquePtr();
}

CXQualType clang_ASTContext_Char16Ty_getAsQualType(CXASTContext Ctx) {
  return static_cast<clang::ASTContext *>(Ctx)->Char16Ty.getAsOpaquePtr();
}

CXQualType clang_ASTContext_Char32Ty_getAsQualType(CXASTContext Ctx) {
  return static_cast<clang::ASTContext *>(Ctx)->Char32Ty.getAsOpaquePtr();
}

CXQualType clang_ASTContext_SignedCharTy_getAsQualType(CXASTContext Ctx) {
  return static_cast<clang::ASTContext *>(Ctx)->SignedCharTy.getAsOpaquePtr();
}

CXQualType clang_ASTContext_ShortTy_getAsQualType(CXASTContext Ctx) {
  return static_cast<clang::ASTContext *>(Ctx)->ShortTy.getAsOpaquePtr();
}

CXQualType clang_ASTContext_IntTy_getAsQualType(CXASTContext Ctx) {
  return static_cast<clang::ASTContext *>(Ctx)->IntTy.getAsOpaquePtr();
}

CXQualType clang_ASTContext_LongTy_getAsQualType(CXASTContext Ctx) {
  return static_cast<clang::ASTContext *>(Ctx)->LongTy.getAsOpaquePtr();
}

CXQualType clang_ASTContext_LongLongTy_getAsQualType(CXASTContext Ctx) {
  return static_cast<clang::ASTContext *>(Ctx)->LongLongTy.getAsOpaquePtr();
}

CXQualType clang_ASTContext_Int128Ty_getAsQualType(CXASTContext Ctx) {
  return static_cast<clang::ASTContext *>(Ctx)->Int128Ty.getAsOpaquePtr();
}

CXQualType clang_ASTContext_UnsignedCharTy_getAsQualType(CXASTContext Ctx) {
  return static_cast<clang::ASTContext *>(Ctx)->UnsignedCharTy.getAsOpaquePtr();
}

CXQualType clang_ASTContext_UnsignedShortTy_getAsQualType(CXASTContext Ctx) {
  return static_cast<clang::ASTContext *>(Ctx)->UnsignedShortTy.getAsOpaquePtr();
}

CXQualType clang_ASTContext_UnsignedIntTy_getAsQualType(CXASTContext Ctx) {
  return static_cast<clang::ASTContext *>(Ctx)->UnsignedIntTy.getAsOpaquePtr();
}

CXQualType clang_ASTContext_UnsignedLongTy_getAsQualType(CXASTContext Ctx) {
  return static_cast<clang::ASTContext *>(Ctx)->UnsignedLongTy.getAsOpaquePtr();
}

CXQualType clang_ASTContext_UnsignedLongLongTy_getAsQualType(CXASTContext Ctx) {
  return static_cast<clang::ASTContext *>(Ctx)->UnsignedLongLongTy.getAsOpaquePtr();
}

CXQualType clang_ASTContext_UnsignedInt128Ty_getAsQualType(CXASTContext Ctx) {
  return static_cast<clang::ASTContext *>(Ctx)->UnsignedInt128Ty.getAsOpaquePtr();
}

CXQualType clang_ASTContext_FloatTy_getAsQualType(CXASTContext Ctx) {
  return static_cast<clang::ASTContext *>(Ctx)->FloatTy.getAsOpaquePtr();
}

CXQualType clang_ASTContext_DoubleTy_getAsQualType(CXASTContext Ctx) {
  return static_cast<clang::ASTContext *>(Ctx)->DoubleTy.getAsOpaquePtr();
}

CXQualType clang_ASTContext_LongDoubleTy_getAsQualType(CXASTContext Ctx) {
  return static_cast<clang::ASTContext *>(Ctx)->LongDoubleTy.getAsOpaquePtr();
}

CXQualType clang_ASTContext_Float128Ty_getAsQualType(CXASTContext Ctx) {
  return static_cast<clang::ASTContext *>(Ctx)->Float128Ty.getAsOpaquePtr();
}

CXQualType clang_ASTContext_HalfTy_getAsQualType(CXASTContext Ctx) {
  return static_cast<clang::ASTContext *>(Ctx)->HalfTy.getAsOpaquePtr();
}

CXQualType clang_ASTContext_BFloat16Ty_getAsQualType(CXASTContext Ctx) {
  return static_cast<clang::ASTContext *>(Ctx)->BFloat16Ty.getAsOpaquePtr();
}

CXQualType clang_ASTContext_Float16Ty_getAsQualType(CXASTContext Ctx) {
  return static_cast<clang::ASTContext *>(Ctx)->Float16Ty.getAsOpaquePtr();
}

CXQualType clang_ASTContext_FloatComplexTy_getAsQualType(CXASTContext Ctx) {
  return static_cast<clang::ASTContext *>(Ctx)->FloatComplexTy.getAsOpaquePtr();
}

CXQualType clang_ASTContext_DoubleComplexTy_getAsQualType(CXASTContext Ctx) {
  return static_cast<clang::ASTContext *>(Ctx)->DoubleComplexTy.getAsOpaquePtr();
}

CXQualType clang_ASTContext_LongDoubleComplexTy_getAsQualType(CXASTContext Ctx) {
  return static_cast<clang::ASTContext *>(Ctx)->LongDoubleComplexTy.getAsOpaquePtr();
}

CXQualType clang_ASTContext_Float128ComplexTy_getAsQualType(CXASTContext Ctx) {
  return static_cast<clang::ASTContext *>(Ctx)->Float128ComplexTy.getAsOpaquePtr();
}

CXQualType clang_ASTContext_VoidPtrTy_getAsQualType(CXASTContext Ctx) {
  return static_cast<clang::ASTContext *>(Ctx)->VoidPtrTy.getAsOpaquePtr();
}

CXQualType clang_ASTContext_NullPtrTy_getAsQualType(CXASTContext Ctx) {
  return static_cast<clang::ASTContext *>(Ctx)->NullPtrTy.getAsOpaquePtr();
}
