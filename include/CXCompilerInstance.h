#ifndef LIBCLANGEX_CXCOMPILERINSTANCE_H
#define LIBCLANGEX_CXCOMPILERINSTANCE_H

#include "CXCodeGenOptions.h"
#include "CXDiagnostic.h"
#include "CXDiagnosticOptions.h"
#include "CXError.h"
#include "CXFileManager.h"
#include "CXIntrusiveRefCntPtr.h"
#include "CXMemoryBuffer.h"
#include "clang-c/Platform.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void *CXCompilerInstance;

CINDEX_LINKAGE CXCompilerInstance
clang_CompilerInstance_create(CXInit_Error *ErrorCode);

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

CINDEX_LINKAGE bool
clang_CompilerInstance_hasFileManager(CXCompilerInstance CI);
CINDEX_LINKAGE CXFileManager
clang_CompilerInstance_getFileManager(CXCompilerInstance CI);
CINDEX_LINKAGE void clang_CompilerInstance_setFileManager(CXCompilerInstance CI,
                                                          CXFileManager FM);

CINDEX_LINKAGE CXFileManager
clang_CompilerInstance_createFileManager(CXCompilerInstance CI);

CINDEX_LINKAGE CXFileManager
clang_CompilerInstance_createFileManagerWithVOFS4PCH(CXCompilerInstance CI,
                                                     const char *Path,
                                                     time_t ModificationTime,
                                                     CXMemoryBuffer PCHBuffer);

#ifdef __cplusplus
}
#endif
#endif
