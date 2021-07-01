#ifndef LIBCLANGEX_H
#define LIBCLANGEX_H

#include "CXASTUnit.h"
#include "CXCodeGen.h"
#include "CXCompilerInstance.h"
#include "CXCompilerInvocation.h"
#include "CXDiagnostic.h"
#include "CXFileManager.h"
#include "CXMemoryBuffer.h"
#include "CXSourceManager.h"
#include "CXTypes.h"
#include "clang-c/Platform.h"

#ifdef __cplusplus
extern "C" {
#endif

CINDEX_LINKAGE void clang_ParseAST(CXSema Sema, bool PrintStats, bool SkipFunctionBodies);

#ifdef __cplusplus
}
#endif
#endif
