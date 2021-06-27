#ifndef LIBCLANGEX_CXSOURCEMANAGER_H
#define LIBCLANGEX_CXSOURCEMANAGER_H

#include "CXDiagnostic.h"
#include "CXError.h"
#include "CXFileManager.h"
#include "clang-c/Platform.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void *CXSourceManager;

CINDEX_LINKAGE CXSourceManager clang_SourceManager_create(CXInit_Error *ErrorCode,
                                                          CXDiagnosticsEngine Diag,
                                                          CXFileManager FileMgr,
                                                          bool UserFilesAreVolatile);

CINDEX_LINKAGE void clang_SourceManager_dispose(CXSourceManager SM);

#ifdef __cplusplus
}
#endif
#endif
