#include "CXCompilerInvocation.h"
#include "clang/Frontend/CompilerInvocation.h"
#include "clang/Frontend/Utils.h"
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

CXTargetOptions clang_CompilerInvocation_getTargetOpts(CXCompilerInvocation CI) {
  auto &TargetOpts =
      static_cast<clang::CompilerInvocation *>(CI)->getTargetOpts();
  return &TargetOpts;
}

CXCompilerInvocation clang_CompilerInvocation_createFromCommandLine(
    const char *source_filename, const char *const *command_line_args,
    int num_command_line_args, CXDiagnosticsEngine Diags,
    CXInit_Error *ErrorCode) {
  std::unique_ptr<std::vector<const char *>> Args(
      std::make_unique<std::vector<const char *>>());

  Args->insert(Args->end(), command_line_args,
               command_line_args + num_command_line_args);

  CXInit_Error Err = CXInit_NoError;
  std::unique_ptr<clang::CompilerInvocation> ptr =
      clang::createInvocationFromCommandLine(
          llvm::makeArrayRef(Args->data(), Args->data() + Args->size()),
          static_cast<clang::DiagnosticsEngine *>(Diags));

  if (!ptr) {
    fprintf(stderr,
            "LIBCLANGEX ERROR: failed to create `clang::CompilerInvocation`\n");
    Err = CXInit_CanNotCreate;
  }

  if (ErrorCode)
    *ErrorCode = Err;

  return ptr.release();
}