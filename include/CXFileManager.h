#ifndef LIBCLANGEX_CXFILEMANAGER_H
#define LIBCLANGEX_CXFILEMANAGER_H

#include "CXError.h"
#include "CXTypes.h"
#include "clang-c/CXString.h"
#include "clang-c/Platform.h"

#ifdef __cplusplus
extern "C" {
#endif

CINDEX_LINKAGE CXFileManager clang_FileManager_create(CXInit_Error *ErrorCode);

CINDEX_LINKAGE void clang_FileManager_dispose(CXFileManager FM);

CINDEX_LINKAGE CXMemoryBuffer clang_FileManager_getBufferForFile(
    CXFileManager FM, CXFileEntry FE, bool isVolatile, bool RequiresNullTerminator);

CINDEX_LINKAGE void clang_FileManager_PrintStats(CXFileManager FM);

// DirectoryEntry
CINDEX_LINKAGE CXDirectoryEntry clang_FileManager_getDirectory(CXFileManager FM,
                                                               const char *DirName,
                                                               bool CacheFailure);

CINDEX_LINKAGE const char *clang_DirectoryEntry_getName(CXDirectoryEntry DE);

// FileEntryRef
// FIXME: this function allocates memory, do not forget to call
// `clang_FileEntryRef_dispose` to release the resource
CINDEX_LINKAGE CXFileEntryRef clang_FileManager_getFileRef(CXFileManager FM,
                                                           const char *Filename,
                                                           bool OpenFile,
                                                           bool CacheFailure);

// FIXME: users must call this dispose function manually to release the resource created by
// `clang_FileManager_getFileRef`
CINDEX_LINKAGE void clang_FileEntryRef_dispose(CXFileEntryRef FER);

CINDEX_LINKAGE CXFileEntry clang_FileEntryRef_getFileEntry(CXFileEntryRef FER);

// FileEntry
CINDEX_LINKAGE const char *clang_FileEntry_getName(CXFileEntry FE);

CINDEX_LINKAGE const char *clang_FileEntry_tryGetRealPathName(CXFileEntry FE);

CINDEX_LINKAGE bool clang_FileEntry_isValid(CXFileEntry FE);

CINDEX_LINKAGE unsigned clang_FileEntry_getUID(CXFileEntry FE);

CINDEX_LINKAGE time_t clang_FileEntry_getModificationTime(CXFileEntry FE);

CINDEX_LINKAGE CXDirectoryEntry clang_FileEntry_getDir(CXFileEntry FE);

CINDEX_LINKAGE bool clang_FileEntry_isNamedPipe(CXFileEntry FE);

#ifdef __cplusplus
}
#endif
#endif
