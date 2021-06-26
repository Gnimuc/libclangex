#include "CXFileManager.h"
#include "CXString.h"
#include "clang/Basic/FileManager.h"
#include <cstdio>

CXFileManager clang_FileManager_create(CXInit_Error *ErrorCode) {
  CXInit_Error Err = CXInit_NoError;
  std::unique_ptr<clang::FileManager> ptr =
      std::make_unique<clang::FileManager>(clang::FileSystemOptions());

  if (!ptr) {
    fprintf(stderr,
            "LIBCLANGEX ERROR: failed to create `clang::FileManager`\n");
    Err = CXInit_CanNotCreate;
  }

  if (ErrorCode)
    *ErrorCode = Err;

  return ptr.release();
}

void clang_FileManager_dispose(CXFileManager FM) {
  delete static_cast<clang::FileManager *>(FM);
}

CXDirectoryEntry clang_FileManager_getDirectory(CXFileManager FM,
                                                const char *DirName,
                                                bool CacheFailure) {
  return const_cast<clang::DirectoryEntry *>(
      *static_cast<clang::FileManager *>(FM)->getDirectory(
          llvm::StringRef(DirName), CacheFailure));
}

CXFileEntry clang_FileManager_getFile(CXFileManager FM, const char *Filename,
                                      bool OpenFile, bool CacheFailure) {
  return const_cast<clang::FileEntry *>(
      *static_cast<clang::FileManager *>(FM)->getFile(llvm::StringRef(Filename),
                                                      OpenFile, CacheFailure));
}

CXFileEntry clang_FileManager_getVirtualFile(CXFileManager FM,
                                             const char *Filename,
                                             unsigned Size,
                                             time_t ModificationTime) {
  return const_cast<clang::FileEntry *>(
      static_cast<clang::FileManager *>(FM)->getVirtualFile(
          llvm::StringRef(Filename), Size, ModificationTime));
}

bool clang_FileEntry_isValid(CXFileEntry FE) {
  return static_cast<clang::FileEntry *>(FE)->isValid();
}

unsigned clang_FileEntry_getUID(CXFileEntry FE) {
  return static_cast<clang::FileEntry *>(FE)->getUID();
}

time_t clang_FileEntry_getModificationTime(CXFileEntry FE) {
  return static_cast<clang::FileEntry *>(FE)->getModificationTime();
}

CXDirectoryEntry clang_FileEntry_getDir(CXFileEntry FE) {
  return const_cast<clang::DirectoryEntry *>(
      static_cast<clang::FileEntry *>(FE)->getDir());
}

bool clang_FileEntry_isNamedPipe(CXFileEntry FE) {
  return static_cast<clang::FileEntry *>(FE)->isNamedPipe();
}
