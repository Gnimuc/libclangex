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

CINDEX_LINKAGE CXDeclGroupRef clang_Parser_parseOneTopLevelDecl(CXParser Parser,
                                                                bool IsFirstDecl);

CINDEX_LINKAGE void clang_ParseAST(CXSema Sema, bool PrintStats, bool SkipFunctionBodies);

#ifdef __cplusplus
}
#endif
#endif