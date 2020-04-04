#include "CXDiagnostic.h"
#include "clang/Basic/Diagnostic.h"
#include "llvm/ADT/IntrusiveRefCntPtr.h"
#include <cstdio>

CXDiagnosticConsumer
clang_DiagnosticConsumer_create(CXDiagnosticConsumer_Error *ErrorCode) {
  CXDiagnosticConsumer_Error Err = CXDiagnosticConsumer_NoError;
  std::unique_ptr<clang::DiagnosticConsumer> ptr =
      std::make_unique<clang::DiagnosticConsumer>();

  if (!ptr) {
    fprintf(stderr,
            "LIBCLANGEX ERROR: failed to create `clang::DiagnosticConsumer`\n");
    Err = CXDiagnosticConsumer_CanNotCreate;
  }

  if (ErrorCode)
    *ErrorCode = Err;

  return ptr.release();
}

void clang_DiagnosticConsumer_dispose(CXDiagnosticConsumer DC) {
  delete static_cast<clang::DiagnosticConsumer *>(DC);
}

CXDiagnosticsEngine
clang_DiagnosticsEngineIntrusiveRefCntPtr_get(CXIntrusiveRefCntPtr ptr) {
  return static_cast<llvm::IntrusiveRefCntPtr<clang::DiagnosticsEngine> *>(ptr)
      ->get();
}

void clang_DiagnosticsEngineIntrusiveRefCntPtr_dispose(CXIntrusiveRefCntPtr ptr) {
  delete static_cast<llvm::IntrusiveRefCntPtr<clang::DiagnosticsEngine> *>(ptr);
}
