#include "CXCompilerInstance.h"
#include "CXCodeGen.h"
#include "clang/Basic/TargetInfo.h"
#include "clang/CodeGen/ModuleBuilder.h"
#include "clang/Frontend/CompilerInstance.h"
#include "clang/Lex/Preprocessor.h"
#include "llvm/Support/VirtualFileSystem.h"
#include <cstdio>

CXCompilerInstance clang_CompilerInstance_create(CXInit_Error *ErrorCode) {
  CXInit_Error Err = CXInit_NoError;
  std::unique_ptr<clang::CompilerInstance> ptr =
      std::make_unique<clang::CompilerInstance>();

  if (!ptr) {
    fprintf(stderr, "LIBCLANGEX ERROR: failed to create `clang::CompilerInstance`\n");
    Err = CXInit_CanNotCreate;
  }

  if (ErrorCode)
    *ErrorCode = Err;

  return ptr.release();
}

void clang_CompilerInstance_dispose(CXCompilerInstance CI) {
  delete static_cast<clang::CompilerInstance *>(CI);
}

bool clang_CompilerInstance_hasDiagnostics(CXCompilerInstance CI) {
  return static_cast<clang::CompilerInstance *>(CI)->hasDiagnostics();
}

CXDiagnosticsEngine clang_CompilerInstance_getDiagnostics(CXCompilerInstance CI) {
  auto &Diag = static_cast<clang::CompilerInstance *>(CI)->getDiagnostics();
  return &Diag;
}

void clang_CompilerInstance_setDiagnostics(CXCompilerInstance CI,
                                           CXDiagnosticsEngine Value) {
  static_cast<clang::CompilerInstance *>(CI)->setDiagnostics(
      static_cast<clang::DiagnosticsEngine *>(Value));
}

CXDiagnosticConsumer clang_CompilerInstance_getDiagnosticClient(CXCompilerInstance CI) {
  auto &DC = static_cast<clang::CompilerInstance *>(CI)->getDiagnosticClient();
  return &DC;
}

void clang_CompilerInstance_createDiagnostics(CXCompilerInstance CI,
                                              CXDiagnosticConsumer DC,
                                              bool ShouldOwnClient) {
  return static_cast<clang::CompilerInstance *>(CI)->createDiagnostics(
      static_cast<clang::DiagnosticConsumer *>(DC), ShouldOwnClient);
}

CXIntrusiveRefCntPtr clang_CompilerInstance_createDiagnosticsEngine(CXDiagnosticOptions DO,
                                                                    CXDiagnosticConsumer DC,
                                                                    bool ShouldOwnClient,
                                                                    CXCodeGenOptions CGO) {
  auto ptr = std::make_unique<llvm::IntrusiveRefCntPtr<clang::DiagnosticsEngine>>(
      clang::CompilerInstance::createDiagnostics(
          static_cast<clang::DiagnosticOptions *>(DO),
          static_cast<clang::DiagnosticConsumer *>(DC), ShouldOwnClient,
          static_cast<clang::CodeGenOptions *>(CGO)));
  return ptr.release();
}

bool clang_CompilerInstance_hasFileManager(CXCompilerInstance CI) {
  return static_cast<clang::CompilerInstance *>(CI)->hasFileManager();
}

CXFileManager clang_CompilerInstance_getFileManager(CXCompilerInstance CI) {
  auto &FileMgr = static_cast<clang::CompilerInstance *>(CI)->getFileManager();
  return &FileMgr;
}

void clang_CompilerInstance_setFileManager(CXCompilerInstance CI, CXFileManager FM) {
  static_cast<clang::CompilerInstance *>(CI)->setFileManager(
      static_cast<clang::FileManager *>(FM));
}

CXFileManager clang_CompilerInstance_createFileManager(CXCompilerInstance CI) {
  return static_cast<clang::CompilerInstance *>(CI)->createFileManager();
}

CXFileManager clang_CompilerInstance_createFileManagerWithVOFS4PCH(
    CXCompilerInstance CI, const char *Path, time_t ModificationTime,
    CXMemoryBuffer PCHBuffer) {
  std::unique_ptr<llvm::MemoryBuffer> buffer(static_cast<llvm::MemoryBuffer *>(PCHBuffer));

  llvm::IntrusiveRefCntPtr<llvm::vfs::OverlayFileSystem> Overlay(
      new llvm::vfs::OverlayFileSystem(llvm::vfs::createPhysicalFileSystem().release()));

  llvm::IntrusiveRefCntPtr<llvm::vfs::InMemoryFileSystem> PCHIMFS(
      new llvm::vfs::InMemoryFileSystem());

  PCHIMFS->addFile(llvm::StringRef(Path), ModificationTime, std::move(buffer));
  Overlay->pushOverlay(PCHIMFS);

  return static_cast<clang::CompilerInstance *>(CI)->createFileManager(Overlay);
}

bool clang_CompilerInstance_hasSourceManager(CXCompilerInstance CI) {
  return static_cast<clang::CompilerInstance *>(CI)->hasSourceManager();
}

CXSourceManager clang_CompilerInstance_getSourceManager(CXCompilerInstance CI) {
  auto &SrcMgr = static_cast<clang::CompilerInstance *>(CI)->getSourceManager();
  return &SrcMgr;
}

void clang_CompilerInstance_setSourceManager(CXCompilerInstance CI, CXSourceManager SM) {
  static_cast<clang::CompilerInstance *>(CI)->setSourceManager(
      static_cast<clang::SourceManager *>(SM));
}

void clang_CompilerInstance_createSourceManager(CXCompilerInstance CI,
                                                CXFileManager FileMgr) {
  auto FM = static_cast<clang::FileManager *>(FileMgr);
  static_cast<clang::CompilerInstance *>(CI)->createSourceManager(*FM);
}

void clang_CompilerInstance_setInvocation(CXCompilerInstance CI,
                                          CXCompilerInvocation CInv) {
  std::shared_ptr<clang::CompilerInvocation> Invocation(
      static_cast<clang::CompilerInvocation *>(CInv));
  static_cast<clang::CompilerInstance *>(CI)->setInvocation(Invocation);
}

void clang_CompilerInstance_setTarget(CXCompilerInstance CI) {
  auto compiler = static_cast<clang::CompilerInstance *>(CI);
  compiler->setTarget(clang::TargetInfo::CreateTargetInfo(
      compiler->getDiagnostics(),
      std::make_shared<clang::TargetOptions>(compiler->getTargetOpts())));
  compiler->getTarget().adjust(compiler->getLangOpts());
}

void clang_CompilerInstance_createSema(CXCompilerInstance CI) {
  static_cast<clang::CompilerInstance *>(CI)->createSema(clang::TU_Prefix, nullptr);
}

CXSema clang_CompilerInstance_getSema(CXCompilerInstance CI) {
  auto &Sema = static_cast<clang::CompilerInstance *>(CI)->getSema();
  return &Sema;
}

void clang_CompilerInstance_setSema(CXCompilerInstance CI, CXSema S) {
  static_cast<clang::CompilerInstance *>(CI)->setSema(static_cast<clang::Sema *>(S));
}

void clang_CompilerInstance_createPreprocessor(CXCompilerInstance CI) {
  static_cast<clang::CompilerInstance *>(CI)->createPreprocessor(clang::TU_Prefix);
}

void clang_CompilerInstance_setPreprocessor(CXCompilerInstance CI, CXPreprocessor PP) {
  std::shared_ptr<clang::Preprocessor> PProc(static_cast<clang::Preprocessor *>(PP));
  static_cast<clang::CompilerInstance *>(CI)->setPreprocessor(PProc);
}

void clang_CompilerInstance_setASTContext(CXCompilerInstance CI, CXASTContext Ctx) {
  static_cast<clang::CompilerInstance *>(CI)->setASTContext(
      static_cast<clang::ASTContext *>(Ctx));
}

void clang_CompilerInstance_createASTContext(CXCompilerInstance CI) {
  static_cast<clang::CompilerInstance *>(CI)->createASTContext();
}

void clang_CompilerInstance_setCodeGenerator(CXCompilerInstance CI, CXCodeGenerator CG) {
  static_cast<clang::CompilerInstance *>(CI)->setASTConsumer(
      std::unique_ptr<clang::ASTConsumer>(static_cast<clang::CodeGenerator *>(CG)));
}