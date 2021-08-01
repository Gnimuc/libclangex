#include "CXASTContext.h"
#include "clang/AST/ASTContext.h"
#include "clang/AST/DeclGroup.h"
#include "clang/AST/Stmt.h"

void clang_ASTContext_PrintStats(CXASTContext Ctx) {
  static_cast<clang::ASTContext *>(Ctx)->PrintStats();
}

CXQualType clang_ASTContext_getPointerType(CXASTContext Ctx, CXQualType OpaquePtr) {
  return static_cast<clang::ASTContext *>(Ctx)
      ->getPointerType(clang::QualType::getFromOpaquePtr(OpaquePtr))
      .getAsOpaquePtr();
}

// Decls
CXTranslationUnitDecl clang_ASTContext_getTranslationUnitDecl(CXASTContext Ctx) {
  return static_cast<clang::ASTContext *>(Ctx)->getTranslationUnitDecl();
}

CXDeclGroupRef clang_DeclGroupRef_fromeDecl(CXDecl D) {
  return clang::DeclGroupRef(static_cast<clang::Decl *>(D)).getAsOpaquePtr();
}

bool clang_DeclGroupRef_isNull(CXDeclGroupRef DG) {
  return clang::DeclGroupRef::getFromOpaquePtr(DG).isNull();
}

bool clang_DeclGroupRef_isSingleDecl(CXDeclGroupRef DG) {
  return clang::DeclGroupRef::getFromOpaquePtr(DG).isSingleDecl();
}

bool clang_DeclGroupRef_isDeclGroup(CXDeclGroupRef DG) {
  return clang::DeclGroupRef::getFromOpaquePtr(DG).isDeclGroup();
}

CXDecl clang_DeclGroupRef_getSingleDecl(CXDeclGroupRef DG) {
  return clang::DeclGroupRef::getFromOpaquePtr(DG).getSingleDecl();
}

void clang_Decl_EnableStatistics(void) { clang::Decl::EnableStatistics(); }

void clang_Stmt_EnableStatistics(void) { clang::Stmt::EnableStatistics(); }

void clang_Decl_PrintStats(void) { clang::Decl::PrintStats(); }

void clang_Stmt_PrintStats(void) { clang::Stmt::PrintStats(); }

void clang_Decl_dumpColor(CXDecl DC) { static_cast<clang::Decl *>(DC)->dumpColor(); }

// Builtin Types
CXType_ clang_ASTContext_VoidTy_getTypePtrOrNull(CXASTContext Ctx) {
  return const_cast<clang::Type *>(
      static_cast<clang::ASTContext *>(Ctx)->VoidTy.getTypePtrOrNull());
}

CXType_ clang_ASTContext_BoolTy_getTypePtrOrNull(CXASTContext Ctx) {
  return const_cast<clang::Type *>(
      static_cast<clang::ASTContext *>(Ctx)->BoolTy.getTypePtrOrNull());
}

CXType_ clang_ASTContext_CharTy_getTypePtrOrNull(CXASTContext Ctx) {
  return const_cast<clang::Type *>(
      static_cast<clang::ASTContext *>(Ctx)->CharTy.getTypePtrOrNull());
}

CXType_ clang_ASTContext_WCharTy_getTypePtrOrNull(CXASTContext Ctx) {
  return const_cast<clang::Type *>(
      static_cast<clang::ASTContext *>(Ctx)->WCharTy.getTypePtrOrNull());
}

CXType_ clang_ASTContext_WideCharTy_getTypePtrOrNull(CXASTContext Ctx) {
  return const_cast<clang::Type *>(
      static_cast<clang::ASTContext *>(Ctx)->WideCharTy.getTypePtrOrNull());
}

CXType_ clang_ASTContext_WIntTy_getTypePtrOrNull(CXASTContext Ctx) {
  return const_cast<clang::Type *>(
      static_cast<clang::ASTContext *>(Ctx)->WIntTy.getTypePtrOrNull());
}

CXType_ clang_ASTContext_Char8Ty_getTypePtrOrNull(CXASTContext Ctx) {
  return const_cast<clang::Type *>(
      static_cast<clang::ASTContext *>(Ctx)->Char8Ty.getTypePtrOrNull());
}

CXType_ clang_ASTContext_Char16Ty_getTypePtrOrNull(CXASTContext Ctx) {
  return const_cast<clang::Type *>(
      static_cast<clang::ASTContext *>(Ctx)->Char16Ty.getTypePtrOrNull());
}

CXType_ clang_ASTContext_Char32Ty_getTypePtrOrNull(CXASTContext Ctx) {
  return const_cast<clang::Type *>(
      static_cast<clang::ASTContext *>(Ctx)->Char32Ty.getTypePtrOrNull());
}

CXType_ clang_ASTContext_SignedCharTy_getTypePtrOrNull(CXASTContext Ctx) {
  return const_cast<clang::Type *>(
      static_cast<clang::ASTContext *>(Ctx)->SignedCharTy.getTypePtrOrNull());
}

CXType_ clang_ASTContext_ShortTy_getTypePtrOrNull(CXASTContext Ctx) {
  return const_cast<clang::Type *>(
      static_cast<clang::ASTContext *>(Ctx)->ShortTy.getTypePtrOrNull());
}

CXType_ clang_ASTContext_IntTy_getTypePtrOrNull(CXASTContext Ctx) {
  return const_cast<clang::Type *>(
      static_cast<clang::ASTContext *>(Ctx)->IntTy.getTypePtrOrNull());
}

CXType_ clang_ASTContext_LongTy_getTypePtrOrNull(CXASTContext Ctx) {
  return const_cast<clang::Type *>(
      static_cast<clang::ASTContext *>(Ctx)->LongTy.getTypePtrOrNull());
}

CXType_ clang_ASTContext_LongLongTy_getTypePtrOrNull(CXASTContext Ctx) {
  return const_cast<clang::Type *>(
      static_cast<clang::ASTContext *>(Ctx)->LongLongTy.getTypePtrOrNull());
}

CXType_ clang_ASTContext_Int128Ty_getTypePtrOrNull(CXASTContext Ctx) {
  return const_cast<clang::Type *>(
      static_cast<clang::ASTContext *>(Ctx)->Int128Ty.getTypePtrOrNull());
}

CXType_ clang_ASTContext_UnsignedCharTy_getTypePtrOrNull(CXASTContext Ctx) {
  return const_cast<clang::Type *>(
      static_cast<clang::ASTContext *>(Ctx)->UnsignedCharTy.getTypePtrOrNull());
}

CXType_ clang_ASTContext_UnsignedShortTy_getTypePtrOrNull(CXASTContext Ctx) {
  return const_cast<clang::Type *>(
      static_cast<clang::ASTContext *>(Ctx)->UnsignedShortTy.getTypePtrOrNull());
}

CXType_ clang_ASTContext_UnsignedIntTy_getTypePtrOrNull(CXASTContext Ctx) {
  return const_cast<clang::Type *>(
      static_cast<clang::ASTContext *>(Ctx)->UnsignedIntTy.getTypePtrOrNull());
}

CXType_ clang_ASTContext_UnsignedLongTy_getTypePtrOrNull(CXASTContext Ctx) {
  return const_cast<clang::Type *>(
      static_cast<clang::ASTContext *>(Ctx)->UnsignedLongTy.getTypePtrOrNull());
}

CXType_ clang_ASTContext_UnsignedLongLongTy_getTypePtrOrNull(CXASTContext Ctx) {
  return const_cast<clang::Type *>(
      static_cast<clang::ASTContext *>(Ctx)->UnsignedLongLongTy.getTypePtrOrNull());
}

CXType_ clang_ASTContext_UnsignedInt128Ty_getTypePtrOrNull(CXASTContext Ctx) {
  return const_cast<clang::Type *>(
      static_cast<clang::ASTContext *>(Ctx)->UnsignedInt128Ty.getTypePtrOrNull());
}

CXType_ clang_ASTContext_FloatTy_getTypePtrOrNull(CXASTContext Ctx) {
  return const_cast<clang::Type *>(
      static_cast<clang::ASTContext *>(Ctx)->FloatTy.getTypePtrOrNull());
}

CXType_ clang_ASTContext_DoubleTy_getTypePtrOrNull(CXASTContext Ctx) {
  return const_cast<clang::Type *>(
      static_cast<clang::ASTContext *>(Ctx)->DoubleTy.getTypePtrOrNull());
}

CXType_ clang_ASTContext_LongDoubleTy_getTypePtrOrNull(CXASTContext Ctx) {
  return const_cast<clang::Type *>(
      static_cast<clang::ASTContext *>(Ctx)->LongDoubleTy.getTypePtrOrNull());
}

CXType_ clang_ASTContext_Float128Ty_getTypePtrOrNull(CXASTContext Ctx) {
  return const_cast<clang::Type *>(
      static_cast<clang::ASTContext *>(Ctx)->Float128Ty.getTypePtrOrNull());
}

CXType_ clang_ASTContext_HalfTy_getTypePtrOrNull(CXASTContext Ctx) {
  return const_cast<clang::Type *>(
      static_cast<clang::ASTContext *>(Ctx)->HalfTy.getTypePtrOrNull());
}

CXType_ clang_ASTContext_BFloat16Ty_getTypePtrOrNull(CXASTContext Ctx) {
  return const_cast<clang::Type *>(
      static_cast<clang::ASTContext *>(Ctx)->BFloat16Ty.getTypePtrOrNull());
}

CXType_ clang_ASTContext_Float16Ty_getTypePtrOrNull(CXASTContext Ctx) {
  return const_cast<clang::Type *>(
      static_cast<clang::ASTContext *>(Ctx)->Float16Ty.getTypePtrOrNull());
}

CXType_ clang_ASTContext_FloatComplexTy_getTypePtrOrNull(CXASTContext Ctx) {
  return const_cast<clang::Type *>(
      static_cast<clang::ASTContext *>(Ctx)->FloatComplexTy.getTypePtrOrNull());
}

CXType_ clang_ASTContext_DoubleComplexTy_getTypePtrOrNull(CXASTContext Ctx) {
  return const_cast<clang::Type *>(
      static_cast<clang::ASTContext *>(Ctx)->DoubleComplexTy.getTypePtrOrNull());
}

CXType_ clang_ASTContext_LongDoubleComplexTy_getTypePtrOrNull(CXASTContext Ctx) {
  return const_cast<clang::Type *>(
      static_cast<clang::ASTContext *>(Ctx)->LongDoubleComplexTy.getTypePtrOrNull());
}

CXType_ clang_ASTContext_Float128ComplexTy_getTypePtrOrNull(CXASTContext Ctx) {
  return const_cast<clang::Type *>(
      static_cast<clang::ASTContext *>(Ctx)->Float128ComplexTy.getTypePtrOrNull());
}

CXType_ clang_ASTContext_VoidPtrTy_getTypePtrOrNull(CXASTContext Ctx) {
  return const_cast<clang::Type *>(
      static_cast<clang::ASTContext *>(Ctx)->VoidPtrTy.getTypePtrOrNull());
}

CXType_ clang_ASTContext_NullPtrTy_getTypePtrOrNull(CXASTContext Ctx) {
  return const_cast<clang::Type *>(
      static_cast<clang::ASTContext *>(Ctx)->NullPtrTy.getTypePtrOrNull());
}
