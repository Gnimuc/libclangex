#include "CXCompilerInstance.h"
#include "clang/Frontend/CompilerInstance.h"
#include <cstdio>

CXCompilerInstance
clang_CompilerInstance_create(CXCompilerInstance_Error *ErrorCode) {
  CXCompilerInstance_Error Err = CXCompilerInstance_NoError;
  std::unique_ptr<clang::CompilerInstance> ci =
      std::make_unique<clang::CompilerInstance>();

  if (!ci) {
    fprintf(stderr,
            "LIBCLANGEX ERROR: failed to create `clang::CompilerInstance`\n");
    Err = CXCompilerInstance_CanNotCreate;
  }

  if (ErrorCode)
    *ErrorCode = Err;

  return ci.release();
}

void clang_CompilerInstance_dispose(CXCompilerInstance CI) {
  delete static_cast<clang::CompilerInstance *>(CI);
}
