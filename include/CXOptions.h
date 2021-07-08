#ifndef LIBCLANGEX_CXOPTIONS_H
#define LIBCLANGEX_CXOPTIONS_H

#include "CXError.h"
#include "CXTypes.h"
#include "clang-c/Platform.h"
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

// TargetOptions
CINDEX_LINKAGE CXTargetOptions clang_TargetOptions_create(CXInit_Error *ErrorCode);

CINDEX_LINKAGE void clang_TargetOptions_dispose(CXTargetOptions TO);

CINDEX_LINKAGE void clang_TargetOptions_setTriple(CXTargetOptions TO, const char *TripleStr,
                                                  size_t Num);

CINDEX_LINKAGE void clang_TargetOptions_PrintStats(CXTargetOptions TO);

CINDEX_LINKAGE CXTargetInfo clang_TargetInfo_CreateTargetInfo(CXDiagnosticsEngine DE,
                                                              CXTargetOptions Opts);

// CodeGenOptions
CINDEX_LINKAGE CXCodeGenOptions clang_CodeGenOptions_create(CXInit_Error *ErrorCode);

CINDEX_LINKAGE void clang_CodeGenOptions_dispose(CXCodeGenOptions DO);

CINDEX_LINKAGE const char *clang_CodeGenOptions_getArgv0(CXCodeGenOptions CGO);

CINDEX_LINKAGE size_t clang_CodeGenOptions_getCommandLineArgsNum(CXCodeGenOptions CGO);

CINDEX_LINKAGE void clang_CodeGenOptions_getCommandLineArgs(CXCodeGenOptions CGO,
                                                            const char **ArgsOut,
                                                            size_t Num);

CINDEX_LINKAGE void clang_CodeGenOptions_PrintStats(CXCodeGenOptions CGO);

// HeaderSearchOptions
CINDEX_LINKAGE size_t
clang_HeaderSearchOptions_GetResourceDirLength(CXHeaderSearchOptions HSO);

CINDEX_LINKAGE void clang_HeaderSearchOptions_GetResourceDir(CXHeaderSearchOptions HSO,
                                                             char *ResourcesDir, size_t N);

CINDEX_LINKAGE void clang_HeaderSearchOptions_SetResourceDir(CXHeaderSearchOptions HSO,
                                                             const char *ResourcesDir,
                                                             size_t N);

CINDEX_LINKAGE void clang_HeaderSearchOptions_PrintStats(CXHeaderSearchOptions HSO);

// PreprocessorOptions
CINDEX_LINKAGE size_t
clang_PreprocessorOptions_getChainedIncludesNum(CXPreprocessorOptions PPO);

CINDEX_LINKAGE void clang_PreprocessorOptions_getChainedIncludes(CXPreprocessorOptions PPO,
                                                                 const char **IncsOut,
                                                                 size_t Num);

CINDEX_LINKAGE size_t clang_PreprocessorOptions_getIncludesNum(CXPreprocessorOptions PPO);

CINDEX_LINKAGE void clang_PreprocessorOptions_getIncludes(CXPreprocessorOptions PPO,
                                                          const char **IncsOut, size_t Num);

CINDEX_LINKAGE size_t
clang_PreprocessorOptions_getMacroIncludesNum(CXPreprocessorOptions PPO);

CINDEX_LINKAGE void clang_PreprocessorOptions_getMacroIncludes(CXPreprocessorOptions PPO,
                                                               const char **IncsOut,
                                                               size_t Num);

CINDEX_LINKAGE void clang_PreprocessorOptions_PrintStats(CXPreprocessorOptions PPO);

// FrontendOptions
CINDEX_LINKAGE size_t clang_FrontendOptions_getModulesEmbedFilesNum(CXFrontendOptions Opts);

CINDEX_LINKAGE void clang_FrontendOptions_getModulesEmbedFiles(CXFrontendOptions Opts,
                                                               const char **FileNames,
                                                               size_t Num);

CINDEX_LINKAGE void clang_FrontendOptions_PrintStats(CXFrontendOptions FEO);

// LangOptions
CINDEX_LINKAGE void clang_LangOptions_PrintStats(CXLangOptions LO);

#ifdef __cplusplus
}
#endif
#endif