#include "clang-ex/CXASTContext.h"
#include "clang/AST/ASTContext.h"
#include "clang/AST/DeclGroup.h"
#include "clang/AST/NestedNameSpecifier.h"
#include "clang/AST/Stmt.h"

void clang_ASTContext_PrintStats(CXASTContext Ctx) {
  static_cast<clang::ASTContext *>(Ctx)->PrintStats();
}

CXQualType clang_ASTContext_getPointerType(CXASTContext Ctx, CXQualType OpaquePtr) {
  return static_cast<clang::ASTContext *>(Ctx)
      ->getPointerType(clang::QualType::getFromOpaquePtr(OpaquePtr))
      .getAsOpaquePtr();
}

CXIdentifierTable clang_ASTContext_getIdents(CXASTContext Ctx) {
  return &static_cast<clang::ASTContext *>(Ctx)->Idents;
}

// IdentifierTable
void clang_IdentifierTable_PrintStats(CXIdentifierTable IT) {
  static_cast<clang::IdentifierTable *>(IT)->PrintStats();
}

CXIdentifierInfo clang_IdentifierTable_get(CXIdentifierTable Idents, const char *Name) {
  return &static_cast<clang::IdentifierTable *>(Idents)->get(llvm::StringRef(Name));
}

// DeclarationName
CXDeclarationName clang_DeclarationName_createFromIdentifierInfo(CXIdentifierInfo IDInfo) {
  return clang::DeclarationName(static_cast<clang::IdentifierInfo *>(IDInfo))
      .getAsOpaquePtr();
}

void clang_DeclarationName_dump(CXDeclarationName DN) {
  clang::DeclarationName::getFromOpaquePtr(DN).dump();
}

bool clang_DeclarationName_isEmpty(CXDeclarationName DN) {
  return clang::DeclarationName::getFromOpaquePtr(DN).isEmpty();
}

char *clang_DeclarationName_getAsString(CXDeclarationName DN) {
  auto str = clang::DeclarationName::getFromOpaquePtr(DN).getAsString();
  std::unique_ptr<char[]> ptr = std::make_unique<char[]>(str.size() + 1);
  ptr[str.size() + 1] = '\0';
  std::copy(str.begin(), str.end(), ptr.get());
  return ptr.release();
}

void clang_DeclarationName_disposeString(char *Str) { delete[] Str; }

// NestedNameSpecifier
CXNestedNameSpecifier clang_NestedNameSpecifier_getPrefix(CXNestedNameSpecifier NNS) {
  return static_cast<clang::NestedNameSpecifier *>(NNS)->getPrefix();
}

bool clang_NestedNameSpecifier_containsErrors(CXNestedNameSpecifier NNS) {
  return static_cast<clang::NestedNameSpecifier *>(NNS)->containsErrors();
}

void clang_NestedNameSpecifier_dump(CXNestedNameSpecifier NNS) {
  static_cast<clang::NestedNameSpecifier *>(NNS)->dump();
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
