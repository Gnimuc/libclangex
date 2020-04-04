#include "CXCompilerInstance.h"
#include "clang/Frontend/CompilerInstance.h"
#include <cstdio>

CXCompilerInstance
clang_CompilerInstance_create(CXCompilerInstance_Error *ErrorCode) {
  CXCompilerInstance_Error Err = CXCompilerInstance_NoError;
  std::unique_ptr<clang::CompilerInstance> ptr =
      std::make_unique<clang::CompilerInstance>();

  if (!ptr) {
    fprintf(stderr,
            "LIBCLANGEX ERROR: failed to create `clang::CompilerInstance`\n");
    Err = CXCompilerInstance_CanNotCreate;
  }

  if (ErrorCode)
    *ErrorCode = Err;

  return ptr.release();
}

void clang_CompilerInstance_dispose(CXCompilerInstance CI) {
  delete static_cast<clang::CompilerInstance *>(CI);
}

bool clang_CompilerInstance_hasDiagnostics(CXCompilerInstance CI) {
  return static_cast<clang::CompilerInstance *>(CI)->hasDiagnostics();
}

CXDiagnosticsEngine
clang_CompilerInstance_getDiagnostics(CXCompilerInstance CI) {
  return &(static_cast<clang::CompilerInstance *>(CI)->getDiagnostics());
}

void clang_CompilerInstance_setDiagnostics(CXCompilerInstance CI,
                                           CXDiagnosticsEngine Value) {
  static_cast<clang::CompilerInstance *>(CI)->setDiagnostics(
      static_cast<clang::DiagnosticsEngine *>(Value));
}

CXDiagnosticConsumer
clang_CompilerInstance_getDiagnosticClient(CXCompilerInstance CI) {
  return &(static_cast<clang::CompilerInstance *>(CI)->getDiagnosticClient());
}

CINDEX_LINKAGE void clang_CompilerInstance_createDiagnostics(
    CXCompilerInstance CI, CXDiagnosticConsumer DC, bool ShouldOwnClient) {
  return static_cast<clang::CompilerInstance *>(CI)->createDiagnostics(
      static_cast<clang::DiagnosticConsumer *>(DC), ShouldOwnClient);
}

CINDEX_LINKAGE CXIntrusiveRefCntPtr
clang_CompilerInstance_createDiagnosticsEngine(CXDiagnosticOptions DO,
                                               CXDiagnosticConsumer DC,
                                               bool ShouldOwnClient,
                                               CXCodeGenOptions CGO) {
  std::unique_ptr<llvm::IntrusiveRefCntPtr<clang::DiagnosticsEngine>> ptr =
      std::make_unique<llvm::IntrusiveRefCntPtr<clang::DiagnosticsEngine>>(
          clang::CompilerInstance::createDiagnostics(
              static_cast<clang::DiagnosticOptions *>(DO),
              static_cast<clang::DiagnosticConsumer *>(DC), ShouldOwnClient,
              static_cast<clang::CodeGenOptions *>(CGO)));
  return ptr.release();
}
