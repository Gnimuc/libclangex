#include "CXSourceManager.h"
#include "clang/Basic/SourceManager.h"
#include <cstdio>

CXSourceManager clang_SourceManager_create(CXInit_Error *ErrorCode,
                                           CXDiagnosticsEngine Diag, CXFileManager FileMgr,
                                           bool UserFilesAreVolatile) {
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
