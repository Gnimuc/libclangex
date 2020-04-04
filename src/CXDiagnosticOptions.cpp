#include "CXDiagnosticOptions.h"
#include "clang/Basic/DiagnosticOptions.h"
#include <cstdio>

CXDiagnosticOptions
clang_DiagnosticOptions_create(CXDiagnosticOptions_Error *ErrorCode) {
  CXDiagnosticOptions_Error Err = CXDiagnosticOptions_NoError;
  std::unique_ptr<clang::DiagnosticOptions> ptr =
      std::make_unique<clang::DiagnosticOptions>();

  if (!ptr) {
    fprintf(stderr,
            "LIBCLANGEX ERROR: failed to create `clang::DiagnosticOptions`\n");
    Err = CXDiagnosticOptions_CanNotCreate;
  }

  if (ErrorCode)
    *ErrorCode = Err;

  return ptr.release();
}

void clang_DiagnosticOptions_dispose(CXDiagnosticOptions DO) {
  delete static_cast<clang::DiagnosticOptions *>(DO);
}
