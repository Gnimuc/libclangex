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

CINDEX_LINKAGE unsigned clang_FileID_getHashValue(CXFileID FID);

CINDEX_LINKAGE void clang_FileID_dispose(CXFileID FID);

CINDEX_LINKAGE CXFileID clang_SourceManager_createFileIDFromMemoryBuffer(CXSourceManager SM,
                                                                         CXMemoryBuffer MB);

CINDEX_LINKAGE
CXFileID clang_SourceManager_createFileIDFromFileEntry(CXSourceManager SM, CXFileEntry FE);

CINDEX_LINKAGE CXFileID clang_SourceManager_getMainFileID(CXSourceManager SM);

CINDEX_LINKAGE void clang_SourceManager_setMainFileID(CXSourceManager SM, CXFileID ID);

CINDEX_LINKAGE void clang_SourceManager_overrideFileContents(CXSourceManager SM,
                                                             CXFileEntry FE,
                                                             CXMemoryBuffer MB);

#ifdef __cplusplus
}
#endif
#endif
