#include "CXOptions.h"
#include "clang/Basic/CodeGenOptions.h"
#include "clang/Basic/TargetInfo.h"
#include "clang/Basic/TargetOptions.h"
#include "clang/Frontend/FrontendOptions.h"
#include "clang/Lex/HeaderSearchOptions.h"
#include "clang/Lex/PreprocessorOptions.h"

CXTargetOptions clang_TargetOptions_create(CXInit_Error *ErrorCode) {
  CXInit_Error Err = CXInit_NoError;
  std::unique_ptr<clang::TargetOptions> ptr = std::make_unique<clang::TargetOptions>();

  if (!ptr) {
    fprintf(stderr, "LIBCLANGEX ERROR: failed to create `clang::TargetOptions`\n");
    Err = CXInit_CanNotCreate;
  }

  if (ErrorCode)
    *ErrorCode = Err;

  return ptr.release();
}

void clang_TargetOptions_dispose(CXTargetOptions TO) {
  delete static_cast<clang::TargetOptions *>(TO);
}

void clang_TargetOptions_setTriple(CXTargetOptions TO, const char *TripleStr, size_t Num) {
  static_cast<clang::TargetOptions *>(TO)->Triple = std::string(TripleStr, Num);
}

CXTargetInfo clang_TargetInfo_CreateTargetInfo(CXDiagnosticsEngine DE,
                                               CXTargetOptions Opts) {
  return clang::TargetInfo::CreateTargetInfo(
      *static_cast<clang::DiagnosticsEngine *>(DE),
      std::shared_ptr<clang::TargetOptions>(static_cast<clang::TargetOptions *>(Opts)));
}

CXCodeGenOptions clang_CodeGenOptions_create(CXInit_Error *ErrorCode) {
  CXInit_Error Err = CXInit_NoError;
  std::unique_ptr<clang::CodeGenOptions> ptr = std::make_unique<clang::CodeGenOptions>();

  if (!ptr) {
    fprintf(stderr, "LIBCLANGEX ERROR: failed to create `clang::CodeGenOptions`\n");
    Err = CXInit_CanNotCreate;
  }

  if (ErrorCode)
    *ErrorCode = Err;

  return ptr.release();
}

void clang_CodeGenOptions_dispose(CXCodeGenOptions DO) {
  delete static_cast<clang::CodeGenOptions *>(DO);
}

const char *clang_CodeGenOptions_getArgv0(CXCodeGenOptions CGO) {
  return static_cast<clang::CodeGenOptions *>(CGO)->Argv0;
}

size_t clang_CodeGenOptions_getCommandLineArgsNum(CXCodeGenOptions CGO) {
  // return static_cast<clang::CodeGenOptions *>(CGO)->CommandLineArgs.size();
  return 0; // seal the usage, see
            // https://llvm.discourse.group/t/confused-about-the-usage-of-arrayref-in-clang/3807
}

void clang_CodeGenOptions_getCommandLineArgs(CXCodeGenOptions CGO, const char **ArgsOut,
                                             size_t Num) {
  auto CmdArgs = static_cast<clang::CodeGenOptions *>(CGO)->CommandLineArgs;
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

size_t clang_FrontendOptions_getModulesEmbedFilesNum(CXFrontendOptions Opts) {
  return static_cast<clang::FrontendOptions *>(Opts)->ModulesEmbedFiles.size();
}

void clang_FrontendOptions_getModulesEmbedFiles(CXFrontendOptions Opts,
                                                const char **FileNames, size_t Num) {
  auto &Files = static_cast<clang::FrontendOptions *>(Opts)->ModulesEmbedFiles;
  for (auto &File : Files) {
    auto i = &File - &Files[0];
    if (i < Num)
      FileNames[i] = File.c_str();
  }
}