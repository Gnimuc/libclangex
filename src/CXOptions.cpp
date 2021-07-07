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

void clang_TargetOptions_PrintStats(CXTargetOptions TO) {
  auto Opts = static_cast<clang::TargetOptions *>(TO);
  llvm::errs() << "\n*** TargetOptions Stats:\n";
  llvm::errs() << "  Triple: " << Opts->Triple << "\n";
  llvm::errs() << "  HostTriple: " << Opts->HostTriple << "\n";
  llvm::errs() << "  CPU: " << Opts->CPU << "\n";
  llvm::errs() << "  FPMath: " << Opts->FPMath << "\n";
  llvm::errs() << "  ABI: " << Opts->ABI << "\n";
  llvm::errs() << "  EABIVersion: " << static_cast<int>(Opts->EABIVersion) << "\n";
  llvm::errs() << "  LinkerVersion: " << Opts->LinkerVersion << "\n";

  llvm::errs() << "  FeaturesAsWritten: \n";
  for (const auto &Feature : Opts->FeaturesAsWritten)
    llvm::errs() << "    " << Feature << "\n";

  llvm::errs() << "  Features: \n";
  for (const auto &Feature : Opts->Features)
    llvm::errs() << "    " << Feature << "\n";

  llvm::errs() << "  ForceEnableInt128: " << Opts->ForceEnableInt128 << "\n";
  llvm::errs() << "  NVPTXUseShortPointers: " << Opts->NVPTXUseShortPointers << "\n";
  llvm::errs() << "  CodeModel: " << Opts->CodeModel << "\n";
  llvm::errs() << "  SDKVersion: " << Opts->SDKVersion << "\n";
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

void clang_CodeGenOptions_PrintStats(CXCodeGenOptions CGO) {
  auto Opts = static_cast<clang::CodeGenOptions *>(CGO);
  llvm::errs() << "\n*** CodeGenOptions Stats:\n";
  llvm::errs() << "  CodeModel: " << Opts->CodeModel << "\n";
  llvm::errs() << "  DebugPass: " << Opts->DebugPass << "\n";
  llvm::errs() << "  FloatABI: " << Opts->FloatABI << "\n";
  llvm::errs() << "  LimitFloatPrecision: " << Opts->LimitFloatPrecision << "\n";
  llvm::errs() << "  MainFileName: " << Opts->MainFileName << "\n";
  llvm::errs() << "  ThreadModel: " << Opts->ThreadModel << "\n";
  llvm::errs() << "  TrapFuncName: " << Opts->TrapFuncName << "\n";

  llvm::errs() << "  DependentLibraries: \n";
  for (const auto &Dep : Opts->DependentLibraries)
    llvm::errs() << "    " << Dep << "\n";

  llvm::errs() << "  LinkerOptions: \n";
  for (const auto &Opt : Opts->LinkerOptions)
    llvm::errs() << "    " << Opt << "\n";

  llvm::errs() << "  CudaGpuBinaryFileName: " << Opts->CudaGpuBinaryFileName << "\n";
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

void clang_HeaderSearchOptions_PrintStats(CXHeaderSearchOptions HSO) {
  auto Opts = static_cast<clang::HeaderSearchOptions *>(HSO);
  llvm::errs() << "\n*** HeaderSearchOptions Stats:\n";
  llvm::errs() << "  Sysroot: " << Opts->Sysroot << "\n";

  llvm::errs() << "  UserEntries: \n";
  for (const auto &UE : Opts->UserEntries)
    llvm::errs() << "    " << UE.Path << "  (IsFramework:" << UE.IsFramework
                 << "; IgnoreSysRoot:" << UE.IgnoreSysRoot << ")\n";

  llvm::errs() << "  SystemHeaderPrefixes: \n";
  for (const auto &PF : Opts->SystemHeaderPrefixes)
    llvm::errs() << "    " << PF.Prefix << "  (IsSystemHeader:" << PF.IsSystemHeader
                 << ")\n";

  llvm::errs() << "  ResourceDir: " << Opts->ResourceDir << "\n";
  llvm::errs() << "  ModuleCachePath: " << Opts->ModuleCachePath << "\n";
  llvm::errs() << "  ModuleUserBuildPath: " << Opts->ModuleUserBuildPath << "\n";

  llvm::errs() << "  PrebuiltModulePaths: \n";
  for (const auto &Path : Opts->PrebuiltModulePaths)
    llvm::errs() << "    " << Path << "\n";

  llvm::errs() << "  ModuleFormat: " << Opts->ModuleFormat << "\n";

  llvm::errs() << "  VFSOverlayFiles: \n";
  for (const auto &VFS : Opts->VFSOverlayFiles)
    llvm::errs() << "    " << VFS << "\n";

  llvm::errs() << "  Options: \n";
  llvm::errs() << "    UseBuiltinIncludes: " << Opts->UseBuiltinIncludes << "\n";
  llvm::errs() << "    UseStandardSystemIncludes: " << Opts->UseStandardSystemIncludes
               << "\n";
  llvm::errs() << "    UseStandardCXXIncludes: " << Opts->UseStandardCXXIncludes << "\n";
  llvm::errs() << "    UseLibcxx: " << Opts->UseLibcxx << "\n";
  llvm::errs() << "    Verbose: " << Opts->Verbose << "\n";
  llvm::errs() << "    ModulesValidateSystemHeaders: " << Opts->ModulesValidateSystemHeaders
               << "\n";
  llvm::errs() << "    ValidateASTInputFilesContent: " << Opts->ValidateASTInputFilesContent
               << "\n";
  llvm::errs() << "    UseDebugInfo: " << Opts->UseDebugInfo << "\n";
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

void clang_PreprocessorOptions_PrintStats(CXPreprocessorOptions PPO) {
  auto Opts = static_cast<clang::PreprocessorOptions *>(PPO);
  llvm::errs() << "\n*** PreprocessorOptions Stats:\n";
  llvm::errs() << "  Macros: \n";
  for (const auto &M : Opts->Macros)
    llvm::errs() << "    " << M.first << "  (isUndef:" << M.second << ")\n";

  llvm::errs() << "  Includes: \n";
  for (const auto &Inc : Opts->Includes)
    llvm::errs() << "    " << Inc << "\n";

  llvm::errs() << "  MacroIncludes: \n";
  for (const auto &Inc : Opts->MacroIncludes)
    llvm::errs() << "    " << Inc << "\n";

  llvm::errs() << "  ImplicitPCHInclude: " << Opts->ImplicitPCHInclude << "\n";

  llvm::errs() << "  ChainedIncludes: \n";
  for (const auto &Inc : Opts->ChainedIncludes)
    llvm::errs() << "    " << Inc << "\n";

  llvm::errs() << "  Options: \n";
  llvm::errs() << "    UsePredefines: " << Opts->UsePredefines << "\n";
  llvm::errs() << "    DetailedRecord: " << Opts->DetailedRecord << "\n";
  llvm::errs() << "    SingleFileParseMode: " << Opts->SingleFileParseMode << "\n";

  llvm::errs() << "  RemappedFiles: \n";
  for (const auto &RF : Opts->RemappedFiles)
    llvm::errs() << "    " << RF.first << "  ->  " << RF.second << "\n";
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

void clang_FrontendOptions_PrintStats(CXFrontendOptions FEO) {
  auto Opts = static_cast<clang::FrontendOptions *>(FEO);
  llvm::errs() << "\n*** FrontendOptions Stats:\n";
  llvm::errs() << "  Inputs: \n";
  for (const auto &IF : Opts->Inputs)
    llvm::errs() << "    " << IF.getFile() << "  (IsSystem:" << IF.isSystem()
                 << "; IsBuffer:" << IF.isBuffer() << "; IsEmpty:" << IF.isEmpty()
                 << "; IsPreprocessed:" << IF.isPreprocessed() << ")\n";

  llvm::errs() << "  OutputFile: " << Opts->OutputFile << "\n";

  llvm::errs() << "  ModuleMapFiles: \n";
  for (const auto &MF : Opts->ModuleMapFiles)
    llvm::errs() << "    " << MF << "\n";

  llvm::errs() << "  ModuleFiles: \n";
  for (const auto &MF : Opts->ModuleFiles)
    llvm::errs() << "    " << MF << "\n";

  llvm::errs() << "  ModulesEmbedFiles: \n";
  for (const auto &MF : Opts->ModulesEmbedFiles)
    llvm::errs() << "    " << MF << "\n";

  llvm::errs() << "  LLVMArgs: \n";
  for (const auto &Arg : Opts->LLVMArgs)
    llvm::errs() << "    " << Arg << "\n";

  llvm::errs() << "  AuxTriple: " << Opts->AuxTriple << "\n";
  llvm::errs() << "  StatsFile: " << Opts->StatsFile << "\n";

  llvm::errs() << "  Options: \n";
  llvm::errs() << "    ShowHelp: " << Opts->ShowHelp << "\n";
  llvm::errs() << "    ShowStats: " << Opts->ShowStats << "\n";
  llvm::errs() << "    ShowTimers: " << Opts->ShowTimers << "\n";
  llvm::errs() << "    PrintSupportedCPUs: " << Opts->PrintSupportedCPUs << "\n";
  llvm::errs() << "    ShowVersion: " << Opts->ShowVersion << "\n";
  llvm::errs() << "    SkipFunctionBodies: " << Opts->SkipFunctionBodies << "\n";
  llvm::errs() << "    ASTDumpDecls: " << Opts->ASTDumpDecls << "\n";
  llvm::errs() << "    ASTDumpAll: " << Opts->ASTDumpAll << "\n";
  llvm::errs() << "    ASTDumpLookups: " << Opts->ASTDumpLookups << "\n";
  llvm::errs() << "    ASTDumpDeclTypes: " << Opts->ASTDumpDeclTypes << "\n";
  llvm::errs() << "    ModulesEmbedAllFiles: " << Opts->ModulesEmbedAllFiles << "\n";
  llvm::errs() << "    UseTemporary: " << Opts->UseTemporary << "\n";
  llvm::errs() << "    IsSystemModule: " << Opts->IsSystemModule << "\n";
}
