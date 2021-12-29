#ifndef LIBCLANGEX_CXDECLBASE_H
#define LIBCLANGEX_CXDECLBASE_H

#include "clang-ex/CXTypes.h"
#include "clang-c/Platform.h"

#ifdef __cplusplus
extern "C" {
#endif

CINDEX_LINKAGE CXTagDecl clang_DeclContext_castToTagDecl(CXDeclContext DC);

CINDEX_LINKAGE CXRecordDecl clang_DeclContext_castToRecordDecl(CXDeclContext DC);

CINDEX_LINKAGE CXCXXRecordDecl clang_DeclContext_castToCXXRecordDecl(CXDeclContext DC);

CINDEX_LINKAGE const char *clang_DeclContext_getDeclKindName(CXDeclContext DC);

CINDEX_LINKAGE CXDeclContext clang_DeclContext_getParent(CXDeclContext DC);

CINDEX_LINKAGE CXDeclContext clang_DeclContext_getLexicalParent(CXDeclContext DC);

CINDEX_LINKAGE CXDeclContext clang_DeclContext_getLookupParent(CXDeclContext DC);

CINDEX_LINKAGE CXASTContext clang_DeclContext_getParentASTContext(CXDeclContext DC);

CINDEX_LINKAGE bool clang_DeclContext_isClosure(CXDeclContext DC);

CINDEX_LINKAGE bool clang_DeclContext_isFunctionOrMethod(CXDeclContext DC);

CINDEX_LINKAGE bool clang_DeclContext_isLookupContext(CXDeclContext DC);

CINDEX_LINKAGE bool clang_DeclContext_isFileContext(CXDeclContext DC);

CINDEX_LINKAGE bool clang_DeclContext_isTranslationUnit(CXDeclContext DC);

CINDEX_LINKAGE bool clang_DeclContext_isRecord(CXDeclContext DC);

CINDEX_LINKAGE bool clang_DeclContext_isNamespace(CXDeclContext DC);

CINDEX_LINKAGE bool clang_DeclContext_isStdNamespace(CXDeclContext DC);

CINDEX_LINKAGE bool clang_DeclContext_isInlineNamespace(CXDeclContext DC);

CINDEX_LINKAGE bool clang_DeclContext_isDependentContext(CXDeclContext DC);

CINDEX_LINKAGE bool clang_DeclContext_isTransparentContext(CXDeclContext DC);

CINDEX_LINKAGE bool clang_DeclContext_isExternCContext(CXDeclContext DC);

CINDEX_LINKAGE bool clang_DeclContext_isExternCXXContext(CXDeclContext DC);

CINDEX_LINKAGE bool clang_DeclContext_Equals(CXDeclContext DC, CXDeclContext DC2);

CINDEX_LINKAGE CXDeclContext clang_DeclContext_getPrimaryContext(CXDeclContext DC);

CINDEX_LINKAGE void clang_DeclContext_addDecl(CXDeclContext DC, CXDecl D);

CINDEX_LINKAGE void clang_DeclContext_addDeclInternal(CXDeclContext DC, CXDecl D);

CINDEX_LINKAGE void clang_DeclContext_addHiddenDecl(CXDeclContext DC, CXDecl D);

CINDEX_LINKAGE void clang_DeclContext_removeDecl(CXDeclContext DC, CXDecl D);

CINDEX_LINKAGE void clang_DeclContext_containsDecl(CXDeclContext DC, CXDecl D);

CINDEX_LINKAGE void clang_DeclContext_dumpDeclContext(CXDeclContext DC);

CINDEX_LINKAGE void clang_DeclContext_dumpLookups(CXDeclContext DC);

#ifdef __cplusplus
}
#endif
#endif