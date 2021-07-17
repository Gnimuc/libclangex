#ifndef LIBCLANGEX_H
#define LIBCLANGEX_H

#include "CXASTContext.h"
#include "CXCodeGen.h"
#include "CXCompilerInstance.h"
#include "CXCompilerInvocation.h"
#include "CXDiagnostic.h"
#include "CXDriver.h"
#include "CXFileManager.h"
#include "CXMemoryBuffer.h"
#include "CXOptions.h"
#include "CXPreprocessor.h"
#include "CXSema.h"
#include "CXSourceManager.h"
#include "CXTypes.h"
#include "clang-c/Platform.h"

#ifdef __cplusplus
extern "C" {
#endif

CINDEX_LINKAGE void clang_ParseAST(CXSema Sema, bool PrintStats, bool SkipFunctionBodies);

// Statistics
CINDEX_LINKAGE void clang_Decl_EnableStatistics(void);
CINDEX_LINKAGE void clang_Stmt_EnableStatistics(void);
CINDEX_LINKAGE void clang_Decl_PrintStats(void);
CINDEX_LINKAGE void clang_Stmt_PrintStats(void);

#ifdef __cplusplus
}
#endif
#endif
