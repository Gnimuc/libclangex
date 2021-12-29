#include "clang-ex/AST/CXDecl.h"
#include "clang/AST/Decl.h"
#include "clang/AST/DeclTemplate.h"

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

bool clang_Decl_isOutOfLine(CXDecl DC) {
  return static_cast<clang::Decl *>(DC)->isOutOfLine();
}

void clang_Decl_setDeclContext(CXDecl DC, CXDeclContext Ctx) {
  return static_cast<clang::Decl *>(DC)->setDeclContext(
      static_cast<clang::DeclContext *>(Ctx));
}

void clang_Decl_setLexicalDeclContext(CXDecl DC, CXDeclContext Ctx) {
  return static_cast<clang::Decl *>(DC)->setLexicalDeclContext(
      static_cast<clang::DeclContext *>(Ctx));
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

void clang_Decl_PrintStats(void) { clang::Decl::PrintStats(); }

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

bool clang_NamedDecl_isOutOfLine(CXNamedDecl ND) {
  return static_cast<clang::NamedDecl *>(ND)->isOutOfLine();
}

// NamedDecl Cast
CXTypeDecl clang_NamedDecl_castToTypeDecl(CXNamedDecl ND) {
  return llvm::dyn_cast<clang::TypeDecl>(static_cast<clang::NamedDecl *>(ND));
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

CXTagTypeKind clang_TagDecl_getTagKind(CXTagDecl TD) {
  return static_cast<CXTagTypeKind>(static_cast<clang::TagDecl *>(TD)->getTagKind());
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

// EnumDecl
CXEnumDecl clang_EnumDecl_getCanonicalDecl(CXEnumDecl ED) {
  return static_cast<clang::EnumDecl *>(ED)->getCanonicalDecl();
}

CXEnumDecl clang_EnumDecl_getPreviousDecl(CXEnumDecl ED) {
  return static_cast<clang::EnumDecl *>(ED)->getPreviousDecl();
}

CXEnumDecl clang_EnumDecl_getMostRecentDecl(CXEnumDecl ED) {
  return static_cast<clang::EnumDecl *>(ED)->getMostRecentDecl();
}

CXEnumDecl clang_EnumDecl_getDefinition(CXEnumDecl ED) {
  return static_cast<clang::EnumDecl *>(ED)->getDefinition();
}

CXQualType clang_EnumDecl_getIntegerType(CXEnumDecl ED) {
  return static_cast<clang::EnumDecl *>(ED)->getIntegerType().getAsOpaquePtr();
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