#include "CXCodeGenOptions.h"
#include "clang/Basic/CodeGenOptions.h"
#include <cstdio>

CXCodeGenOptions clang_CodeGenOptions_create(CXInit_Error *ErrorCode) {
  CXInit_Error Err = CXInit_NoError;
  std::unique_ptr<clang::CodeGenOptions> ptr =
      std::make_unique<clang::CodeGenOptions>();

  if (!ptr) {
    fprintf(stderr,
            "LIBCLANGEX ERROR: failed to create `clang::CodeGenOptions`\n");
    Err = CXInit_CanNotCreate;
  }

  if (ErrorCode)
    *ErrorCode = Err;

  return ptr.release();
}

void clang_CodeGenOptions_dispose(CXCodeGenOptions DO) {
  delete static_cast<clang::CodeGenOptions *>(DO);
}
