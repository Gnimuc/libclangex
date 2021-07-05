#include "CXSourceManager.h"
#include "clang/Basic/FileManager.h"
#include "clang/Basic/SourceLocation.h"
#include "clang/Basic/SourceManager.h"
#include "llvm/Support/MemoryBuffer.h"
#include <cstdio>

CXSourceManager clang_SourceManager_create(CXDiagnosticsEngine Diag, CXFileManager FileMgr,
                                           bool UserFilesAreVolatile,
                                           CXInit_Error *ErrorCode) {
  CXInit_Error Err = CXInit_NoError;
  std::unique_ptr<clang::SourceManager> ptr = std::make_unique<clang::SourceManager>(
      *(static_cast<clang::DiagnosticsEngine *>(Diag)),
      *(static_cast<clang::FileManager *>(FileMgr)), UserFilesAreVolatile);

  if (!ptr) {
    fprintf(stderr, "LIBCLANGEX ERROR: failed to create `clang::SourceManager`\n");
    Err = CXInit_CanNotCreate;
  }

  if (ErrorCode)
    *ErrorCode = Err;

  return ptr.release();
}

void clang_SourceManager_dispose(CXSourceManager SM) {
  delete static_cast<clang::SourceManager *>(SM);
}

CXFileID clang_SourceManager_createFileIDFromMemoryBuffer(CXSourceManager SM,
                                                          CXMemoryBuffer MB) {
  std::unique_ptr<clang::FileID> ptr =
      std::make_unique<clang::FileID>(static_cast<clang::SourceManager *>(SM)->createFileID(
          std::unique_ptr<llvm::MemoryBuffer>(static_cast<llvm::MemoryBuffer *>(MB)),
          clang::SrcMgr::C_User));
  return ptr.release();
}

CXFileID clang_SourceManager_createFileIDFromFileEntry(CXSourceManager SM, CXFileEntry FE) {
  std::unique_ptr<clang::FileID> ptr =
      std::make_unique<clang::FileID>(static_cast<clang::SourceManager *>(SM)->createFileID(
          static_cast<clang::FileEntry *>(FE), clang::SourceLocation(),
          clang::SrcMgr::C_User));
  return ptr.release();
}

CXFileID clang_SourceManager_getMainFileID(CXSourceManager SM) {
  std::unique_ptr<clang::FileID> ptr = std::make_unique<clang::FileID>(
      static_cast<clang::SourceManager *>(SM)->getMainFileID());
  return ptr.release();
}

void clang_FileID_dispose(CXFileID FID) { delete static_cast<clang::FileID *>(FID); }

void clang_SourceManager_setMainFileID(CXSourceManager SM, CXFileID FID) {
  static_cast<clang::SourceManager *>(SM)->setMainFileID(
      *static_cast<clang::FileID *>(FID));
}

void clang_SourceManager_overrideFileContents(CXSourceManager SM, CXFileEntry FE,
                                              CXMemoryBuffer MB) {
  static_cast<clang::SourceManager *>(SM)->overrideFileContents(
      static_cast<clang::FileEntry *>(FE),
      std::unique_ptr<llvm::MemoryBuffer>(static_cast<llvm::MemoryBuffer *>(MB)));
}