#ifndef LIBCLANGEX_CXDECL_H
#define LIBCLANGEX_CXDECL_H

#include "clang-ex/CXTypes.h"
#include "clang-c/Platform.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum CXTagTypeKind {
  CXTagTypeKind_TTK_Struct,
  CXTagTypeKind_TTK_Interface,
  CXTagTypeKind_TTK_Union,
  CXTagTypeKind_TTK_Class,
  CXTagTypeKind_TTK_Enum
} CXTagTypeKind;

// TranslationUnitDecl
CINDEX_LINKAGE CXASTContext
clang_TranslationUnitDecl_getASTContext(CXTranslationUnitDecl TUD);

// NamedDecl
CINDEX_LINKAGE CXIdentifierInfo clang_NamedDecl_getIdentifier(CXNamedDecl ND);

CINDEX_LINKAGE const char *clang_NamedDecl_getName(CXNamedDecl ND);

CINDEX_LINKAGE CXDeclarationName clang_NamedDecl_getDeclName(CXNamedDecl ND);

CINDEX_LINKAGE void clang_NamedDecl_setDeclName(CXNamedDecl ND, CXDeclarationName DN);

CINDEX_LINKAGE bool clang_NamedDecl_hasLinkage(CXNamedDecl ND);

CINDEX_LINKAGE bool clang_NamedDecl_isCXXClassMember(CXNamedDecl ND);

CINDEX_LINKAGE bool clang_NamedDecl_isCXXInstanceMember(CXNamedDecl ND);

CINDEX_LINKAGE bool clang_NamedDecl_hasExternalFormalLinkage(CXNamedDecl ND);

CINDEX_LINKAGE bool clang_NamedDecl_isExternallyVisible(CXNamedDecl ND);

CINDEX_LINKAGE bool clang_NamedDecl_isExternallyDeclarable(CXNamedDecl ND);

CINDEX_LINKAGE CXNamedDecl clang_NamedDecl_getUnderlyingDecl(CXNamedDecl ND);

CINDEX_LINKAGE CXNamedDecl clang_NamedDecl_getMostRecentDecl(CXNamedDecl ND);

CINDEX_LINKAGE bool clang_NamedDecl_isOutOfLine(CXNamedDecl ND);

// NamedDecl Cast
CINDEX_LINKAGE CXTypeDecl clang_NamedDecl_castToTypeDecl(CXNamedDecl ND);

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