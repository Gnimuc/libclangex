#ifndef LIBCLANGEX_H
#define LIBCLANGEX_H

#include "clang-ex/CXASTContext.h"
#include "clang-ex/CXCodeGen.h"
#include "clang-ex/CXCompilerInstance.h"
#include "clang-ex/CXCompilerInvocation.h"
#include "clang-ex/CXDiagnostic.h"
#include "clang-ex/CXDriver.h"
#include "clang-ex/CXFileManager.h"
#include "clang-ex/CXOptions.h"
#include "clang-ex/CXPreprocessor.h"
#include "clang-ex/CXSema.h"
#include "clang-ex/CXSourceManager.h"
#include "clang-ex/CXTypes.h"
#include "clang-c/Platform.h"

#ifdef __cplusplus
extern "C" {
#endif

CINDEX_LINKAGE bool
clang_Parser_tryParseAndSkipInvalidOrParsedDecl(CXParser Parser, CXCodeGenerator CodeGen);

CINDEX_LINKAGE void clang_Sema_processWeakTopLevelDecls(CXSema Sema,
                                                        CXCodeGenerator CodeGen);

#ifdef __cplusplus
}
#endif
#endif
