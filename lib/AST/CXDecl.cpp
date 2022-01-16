#include "clang-ex/AST/CXDecl.h"
#include "clang/AST/Decl.h"

// TranslationUnitDecl
CXASTContext clang_TranslationUnitDecl_getASTContext(CXTranslationUnitDecl TUD) {
  return &static_cast<clang::TranslationUnitDecl *>(TUD)->getASTContext();
}

CXNamespaceDecl clang_TranslationUnitDecl_getAnonymousNamespace(CXTranslationUnitDecl TUD) {
  return static_cast<clang::TranslationUnitDecl *>(TUD)->getAnonymousNamespace();
}

void clang_TranslationUnitDecl_setAnonymousNamespace(CXTranslationUnitDecl TUD,
                                                     CXNamespaceDecl ND) {
  static_cast<clang::TranslationUnitDecl *>(TUD)->setAnonymousNamespace(
      static_cast<clang::NamespaceDecl *>(ND));
}

// PragmaCommentDecl
CXPragmaMSCommentKind clang_PragmaCommentDecl_getCommentKind(CXPragmaCommentDecl PCD) {
  return static_cast<CXPragmaMSCommentKind>(
      static_cast<clang::PragmaCommentDecl *>(PCD)->getCommentKind());
}

const char *clang_PragmaCommentDecl_getArg(CXPragmaCommentDecl PCD) {
  return static_cast<clang::PragmaCommentDecl *>(PCD)->getArg().data();
}

// PragmaDetectMismatchDecl
const char *clang_PragmaDetectMismatchDecl_getName(CXPragmaDetectMismatchDecl PDMD) {
  return static_cast<clang::PragmaDetectMismatchDecl *>(PDMD)->getName().data();
}

const char *clang_PragmaDetectMismatchDecl_getValue(CXPragmaDetectMismatchDecl PDMD) {
  return static_cast<clang::PragmaDetectMismatchDecl *>(PDMD)->getValue().data();
}

// ExternCContextDecl

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

bool clang_NamedDecl_declarationReplaces(CXNamedDecl ND, CXNamedDecl OldD,
                                         bool IsKnownNewer) {
  return static_cast<clang::NamedDecl *>(ND)->declarationReplaces(
      static_cast<clang::NamedDecl *>(OldD), IsKnownNewer);
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

CXLinkage clang_NamedDecl_getLinkageInternal(CXNamedDecl ND) {
  return static_cast<CXLinkage>(static_cast<clang::NamedDecl *>(ND)->getLinkageInternal());
}

CXLinkage clang_NamedDecl_getFormalLinkage(CXNamedDecl ND) {
  return static_cast<CXLinkage>(static_cast<clang::NamedDecl *>(ND)->getFormalLinkage());
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

CXVisibility clang_NamedDecl_getVisibility(CXNamedDecl ND) {
  return static_cast<CXVisibility>(static_cast<clang::NamedDecl *>(ND)->getVisibility());
}

// getLinkageAndVisibility
// getExplicitVisibility

bool clang_NamedDecl_isLinkageValid(CXNamedDecl ND) {
  return static_cast<clang::NamedDecl *>(ND)->isLinkageValid();
}

bool clang_NamedDecl_hasLinkageBeenComputed(CXNamedDecl ND) {
  return static_cast<clang::NamedDecl *>(ND)->hasLinkageBeenComputed();
}

CXNamedDecl clang_NamedDecl_getUnderlyingDecl(CXNamedDecl ND) {
  return static_cast<clang::NamedDecl *>(ND)->getUnderlyingDecl();
}

CXNamedDecl clang_NamedDecl_getMostRecentDecl(CXNamedDecl ND) {
  return static_cast<clang::NamedDecl *>(ND)->getMostRecentDecl();
}

// getObjCFStringFormattingFamily

// NamedDecl Cast
CXTypeDecl clang_NamedDecl_castToTypeDecl(CXNamedDecl ND) {
  return llvm::dyn_cast<clang::TypeDecl>(static_cast<clang::NamedDecl *>(ND));
}

// LabelDecl
CXLabelStmt clang_LabelDecl_getStmt(CXLabelDecl LD) {
  return static_cast<clang::LabelDecl *>(LD)->getStmt();
}

void clang_LabelDecl_setStmt(CXLabelDecl LD, CXLabelStmt T) {
  static_cast<clang::LabelDecl *>(LD)->setStmt(static_cast<clang::LabelStmt *>(T));
}

bool clang_LabelDecl_isGnuLocal(CXLabelDecl LD) {
  return static_cast<clang::LabelDecl *>(LD)->isGnuLocal();
}

void clang_LabelDecl_setLocStart(CXLabelDecl LD, CXSourceLocation_ Loc) {
  static_cast<clang::LabelDecl *>(LD)->setLocStart(
      clang::SourceLocation::getFromPtrEncoding(Loc));
}

// getSourceRange

bool clang_LabelDecl_isMSAsmLabel(CXLabelDecl LD) {
  return static_cast<clang::LabelDecl *>(LD)->isMSAsmLabel();
}

bool clang_LabelDecl_isResolvedMSAsmLabel(CXLabelDecl LD) {
  return static_cast<clang::LabelDecl *>(LD)->isResolvedMSAsmLabel();
}

// setMSAsmLabel

const char *clang_LabelDecl_getMSAsmLabel(CXLabelDecl LD) {
  return static_cast<clang::LabelDecl *>(LD)->getMSAsmLabel().data();
}

void clang_LabelDecl_setMSAsmLabelResolved(CXLabelDecl LD) {
  static_cast<clang::LabelDecl *>(LD)->setMSAsmLabelResolved();
}

// NamespaceDecl
bool clang_NamespaceDecl_isAnonymousNamespace(CXNamespaceDecl ND) {
  return static_cast<clang::NamespaceDecl *>(ND)->isAnonymousNamespace();
}

bool clang_NamespaceDecl_isInline(CXNamespaceDecl ND) {
  return static_cast<clang::NamespaceDecl *>(ND)->isInline();
}

void clang_NamespaceDecl_setInline(CXNamespaceDecl ND, bool Inline) {
  return static_cast<clang::NamespaceDecl *>(ND)->setInline(Inline);
}

CXNamespaceDecl clang_NamespaceDecl_getOriginalNamespace(CXNamespaceDecl ND) {
  return static_cast<clang::NamespaceDecl *>(ND)->getOriginalNamespace();
}

bool clang_NamespaceDecl_isOriginalNamespace(CXNamespaceDecl ND) {
  return static_cast<clang::NamespaceDecl *>(ND)->isOriginalNamespace();
}

CXNamespaceDecl clang_NamespaceDecl_getAnonymousNamespace(CXNamespaceDecl ND) {
  return static_cast<clang::NamespaceDecl *>(ND)->getAnonymousNamespace();
}

void clang_NamespaceDecl_setAnonymousNamespace(CXNamespaceDecl ND, CXNamespaceDecl D) {
  static_cast<clang::NamespaceDecl *>(ND)->setAnonymousNamespace(
      static_cast<clang::NamespaceDecl *>(D));
}

CXNamespaceDecl clang_NamespaceDecl_getCanonicalDecl(CXNamespaceDecl ND) {
  return static_cast<clang::NamespaceDecl *>(ND)->getCanonicalDecl();
}

// getSourceRange

CXSourceLocation_ clang_NamespaceDecl_getBeginLoc(CXNamespaceDecl ND) {
  return static_cast<clang::NamespaceDecl *>(ND)->getBeginLoc().getPtrEncoding();
}

CXSourceLocation_ clang_NamespaceDecl_getRBraceLoc(CXNamespaceDecl ND) {
  return static_cast<clang::NamespaceDecl *>(ND)->getRBraceLoc().getPtrEncoding();
}

void clang_NamespaceDecl_setLocStart(CXNamespaceDecl ND, CXSourceLocation_ Loc) {
  static_cast<clang::NamespaceDecl *>(ND)->setLocStart(
      clang::SourceLocation::getFromPtrEncoding(Loc));
}

void clang_NamespaceDecl_setRBraceLoc(CXNamespaceDecl ND, CXSourceLocation_ Loc) {
  static_cast<clang::NamespaceDecl *>(ND)->setRBraceLoc(
      clang::SourceLocation::getFromPtrEncoding(Loc));
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

// DeclaratorDecl
CXTypeSourceInfo clang_DeclaratorDecl_getTypeSourceInfo(CXDeclaratorDecl DD) {
  return static_cast<clang::DeclaratorDecl *>(DD)->getTypeSourceInfo();
}

void clang_DeclaratorDecl_setTypeSourceInfo(CXDeclaratorDecl DD, CXTypeSourceInfo TI) {
  static_cast<clang::DeclaratorDecl *>(DD)->setTypeSourceInfo(
      static_cast<clang::TypeSourceInfo *>(TI));
}

CXSourceLocation_ clang_DeclaratorDecl_getInnerLocStart(CXDeclaratorDecl DD) {
  return static_cast<clang::DeclaratorDecl *>(DD)->getInnerLocStart().getPtrEncoding();
}

void clang_DeclaratorDecl_setInnerLocStart(CXDeclaratorDecl DD, CXSourceLocation_ Loc) {
  static_cast<clang::DeclaratorDecl *>(DD)->setInnerLocStart(
      clang::SourceLocation::getFromPtrEncoding(Loc));
}

CXSourceLocation_ clang_DeclaratorDecl_getOuterLocStart(CXDeclaratorDecl DD) {
  return static_cast<clang::DeclaratorDecl *>(DD)->getOuterLocStart().getPtrEncoding();
}

CXSourceLocation_ clang_DeclaratorDecl_getBeginLoc(CXDeclaratorDecl DD) {
  return static_cast<clang::DeclaratorDecl *>(DD)->getBeginLoc().getPtrEncoding();
}

CXNestedNameSpecifier clang_DeclaratorDecl_getQualifier(CXDeclaratorDecl DD) {
  return static_cast<clang::DeclaratorDecl *>(DD)->getQualifier();
}

// getQualifierLoc
// setQualifierInfo

CXExpr clang_DeclaratorDecl_getTrailingRequiresClause(CXDeclaratorDecl DD) {
  return static_cast<clang::DeclaratorDecl *>(DD)->getTrailingRequiresClause();
}

void clang_DeclaratorDecl_setTrailingRequiresClause(CXDeclaratorDecl DD,
                                                    CXExpr TrailingRequiresClause) {
  return static_cast<clang::DeclaratorDecl *>(DD)->setTrailingRequiresClause(
      static_cast<clang::Expr *>(TrailingRequiresClause));
}

unsigned clang_DeclaratorDecl_getNumTemplateParameterLists(CXDeclaratorDecl DD) {
  return static_cast<clang::DeclaratorDecl *>(DD)->getNumTemplateParameterLists();
}

CXTemplateParameterList clang_DeclaratorDecl_getTemplateParameterList(CXDeclaratorDecl DD,
                                                                      unsigned index) {
  return static_cast<clang::DeclaratorDecl *>(DD)->getTemplateParameterList(index);
}

// setTemplateParameterListsInfo

CXSourceLocation_ clang_DeclaratorDecl_getTypeSpecStartLoc(CXDeclaratorDecl DD) {
  return static_cast<clang::DeclaratorDecl *>(DD)->getTypeSpecStartLoc().getPtrEncoding();
}

CXSourceLocation_ clang_DeclaratorDecl_getTypeSpecEndLoc(CXDeclaratorDecl DD) {
  return static_cast<clang::DeclaratorDecl *>(DD)->getTypeSpecEndLoc().getPtrEncoding();
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