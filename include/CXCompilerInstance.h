#ifndef LIBCLANGEX_CXCOMPILERINSTANCE_H
#define LIBCLANGEX_CXCOMPILERINSTANCE_H

#include "clang-c/Platform.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Opaque type for CompilerInstance
 *
 * It must be freed by \c clang_CompilerInstance_dispose.
 */
typedef void * CXCompilerInstance;

/**
 * Error codes for Compilation Database
 */
typedef enum  {
  /*
   * No error occurred
   */
  CXCompilerInstance_NoError = 0,

  /*
   * CompilerInstance can not be created
   */
  CXCompilerInstance_CanNotCreate = 1

} CXCompilerInstance_Error;

/**
 * Create CompilerInstance.
 * It must be freed by \c clang_CompilerInstance_dispose.
 */
CINDEX_LINKAGE CXCompilerInstance
clang_CompilerInstance_create(CXCompilerInstance_Error *ErrorCode);

/**
 * Create CompilerInstance.
 *
 * It must be freed by \c clang_CompilationDatabase_dispose.
 */
CINDEX_LINKAGE void clang_CompilerInstance_dispose(CXCompilerInstance CI);

#ifdef __cplusplus
}
#endif
#endif
