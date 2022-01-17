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

// VarDecl

// getSourceRange

CXStorageClass clang_VarDecl_getStorageClass(CXVarDecl VD) {
  return static_cast<CXStorageClass>(static_cast<clang::VarDecl *>(VD)->getStorageClass());
}

void clang_VarDecl_setStorageClass(CXVarDecl VD, CXStorageClass SC) {
  static_cast<clang::VarDecl *>(VD)->setStorageClass(static_cast<clang::StorageClass>(SC));
}

void clang_VarDecl_setTSCSpec(CXVarDecl VD, CXThreadStorageClassSpecifier TSC) {
  static_cast<clang::VarDecl *>(VD)->setTSCSpec(
      static_cast<clang::ThreadStorageClassSpecifier>(TSC));
}

CXThreadStorageClassSpecifier clang_VarDecl_getTSCSpec(CXVarDecl VD) {
  return static_cast<CXThreadStorageClassSpecifier>(
      static_cast<clang::VarDecl *>(VD)->getTSCSpec());
}

// getTLSKind

bool clang_VarDecl_hasLocalStorage(CXVarDecl VD) {
  return static_cast<clang::VarDecl *>(VD)->hasLocalStorage();
}

bool clang_VarDecl_isStaticLocal(CXVarDecl VD) {
  return static_cast<clang::VarDecl *>(VD)->isStaticLocal();
}

bool clang_VarDecl_hasExternalStorage(CXVarDecl VD) {
  return static_cast<clang::VarDecl *>(VD)->hasExternalStorage();
}

bool clang_VarDecl_hasGlobalStorage(CXVarDecl VD) {
  return static_cast<clang::VarDecl *>(VD)->hasGlobalStorage();
}

CXStorageDuration clang_VarDecl_getStorageDuration(CXVarDecl VD) {
  return static_cast<CXStorageDuration>(
      static_cast<clang::VarDecl *>(VD)->getStorageDuration());
}

CXLanguageLinkage clang_VarDecl_getLanguageLinkage(CXVarDecl VD) {
  return static_cast<CXLanguageLinkage>(
      static_cast<clang::VarDecl *>(VD)->getLanguageLinkage());
}

bool clang_VarDecl_isExternC(CXVarDecl VD) {
  return static_cast<clang::VarDecl *>(VD)->isExternC();
}

bool clang_VarDecl_isInExternCContext(CXVarDecl VD) {
  return static_cast<clang::VarDecl *>(VD)->isInExternCContext();
}

bool clang_VarDecl_isInExternCXXContext(CXVarDecl VD) {
  return static_cast<clang::VarDecl *>(VD)->isInExternCXXContext();
}

bool clang_VarDecl_isLocalVarDecl(CXVarDecl VD) {
  return static_cast<clang::VarDecl *>(VD)->isLocalVarDecl();
}

bool clang_VarDecl_isLocalVarDeclOrParm(CXVarDecl VD) {
  return static_cast<clang::VarDecl *>(VD)->isLocalVarDeclOrParm();
}

bool clang_VarDecl_isFunctionOrMethodVarDecl(CXVarDecl VD) {
  return static_cast<clang::VarDecl *>(VD)->isFunctionOrMethodVarDecl();
}

bool clang_VarDecl_isStaticDataMember(CXVarDecl VD) {
  return static_cast<clang::VarDecl *>(VD)->isStaticDataMember();
}

CXVarDecl clang_VarDecl_getCanonicalDecl(CXVarDecl VD) {
  return static_cast<clang::VarDecl *>(VD)->getCanonicalDecl();
}

// isThisDeclarationADefinition
// hasDefinition

CXVarDecl clang_VarDecl_getActingDefinition(CXVarDecl VD) {
  return static_cast<clang::VarDecl *>(VD)->getActingDefinition();
}

CXVarDecl clang_VarDecl_getDefinition(CXVarDecl VD) {
  return static_cast<clang::VarDecl *>(VD)->getDefinition();
}

bool clang_VarDecl_isOutOfLine(CXVarDecl VD) {
  return static_cast<clang::VarDecl *>(VD)->isOutOfLine();
}

bool clang_VarDecl_isFileVarDecl(CXVarDecl VD) {
  return static_cast<clang::VarDecl *>(VD)->isFileVarDecl();
}

CXExpr clang_VarDecl_getAnyInitializer(CXVarDecl VD) {
  return const_cast<clang::Expr *>(static_cast<clang::VarDecl *>(VD)->getAnyInitializer());
}

bool clang_VarDecl_hasInit(CXVarDecl VD) {
  return static_cast<clang::VarDecl *>(VD)->hasInit();
}

CXExpr clang_VarDecl_getInit(CXVarDecl VD) {
  return static_cast<clang::VarDecl *>(VD)->getInit();
}

// getInitAddress

void clang_VarDecl_setInit(CXVarDecl VD, CXExpr I) {
  static_cast<clang::VarDecl *>(VD)->setInit(static_cast<clang::Expr *>(I));
}

CXVarDecl clang_VarDecl_getInitializingDeclaration(CXVarDecl VD) {
  return static_cast<clang::VarDecl *>(VD)->getInitializingDeclaration();
}

bool clang_VarDecl_mightBeUsableInConstantExpressions(CXVarDecl VD, CXASTContext C) {
  return static_cast<clang::VarDecl *>(VD)->mightBeUsableInConstantExpressions(
      *static_cast<clang::ASTContext *>(C));
}

bool clang_VarDecl_isUsableInConstantExpressions(CXVarDecl VD, CXASTContext C) {
  return static_cast<clang::VarDecl *>(VD)->isUsableInConstantExpressions(
      *static_cast<clang::ASTContext *>(C));
}

CXEvaluatedStmt clang_VarDecl_ensureEvaluatedStmt(CXVarDecl VD) {
  return static_cast<clang::VarDecl *>(VD)->ensureEvaluatedStmt();
}

CXEvaluatedStmt clang_VarDecl_getEvaluatedStmt(CXVarDecl VD) {
  return static_cast<clang::VarDecl *>(VD)->getEvaluatedStmt();
}

// evaluateValue
// getEvaluatedValue
// evaluateDestruction

bool clang_VarDecl_hasConstantInitialization(CXVarDecl VD) {
  return static_cast<clang::VarDecl *>(VD)->hasConstantInitialization();
}

bool clang_VarDecl_hasICEInitializer(CXVarDecl VD, CXASTContext Context) {
  return static_cast<clang::VarDecl *>(VD)->hasICEInitializer(
      *static_cast<clang::ASTContext *>(Context));
}

// checkForConstantInitialization
// setInitStyle
// getInitStyle

bool clang_VarDecl_isDirectInit(CXVarDecl VD) {
  return static_cast<clang::VarDecl *>(VD)->isDirectInit();
}

bool clang_VarDecl_isThisDeclarationADemotedDefinition(CXVarDecl VD) {
  return static_cast<clang::VarDecl *>(VD)->isThisDeclarationADemotedDefinition();
}

void clang_VarDecl_demoteThisDefinitionToDeclaration(CXVarDecl VD) {
  static_cast<clang::VarDecl *>(VD)->demoteThisDefinitionToDeclaration();
}

bool clang_VarDecl_isExceptionVariable(CXVarDecl VD) {
  return static_cast<clang::VarDecl *>(VD)->isExceptionVariable();
}

void clang_VarDecl_setExceptionVariable(CXVarDecl VD, bool EV) {
  static_cast<clang::VarDecl *>(VD)->setExceptionVariable(EV);
}

bool clang_VarDecl_isNRVOVariable(CXVarDecl VD) {
  return static_cast<clang::VarDecl *>(VD)->isNRVOVariable();
}

void clang_VarDecl_setNRVOVariable(CXVarDecl VD, bool NRVO) {
  static_cast<clang::VarDecl *>(VD)->setNRVOVariable(NRVO);
}

bool clang_VarDecl_isCXXForRangeDecl(CXVarDecl VD) {
  return static_cast<clang::VarDecl *>(VD)->isCXXForRangeDecl();
}

void clang_VarDecl_setCXXForRangeDecl(CXVarDecl VD, bool FRD) {
  static_cast<clang::VarDecl *>(VD)->setCXXForRangeDecl(FRD);
}

bool clang_VarDecl_isObjCForDecl(CXVarDecl VD) {
  return static_cast<clang::VarDecl *>(VD)->isObjCForDecl();
}

void clang_VarDecl_setObjCForDecl(CXVarDecl VD, bool FRD) {
  static_cast<clang::VarDecl *>(VD)->setObjCForDecl(FRD);
}

bool clang_VarDecl_isARCPseudoStrong(CXVarDecl VD) {
  return static_cast<clang::VarDecl *>(VD)->isARCPseudoStrong();
}

void clang_VarDecl_setARCPseudoStrong(CXVarDecl VD, bool PS) {
  static_cast<clang::VarDecl *>(VD)->setARCPseudoStrong(PS);
}

bool clang_VarDecl_isInline(CXVarDecl VD) {
  return static_cast<clang::VarDecl *>(VD)->isInline();
}

bool clang_VarDecl_isInlineSpecified(CXVarDecl VD) {
  return static_cast<clang::VarDecl *>(VD)->isInlineSpecified();
}

void clang_VarDecl_setInlineSpecified(CXVarDecl VD) {
  static_cast<clang::VarDecl *>(VD)->setInlineSpecified();
}

void clang_VarDecl_setImplicitlyInline(CXVarDecl VD) {
  static_cast<clang::VarDecl *>(VD)->setImplicitlyInline();
}

bool clang_VarDecl_isConstexpr(CXVarDecl VD) {
  return static_cast<clang::VarDecl *>(VD)->isConstexpr();
}

void clang_VarDecl_setConstexpr(CXVarDecl VD, bool IC) {
  static_cast<clang::VarDecl *>(VD)->setConstexpr(IC);
}

bool clang_VarDecl_isInitCapture(CXVarDecl VD) {
  return static_cast<clang::VarDecl *>(VD)->isInitCapture();
}

void clang_VarDecl_setInitCapture(CXVarDecl VD, bool IC) {
  static_cast<clang::VarDecl *>(VD)->setInitCapture(IC);
}

bool clang_VarDecl_isParameterPack(CXVarDecl VD) {
  return static_cast<clang::VarDecl *>(VD)->isParameterPack();
}

bool clang_VarDecl_isPreviousDeclInSameBlockScope(CXVarDecl VD) {
  return static_cast<clang::VarDecl *>(VD)->isPreviousDeclInSameBlockScope();
}

void clang_VarDecl_setPreviousDeclInSameBlockScope(CXVarDecl VD, bool Same) {
  static_cast<clang::VarDecl *>(VD)->setPreviousDeclInSameBlockScope(Same);
}

bool clang_VarDecl_isEscapingByref(CXVarDecl VD) {
  return static_cast<clang::VarDecl *>(VD)->isEscapingByref();
}

bool clang_VarDecl_isNonEscapingByref(CXVarDecl VD) {
  return static_cast<clang::VarDecl *>(VD)->isNonEscapingByref();
}

void clang_VarDecl_setEscapingByref(CXVarDecl VD) {
  static_cast<clang::VarDecl *>(VD)->setEscapingByref();
}

CXVarDecl clang_VarDecl_getTemplateInstantiationPattern(CXVarDecl VD) {
  return static_cast<clang::VarDecl *>(VD)->getTemplateInstantiationPattern();
}

CXVarDecl clang_VarDecl_getInstantiatedFromStaticDataMember(CXVarDecl VD) {
  return static_cast<clang::VarDecl *>(VD)->getInstantiatedFromStaticDataMember();
}

CXTemplateSpecializationKind clang_VarDecl_getTemplateSpecializationKind(CXVarDecl VD) {
  return static_cast<CXTemplateSpecializationKind>(
      static_cast<clang::VarDecl *>(VD)->getTemplateSpecializationKind());
}

CXTemplateSpecializationKind
clang_VarDecl_getTemplateSpecializationKindForInstantiation(CXVarDecl VD) {
  return static_cast<CXTemplateSpecializationKind>(
      static_cast<clang::VarDecl *>(VD)->getTemplateSpecializationKindForInstantiation());
}

CXSourceLocation_ clang_VarDecl_getPointOfInstantiation(CXVarDecl VD) {
  return static_cast<clang::VarDecl *>(VD)->getPointOfInstantiation().getPtrEncoding();
}

// getMemberSpecializationInfo

void clang_VarDecl_setTemplateSpecializationKind(CXVarDecl VD,
                                                 CXTemplateSpecializationKind TSK,
                                                 CXSourceLocation_ PointOfInstantiation) {
  static_cast<clang::VarDecl *>(VD)->setTemplateSpecializationKind(
      static_cast<clang::TemplateSpecializationKind>(TSK),
      clang::SourceLocation::getFromPtrEncoding(PointOfInstantiation));
}

void clang_VarDecl_setInstantiationOfStaticDataMember(CXVarDecl VD, CXVarDecl VD2,
                                                      CXTemplateSpecializationKind TSK) {
  static_cast<clang::VarDecl *>(VD)->setInstantiationOfStaticDataMember(
      static_cast<clang::VarDecl *>(VD2),
      static_cast<clang::TemplateSpecializationKind>(TSK));
}

CXVarTemplateDecl clang_VarDecl_getDescribedVarTemplate(CXVarDecl VD) {
  return static_cast<clang::VarDecl *>(VD)->getDescribedVarTemplate();
}

void clang_VarDecl_setDescribedVarTemplate(CXVarDecl VD, CXVarTemplateDecl Template) {
  static_cast<clang::VarDecl *>(VD)->setDescribedVarTemplate(
      static_cast<clang::VarTemplateDecl *>(Template));
}

bool clang_VarDecl_isKnownToBeDefined(CXVarDecl VD) {
  return static_cast<clang::VarDecl *>(VD)->isKnownToBeDefined();
}

bool clang_VarDecl_isNoDestroy(CXVarDecl VD, CXASTContext AST) {
  return static_cast<clang::VarDecl *>(VD)->isNoDestroy(
      *static_cast<clang::ASTContext *>(AST));
}

// needsDestruction

// ImplicitParamDecl
CXImplicitParamDecl_ImplicitParamKind
clang_VarDecl_getParameterKind(CXImplicitParamDecl IPD) {
  return static_cast<CXImplicitParamDecl_ImplicitParamKind>(
      static_cast<clang::ImplicitParamDecl *>(IPD)->getParameterKind());
}

// ParmVarDecl
void clang_ParmVarDecl_setObjCMethodScopeInfo(CXParmVarDecl PVD, unsigned parameterIndex) {
  static_cast<clang::ParmVarDecl *>(PVD)->setObjCMethodScopeInfo(parameterIndex);
}

void clang_ParmVarDecl_setScopeInfo(CXParmVarDecl PVD, unsigned scopeDepth,
                                    unsigned parameterIndex) {
  static_cast<clang::ParmVarDecl *>(PVD)->setScopeInfo(scopeDepth, parameterIndex);
}

bool clang_ParmVarDecl_isObjCMethodParameter(CXParmVarDecl PVD) {
  return static_cast<clang::ParmVarDecl *>(PVD)->isObjCMethodParameter();
}

bool clang_ParmVarDecl_isDestroyedInCallee(CXParmVarDecl PVD) {
  return static_cast<clang::ParmVarDecl *>(PVD)->isDestroyedInCallee();
}

unsigned clang_ParmVarDecl_getFunctionScopeDepth(CXParmVarDecl PVD) {
  return static_cast<clang::ParmVarDecl *>(PVD)->getFunctionScopeDepth();
}

unsigned clang_ParmVarDecl_getFunctionScopeIndex(CXParmVarDecl PVD) {
  return static_cast<clang::ParmVarDecl *>(PVD)->getFunctionScopeIndex();
}

// getObjCDeclQualifier
// setObjCDeclQualifier

bool clang_ParmVarDecl_isKNRPromoted(CXParmVarDecl PVD) {
  return static_cast<clang::ParmVarDecl *>(PVD)->isKNRPromoted();
}

void clang_ParmVarDecl_setKNRPromoted(CXParmVarDecl PVD, bool promoted) {
  static_cast<clang::ParmVarDecl *>(PVD)->setKNRPromoted(promoted);
}

CXExpr clang_ParmVarDecl_getDefaultArg(CXParmVarDecl PVD) {
  return static_cast<clang::ParmVarDecl *>(PVD)->getDefaultArg();
}

void clang_ParmVarDecl_setDefaultArg(CXParmVarDecl PVD, CXExpr defarg) {
  static_cast<clang::ParmVarDecl *>(PVD)->setDefaultArg(static_cast<clang::Expr *>(defarg));
}

// getDefaultArgRange

void clang_ParmVarDecl_setUninstantiatedDefaultArg(CXParmVarDecl PVD, CXExpr arg) {
  static_cast<clang::ParmVarDecl *>(PVD)->setUninstantiatedDefaultArg(
      static_cast<clang::Expr *>(arg));
}

CXExpr clang_ParmVarDecl_getUninstantiatedDefaultArg(CXParmVarDecl PVD) {
  return static_cast<clang::ParmVarDecl *>(PVD)->getUninstantiatedDefaultArg();
}

bool clang_ParmVarDecl_hasDefaultArg(CXParmVarDecl PVD) {
  return static_cast<clang::ParmVarDecl *>(PVD)->hasDefaultArg();
}

bool clang_ParmVarDecl_hasUnparsedDefaultArg(CXParmVarDecl PVD) {
  return static_cast<clang::ParmVarDecl *>(PVD)->hasUnparsedDefaultArg();
}

bool clang_ParmVarDecl_hasUninstantiatedDefaultArg(CXParmVarDecl PVD) {
  return static_cast<clang::ParmVarDecl *>(PVD)->hasUninstantiatedDefaultArg();
}

void clang_ParmVarDecl_setUnparsedDefaultArg(CXParmVarDecl PVD) {
  static_cast<clang::ParmVarDecl *>(PVD)->setUnparsedDefaultArg();
}

bool clang_ParmVarDecl_hasInheritedDefaultArg(CXParmVarDecl PVD) {
  return static_cast<clang::ParmVarDecl *>(PVD)->hasInheritedDefaultArg();
}

void clang_ParmVarDecl_setHasInheritedDefaultArg(CXParmVarDecl PVD, bool I) {
  static_cast<clang::ParmVarDecl *>(PVD)->setHasInheritedDefaultArg(I);
}

CXQualType clang_ParmVarDecl_getOriginalType(CXParmVarDecl PVD) {
  return static_cast<clang::ParmVarDecl *>(PVD)->getOriginalType().getAsOpaquePtr();
}

void clang_ParmVarDecl_setOwningFunction(CXParmVarDecl PVD, CXDeclContext FD) {
  static_cast<clang::ParmVarDecl *>(PVD)->setOwningFunction(
      static_cast<clang::DeclContext *>(FD));
}

// FunctionDecl

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