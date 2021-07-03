#ifndef LIBCLANGEX_CXOPTIONS_H
#define LIBCLANGEX_CXOPTIONS_H

#include "CXTypes.h"
#include "clang-c/Platform.h"
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

// CodeGenOptions
CINDEX_LINKAGE const char *clang_CodeGenOptions_getArgv0(CXCodeGenOptions CGO);

CINDEX_LINKAGE size_t clang_CodeGenOptions_getCommandLineArgsNum(CXCodeGenOptions CGO);

CINDEX_LINKAGE void clang_CodeGenOptions_getCommandLineArgs(CXCodeGenOptions CGO,
                                                            const char **ArgsOut,
                                                            size_t Num);

// HeaderSearchOptions
CINDEX_LINKAGE size_t
clang_HeaderSearchOptions_GetResourceDirLength(CXHeaderSearchOptions HSO);

CINDEX_LINKAGE void clang_HeaderSearchOptions_GetResourceDir(CXHeaderSearchOptions HSO,
                                                             char *ResourcesDir, size_t N);

CINDEX_LINKAGE void clang_HeaderSearchOptions_SetResourceDir(CXHeaderSearchOptions HSO,
                                                             const char *ResourcesDir,
                                                             size_t N);

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

#ifdef __cplusplus
}
#endif
#endif