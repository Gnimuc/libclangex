#ifndef LIBCLANGEX_CXASTCONTEXT_H
#define LIBCLANGEX_CXASTCONTEXT_H

#include "clang-ex/CXTypes.h"
#include "clang-c/Platform.h"

#ifdef __cplusplus
extern "C" {
#endif

CINDEX_LINKAGE void clang_ASTContext_PrintStats(CXASTContext Ctx);

CINDEX_LINKAGE CXQualType clang_ASTContext_getPointerType(CXASTContext Ctx,
                                                          CXQualType OpaquePtr);

CINDEX_LINKAGE CXIdentifierTable clang_ASTContext_getIdents(CXASTContext Ctx);

// IdentifierTable
CINDEX_LINKAGE void clang_IdentifierTable_PrintStats(CXIdentifierTable IT);

CINDEX_LINKAGE CXIdentifierInfo clang_IdentifierTable_get(CXIdentifierTable Idents,
                                                          const char *Name);

// DeclarationName
CINDEX_LINKAGE CXDeclarationName clang_DeclarationName_create(void);

CINDEX_LINKAGE CXDeclarationName
clang_DeclarationName_createFromIdentifierInfo(CXIdentifierInfo IDInfo);

CINDEX_LINKAGE void clang_LookupResult_setLookupName(CXLookupResult LR,
                                                     CXDeclarationName DN);

CINDEX_LINKAGE CXDeclarationName clang_LookupResult_getLookupName(CXLookupResult LR);

CINDEX_LINKAGE void clang_DeclarationName_dump(CXDeclarationName DN);

CINDEX_LINKAGE bool clang_DeclarationName_isEmpty(CXDeclarationName DN);

CINDEX_LINKAGE char *clang_DeclarationName_getAsString(CXDeclarationName DN);

CINDEX_LINKAGE void clang_DeclarationName_disposeString(char *Str);

// NestedNameSpecifier
CINDEX_LINKAGE CXNestedNameSpecifier
clang_NestedNameSpecifier_getPrefix(CXNestedNameSpecifier NNS);

CINDEX_LINKAGE bool clang_NestedNameSpecifier_containsErrors(CXNestedNameSpecifier NNS);

CINDEX_LINKAGE void clang_NestedNameSpecifier_dump(CXNestedNameSpecifier NNS);

// Decls
CINDEX_LINKAGE CXTranslationUnitDecl
clang_ASTContext_getTranslationUnitDecl(CXASTContext Ctx);

// DeclGroup
CINDEX_LINKAGE CXDeclGroupRef clang_DeclGroupRef_fromeDecl(CXDecl D);

CINDEX_LINKAGE bool clang_DeclGroupRef_isNull(CXDeclGroupRef DG);

CINDEX_LINKAGE bool clang_DeclGroupRef_isSingleDecl(CXDeclGroupRef DG);

CINDEX_LINKAGE bool clang_DeclGroupRef_isDeclGroup(CXDeclGroupRef DG);

CINDEX_LINKAGE CXDecl clang_DeclGroupRef_getSingleDecl(CXDeclGroupRef DG);

// Decl
CINDEX_LINKAGE CXSourceLocation_ clang_Decl_getLocation(CXDecl DC);

CINDEX_LINKAGE CXSourceLocation_ clang_Decl_getBeginLoc(CXDecl DC);

CINDEX_LINKAGE CXSourceLocation_ clang_Decl_getEndLoc(CXDecl DC);

CINDEX_LINKAGE const char *clang_Decl_getDeclKindName(CXDecl DC);

CINDEX_LINKAGE CXDecl clang_Decl_getNextDeclInContext(CXDecl DC);

CINDEX_LINKAGE CXDeclContext clang_Decl_getDeclContext(CXDecl DC);

CINDEX_LINKAGE CXDecl clang_Decl_getNonClosureContext(CXDecl DC);

CINDEX_LINKAGE CXTranslationUnitDecl clang_Decl_getTranslationUnitDecl(CXDecl DC);

CINDEX_LINKAGE bool clang_Decl_isInAnonymousNamespace(CXDecl DC);

CINDEX_LINKAGE bool clang_Decl_isInStdNamespace(CXDecl DC);

CINDEX_LINKAGE CXASTContext clang_Decl_getASTContext(CXDecl DC);

CINDEX_LINKAGE CXLangOptions clang_Decl_getLangOpts(CXDecl DC);

CINDEX_LINKAGE CXDeclContext clang_Decl_getLexicalDeclContext(CXDecl DC);

CINDEX_LINKAGE bool clang_Decl_isTemplated(CXDecl DC);

CINDEX_LINKAGE bool clang_Decl_isCanonicalDecl(CXDecl DC);

CINDEX_LINKAGE CXDecl clang_Decl_getPreviousDecl(CXDecl DC);

CINDEX_LINKAGE bool clang_Decl_isFirstDecl(CXDecl DC);

CINDEX_LINKAGE CXDecl clang_Decl_getMostRecentDecl(CXDecl DC);

CINDEX_LINKAGE bool clang_Decl_isTemplateParameter(CXDecl DC);

CINDEX_LINKAGE bool clang_Decl_isTemplateDecl(CXDecl DC);

CINDEX_LINKAGE CXTemplateDecl clang_Decl_getDescribedTemplate(CXDecl DC);

CINDEX_LINKAGE CXTemplateParameterList clang_Decl_getDescribedTemplateParams(CXDecl DC);

CINDEX_LINKAGE void clang_Decl_EnableStatistics(void);

CINDEX_LINKAGE void clang_Stmt_EnableStatistics(void);

CINDEX_LINKAGE void clang_Decl_PrintStats(void);

CINDEX_LINKAGE void clang_Stmt_PrintStats(void);

CINDEX_LINKAGE void clang_Decl_dumpColor(CXDecl DC);

// NamedDecl
CINDEX_LINKAGE CXIdentifierInfo clang_NamedDecl_getIdentifier(CXNamedDecl ND);

CINDEX_LINKAGE const char *clang_NamedDecl_getName(CXNamedDecl ND);

CINDEX_LINKAGE void clang_NamedDecl_setDeclName(CXNamedDecl ND, CXDeclarationName DN);

CINDEX_LINKAGE bool clang_NamedDecl_hasLinkage(CXNamedDecl ND);

CINDEX_LINKAGE bool clang_NamedDecl_isCXXClassMember(CXNamedDecl ND);

CINDEX_LINKAGE bool clang_NamedDecl_isCXXInstanceMember(CXNamedDecl ND);

CINDEX_LINKAGE bool clang_NamedDecl_hasExternalFormalLinkage(CXNamedDecl ND);

CINDEX_LINKAGE bool clang_NamedDecl_isExternallyVisible(CXNamedDecl ND);

CINDEX_LINKAGE bool clang_NamedDecl_isExternallyDeclarable(CXNamedDecl ND);

CINDEX_LINKAGE CXNamedDecl clang_NamedDecl_getUnderlyingDecl(CXNamedDecl ND);

CINDEX_LINKAGE CXNamedDecl clang_NamedDecl_getMostRecentDecl(CXNamedDecl ND);

// TypeDecl
CINDEX_LINKAGE CXType_ clang_TypeDecl_getTypeForDecl(CXTypeDecl TD);

CINDEX_LINKAGE void clang_TypeDecl_setTypeForDecl(CXTypeDecl TD, CXType_ Ty);

CINDEX_LINKAGE CXSourceLocation_ clang_TypeDecl_getBeginLoc(CXTypeDecl TD);

CINDEX_LINKAGE void clang_TypeDecl_setLocStart(CXTypeDecl TD, CXSourceLocation_ Loc);

// TagDecl
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

CINDEX_LINKAGE bool clang_TagDecl_isStruct(CXTagDecl TD);

CINDEX_LINKAGE bool clang_TagDecl_isInterface(CXTagDecl TD);

CINDEX_LINKAGE bool clang_TagDecl_isClass(CXTagDecl TD);

CINDEX_LINKAGE bool clang_TagDecl_isUnion(CXTagDecl TD);

CINDEX_LINKAGE bool clang_TagDecl_isEnum(CXTagDecl TD);

CINDEX_LINKAGE bool clang_TagDecl_hasNameForLinkage(CXTagDecl TD);

CINDEX_LINKAGE CXNestedNameSpecifier clang_TagDecl_getQualifier(CXTagDecl TD);

CINDEX_LINKAGE unsigned clang_TagDecl_getNumTemplateParameterLists(CXTagDecl TD);

CINDEX_LINKAGE CXTemplateParameterList clang_TagDecl_getTemplateParameterList(CXTagDecl TD,
                                                                              unsigned i);

// TemplateParameterList
CINDEX_LINKAGE CXNamedDecl clang_TemplateParameterList_getParam(CXTemplateParameterList TPL,
                                                                unsigned Idx);

CINDEX_LINKAGE unsigned clang_TemplateParameterList_size(CXTemplateParameterList TPL);

// TemplateDecl
CINDEX_LINKAGE void clang_TemplateDecl_init(CXTemplateDecl TD, CXNamedDecl ND,
                                            CXTemplateParameterList TP);

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

// CXXRecordDecl
CINDEX_LINKAGE CXCXXRecordDecl clang_CXXRecordDecl_getCanonicalDecl(CXCXXRecordDecl CXXRD);

CINDEX_LINKAGE CXCXXRecordDecl clang_CXXRecordDecl_getPreviousDecl(CXCXXRecordDecl CXXRD);

CINDEX_LINKAGE CXCXXRecordDecl clang_CXXRecordDecl_getMostRecentDecl(CXCXXRecordDecl CXXRD);

CINDEX_LINKAGE CXCXXRecordDecl
clang_CXXRecordDecl_getMostRecentNonInjectedDecl(CXCXXRecordDecl CXXRD);

CINDEX_LINKAGE CXCXXRecordDecl clang_CXXRecordDecl_getDefinition(CXCXXRecordDecl CXXRD);

CINDEX_LINKAGE bool clang_CXXRecordDecl_hasDefinition(CXCXXRecordDecl CXXRD);

CINDEX_LINKAGE bool clang_CXXRecordDecl_isLambda(CXCXXRecordDecl CXXRD);

CINDEX_LINKAGE bool clang_CXXRecordDecl_isGenericLambda(CXCXXRecordDecl CXXRD);

CINDEX_LINKAGE CXTemplateParameterList
clang_CXXRecordDecl_getGenericLambdaTemplateParameterList(CXCXXRecordDecl CXXRD);

CINDEX_LINKAGE bool clang_CXXRecordDecl_isAggregate(CXCXXRecordDecl CXXRD);

CINDEX_LINKAGE bool clang_CXXRecordDecl_isPOD(CXCXXRecordDecl CXXRD);

CINDEX_LINKAGE bool clang_CXXRecordDecl_isCLike(CXCXXRecordDecl CXXRD);

CINDEX_LINKAGE bool clang_CXXRecordDecl_isEmpty(CXCXXRecordDecl CXXRD);

// Builtin Types
CINDEX_LINKAGE CXType_ clang_ASTContext_VoidTy_getTypePtrOrNull(CXASTContext Ctx);
CINDEX_LINKAGE CXType_ clang_ASTContext_BoolTy_getTypePtrOrNull(CXASTContext Ctx);
CINDEX_LINKAGE CXType_ clang_ASTContext_CharTy_getTypePtrOrNull(CXASTContext Ctx);
CINDEX_LINKAGE CXType_ clang_ASTContext_WCharTy_getTypePtrOrNull(CXASTContext Ctx);
CINDEX_LINKAGE CXType_ clang_ASTContext_WideCharTy_getTypePtrOrNull(CXASTContext Ctx);
CINDEX_LINKAGE CXType_ clang_ASTContext_WIntTy_getTypePtrOrNull(CXASTContext Ctx);
CINDEX_LINKAGE CXType_ clang_ASTContext_Char8Ty_getTypePtrOrNull(CXASTContext Ctx);
CINDEX_LINKAGE CXType_ clang_ASTContext_Char16Ty_getTypePtrOrNull(CXASTContext Ctx);
CINDEX_LINKAGE CXType_ clang_ASTContext_Char32Ty_getTypePtrOrNull(CXASTContext Ctx);
CINDEX_LINKAGE CXType_ clang_ASTContext_SignedCharTy_getTypePtrOrNull(CXASTContext Ctx);
CINDEX_LINKAGE CXType_ clang_ASTContext_ShortTy_getTypePtrOrNull(CXASTContext Ctx);
CINDEX_LINKAGE CXType_ clang_ASTContext_IntTy_getTypePtrOrNull(CXASTContext Ctx);
CINDEX_LINKAGE CXType_ clang_ASTContext_LongTy_getTypePtrOrNull(CXASTContext Ctx);
CINDEX_LINKAGE CXType_ clang_ASTContext_LongLongTy_getTypePtrOrNull(CXASTContext Ctx);
CINDEX_LINKAGE CXType_ clang_ASTContext_Int128Ty_getTypePtrOrNull(CXASTContext Ctx);
CINDEX_LINKAGE CXType_ clang_ASTContext_UnsignedCharTy_getTypePtrOrNull(CXASTContext Ctx);
CINDEX_LINKAGE CXType_ clang_ASTContext_UnsignedShortTy_getTypePtrOrNull(CXASTContext Ctx);
CINDEX_LINKAGE CXType_ clang_ASTContext_UnsignedIntTy_getTypePtrOrNull(CXASTContext Ctx);
CINDEX_LINKAGE CXType_ clang_ASTContext_UnsignedLongTy_getTypePtrOrNull(CXASTContext Ctx);
CINDEX_LINKAGE CXType_
clang_ASTContext_UnsignedLongLongTy_getTypePtrOrNull(CXASTContext Ctx);
CINDEX_LINKAGE CXType_ clang_ASTContext_UnsignedInt128Ty_getTypePtrOrNull(CXASTContext Ctx);
CINDEX_LINKAGE CXType_ clang_ASTContext_FloatTy_getTypePtrOrNull(CXASTContext Ctx);
CINDEX_LINKAGE CXType_ clang_ASTContext_DoubleTy_getTypePtrOrNull(CXASTContext Ctx);
CINDEX_LINKAGE CXType_ clang_ASTContext_LongDoubleTy_getTypePtrOrNull(CXASTContext Ctx);
CINDEX_LINKAGE CXType_ clang_ASTContext_Float128Ty_getTypePtrOrNull(CXASTContext Ctx);
CINDEX_LINKAGE CXType_ clang_ASTContext_HalfTy_getTypePtrOrNull(CXASTContext Ctx);
CINDEX_LINKAGE CXType_ clang_ASTContext_BFloat16Ty_getTypePtrOrNull(CXASTContext Ctx);
CINDEX_LINKAGE CXType_ clang_ASTContext_Float16Ty_getTypePtrOrNull(CXASTContext Ctx);
CINDEX_LINKAGE CXType_ clang_ASTContext_FloatComplexTy_getTypePtrOrNull(CXASTContext Ctx);
CINDEX_LINKAGE CXType_ clang_ASTContext_DoubleComplexTy_getTypePtrOrNull(CXASTContext Ctx);
CINDEX_LINKAGE CXType_
clang_ASTContext_LongDoubleComplexTy_getTypePtrOrNull(CXASTContext Ctx);
CINDEX_LINKAGE CXType_
clang_ASTContext_Float128ComplexTy_getTypePtrOrNull(CXASTContext Ctx);
CINDEX_LINKAGE CXType_ clang_ASTContext_VoidPtrTy_getTypePtrOrNull(CXASTContext Ctx);
CINDEX_LINKAGE CXType_ clang_ASTContext_NullPtrTy_getTypePtrOrNull(CXASTContext Ctx);

#ifdef __cplusplus
}
#endif
#endif