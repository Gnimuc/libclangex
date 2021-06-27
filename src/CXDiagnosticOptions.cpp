#include "CXDiagnosticOptions.h"
#include "clang/Basic/DiagnosticOptions.h"
#include <cstdio>

CXDiagnosticOptions clang_DiagnosticOptions_create(CXInit_Error *ErrorCode) {
  CXInit_Error Err = CXInit_NoError;
  std::unique_ptr<clang::DiagnosticOptions> ptr =
      std::make_unique<clang::DiagnosticOptions>();

  if (!ptr) {
    fprintf(stderr, "LIBCLANGEX ERROR: failed to create `clang::DiagnosticOptions`\n");
    Err = CXInit_CanNotCreate;
  }

  if (ErrorCode)
    *ErrorCode = Err;

  return ptr.release();
}

void clang_DiagnosticOptions_dispose(CXDiagnosticOptions DO) {
  delete static_cast<clang::DiagnosticOptions *>(DO);
}
