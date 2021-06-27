#ifndef LIBCLANGEX_CXSOURCEMANAGER_H
#define LIBCLANGEX_CXSOURCEMANAGER_H

#include "CXDiagnostic.h"
#include "CXError.h"
#include "CXFileManager.h"
#include "CXTypes.h"
#include "clang-c/Platform.h"

#ifdef __cplusplus
extern "C" {
#endif

CINDEX_LINKAGE CXSourceManager clang_SourceManager_create(CXDiagnosticsEngine Diag,
                                                          CXFileManager FileMgr,
                                                          bool UserFilesAreVolatile,
                                                          CXInit_Error *ErrorCode);

CINDEX_LINKAGE void clang_SourceManager_dispose(CXSourceManager SM);

#ifdef __cplusplus
}
#endif
#endif
