#ifndef LIBCLANGEX_CXTYPES_H
#define LIBCLANGEX_CXTYPES_H

#include "clang-c/Platform.h"
#include <stdbool.h>
#include <time.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef void *CXIntrusiveRefCntPtr;

typedef void *CXMemoryBuffer;

// Options
typedef void *CXTargetOptions;
typedef void *CXCodeGenOptions;
typedef void *CXHeaderSearchOptions;
typedef void *CXPreprocessorOptions;

// Sema
typedef void *CXSema;

// Preprocessor
typedef void *CXPreprocessor;

// AST
typedef void *CXASTUnit;
typedef void *CXASTContext;
typedef void *CXASTConsumer;

// CompilerInstance
typedef void *CXCompilerInstance;

// CompilerInvocation
typedef void *CXCompilerInvocation;

// FileManager
typedef void *CXDirectoryEntry;
typedef void *CXFileEntry;
typedef void *CXFileEntryRef; // FIXME: make it a stack value instead of opaque pointer
typedef void *CXFileManager;

// SourceManager
typedef void *CXSourceManager;

// Diagnostic
typedef void *CXDiagnosticIDs;
typedef void *CXDiagnosticOptions;
typedef void *CXDiagnosticConsumer;
typedef void *CXDiagnosticsEngine;

// CodeGen
typedef void *CXCodeGenerator;

#ifdef __cplusplus
}
#endif
#endif