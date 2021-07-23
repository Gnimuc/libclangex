#ifndef LIBCLANGEX_CXTYPES_H
#define LIBCLANGEX_CXTYPES_H

#include "clang-c/Platform.h"
#include <stdbool.h>
#include <time.h>

#ifdef __cplusplus
extern "C" {
#endif

// CompilerInstance
typedef void *CXCompilerInstance;

// Options
typedef void *CXTargetOptions;
typedef void *CXTargetInfo_;
typedef void *CXCodeGenOptions;
typedef void *CXHeaderSearchOptions;
typedef void *CXPreprocessorOptions;
typedef void *CXFrontendOptions;
typedef void *CXLangOptions;

// Diagnostic
typedef void *CXDiagnosticIDs;
typedef void *CXDiagnosticOptions;
typedef void *CXDiagnosticConsumer;
typedef void *CXDiagnosticsEngine;

// CompilerInvocation
typedef void *CXCompilerInvocation;

// FileManager
typedef void *CXDirectoryEntry;
typedef void *CXFileID;
typedef void *CXFileEntry;
typedef void *CXFileEntryRef; // FIXME: make it a stack value instead of opaque pointer
typedef void *CXFileManager;

// SourceManager
typedef void *CXMemoryBuffer;
typedef void *CXSourceManager;

// Preprocessor
typedef void *CXPreprocessor;
typedef void *CXHeaderSearch;

typedef enum CXTranslationUnitKind {
  CXTU_Complete,
  CXTU_Prefix,
  CXTU_Module
} CXTranslationUnitKind;

// AST
typedef void *CXASTContext;
typedef void *CXASTConsumer;
typedef void *CXType_;

// CodeGen
typedef void *CXCodeGenerator;

// Sema
typedef void *CXSema;

// Parser
typedef void *CXParser;

// Action
typedef void *CXFrontendAction;
typedef void *CXCodeGenAction;

#ifdef __cplusplus
}
#endif
#endif