#ifndef LIBCLANGEX_CXPREPROCESSOR_H
#define LIBCLANGEX_CXPREPROCESSOR_H

#include "clang-ex/CXError.h"
#include "clang-ex/CXTypes.h"
#include "clang-c/Platform.h"
#include "llvm-c/Types.h"

#ifdef __cplusplus
extern "C" {
#endif

// Lexer
CINDEX_LINKAGE CXLexer clang_Lexer_create(CXFileID FID, LLVMMemoryBufferRef FromFile,
                                          CXSourceManager SM, CXLangOptions langOpts,
                                          CXInit_Error *ErrorCode);

CINDEX_LINKAGE void clang_Lexer_dispose(CXLexer Lex);

// Preprocessor
CINDEX_LINKAGE CXHeaderSearch clang_Preprocessor_getHeaderSearchInfo(CXPreprocessor PP);

CINDEX_LINKAGE void clang_HeaderSearch_PrintStats(CXHeaderSearch HS);

CINDEX_LINKAGE void clang_Preprocessor_EnterMainSourceFile(CXPreprocessor PP);

CINDEX_LINKAGE bool clang_Preprocessor_EnterSourceFile(CXPreprocessor PP, CXFileID FID,
                                                       CXSourceLocation_ Loc);

CINDEX_LINKAGE void clang_Preprocessor_EndSourceFile(CXPreprocessor PP);

CINDEX_LINKAGE void clang_Preprocessor_PrintStats(CXPreprocessor PP);

CINDEX_LINKAGE void clang_Preprocessor_InitializeBuiltins(CXPreprocessor PP);

CINDEX_LINKAGE void clang_Preprocessor_enableIncrementalProcessing(CXPreprocessor PP);

CINDEX_LINKAGE bool clang_Preprocessor_isIncrementalProcessingEnabled(CXPreprocessor PP);

// Token

#ifdef __cplusplus
}
#endif
#endif