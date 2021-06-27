#ifndef LIBCLANGEX_CXFILEMANAGER_H
#define LIBCLANGEX_CXFILEMANAGER_H

#include "CXError.h"
#include "CXString.h"
#include "CXTypes.h"
#include "clang-c/Platform.h"

#ifdef __cplusplus
extern "C" {
#endif

CINDEX_LINKAGE CXFileManager clang_FileManager_create(CXInit_Error *ErrorCode);

CINDEX_LINKAGE void clang_FileManager_dispose(CXFileManager FM);

CINDEX_LINKAGE CXDirectoryEntry clang_FileManager_getDirectory(CXFileManager FM,
                                                               const char *DirName,
                                                               bool CacheFailure);

CINDEX_LINKAGE CXFileEntry clang_FileManager_getFile(CXFileManager FM, const char *Filename,
                                                     bool OpenFile, bool CacheFailure);

CINDEX_LINKAGE CXFileEntry clang_FileManager_getVirtualFile(CXFileManager FM,
                                                            const char *Filename,
                                                            unsigned Size,
                                                            time_t ModificationTime);

CINDEX_LINKAGE CXString clang_DirectoryEntry_getName(CXDirectoryEntry DE);

CINDEX_LINKAGE CXString clang_FileEntry_getName(CXFileEntry FE);

CINDEX_LINKAGE CXString clang_FileEntry_tryGetRealPathName(CXFileEntry FE);

CINDEX_LINKAGE bool clang_FileEntry_isValid(CXFileEntry FE);

CINDEX_LINKAGE unsigned clang_FileEntry_getUID(CXFileEntry FE);

CINDEX_LINKAGE time_t clang_FileEntry_getModificationTime(CXFileEntry FE);

CINDEX_LINKAGE CXDirectoryEntry clang_FileEntry_getDir(CXFileEntry FE);

CINDEX_LINKAGE bool clang_FileEntry_isNamedPipe(CXFileEntry FE);

#ifdef __cplusplus
}
#endif
#endif
