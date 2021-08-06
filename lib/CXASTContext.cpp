#include "clang-ex/CXASTContext.h"
#include "clang/AST/ASTContext.h"
#include "clang/AST/DeclCXX.h"
#include "clang/AST/DeclGroup.h"
#include "clang/AST/DeclTemplate.h"
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
CXDeclarationName clang_DeclarationName_create(void) {
  return clang::DeclarationName().getAsOpaquePtr();
}

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

// DeclGroup
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

// Decl
CXSourceLocation_ clang_Decl_getLocation(CXDecl DC) {
  return static_cast<clang::Decl *>(DC)->getLocation().getPtrEncoding();
}

void clang_Decl_EnableStatistics(void) { clang::Decl::EnableStatistics(); }

void clang_Stmt_EnableStatistics(void) { clang::Stmt::EnableStatistics(); }

void clang_Decl_PrintStats(void) { clang::Decl::PrintStats(); }

void clang_Stmt_PrintStats(void) { clang::Stmt::PrintStats(); }

void clang_Decl_dumpColor(CXDecl DC) { static_cast<clang::Decl *>(DC)->dumpColor(); }

// NamedDecl
CXIdentifierInfo clang_NamedDecl_getIdentifier(CXNamedDecl ND) {
  return static_cast<clang::NamedDecl *>(ND)->getIdentifier();
}

const char *clang_NamedDecl_getName(CXNamedDecl ND) {
  return static_cast<clang::NamedDecl *>(ND)->getName().data();
}

CXDeclarationName clang_NamedDecl_getDeclName(CXNamedDecl ND) {
  return static_cast<clang::NamedDecl *>(ND)->getDeclName().getAsOpaquePtr();
}

void clang_NamedDecl_setDeclName(CXNamedDecl ND, CXDeclarationName DN) {
  return static_cast<clang::NamedDecl *>(ND)->setDeclName(
      clang::DeclarationName::getFromOpaquePtr(DN));
}

bool clang_NamedDecl_hasLinkage(CXNamedDecl ND) {
  return static_cast<clang::NamedDecl *>(ND)->hasLinkage();
}

bool clang_NamedDecl_isCXXClassMember(CXNamedDecl ND) {
  return static_cast<clang::NamedDecl *>(ND)->isCXXClassMember();
}

bool clang_NamedDecl_isCXXInstanceMember(CXNamedDecl ND) {
  return static_cast<clang::NamedDecl *>(ND)->isCXXInstanceMember();
}

bool clang_NamedDecl_hasExternalFormalLinkage(CXNamedDecl ND) {
  return static_cast<clang::NamedDecl *>(ND)->hasExternalFormalLinkage();
}

bool clang_NamedDecl_isExternallyVisible(CXNamedDecl ND) {
  return static_cast<clang::NamedDecl *>(ND)->isExternallyVisible();
}

bool clang_NamedDecl_isExternallyDeclarable(CXNamedDecl ND) {
  return static_cast<clang::NamedDecl *>(ND)->isExternallyDeclarable();
}

CXNamedDecl clang_NamedDecl_getUnderlyingDecl(CXNamedDecl ND) {
  return static_cast<clang::NamedDecl *>(ND)->getUnderlyingDecl();
}

CXNamedDecl clang_NamedDecl_getMostRecentDecl(CXNamedDecl ND) {
  return static_cast<clang::NamedDecl *>(ND)->getMostRecentDecl();
}

// TypeDecl
CXType_ clang_TypeDecl_getTypeForDecl(CXTypeDecl TD) {
  return const_cast<clang::Type *>(static_cast<clang::TypeDecl *>(TD)->getTypeForDecl());
}

void clang_TypeDecl_setTypeForDecl(CXTypeDecl TD, CXType_ Ty) {
  static_cast<clang::TypeDecl *>(TD)->setTypeForDecl(static_cast<clang::Type *>(Ty));
}

CXSourceLocation_ clang_TypeDecl_getBeginLoc(CXTypeDecl TD) {
  return static_cast<clang::TypeDecl *>(TD)->getBeginLoc().getPtrEncoding();
}

void clang_TypeDecl_setLocStart(CXTypeDecl TD, CXSourceLocation_ Loc) {
  static_cast<clang::TypeDecl *>(TD)->setLocStart(
      clang::SourceLocation::getFromPtrEncoding(Loc));
}

// TagDecl
CXTagDecl clang_TypeDecl_getCanonicalDecl(CXTagDecl TD) {
  return static_cast<clang::TagDecl *>(TD)->getCanonicalDecl();
}

bool clang_TypeDecl_isThisDeclarationADefinition(CXTagDecl TD) {
  return static_cast<clang::TagDecl *>(TD)->isThisDeclarationADefinition();
}

bool clang_TypeDecl_isCompleteDefinition(CXTagDecl TD) {
  return static_cast<clang::TagDecl *>(TD)->isCompleteDefinition();
}

void clang_TypeDecl_setCompleteDefinition(CXTagDecl TD, bool V) {
  static_cast<clang::TagDecl *>(TD)->setCompleteDefinition(V);
}

bool clang_TypeDecl_isBeingDefined(CXTagDecl TD) {
  return static_cast<clang::TagDecl *>(TD)->isBeingDefined();
}

bool clang_TypeDecl_isFreeStanding(CXTagDecl TD) {
  return static_cast<clang::TagDecl *>(TD)->isFreeStanding();
}

void clang_TypeDecl_startDefinition(CXTagDecl TD) {
  static_cast<clang::TagDecl *>(TD)->startDefinition();
}

CXTagDecl clang_TypeDecl_getDefinition(CXTagDecl TD) {
  return static_cast<clang::TagDecl *>(TD)->getDefinition();
}

const char *clang_TypeDecl_getKindName(CXTagDecl TD) {
  return static_cast<clang::TagDecl *>(TD)->getKindName().data();
}

bool clang_TypeDecl_isStruct(CXTagDecl TD) {
  return static_cast<clang::TagDecl *>(TD)->isStruct();
}

bool clang_TypeDecl_isInterface(CXTagDecl TD) {
  return static_cast<clang::TagDecl *>(TD)->isInterface();
}

bool clang_TypeDecl_isClass(CXTagDecl TD) {
  return static_cast<clang::TagDecl *>(TD)->isClass();
}

bool clang_TypeDecl_isUnion(CXTagDecl TD) {
  return static_cast<clang::TagDecl *>(TD)->isUnion();
}

bool clang_TypeDecl_isEnum(CXTagDecl TD) {
  return static_cast<clang::TagDecl *>(TD)->isEnum();
}

bool clang_TypeDecl_hasNameForLinkage(CXTagDecl TD) {
  return static_cast<clang::TagDecl *>(TD)->hasNameForLinkage();
}

CXNestedNameSpecifier clang_TypeDecl_getQualifier(CXTagDecl TD) {
  return static_cast<clang::TagDecl *>(TD)->getQualifier();
}

unsigned clang_TypeDecl_getNumTemplateParameterLists(CXTagDecl TD) {
  return static_cast<clang::TagDecl *>(TD)->getNumTemplateParameterLists();
}

CXTemplateParameterList clang_TypeDecl_getTemplateParameterList(CXTagDecl TD, unsigned i) {
  return static_cast<clang::TagDecl *>(TD)->getTemplateParameterList(i);
}

// TemplateParameterList
CXNamedDecl clang_TemplateParameterList_getParam(CXTagDecl TPL, unsigned Idx) {
  return static_cast<clang::TemplateParameterList *>(TPL)->getParam(Idx);
}

// RecordDecl
CXRecordDecl clang_RecordDecl_getPreviousDecl(CXRecordDecl RD) {
  return static_cast<clang::RecordDecl *>(RD)->getPreviousDecl();
}

CXRecordDecl clang_RecordDecl_getMostRecentDecl(CXRecordDecl RD) {
  return static_cast<clang::RecordDecl *>(RD)->getMostRecentDecl();
}

bool clang_RecordDecl_hasFlexibleArrayMember(CXRecordDecl RD) {
  return static_cast<clang::RecordDecl *>(RD)->hasFlexibleArrayMember();
}

bool clang_RecordDecl_isAnonymousStructOrUnion(CXRecordDecl RD) {
  return static_cast<clang::RecordDecl *>(RD)->isAnonymousStructOrUnion();
}

bool clang_RecordDecl_isInjectedClassName(CXRecordDecl RD) {
  return static_cast<clang::RecordDecl *>(RD)->isInjectedClassName();
}

bool clang_RecordDecl_isLambda(CXRecordDecl RD) {
  return static_cast<clang::RecordDecl *>(RD)->isLambda();
}

bool clang_RecordDecl_isCapturedRecord(CXRecordDecl RD) {
  return static_cast<clang::RecordDecl *>(RD)->isCapturedRecord();
}

CXRecordDecl clang_RecordDecl_getDefinition(CXRecordDecl RD) {
  return static_cast<clang::RecordDecl *>(RD)->getDefinition();
}

bool clang_RecordDecl_isOrContainsUnion(CXRecordDecl RD) {
  return static_cast<clang::RecordDecl *>(RD)->isOrContainsUnion();
}

// CXXRecordDecl
CXCXXRecordDecl clang_CXXRecordDecl_getCanonicalDecl(CXCXXRecordDecl CXXRD) {
  return static_cast<clang::CXXRecordDecl *>(CXXRD)->getCanonicalDecl();
}

CXCXXRecordDecl clang_CXXRecordDecl_getPreviousDecl(CXCXXRecordDecl CXXRD) {
  return static_cast<clang::CXXRecordDecl *>(CXXRD)->getPreviousDecl();
}

CXCXXRecordDecl clang_CXXRecordDecl_getMostRecentDecl(CXCXXRecordDecl CXXRD) {
  return static_cast<clang::CXXRecordDecl *>(CXXRD)->getMostRecentDecl();
}

CXCXXRecordDecl clang_CXXRecordDecl_getMostRecentNonInjectedDecl(CXCXXRecordDecl CXXRD) {
  return static_cast<clang::CXXRecordDecl *>(CXXRD)->getMostRecentNonInjectedDecl();
}

CXCXXRecordDecl clang_CXXRecordDecl_getDefinition(CXCXXRecordDecl CXXRD) {
  return static_cast<clang::CXXRecordDecl *>(CXXRD)->getDefinition();
}

bool clang_CXXRecordDecl_hasDefinition(CXCXXRecordDecl CXXRD) {
  return static_cast<clang::CXXRecordDecl *>(CXXRD)->hasDefinition();
}

bool clang_CXXRecordDecl_isLambda(CXCXXRecordDecl CXXRD) {
  return static_cast<clang::CXXRecordDecl *>(CXXRD)->isLambda();
}

bool clang_CXXRecordDecl_isGenericLambda(CXCXXRecordDecl CXXRD) {
  return static_cast<clang::CXXRecordDecl *>(CXXRD)->isGenericLambda();
}

CXTemplateParameterList
clang_CXXRecordDecl_getGenericLambdaTemplateParameterList(CXCXXRecordDecl CXXRD) {
  return static_cast<clang::CXXRecordDecl *>(CXXRD)
      ->getGenericLambdaTemplateParameterList();
}

bool clang_CXXRecordDecl_isAggregate(CXCXXRecordDecl CXXRD) {
  return static_cast<clang::CXXRecordDecl *>(CXXRD)->isAggregate();
}

bool clang_CXXRecordDecl_isPOD(CXCXXRecordDecl CXXRD) {
  return static_cast<clang::CXXRecordDecl *>(CXXRD)->isPOD();
}

bool clang_CXXRecordDecl_isCLike(CXCXXRecordDecl CXXRD) {
  return static_cast<clang::CXXRecordDecl *>(CXXRD)->isCLike();
}

bool clang_CXXRecordDecl_isEmpty(CXCXXRecordDecl CXXRD) {
  return static_cast<clang::CXXRecordDecl *>(CXXRD)->isEmpty();
}

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
