#include "CXFileManager.h"
#include "clang/Basic/FileManager.h"
#include "llvm/Support/Errc.h"
#include "llvm/Support/MemoryBuffer.h"
#include <cstdio>

CXFileManager clang_FileManager_create(CXInit_Error *ErrorCode) {
  CXInit_Error Err = CXInit_NoError;
  std::unique_ptr<clang::FileManager> ptr =
      std::make_unique<clang::FileManager>(clang::FileSystemOptions());

  if (!ptr) {
    fprintf(stderr, "LIBCLANGEX ERROR: failed to create `clang::FileManager`\n");
    Err = CXInit_CanNotCreate;
  }

  if (ErrorCode)
    *ErrorCode = Err;

  return ptr.release();
}

void clang_FileManager_dispose(CXFileManager FM) {
  delete static_cast<clang::FileManager *>(FM);
}

CXDirectoryEntry clang_FileManager_getDirectory(CXFileManager FM, const char *DirName,
                                                bool CacheFailure) {
  return const_cast<clang::DirectoryEntry *>(
      *static_cast<clang::FileManager *>(FM)->getDirectory(llvm::StringRef(DirName),
                                                           CacheFailure));
}

void clang_FileManager_PrintStats(CXFileManager FM) {
  static_cast<clang::FileManager *>(FM)->PrintStats();
}

CXMemoryBuffer clang_FileManager_getBufferForFile(CXFileManager FM, CXFileEntry FE,
                                                  bool isVolatile,
                                                  bool RequiresNullTerminator) {
  auto MB = static_cast<clang::FileManager *>(FM)->getBufferForFile(
      static_cast<clang::FileEntry *>(FE), isVolatile, RequiresNullTerminator);
  return MB->release();
}

CXFileEntryRef clang_FileManager_getFileRef(CXFileManager FM, const char *Filename,
                                            bool OpenFile, bool CacheFailure) {
  auto File =
      static_cast<clang::FileManager *>(FM)->getFileRef(Filename, OpenFile, CacheFailure);
  if (!File) {
    std::error_code EC = llvm::errorToErrorCode(File.takeError());
    if (EC != llvm::errc::no_such_file_or_directory && EC != llvm::errc::invalid_argument &&
        EC != llvm::errc::is_a_directory && EC != llvm::errc::not_a_directory) {
      llvm::errs() << "Cannot open file: " << Filename << " " << EC.message() << "\n";
    } else {
      llvm::errs() << Filename << " " << EC.message() << "\n";
    }
    return nullptr;
  }
  std::unique_ptr<clang::FileEntryRef> ptr = std::make_unique<clang::FileEntryRef>(*File);
  return ptr.release();
}

void clang_FileEntryRef_dispose(CXFileEntryRef FER) {
  delete static_cast<clang::FileEntryRef *>(FER);
}

CXFileEntry clang_FileEntryRef_getFileEntry(CXFileEntryRef FER) {
  auto &FE = const_cast<clang::FileEntry &>(
      static_cast<clang::FileEntryRef *>(FER)->getFileEntry());
  return &FE;
}

const char *clang_DirectoryEntry_getName(CXDirectoryEntry DE) {
  return static_cast<clang::DirectoryEntry *>(DE)->getName().data();
}

const char *clang_FileEntry_getName(CXFileEntry FE) {
  return static_cast<clang::FileEntry *>(FE)->getName().data();
}

const char *clang_FileEntry_tryGetRealPathName(CXFileEntry FE) {
  return static_cast<clang::FileEntry *>(FE)->tryGetRealPathName().data();
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
  return const_cast<clang::DirectoryEntry *>(static_cast<clang::FileEntry *>(FE)->getDir());
}

bool clang_FileEntry_isNamedPipe(CXFileEntry FE) {
  return static_cast<clang::FileEntry *>(FE)->isNamedPipe();
}
