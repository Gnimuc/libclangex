#ifndef LIBCLANGEX_CXDECL_H
#define LIBCLANGEX_CXDECL_H

#include "clang-ex/AST/CXType.h"
#include "clang-ex/Basic/CXLinkage.h"
#include "clang-ex/Basic/CXPragmaKinds.h"
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

CINDEX_LINKAGE CXNamedDecl clang_NamedDecl_getUnderlyingDecl(CXNamedDecl ND);

CINDEX_LINKAGE CXNamedDecl clang_NamedDecl_getMostRecentDecl(CXNamedDecl ND);

// NamedDecl Cast
CINDEX_LINKAGE CXTypeDecl clang_NamedDecl_castToTypeDecl(CXNamedDecl ND);

// LabelDecl
// getStmt
// setStmt

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