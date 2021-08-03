#ifndef LIBCLANGEX_CXPARSER_H
#define LIBCLANGEX_CXPARSER_H

#include "clang-ex/CXError.h"
#include "clang-ex/CXTypes.h"
#include "clang-c/Platform.h"

#ifdef __cplusplus
extern "C" {
#endif

CINDEX_LINKAGE CXParser clang_Parser_create(CXPreprocessor PP, CXSema Actions,
                                            bool SkipFunctionBodies,
                                            CXInit_Error *ErrorCode);

CINDEX_LINKAGE void clang_Parser_dispose(CXParser P);

CINDEX_LINKAGE void clang_Parser_Initialize(CXParser P);

CINDEX_LINKAGE CXLangOptions clang_Parser_getLangOpts(CXParser P);

CINDEX_LINKAGE CXTargetInfo_ clang_Parser_getTargetInfo(CXParser P);

CINDEX_LINKAGE CXPreprocessor clang_Parser_getPreprocessor(CXParser P);

CINDEX_LINKAGE CXSema clang_Parser_getActions(CXParser P);

CINDEX_LINKAGE CXToken_ clang_Parser_getCurToken(CXParser P);

CINDEX_LINKAGE CXToken_ clang_Parser_NextToken(CXParser P);

CINDEX_LINKAGE CXScope clang_Parser_getCurScope(CXParser P);

CINDEX_LINKAGE CXSourceLocation_ clang_Parser_ConsumeToken(CXParser P);

CINDEX_LINKAGE CXSourceLocation_ clang_Parser_ConsumeAnyToken(CXParser P);

CINDEX_LINKAGE bool clang_Parser_TryAnnotateCXXScopeToken(CXParser P, bool EnteringContext);

CINDEX_LINKAGE CXDeclGroupRef clang_Parser_parseOneTopLevelDecl(CXParser Parser,
                                                                bool IsFirstDecl);

CINDEX_LINKAGE void clang_ParseAST(CXSema Sema, bool PrintStats, bool SkipFunctionBodies);

#ifdef __cplusplus
}
#endif
#endif