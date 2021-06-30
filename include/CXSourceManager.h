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

CINDEX_LINKAGE void clang_SourceManager_overrideFileContents(CXSourceManager SM,
                                                             CXFileEntry FE,
                                                             CXMemoryBuffer MB);

CINDEX_LINKAGE void clang_SourceManager_createAndSetMainFileID(CXSourceManager SM,
                                                               CXFileEntry FE);

CINDEX_LINKAGE int clang_SourceManager_getMainFileID_HashValue(CXSourceManager SM);

#ifdef __cplusplus
}
#endif
#endif
