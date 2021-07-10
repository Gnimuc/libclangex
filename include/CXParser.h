#ifndef LIBCLANGEX_CXPARSER_H
#define LIBCLANGEX_CXPARSER_H

#include "CXError.h"
#include "CXTypes.h"
#include "clang-c/Platform.h"

#ifdef __cplusplus
extern "C" {
#endif

CINDEX_LINKAGE CXParser clang_Parser_create(CXPreprocessor PP, CXSema Actions,
                                            bool SkipFunctionBodies,
                                            CXInit_Error *ErrorCode);

CINDEX_LINKAGE void clang_Parser_dispose(CXParser P);

CINDEX_LINKAGE void clang_Parser_Initialize(CXParser P);

CINDEX_LINKAGE bool
clang_Parser_tryParseAndSkipInvalidOrParsedDecl(CXParser Parser, CXCodeGenerator CodeGen);

#ifdef __cplusplus
}
#endif
#endif