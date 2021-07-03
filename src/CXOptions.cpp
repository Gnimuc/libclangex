#include "CXOptions.h"
#include "clang/Basic/CodeGenOptions.h"
#include "clang/Lex/HeaderSearchOptions.h"
#include "clang/Lex/PreprocessorOptions.h"

const char *clang_CodeGenOptions_getArgv0(CXCodeGenOptions CGO) {
  return static_cast<clang::CodeGenOptions *>(CGO)->Argv0;
}

size_t clang_CodeGenOptions_getCommandLineArgsNum(CXCodeGenOptions CGO) {
  return static_cast<clang::CodeGenOptions *>(CGO)->CommandLineArgs.size();
}

void clang_CodeGenOptions_getCommandLineArgs(CXCodeGenOptions CGO, const char **ArgsOut,
                                             size_t Num) {
  auto CmdArgs = static_cast<clang::CodeGenOptions *>(CGO)->CommandLineArgs.vec();
  std::copy_n(CmdArgs.begin(), Num, ArgsOut);
}

size_t clang_HeaderSearchOptions_GetResourceDirLength(CXHeaderSearchOptions HSO) {
  return static_cast<clang::HeaderSearchOptions *>(HSO)->ResourceDir.size();
}

void clang_HeaderSearchOptions_GetResourceDir(CXHeaderSearchOptions HSO, char *ResourcesDir,
                                              size_t N) {
  auto s = static_cast<clang::HeaderSearchOptions *>(HSO)->ResourceDir;
  std::copy_n(s.begin(), N, ResourcesDir);
}

void clang_HeaderSearchOptions_SetResourceDir(CXHeaderSearchOptions HSO,
                                              const char *ResourcesDir, size_t N) {
  static_cast<clang::HeaderSearchOptions *>(HSO)->ResourceDir =
      std::string(ResourcesDir, N);
}

size_t clang_PreprocessorOptions_getChainedIncludesNum(CXPreprocessorOptions PPO) {
  return static_cast<clang::PreprocessorOptions *>(PPO)->ChainedIncludes.size();
}

void clang_PreprocessorOptions_getChainedIncludes(CXPreprocessorOptions PPO,
                                                  const char **IncsOut, size_t Num) {
  auto &Incs = static_cast<clang::PreprocessorOptions *>(PPO)->ChainedIncludes;
  for (auto &Inc : Incs) {
    auto i = &Inc - &Incs[0];
    if (i < Num)
      IncsOut[i] = Inc.c_str();
  }
}

size_t clang_PreprocessorOptions_getIncludesNum(CXPreprocessorOptions PPO) {
  return static_cast<clang::PreprocessorOptions *>(PPO)->Includes.size();
}

void clang_PreprocessorOptions_getIncludes(CXPreprocessorOptions PPO, const char **IncsOut,
                                           size_t Num) {
  auto &Incs = static_cast<clang::PreprocessorOptions *>(PPO)->Includes;
  for (auto &Inc : Incs) {
    auto i = &Inc - &Incs[0];
    if (i < Num)
      IncsOut[i] = Inc.c_str();
  }
}

size_t clang_PreprocessorOptions_getMacroIncludesNum(CXPreprocessorOptions PPO) {
  return static_cast<clang::PreprocessorOptions *>(PPO)->MacroIncludes.size();
}

void clang_PreprocessorOptions_getMacroIncludes(CXPreprocessorOptions PPO,
                                                const char **IncsOut, size_t Num) {
  auto &Incs = static_cast<clang::PreprocessorOptions *>(PPO)->MacroIncludes;
  for (auto &Inc : Incs) {
    auto i = &Inc - &Incs[0];
    if (i < Num)
      IncsOut[i] = Inc.c_str();
  }
}