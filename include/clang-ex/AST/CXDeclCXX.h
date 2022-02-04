#ifndef LIBCLANGEX_CXDECLCXX_H
#define LIBCLANGEX_CXDECLCXX_H

#include "clang-ex/AST/CXType.h"
#include "clang-ex/Basic/CXLambda.h"
#include "clang-ex/Basic/CXSpecifiers.h"
#include "clang-ex/CXTypes.h"
#include "clang-c/Platform.h"

#ifdef __cplusplus
extern "C" {
#endif

// AccessSpecDecl
CINDEX_LINKAGE CXSourceLocation_
clang_AccessSpecDecl_getAccessSpecifierLoc(CXAccessSpecDecl AS);

CINDEX_LINKAGE void clang_AccessSpecDecl_setAccessSpecifierLoc(CXAccessSpecDecl AS,
                                                               CXSourceLocation_ ASLoc);

CINDEX_LINKAGE CXSourceLocation_ clang_AccessSpecDecl_getColonLoc(CXAccessSpecDecl AS);

CINDEX_LINKAGE void clang_AccessSpecDecl_setColonLoc(CXAccessSpecDecl AS,
                                                     CXSourceLocation_ CLoc);

CINDEX_LINKAGE CXSourceRange_ clang_AccessSpecDecl_getSourceRange(CXAccessSpecDecl AS);

CINDEX_LINKAGE CXAccessSpecDecl clang_AccessSpecDecl_Create(CXASTContext C,
                                                            CXAccessSpecifier AS,
                                                            CXDeclContext DC,
                                                            CXSourceLocation_ ASLoc,
                                                            CXSourceLocation_ ColonLoc);

CINDEX_LINKAGE CXAccessSpecDecl clang_AccessSpecDecl_CreateDeserialized(CXASTContext C,
                                                                        unsigned ID);

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

#ifdef __cplusplus
}
#endif
#endif