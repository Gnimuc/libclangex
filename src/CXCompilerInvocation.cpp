#include "CXCompilerInvocation.h"
#include "clang/Frontend/CompilerInvocation.h"
#include <cstdio>

CXCompilerInvocation clang_CompilerInvocation_create(CXInit_Error *ErrorCode) {
  CXInit_Error Err = CXInit_NoError;
  std::unique_ptr<clang::CompilerInvocation> ptr =
      std::make_unique<clang::CompilerInvocation>();

  if (!ptr) {
    fprintf(stderr,
            "LIBCLANGEX ERROR: failed to create `clang::CompilerInvocation`\n");
    Err = CXInit_CanNotCreate;
  }

  if (ErrorCode)
    *ErrorCode = Err;

  return ptr.release();
}

void clang_CompilerInvocation_dispose(CXCompilerInvocation CI) {
  delete static_cast<clang::CompilerInvocation *>(CI);
}
