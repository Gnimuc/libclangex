#include "CXSourceManager.h"
#include "clang/Basic/FileManager.h"
#include "clang/Basic/SourceManager.h"
#include "llvm/Support/MemoryBuffer.h"
#include <cstdio>

CXSourceManager clang_SourceManager_create(CXDiagnosticsEngine Diag, CXFileManager FileMgr,
                                           bool UserFilesAreVolatile,
                                           CXInit_Error *ErrorCode) {
  CXInit_Error Err = CXInit_NoError;
  auto ptr = std::unique_ptr<clang::SourceManager>(new clang::SourceManager(
      *(static_cast<clang::DiagnosticsEngine *>(Diag)),
      *(static_cast<clang::FileManager *>(FileMgr)), UserFilesAreVolatile));

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

void clang_SourceManager_overrideFileContents(CXSourceManager SM, CXFileEntry FE,
                                              CXMemoryBuffer MB) {
  auto SourceMgr = static_cast<clang::SourceManager *>(SM);
  SourceMgr->overrideFileContents(
      static_cast<clang::FileEntry *>(FE),
      std::unique_ptr<llvm::MemoryBuffer>(static_cast<llvm::MemoryBuffer *>(MB)));
}

void clang_SourceManager_createAndSetMainFileID(CXSourceManager SM, CXFileEntry FE) {
  auto SourceMgr = static_cast<clang::SourceManager *>(SM);
  SourceMgr->setMainFileID(SourceMgr->createFileID(static_cast<clang::FileEntry *>(FE),
                                                   clang::SourceLocation(),
                                                   clang::SrcMgr::C_User));
}

int clang_SourceManager_getMainFileID_HashValue(CXSourceManager SM) {
  return static_cast<clang::SourceManager *>(SM)->getMainFileID().getHashValue();
}