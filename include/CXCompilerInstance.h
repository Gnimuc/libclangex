#ifndef LIBCLANGEX_CXCOMPILERINSTANCE_H
#define LIBCLANGEX_CXCOMPILERINSTANCE_H

#include "CXCodeGenOptions.h"
#include "CXDiagnostic.h"
#include "CXDiagnosticOptions.h"
#include "CXIntrusiveRefCntPtr.h"
#include "clang-c/Platform.h"

#ifndef __cplusplus
typedef int bool;
#endif

#ifdef __cplusplus
extern "C" {
#endif

typedef void *CXCompilerInstance;

typedef enum {
  CXCompilerInstance_NoError = 0,
  CXCompilerInstance_CanNotCreate = 1
} CXCompilerInstance_Error;

CINDEX_LINKAGE CXCompilerInstance
clang_CompilerInstance_create(CXCompilerInstance_Error *ErrorCode);

CINDEX_LINKAGE void clang_CompilerInstance_dispose(CXCompilerInstance CI);

CINDEX_LINKAGE bool
clang_CompilerInstance_hasDiagnostics(CXCompilerInstance CI);
CINDEX_LINKAGE CXDiagnosticsEngine
clang_CompilerInstance_getDiagnostics(CXCompilerInstance CI);
CINDEX_LINKAGE void
clang_CompilerInstance_setDiagnostics(CXCompilerInstance CI,
                                      CXDiagnosticsEngine Value);
CINDEX_LINKAGE CXDiagnosticConsumer
clang_CompilerInstance_getDiagnosticClient(CXCompilerInstance CI);

CINDEX_LINKAGE void clang_CompilerInstance_createDiagnostics(
    CXCompilerInstance CI, CXDiagnosticConsumer DC, bool ShouldOwnClient);

CINDEX_LINKAGE CXIntrusiveRefCntPtr
clang_CompilerInstance_createDiagnosticsEngine(CXDiagnosticOptions DO,
                                               CXDiagnosticConsumer DC,
                                               bool ShouldOwnClient,
                                               CXCodeGenOptions CGO);

#ifdef __cplusplus
}
#endif
#endif
