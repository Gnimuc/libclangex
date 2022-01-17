#ifndef LIBCLANGEX_CXDECL_H
#define LIBCLANGEX_CXDECL_H

#include "clang-ex/AST/CXType.h"
#include "clang-ex/Basic/CXLinkage.h"
#include "clang-ex/Basic/CXPragmaKinds.h"
#include "clang-ex/Basic/CXSpecifiers.h"
#include "clang-ex/Basic/CXVisibility.h"
#include "clang-ex/CXTypes.h"
#include "clang-c/Platform.h"

#ifdef __cplusplus
extern "C" {
#endif

// TranslationUnitDecl
CINDEX_LINKAGE CXASTContext
clang_TranslationUnitDecl_getASTContext(CXTranslationUnitDecl TUD);

CINDEX_LINKAGE CXNamespaceDecl
clang_TranslationUnitDecl_getAnonymousNamespace(CXTranslationUnitDecl TUD);

CINDEX_LINKAGE void
clang_TranslationUnitDecl_setAnonymousNamespace(CXTranslationUnitDecl TUD,
                                                CXNamespaceDecl ND);

// PragmaCommentDecl
CINDEX_LINKAGE CXPragmaMSCommentKind
clang_PragmaCommentDecl_getCommentKind(CXPragmaCommentDecl PCD);

CINDEX_LINKAGE const char *clang_PragmaCommentDecl_getArg(CXPragmaCommentDecl PCD);

// PragmaDetectMismatchDecl
CINDEX_LINKAGE const char *
clang_PragmaDetectMismatchDecl_getName(CXPragmaDetectMismatchDecl PDMD);

CINDEX_LINKAGE const char *
clang_PragmaDetectMismatchDecl_getValue(CXPragmaDetectMismatchDecl PDMD);

// ExternCContextDecl

// NamedDecl
CINDEX_LINKAGE CXIdentifierInfo clang_NamedDecl_getIdentifier(CXNamedDecl ND);

CINDEX_LINKAGE const char *clang_NamedDecl_getName(CXNamedDecl ND);

CINDEX_LINKAGE CXDeclarationName clang_NamedDecl_getDeclName(CXNamedDecl ND);

CINDEX_LINKAGE void clang_NamedDecl_setDeclName(CXNamedDecl ND, CXDeclarationName DN);

CINDEX_LINKAGE bool clang_NamedDecl_declarationReplaces(CXNamedDecl ND, CXNamedDecl OldD,
                                                        bool IsKnownNewer);

CINDEX_LINKAGE bool clang_NamedDecl_hasLinkage(CXNamedDecl ND);

CINDEX_LINKAGE bool clang_NamedDecl_isCXXClassMember(CXNamedDecl ND);

CINDEX_LINKAGE bool clang_NamedDecl_isCXXInstanceMember(CXNamedDecl ND);

CINDEX_LINKAGE CXLinkage clang_NamedDecl_getLinkageInternal(CXNamedDecl ND);

CINDEX_LINKAGE CXLinkage clang_NamedDecl_getFormalLinkage(CXNamedDecl ND);

CINDEX_LINKAGE bool clang_NamedDecl_hasExternalFormalLinkage(CXNamedDecl ND);

CINDEX_LINKAGE bool clang_NamedDecl_isExternallyVisible(CXNamedDecl ND);

CINDEX_LINKAGE bool clang_NamedDecl_isExternallyDeclarable(CXNamedDecl ND);

CINDEX_LINKAGE CXVisibility clang_NamedDecl_getVisibility(CXNamedDecl ND);

// getLinkageAndVisibility
// getExplicitVisibility

CINDEX_LINKAGE bool clang_NamedDecl_isLinkageValid(CXNamedDecl ND);

CINDEX_LINKAGE bool clang_NamedDecl_hasLinkageBeenComputed(CXNamedDecl ND);

CINDEX_LINKAGE CXNamedDecl clang_NamedDecl_getUnderlyingDecl(CXNamedDecl ND);

CINDEX_LINKAGE CXNamedDecl clang_NamedDecl_getMostRecentDecl(CXNamedDecl ND);

// getObjCFStringFormattingFamily

// NamedDecl Cast
CINDEX_LINKAGE CXTypeDecl clang_NamedDecl_castToTypeDecl(CXNamedDecl ND);

// LabelDecl
CINDEX_LINKAGE CXLabelStmt clang_LabelDecl_getStmt(CXLabelDecl LD);

CINDEX_LINKAGE void clang_LabelDecl_setStmt(CXLabelDecl LD, CXLabelStmt T);

CINDEX_LINKAGE bool clang_LabelDecl_isGnuLocal(CXLabelDecl LD);

CINDEX_LINKAGE void clang_LabelDecl_setLocStart(CXLabelDecl LD, CXSourceLocation_ Loc);

// getSourceRange

CINDEX_LINKAGE bool clang_LabelDecl_isMSAsmLabel(CXLabelDecl LD);

CINDEX_LINKAGE bool clang_LabelDecl_isResolvedMSAsmLabel(CXLabelDecl LD);

// setMSAsmLabel

CINDEX_LINKAGE const char *clang_LabelDecl_getMSAsmLabel(CXLabelDecl LD);

CINDEX_LINKAGE void clang_LabelDecl_setMSAsmLabelResolved(CXLabelDecl LD);

// NamespaceDecl
CINDEX_LINKAGE bool clang_NamespaceDecl_isAnonymousNamespace(CXNamespaceDecl ND);

CINDEX_LINKAGE bool clang_NamespaceDecl_isInline(CXNamespaceDecl ND);

CINDEX_LINKAGE void clang_NamespaceDecl_setInline(CXNamespaceDecl ND, bool Inline);

CINDEX_LINKAGE CXNamespaceDecl clang_NamespaceDecl_getOriginalNamespace(CXNamespaceDecl ND);

CINDEX_LINKAGE bool clang_NamespaceDecl_isOriginalNamespace(CXNamespaceDecl ND);

CINDEX_LINKAGE CXNamespaceDecl
clang_NamespaceDecl_getAnonymousNamespace(CXNamespaceDecl ND);

CINDEX_LINKAGE void clang_NamespaceDecl_setAnonymousNamespace(CXNamespaceDecl ND,
                                                              CXNamespaceDecl D);

CINDEX_LINKAGE CXNamespaceDecl clang_NamespaceDecl_getCanonicalDecl(CXNamespaceDecl ND);

// getSourceRange

CINDEX_LINKAGE CXSourceLocation_ clang_NamespaceDecl_getBeginLoc(CXNamespaceDecl ND);

CINDEX_LINKAGE CXSourceLocation_ clang_NamespaceDecl_getRBraceLoc(CXNamespaceDecl ND);

CINDEX_LINKAGE void clang_NamespaceDecl_setLocStart(CXNamespaceDecl ND,
                                                    CXSourceLocation_ Loc);

CINDEX_LINKAGE void clang_NamespaceDecl_setRBraceLoc(CXNamespaceDecl ND,
                                                     CXSourceLocation_ Loc);

// ValueDecl
CINDEX_LINKAGE CXQualType clang_ValueDecl_getType(CXValueDecl VD);

CINDEX_LINKAGE void clang_ValueDecl_setType(CXValueDecl VD, CXQualType OpaquePtr);

CINDEX_LINKAGE bool clang_ValueDecl_isWeak(CXValueDecl VD);

// DeclaratorDecl
CINDEX_LINKAGE CXTypeSourceInfo clang_DeclaratorDecl_getTypeSourceInfo(CXDeclaratorDecl DD);

CINDEX_LINKAGE void clang_DeclaratorDecl_setTypeSourceInfo(CXDeclaratorDecl DD,
                                                           CXTypeSourceInfo TI);

CINDEX_LINKAGE CXSourceLocation_ clang_DeclaratorDecl_getInnerLocStart(CXDeclaratorDecl DD);

CINDEX_LINKAGE void clang_DeclaratorDecl_setInnerLocStart(CXDeclaratorDecl DD,
                                                          CXSourceLocation_ Loc);

CINDEX_LINKAGE CXSourceLocation_ clang_DeclaratorDecl_getOuterLocStart(CXDeclaratorDecl DD);

CINDEX_LINKAGE CXSourceLocation_ clang_DeclaratorDecl_getBeginLoc(CXDeclaratorDecl DD);

CINDEX_LINKAGE CXNestedNameSpecifier clang_DeclaratorDecl_getQualifier(CXDeclaratorDecl DD);

// getQualifierLoc
// setQualifierInfo

CINDEX_LINKAGE CXExpr clang_DeclaratorDecl_getTrailingRequiresClause(CXDeclaratorDecl DD);

CINDEX_LINKAGE void
clang_DeclaratorDecl_setTrailingRequiresClause(CXDeclaratorDecl DD,
                                               CXExpr TrailingRequiresClause);

CINDEX_LINKAGE unsigned
clang_DeclaratorDecl_getNumTemplateParameterLists(CXDeclaratorDecl DD);

CINDEX_LINKAGE CXTemplateParameterList
clang_DeclaratorDecl_getTemplateParameterList(CXDeclaratorDecl DD, unsigned index);

// setTemplateParameterListsInfo

CINDEX_LINKAGE CXSourceLocation_
clang_DeclaratorDecl_getTypeSpecStartLoc(CXDeclaratorDecl DD);

CINDEX_LINKAGE CXSourceLocation_
clang_DeclaratorDecl_getTypeSpecEndLoc(CXDeclaratorDecl DD);

// VarDecl

// getSourceRange

CINDEX_LINKAGE CXStorageClass clang_VarDecl_getStorageClass(CXVarDecl VD);

CINDEX_LINKAGE void clang_VarDecl_setStorageClass(CXVarDecl VD, CXStorageClass SC);

CINDEX_LINKAGE void clang_VarDecl_setTSCSpec(CXVarDecl VD,
                                             CXThreadStorageClassSpecifier TSC);

CINDEX_LINKAGE CXThreadStorageClassSpecifier clang_VarDecl_getTSCSpec(CXVarDecl VD);

// getTLSKind

CINDEX_LINKAGE bool clang_VarDecl_hasLocalStorage(CXVarDecl VD);

CINDEX_LINKAGE bool clang_VarDecl_isStaticLocal(CXVarDecl VD);

CINDEX_LINKAGE bool clang_VarDecl_hasExternalStorage(CXVarDecl VD);

CINDEX_LINKAGE bool clang_VarDecl_hasGlobalStorage(CXVarDecl VD);

CINDEX_LINKAGE CXStorageDuration clang_VarDecl_getStorageDuration(CXVarDecl VD);

CINDEX_LINKAGE CXLanguageLinkage clang_VarDecl_getLanguageLinkage(CXVarDecl VD);

CINDEX_LINKAGE bool clang_VarDecl_isExternC(CXVarDecl VD);

CINDEX_LINKAGE bool clang_VarDecl_isInExternCContext(CXVarDecl VD);

CINDEX_LINKAGE bool clang_VarDecl_isInExternCXXContext(CXVarDecl VD);

CINDEX_LINKAGE bool clang_VarDecl_isLocalVarDecl(CXVarDecl VD);

CINDEX_LINKAGE bool clang_VarDecl_isLocalVarDeclOrParm(CXVarDecl VD);

CINDEX_LINKAGE bool clang_VarDecl_isFunctionOrMethodVarDecl(CXVarDecl VD);

CINDEX_LINKAGE bool clang_VarDecl_isStaticDataMember(CXVarDecl VD);

CINDEX_LINKAGE CXVarDecl clang_VarDecl_getCanonicalDecl(CXVarDecl VD);

// isThisDeclarationADefinition
// hasDefinition

CINDEX_LINKAGE CXVarDecl clang_VarDecl_getActingDefinition(CXVarDecl VD);

CINDEX_LINKAGE CXVarDecl clang_VarDecl_getDefinition(CXVarDecl VD);

CINDEX_LINKAGE bool clang_VarDecl_isOutOfLine(CXVarDecl VD);

CINDEX_LINKAGE bool clang_VarDecl_isFileVarDecl(CXVarDecl VD);

CINDEX_LINKAGE CXExpr clang_VarDecl_getAnyInitializer(CXVarDecl VD);

CINDEX_LINKAGE bool clang_VarDecl_hasInit(CXVarDecl VD);

CINDEX_LINKAGE CXExpr clang_VarDecl_getInit(CXVarDecl VD);

// getInitAddress

CINDEX_LINKAGE void clang_VarDecl_setInit(CXVarDecl VD, CXExpr I);

CINDEX_LINKAGE CXVarDecl clang_VarDecl_getInitializingDeclaration(CXVarDecl VD);

CINDEX_LINKAGE bool clang_VarDecl_mightBeUsableInConstantExpressions(CXVarDecl VD,
                                                                     CXASTContext C);

CINDEX_LINKAGE bool clang_VarDecl_isUsableInConstantExpressions(CXVarDecl VD,
                                                                CXASTContext C);

CINDEX_LINKAGE CXEvaluatedStmt clang_VarDecl_ensureEvaluatedStmt(CXVarDecl VD);

CINDEX_LINKAGE CXEvaluatedStmt clang_VarDecl_getEvaluatedStmt(CXVarDecl VD);

// evaluateValue
// getEvaluatedValue
// evaluateDestruction

CINDEX_LINKAGE bool clang_VarDecl_hasConstantInitialization(CXVarDecl VD);

CINDEX_LINKAGE bool clang_VarDecl_hasICEInitializer(CXVarDecl VD, CXASTContext Context);

// checkForConstantInitialization
// setInitStyle
// getInitStyle

CINDEX_LINKAGE bool clang_VarDecl_isDirectInit(CXVarDecl VD);

CINDEX_LINKAGE bool clang_VarDecl_isThisDeclarationADemotedDefinition(CXVarDecl VD);

CINDEX_LINKAGE void clang_VarDecl_demoteThisDefinitionToDeclaration(CXVarDecl VD);

CINDEX_LINKAGE bool clang_VarDecl_isExceptionVariable(CXVarDecl VD);

CINDEX_LINKAGE void clang_VarDecl_setExceptionVariable(CXVarDecl VD, bool EV);

CINDEX_LINKAGE bool clang_VarDecl_isNRVOVariable(CXVarDecl VD);

CINDEX_LINKAGE void clang_VarDecl_setNRVOVariable(CXVarDecl VD, bool NRVO);

CINDEX_LINKAGE bool clang_VarDecl_isCXXForRangeDecl(CXVarDecl VD);

CINDEX_LINKAGE void clang_VarDecl_setCXXForRangeDecl(CXVarDecl VD, bool FRD);

CINDEX_LINKAGE bool clang_VarDecl_isObjCForDecl(CXVarDecl VD);

CINDEX_LINKAGE void clang_VarDecl_setObjCForDecl(CXVarDecl VD, bool FRD);

CINDEX_LINKAGE bool clang_VarDecl_isARCPseudoStrong(CXVarDecl VD);

CINDEX_LINKAGE void clang_VarDecl_setARCPseudoStrong(CXVarDecl VD, bool PS);

CINDEX_LINKAGE bool clang_VarDecl_isInline(CXVarDecl VD);

CINDEX_LINKAGE bool clang_VarDecl_isInlineSpecified(CXVarDecl VD);

CINDEX_LINKAGE void clang_VarDecl_setInlineSpecified(CXVarDecl VD);

CINDEX_LINKAGE void clang_VarDecl_setImplicitlyInline(CXVarDecl VD);

CINDEX_LINKAGE bool clang_VarDecl_isConstexpr(CXVarDecl VD);

CINDEX_LINKAGE void clang_VarDecl_setConstexpr(CXVarDecl VD, bool IC);

CINDEX_LINKAGE bool clang_VarDecl_isInitCapture(CXVarDecl VD);

CINDEX_LINKAGE void clang_VarDecl_setInitCapture(CXVarDecl VD, bool IC);

CINDEX_LINKAGE bool clang_VarDecl_isParameterPack(CXVarDecl VD);

CINDEX_LINKAGE bool clang_VarDecl_isPreviousDeclInSameBlockScope(CXVarDecl VD);

CINDEX_LINKAGE void clang_VarDecl_setPreviousDeclInSameBlockScope(CXVarDecl VD, bool Same);

CINDEX_LINKAGE bool clang_VarDecl_isEscapingByref(CXVarDecl VD);

CINDEX_LINKAGE bool clang_VarDecl_isNonEscapingByref(CXVarDecl VD);

CINDEX_LINKAGE void clang_VarDecl_setEscapingByref(CXVarDecl VD);

CINDEX_LINKAGE CXVarDecl clang_VarDecl_getTemplateInstantiationPattern(CXVarDecl VD);

CINDEX_LINKAGE CXVarDecl clang_VarDecl_getInstantiatedFromStaticDataMember(CXVarDecl VD);

CINDEX_LINKAGE CXTemplateSpecializationKind
clang_VarDecl_getTemplateSpecializationKind(CXVarDecl VD);

CINDEX_LINKAGE CXTemplateSpecializationKind
clang_VarDecl_getTemplateSpecializationKindForInstantiation(CXVarDecl VD);

CINDEX_LINKAGE CXSourceLocation_ clang_VarDecl_getPointOfInstantiation(CXVarDecl VD);

// getMemberSpecializationInfo

CINDEX_LINKAGE void
clang_VarDecl_setTemplateSpecializationKind(CXVarDecl VD, CXTemplateSpecializationKind TSK,
                                            CXSourceLocation_ PointOfInstantiation);

CINDEX_LINKAGE void
clang_VarDecl_setInstantiationOfStaticDataMember(CXVarDecl VD, CXVarDecl VD2,
                                                 CXTemplateSpecializationKind TSK);

CINDEX_LINKAGE CXVarTemplateDecl clang_VarDecl_getDescribedVarTemplate(CXVarDecl VD);

CINDEX_LINKAGE void clang_VarDecl_setDescribedVarTemplate(CXVarDecl VD,
                                                          CXVarTemplateDecl Template);

CINDEX_LINKAGE bool clang_VarDecl_isKnownToBeDefined(CXVarDecl VD);

CINDEX_LINKAGE bool clang_VarDecl_isNoDestroy(CXVarDecl VD, CXASTContext AST);

// needsDestruction

// TypeDecl
CINDEX_LINKAGE CXType_ clang_TypeDecl_getTypeForDecl(CXTypeDecl TD);

CINDEX_LINKAGE void clang_TypeDecl_setTypeForDecl(CXTypeDecl TD, CXType_ Ty);

CINDEX_LINKAGE CXSourceLocation_ clang_TypeDecl_getBeginLoc(CXTypeDecl TD);

CINDEX_LINKAGE void clang_TypeDecl_setLocStart(CXTypeDecl TD, CXSourceLocation_ Loc);

// TypedefNameDecl
CINDEX_LINKAGE CXQualType clang_TypedefNameDecl_getUnderlyingType(CXTypedefNameDecl TND);

CINDEX_LINKAGE CXTypedefNameDecl
clang_TypedefNameDecl_getCanonicalDecl(CXTypedefNameDecl TND);

CINDEX_LINKAGE CXTagDecl
clang_TypedefNameDecl_getAnonDeclWithTypedefName(CXTypedefNameDecl TND, bool AnyRedecl);

CINDEX_LINKAGE bool clang_TypedefNameDecl_isTransparentTag(CXTypedefNameDecl TND);

// TagDecl
CINDEX_LINKAGE CXDeclContext clang_TagDecl_castToDeclContext(CXTagDecl TD);

CINDEX_LINKAGE CXTagDecl clang_TagDecl_getCanonicalDecl(CXTagDecl TD);

CINDEX_LINKAGE CXTagDecl clang_TagDecl_getCanonicalDecl(CXTagDecl TD);

CINDEX_LINKAGE bool clang_TagDecl_isThisDeclarationADefinition(CXTagDecl TD);

CINDEX_LINKAGE bool clang_TagDecl_isCompleteDefinition(CXTagDecl TD);

CINDEX_LINKAGE void clang_TagDecl_setCompleteDefinition(CXTagDecl TD, bool V);

CINDEX_LINKAGE bool clang_TagDecl_isBeingDefined(CXTagDecl TD);

CINDEX_LINKAGE bool clang_TagDecl_isFreeStanding(CXTagDecl TD);

CINDEX_LINKAGE void clang_TagDecl_startDefinition(CXTagDecl TD);

CINDEX_LINKAGE CXTagDecl clang_TagDecl_getDefinition(CXTagDecl TD);

CINDEX_LINKAGE const char *clang_TagDecl_getKindName(CXTagDecl TD);

CINDEX_LINKAGE CXTagTypeKind clang_TagDecl_getTagKind(CXTagDecl TD);

CINDEX_LINKAGE bool clang_TagDecl_isStruct(CXTagDecl TD);

CINDEX_LINKAGE bool clang_TagDecl_isInterface(CXTagDecl TD);

CINDEX_LINKAGE bool clang_TagDecl_isClass(CXTagDecl TD);

CINDEX_LINKAGE bool clang_TagDecl_isUnion(CXTagDecl TD);

CINDEX_LINKAGE bool clang_TagDecl_isEnum(CXTagDecl TD);

CINDEX_LINKAGE bool clang_TagDecl_hasNameForLinkage(CXTagDecl TD);

CINDEX_LINKAGE CXTypedefNameDecl clang_TagDecl_getTypedefNameForAnonDecl(CXTagDecl TD);

CINDEX_LINKAGE CXNestedNameSpecifier clang_TagDecl_getQualifier(CXTagDecl TD);

CINDEX_LINKAGE unsigned clang_TagDecl_getNumTemplateParameterLists(CXTagDecl TD);

CINDEX_LINKAGE CXTemplateParameterList clang_TagDecl_getTemplateParameterList(CXTagDecl TD,
                                                                              unsigned i);

// EnumDecl
CINDEX_LINKAGE CXEnumDecl clang_EnumDecl_getCanonicalDecl(CXEnumDecl ED);

CINDEX_LINKAGE CXEnumDecl clang_EnumDecl_getPreviousDecl(CXEnumDecl ED);

CINDEX_LINKAGE CXEnumDecl clang_EnumDecl_getMostRecentDecl(CXEnumDecl ED);

CINDEX_LINKAGE CXEnumDecl clang_EnumDecl_getDefinition(CXEnumDecl ED);

CINDEX_LINKAGE CXQualType clang_EnumDecl_getIntegerType(CXEnumDecl ED);

// RecordDecl
CINDEX_LINKAGE CXRecordDecl clang_RecordDecl_getPreviousDecl(CXRecordDecl RD);

CINDEX_LINKAGE CXRecordDecl clang_RecordDecl_getMostRecentDecl(CXRecordDecl RD);

CINDEX_LINKAGE bool clang_RecordDecl_hasFlexibleArrayMember(CXRecordDecl RD);

CINDEX_LINKAGE bool clang_RecordDecl_isAnonymousStructOrUnion(CXRecordDecl RD);

CINDEX_LINKAGE bool clang_RecordDecl_isInjectedClassName(CXRecordDecl RD);

CINDEX_LINKAGE bool clang_RecordDecl_isLambda(CXRecordDecl RD);

CINDEX_LINKAGE bool clang_RecordDecl_isCapturedRecord(CXRecordDecl RD);

CINDEX_LINKAGE CXRecordDecl clang_RecordDecl_getDefinition(CXRecordDecl RD);

CINDEX_LINKAGE bool clang_RecordDecl_isOrContainsUnion(CXRecordDecl RD);

#ifdef __cplusplus
}
#endif
#endif