#ifndef LIBCLANGEX_CXCOMPILERINVOCATION_H
#define LIBCLANGEX_CXCOMPILERINVOCATION_H

#include "CXError.h"
#include "CXTypes.h"
#include "clang-c/Platform.h"

#ifdef __cplusplus
extern "C" {
#endif

CINDEX_LINKAGE CXCompilerInvocation
clang_CompilerInvocation_create(CXInit_Error *ErrorCode);

CINDEX_LINKAGE void clang_CompilerInvocation_dispose(CXCompilerInvocation CI);

CINDEX_LINKAGE CXCompilerInvocation clang_CompilerInvocation_createFromCommandLine(
    const char **command_line_args_with_src, int num_command_line_args,
    CXDiagnosticsEngine Diags, CXInit_Error *ErrorCode);

// Options
CINDEX_LINKAGE CXTargetOptions
clang_CompilerInvocation_getTargetOpts(CXCompilerInvocation CI);

CINDEX_LINKAGE CXCodeGenOptions
clang_CompilerInvocation_getCodeGenOpts(CXCompilerInvocation CI);

CINDEX_LINKAGE CXCompilerInvocation clang_CompilerInvocation_createFromCommandLine(
    const char *source_filename, const char *const *command_line_args,
    int num_command_line_args, CXDiagnosticsEngine Diags, CXInit_Error *ErrorCode);

#ifdef __cplusplus
}
#endif
#endif
