#include "CXOptions.h"
#include "clang/Basic/CodeGenOptions.h"

const char *clang_CodeGenOptions_getArgv0(CXCodeGenOptions CGO) {
  return static_cast<clang::CodeGenOptions *>(CGO)->Argv0;
}