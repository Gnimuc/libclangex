#include "clang-ex/CXASTContext.h"
#include "clang/AST/ASTContext.h"
#include "clang/AST/DeclCXX.h"
#include "clang/AST/DeclGroup.h"
#include "clang/AST/DeclTemplate.h"
#include "clang/AST/NestedNameSpecifier.h"
#include "clang/AST/Stmt.h"
#include "clang/AST/TemplateBase.h"
#include "llvm/ExecutionEngine/GenericValue.h"
#include "llvm/Support/Casting.h"

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

uint64_t clang_ASTContext_getTypeSize(CXASTContext Ctx, CXQualType OpaquePtr) {
  return static_cast<clang::ASTContext *>(Ctx)->getTypeSize(
      clang::QualType::getFromOpaquePtr(OpaquePtr));
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

// DeclContext
CXTagDecl clang_DeclContext_castToTagDecl(CXDeclContext DC) {
  return llvm::dyn_cast<clang::TagDecl>(static_cast<clang::DeclContext *>(DC));
}

CXRecordDecl clang_DeclContext_castToRecordDecl(CXDeclContext DC) {
  return llvm::dyn_cast<clang::RecordDecl>(static_cast<clang::DeclContext *>(DC));
}

CXCXXRecordDecl clang_DeclContext_castToCXXRecordDecl(CXDeclContext DC) {
  return llvm::dyn_cast<clang::CXXRecordDecl>(static_cast<clang::DeclContext *>(DC));
}

const char *clang_DeclContext_getDeclKindName(CXDeclContext DC) {
  return static_cast<clang::DeclContext *>(DC)->getDeclKindName();
}

CXDeclContext clang_DeclContext_getParent(CXDeclContext DC) {
  return static_cast<clang::DeclContext *>(DC)->getParent();
}

CXDeclContext clang_DeclContext_getLexicalParent(CXDeclContext DC) {
  return static_cast<clang::DeclContext *>(DC)->getLexicalParent();
}

CXDeclContext clang_DeclContext_getLookupParent(CXDeclContext DC) {
  return static_cast<clang::DeclContext *>(DC)->getLookupParent();
}

CXASTContext clang_DeclContext_getParentASTContext(CXDeclContext DC) {
  return &static_cast<clang::DeclContext *>(DC)->getParentASTContext();
}

bool clang_DeclContext_isClosure(CXDeclContext DC) {
  return static_cast<clang::DeclContext *>(DC)->isClosure();
}

bool clang_DeclContext_isFunctionOrMethod(CXDeclContext DC) {
  return static_cast<clang::DeclContext *>(DC)->isFunctionOrMethod();
}

bool clang_DeclContext_isLookupContext(CXDeclContext DC) {
  return static_cast<clang::DeclContext *>(DC)->isLookupContext();
}

bool clang_DeclContext_isFileContext(CXDeclContext DC) {
  return static_cast<clang::DeclContext *>(DC)->isFileContext();
}

bool clang_DeclContext_isTranslationUnit(CXDeclContext DC) {
  return static_cast<clang::DeclContext *>(DC)->isTranslationUnit();
}

bool clang_DeclContext_isRecord(CXDeclContext DC) {
  return static_cast<clang::DeclContext *>(DC)->isRecord();
}

bool clang_DeclContext_isNamespace(CXDeclContext DC) {
  return static_cast<clang::DeclContext *>(DC)->isNamespace();
}

bool clang_DeclContext_isStdNamespace(CXDeclContext DC) {
  return static_cast<clang::DeclContext *>(DC)->isStdNamespace();
}

bool clang_DeclContext_isInlineNamespace(CXDeclContext DC) {
  return static_cast<clang::DeclContext *>(DC)->isInlineNamespace();
}

bool clang_DeclContext_isDependentContext(CXDeclContext DC) {
  return static_cast<clang::DeclContext *>(DC)->isDependentContext();
}

bool clang_DeclContext_isTransparentContext(CXDeclContext DC) {
  return static_cast<clang::DeclContext *>(DC)->isTransparentContext();
}

bool clang_DeclContext_isExternCContext(CXDeclContext DC) {
  return static_cast<clang::DeclContext *>(DC)->isExternCContext();
}

bool clang_DeclContext_isExternCXXContext(CXDeclContext DC) {
  return static_cast<clang::DeclContext *>(DC)->isExternCXXContext();
}

bool clang_DeclContext_Equals(CXDeclContext DC, CXDeclContext DC2) {
  return static_cast<clang::DeclContext *>(DC)->Equals(
      static_cast<clang::DeclContext *>(DC2));
}

CXDeclContext clang_DeclContext_getPrimaryContext(CXDeclContext DC) {
  return static_cast<clang::DeclContext *>(DC)->getPrimaryContext();
}

void clang_DeclContext_addDecl(CXDeclContext DC, CXDecl D) {
  static_cast<clang::DeclContext *>(DC)->addDecl(static_cast<clang::Decl *>(D));
}

void clang_DeclContext_addDeclInternal(CXDeclContext DC, CXDecl D) {
  static_cast<clang::DeclContext *>(DC)->addDeclInternal(static_cast<clang::Decl *>(D));
}

void clang_DeclContext_addHiddenDecl(CXDeclContext DC, CXDecl D) {
  static_cast<clang::DeclContext *>(DC)->addHiddenDecl(static_cast<clang::Decl *>(D));
}

void clang_DeclContext_removeDecl(CXDeclContext DC, CXDecl D) {
  static_cast<clang::DeclContext *>(DC)->removeDecl(static_cast<clang::Decl *>(D));
}

void clang_DeclContext_containsDecl(CXDeclContext DC, CXDecl D) {
  static_cast<clang::DeclContext *>(DC)->containsDecl(static_cast<clang::Decl *>(D));
}

void clang_DeclContext_dumpDeclContext(CXDeclContext DC) {
  static_cast<clang::DeclContext *>(DC)->dumpDeclContext();
}

void clang_DeclContext_dumpLookups(CXDeclContext DC) {
  static_cast<clang::DeclContext *>(DC)->dumpLookups();
}

// Decl
CXSourceLocation_ clang_Decl_getLocation(CXDecl DC) {
  return static_cast<clang::Decl *>(DC)->getLocation().getPtrEncoding();
}

CXSourceLocation_ clang_Decl_getBeginLoc(CXDecl DC) {
  return static_cast<clang::Decl *>(DC)->getBeginLoc().getPtrEncoding();
}

CXSourceLocation_ clang_Decl_getEndLoc(CXDecl DC) {
  return static_cast<clang::Decl *>(DC)->getEndLoc().getPtrEncoding();
}

const char *clang_Decl_getDeclKindName(CXDecl DC) {
  return static_cast<clang::Decl *>(DC)->getDeclKindName();
}

CXDecl clang_Decl_getNextDeclInContext(CXDecl DC) {
  return static_cast<clang::Decl *>(DC)->getNextDeclInContext();
}

CXDeclContext clang_Decl_getDeclContext(CXDecl DC) {
  return static_cast<clang::Decl *>(DC)->getDeclContext();
}

CXDecl clang_Decl_getNonClosureContext(CXDecl DC) {
  return static_cast<clang::Decl *>(DC)->getNonClosureContext();
}

CXTranslationUnitDecl clang_Decl_getTranslationUnitDecl(CXDecl DC) {
  return static_cast<clang::Decl *>(DC)->getTranslationUnitDecl();
}

bool clang_Decl_isInAnonymousNamespace(CXDecl DC) {
  return static_cast<clang::Decl *>(DC)->isInAnonymousNamespace();
}

bool clang_Decl_isInStdNamespace(CXDecl DC) {
  return static_cast<clang::Decl *>(DC)->isInStdNamespace();
}

CXASTContext clang_Decl_getASTContext(CXDecl DC) {
  return &static_cast<clang::Decl *>(DC)->getASTContext();
}

CXLangOptions clang_Decl_getLangOpts(CXDecl DC) {
  return const_cast<clang::LangOptions *>(&static_cast<clang::Decl *>(DC)->getLangOpts());
}

CXDeclContext clang_Decl_getLexicalDeclContext(CXDecl DC) {
  return static_cast<clang::Decl *>(DC)->getLexicalDeclContext();
}

bool clang_Decl_isTemplated(CXDecl DC) {
  return static_cast<clang::Decl *>(DC)->isTemplated();
}

bool clang_Decl_isCanonicalDecl(CXDecl DC) {
  return static_cast<clang::Decl *>(DC)->isCanonicalDecl();
}

CXDecl clang_Decl_getPreviousDecl(CXDecl DC) {
  return static_cast<clang::Decl *>(DC)->getPreviousDecl();
}

bool clang_Decl_isFirstDecl(CXDecl DC) {
  return static_cast<clang::Decl *>(DC)->isFirstDecl();
}

CXDecl clang_Decl_getMostRecentDecl(CXDecl DC) {
  return static_cast<clang::Decl *>(DC)->getMostRecentDecl();
}

bool clang_Decl_isTemplateParameter(CXDecl DC) {
  return static_cast<clang::Decl *>(DC)->isTemplateParameter();
}

bool clang_Decl_isTemplateDecl(CXDecl DC) {
  return static_cast<clang::Decl *>(DC)->isTemplateDecl();
}

CXTemplateDecl clang_Decl_getDescribedTemplate(CXDecl DC) {
  return static_cast<clang::Decl *>(DC)->getDescribedTemplate();
}

CXTemplateParameterList clang_Decl_getDescribedTemplateParams(CXDecl DC) {
  return const_cast<clang::TemplateParameterList *>(
      static_cast<clang::Decl *>(DC)->getDescribedTemplateParams());
}

void clang_Decl_EnableStatistics(void) { clang::Decl::EnableStatistics(); }

void clang_Stmt_EnableStatistics(void) { clang::Stmt::EnableStatistics(); }

void clang_Decl_PrintStats(void) { clang::Decl::PrintStats(); }

void clang_Stmt_PrintStats(void) { clang::Stmt::PrintStats(); }

void clang_Decl_dumpColor(CXDecl DC) { static_cast<clang::Decl *>(DC)->dumpColor(); }

// Decl Cast
CXClassTemplateDecl clang_Decl_castToClassTemplateDecl(CXDecl DC) {
  return llvm::dyn_cast<clang::ClassTemplateDecl>(static_cast<clang::Decl *>(DC));
}

CXValueDecl clang_Decl_castToValueDecl(CXDecl DC) {
  return llvm::dyn_cast<clang::ValueDecl>(static_cast<clang::Decl *>(DC));
}

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

// ValueDecl
CXQualType clang_ValueDecl_getType(CXValueDecl VD) {
  return static_cast<clang::ValueDecl *>(VD)->getType().getAsOpaquePtr();
}

void clang_ValueDecl_setType(CXValueDecl VD, CXQualType OpaquePtr) {
  static_cast<clang::ValueDecl *>(VD)->setType(
      clang::QualType::getFromOpaquePtr(OpaquePtr));
}

bool clang_ValueDecl_isWeak(CXValueDecl VD) {
  return static_cast<clang::ValueDecl *>(VD)->isWeak();
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

// TypedefNameDecl
CXQualType clang_TypedefNameDecl_getUnderlyingType(CXTypedefNameDecl TND) {
  return static_cast<clang::TypedefNameDecl *>(TND)->getUnderlyingType().getAsOpaquePtr();
}

CXTypedefNameDecl clang_TypedefNameDecl_getCanonicalDecl(CXTypedefNameDecl TND) {
  return static_cast<clang::TypedefNameDecl *>(TND)->getCanonicalDecl();
}

CXTagDecl clang_TypedefNameDecl_getAnonDeclWithTypedefName(CXTypedefNameDecl TND,
                                                           bool AnyRedecl) {
  return static_cast<clang::TypedefNameDecl *>(TND)->getAnonDeclWithTypedefName(AnyRedecl);
}

bool clang_TypedefNameDecl_isTransparentTag(CXTypedefNameDecl TND) {
  return static_cast<clang::TypedefNameDecl *>(TND)->isTransparentTag();
}

// TagDecl
CXDeclContext clang_TagDecl_castToDeclContext(CXTagDecl TD) {
  return llvm::dyn_cast<clang::DeclContext>(static_cast<clang::TagDecl *>(TD));
}

CXTagDecl clang_TagDecl_getCanonicalDecl(CXTagDecl TD) {
  return static_cast<clang::TagDecl *>(TD)->getCanonicalDecl();
}

bool clang_TagDecl_isThisDeclarationADefinition(CXTagDecl TD) {
  return static_cast<clang::TagDecl *>(TD)->isThisDeclarationADefinition();
}

bool clang_TagDecl_isCompleteDefinition(CXTagDecl TD) {
  return static_cast<clang::TagDecl *>(TD)->isCompleteDefinition();
}

void clang_TagDecl_setCompleteDefinition(CXTagDecl TD, bool V) {
  static_cast<clang::TagDecl *>(TD)->setCompleteDefinition(V);
}

bool clang_TagDecl_isBeingDefined(CXTagDecl TD) {
  return static_cast<clang::TagDecl *>(TD)->isBeingDefined();
}

bool clang_TagDecl_isFreeStanding(CXTagDecl TD) {
  return static_cast<clang::TagDecl *>(TD)->isFreeStanding();
}

void clang_TagDecl_startDefinition(CXTagDecl TD) {
  static_cast<clang::TagDecl *>(TD)->startDefinition();
}

CXTagDecl clang_TagDecl_getDefinition(CXTagDecl TD) {
  return static_cast<clang::TagDecl *>(TD)->getDefinition();
}

const char *clang_TagDecl_getKindName(CXTagDecl TD) {
  return static_cast<clang::TagDecl *>(TD)->getKindName().data();
}

bool clang_TagDecl_isStruct(CXTagDecl TD) {
  return static_cast<clang::TagDecl *>(TD)->isStruct();
}

bool clang_TagDecl_isInterface(CXTagDecl TD) {
  return static_cast<clang::TagDecl *>(TD)->isInterface();
}

bool clang_TagDecl_isClass(CXTagDecl TD) {
  return static_cast<clang::TagDecl *>(TD)->isClass();
}

bool clang_TagDecl_isUnion(CXTagDecl TD) {
  return static_cast<clang::TagDecl *>(TD)->isUnion();
}

bool clang_TagDecl_isEnum(CXTagDecl TD) {
  return static_cast<clang::TagDecl *>(TD)->isEnum();
}

bool clang_TagDecl_hasNameForLinkage(CXTagDecl TD) {
  return static_cast<clang::TagDecl *>(TD)->hasNameForLinkage();
}

CXTypedefNameDecl clang_TagDecl_getTypedefNameForAnonDecl(CXTagDecl TD) {
  return static_cast<clang::TagDecl *>(TD)->getTypedefNameForAnonDecl();
}

CXNestedNameSpecifier clang_TagDecl_getQualifier(CXTagDecl TD) {
  return static_cast<clang::TagDecl *>(TD)->getQualifier();
}

unsigned clang_TagDecl_getNumTemplateParameterLists(CXTagDecl TD) {
  return static_cast<clang::TagDecl *>(TD)->getNumTemplateParameterLists();
}

CXTemplateParameterList clang_TagDecl_getTemplateParameterList(CXTagDecl TD, unsigned i) {
  return static_cast<clang::TagDecl *>(TD)->getTemplateParameterList(i);
}

// TemplateParameterList
CXNamedDecl clang_TemplateParameterList_getParam(CXTemplateParameterList TPL,
                                                 unsigned Idx) {
  return static_cast<clang::TemplateParameterList *>(TPL)->getParam(Idx);
}

unsigned clang_TemplateParameterList_size(CXTemplateParameterList TPL) {
  return static_cast<clang::TemplateParameterList *>(TPL)->size();
}

// TemplateArgument
CXTemplateArgument clang_TemplateArgument_constructFromQualType(CXQualType OpaquePtr,
                                                                bool isNullPtr) {
  std::unique_ptr<clang::TemplateArgument> ptr = std::make_unique<clang::TemplateArgument>(
      clang::QualType::getFromOpaquePtr(OpaquePtr), isNullPtr);
  return ptr.release();
}

CXTemplateArgument clang_TemplateArgument_constructFromValueDecl(CXValueDecl VD,
                                                                 CXQualType OpaquePtr) {
  std::unique_ptr<clang::TemplateArgument> ptr = std::make_unique<clang::TemplateArgument>(
      static_cast<clang::ValueDecl *>(VD), clang::QualType::getFromOpaquePtr(OpaquePtr));
  return ptr.release();
}

CXTemplateArgument clang_TemplateArgument_constructFromIntegral(CXASTContext Ctx,
                                                                LLVMGenericValueRef Val,
                                                                CXQualType OpaquePtr) {
  std::unique_ptr<clang::TemplateArgument> ptr = std::make_unique<clang::TemplateArgument>(
      *static_cast<clang::ASTContext *>(Ctx),
      llvm::APSInt(reinterpret_cast<llvm::GenericValue *>(Val)->IntVal),
      clang::QualType::getFromOpaquePtr(OpaquePtr));
  return ptr.release();
}

void clang_TemplateArgument_dispose(CXTemplateArgument TA) {
  delete static_cast<clang::TemplateArgument *>(TA);
}

bool clang_TemplateArgument_isNull(CXTemplateArgument TA) {
  return static_cast<clang::TemplateArgument *>(TA)->isNull();
}

bool clang_TemplateArgument_isDependent(CXTemplateArgument TA) {
  return static_cast<clang::TemplateArgument *>(TA)->isDependent();
}

bool clang_TemplateArgument_isInstantiationDependent(CXTemplateArgument TA) {
  return static_cast<clang::TemplateArgument *>(TA)->isInstantiationDependent();
}

CXQualType clang_TemplateArgument_getAsType(CXTemplateArgument TA) {
  return static_cast<clang::TemplateArgument *>(TA)->getAsType().getAsOpaquePtr();
}

CXValueDecl clang_TemplateArgument_getAsDecl(CXTemplateArgument TA) {
  return static_cast<clang::TemplateArgument *>(TA)->getAsDecl();
}

CXQualType clang_TemplateArgument_getParamTypeForDecl(CXTemplateArgument TA) {
  return static_cast<clang::TemplateArgument *>(TA)->getParamTypeForDecl().getAsOpaquePtr();
}

CXQualType clang_TemplateArgument_getNullPtrType(CXTemplateArgument TA) {
  return static_cast<clang::TemplateArgument *>(TA)->getNullPtrType().getAsOpaquePtr();
}

LLVMGenericValueRef clang_TemplateArgument_getAsIntegral(CXTemplateArgument TA) {
  llvm::GenericValue *GenVal = new llvm::GenericValue();
  GenVal->IntVal = static_cast<clang::TemplateArgument *>(TA)->getAsIntegral();
  return reinterpret_cast<LLVMGenericValueRef>(GenVal);
}

CXQualType clang_TemplateArgument_getIntegralType(CXTemplateArgument TA) {
  return static_cast<clang::TemplateArgument *>(TA)->getIntegralType().getAsOpaquePtr();
}

void clang_TemplateArgument_setIntegralType(CXTemplateArgument TA, CXQualType OpaquePtr) {
  return static_cast<clang::TemplateArgument *>(TA)->setIntegralType(
      clang::QualType::getFromOpaquePtr(OpaquePtr));
}

CXQualType clang_TemplateArgument_getNonTypeTemplateArgumentType(CXTemplateArgument TA) {
  return static_cast<clang::TemplateArgument *>(TA)
      ->getNonTypeTemplateArgumentType()
      .getAsOpaquePtr();
}

void clang_TemplateArgument_dump(CXTemplateArgument TA) {
  return static_cast<clang::TemplateArgument *>(TA)->dump();
}

// TemplateArgumentList
CXTemplateArgumentList clang_TemplateArgumentList_CreateCopy(CXASTContext Context,
                                                             CXTemplateArgument Args,
                                                             size_t ArgNum) {
  return clang::TemplateArgumentList::CreateCopy(
      *static_cast<clang::ASTContext *>(Context),
      llvm::makeArrayRef(static_cast<clang::TemplateArgument *>(Args), ArgNum));
}

unsigned clang_TemplateArgumentList_size(CXTemplateArgumentList TAL) {
  return static_cast<clang::TemplateArgumentList *>(TAL)->size();
}

CXTemplateArgument clang_TemplateArgumentList_data(CXTemplateArgumentList TAL) {
  return const_cast<clang::TemplateArgument *>(
      static_cast<clang::TemplateArgumentList *>(TAL)->data());
}

CXTemplateArgument clang_TemplateArgumentList_get(CXTemplateArgumentList TAL,
                                                  unsigned Idx) {
  return const_cast<clang::TemplateArgument *>(
      &static_cast<clang::TemplateArgumentList *>(TAL)->get(Idx));
}

// TemplateDecl
void clang_TemplateDecl_init(CXTemplateDecl TD, CXNamedDecl ND,
                             CXTemplateParameterList TP) {
  static_cast<clang::TemplateDecl *>(TD)->init(
      static_cast<clang::NamedDecl *>(ND), static_cast<clang::TemplateParameterList *>(ND));
}

// RedeclarableTemplateDecl
CXRedeclarableTemplateDecl
clang_RedeclarableTemplateDecl_getCanonicalDecl(CXRedeclarableTemplateDecl RTD) {
  return static_cast<clang::RedeclarableTemplateDecl *>(RTD)->getCanonicalDecl();
}

bool clang_RedeclarableTemplateDecl_isMemberSpecialization(CXRedeclarableTemplateDecl RTD) {
  return static_cast<clang::RedeclarableTemplateDecl *>(RTD)->isMemberSpecialization();
}

void clang_RedeclarableTemplateDecl_setMemberSpecialization(
    CXRedeclarableTemplateDecl RTD) {
  static_cast<clang::RedeclarableTemplateDecl *>(RTD)->setMemberSpecialization();
}

// ClassTemplateDecl
CXCXXRecordDecl clang_ClassTemplateDecl_getTemplatedDecl(CXClassTemplateDecl CTD) {
  return static_cast<clang::ClassTemplateDecl *>(CTD)->getTemplatedDecl();
}

bool clang_ClassTemplateDecl_isThisDeclarationADefinition(CXClassTemplateDecl CTD) {
  return static_cast<clang::ClassTemplateDecl *>(CTD)->isThisDeclarationADefinition();
}

CXClassTemplateSpecializationDecl
clang_ClassTemplateDecl_findSpecialization(CXClassTemplateDecl CTD,
                                           CXTemplateArgumentList TAL, void *InsertPos) {
  return static_cast<clang::ClassTemplateDecl *>(CTD)->findSpecialization(
      static_cast<clang::TemplateArgumentList *>(TAL)->asArray(), InsertPos);
}

void clang_ClassTemplateDecl_AddSpecialization(CXClassTemplateDecl CTD,
                                               CXClassTemplateSpecializationDecl CTSD,
                                               void *InsertPos) {
  return static_cast<clang::ClassTemplateDecl *>(CTD)->AddSpecialization(
      static_cast<clang::ClassTemplateSpecializationDecl *>(CTSD), InsertPos);
}

CXClassTemplateDecl clang_ClassTemplateDecl_getCanonicalDecl(CXClassTemplateDecl CTD) {
  return static_cast<clang::ClassTemplateDecl *>(CTD)->getCanonicalDecl();
}

CXClassTemplateDecl clang_ClassTemplateDecl_getPreviousDecl(CXClassTemplateDecl CTD) {
  return static_cast<clang::ClassTemplateDecl *>(CTD)->getPreviousDecl();
}

CXClassTemplateDecl clang_ClassTemplateDecl_getMostRecentDecl(CXClassTemplateDecl CTD) {
  return static_cast<clang::ClassTemplateDecl *>(CTD)->getMostRecentDecl();
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

// TemplateName

// ClassTemplateSpecializationDecl
CXTemplateArgumentList clang_ClassTemplateSpecializationDecl_getTemplateArgs(
    CXClassTemplateSpecializationDecl CTSD) {
  return const_cast<clang::TemplateArgumentList *>(
      &static_cast<clang::ClassTemplateSpecializationDecl *>(CTSD)->getTemplateArgs());
}

void clang_ClassTemplateSpecializationDecl_setTemplateArgs(
    CXClassTemplateSpecializationDecl CTSD, CXTemplateArgumentList TAL) {
  static_cast<clang::ClassTemplateSpecializationDecl *>(CTSD)->setTemplateArgs(
      static_cast<clang::TemplateArgumentList *>(TAL));
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
