#include "clang-ex/CXDiagnostic.h"
#include "clang/Basic/Diagnostic.h"
#include "clang/Basic/DiagnosticIDs.h"
#include "clang/Basic/DiagnosticOptions.h"
#include "clang/Frontend/TextDiagnosticPrinter.h"
#include "llvm/ADT/IntrusiveRefCntPtr.h"
#include "llvm/Support/raw_ostream.h"
#include <cstdio>

// DiagnosticIDs

CXDiagnosticIDs clang_DiagnosticIDs_create(CXInit_Error *ErrorCode) {
  CXInit_Error Err = CXInit_NoError;
  std::unique_ptr<clang::DiagnosticIDs> ptr = std::make_unique<clang::DiagnosticIDs>();

  if (!ptr) {
    fprintf(stderr, "LIBCLANGEX ERROR: failed to create `clang::DiagnosticIDs`\n");
    Err = CXInit_CanNotCreate;
  }

  if (ErrorCode)
    *ErrorCode = Err;

  return ptr.release();
}

void clang_DiagnosticIDs_dispose(CXDiagnosticIDs ID) {
  delete static_cast<clang::DiagnosticIDs *>(ID);
}

// DiagnosticOptions

CXDiagnosticOptions clang_DiagnosticOptions_create(CXInit_Error *ErrorCode) {
  CXInit_Error Err = CXInit_NoError;
  std::unique_ptr<clang::DiagnosticOptions> ptr =
      std::make_unique<clang::DiagnosticOptions>();

  if (!ptr) {
    fprintf(stderr, "LIBCLANGEX ERROR: failed to create `clang::DiagnosticOptions`\n");
    Err = CXInit_CanNotCreate;
  }

  if (ErrorCode)
    *ErrorCode = Err;

  return ptr.release();
}

void clang_DiagnosticOptions_dispose(CXDiagnosticOptions DO) {
  delete static_cast<clang::DiagnosticOptions *>(DO);
}

void clang_DiagnosticOptions_setShowColors(CXDiagnosticOptions DO, bool ShowColors) {
  static_cast<clang::DiagnosticOptions *>(DO)->ShowColors = ShowColors;
}

void clang_DiagnosticOptions_setShowPresumedLoc(CXDiagnosticOptions DO,
                                                bool ShowPresumedLoc) {
  static_cast<clang::DiagnosticOptions *>(DO)->ShowPresumedLoc = ShowPresumedLoc;
}

void clang_DiagnosticOptions_PrintStats(CXDiagnosticOptions DO) {
  auto Opts = static_cast<clang::DiagnosticOptions *>(DO);
  llvm::errs() << "\n*** DiagnosticOptions Stats:\n";
  llvm::errs() << "  DiagnosticLogFile: " << Opts->DiagnosticLogFile << "\n";
  llvm::errs() << "  DiagnosticSerializationFile: " << Opts->DiagnosticSerializationFile
               << "\n";

  llvm::errs() << "  Warnings: \n";
  for (const auto &WN : Opts->Warnings)
    llvm::errs() << "    " << WN << "\n";

  llvm::errs() << "  UndefPrefixes: \n";
  for (const auto &UP : Opts->UndefPrefixes)
    llvm::errs() << "    " << UP << "\n";

  llvm::errs() << "  Remarks: \n";
  for (const auto &RM : Opts->Remarks)
    llvm::errs() << "    " << RM << "\n";

  llvm::errs() << "  VerifyPrefixes: \n";
  for (const auto &VP : Opts->VerifyPrefixes)
    llvm::errs() << "    " << VP << "\n";

  llvm::errs() << "  Options: \n";
  llvm::errs() << "    ShowColors: " << Opts->ShowColors << "\n";
  llvm::errs() << "    ShowPresumedLoc: " << Opts->ShowPresumedLoc << "\n";
}

// DiagnosticConsumer

CXDiagnosticConsumer clang_IgnoringDiagConsumer_create(CXInit_Error *ErrorCode) {
  CXInit_Error Err = CXInit_NoError;
  std::unique_ptr<clang::DiagnosticConsumer> ptr =
      std::make_unique<clang::IgnoringDiagConsumer>();

  if (!ptr) {
    fprintf(stderr, "LIBCLANGEX ERROR: failed to create `clang::IgnoringDiagConsumer`\n");
    Err = CXInit_CanNotCreate;
  }

  if (ErrorCode)
    *ErrorCode = Err;

  return ptr.release();
}

CXDiagnosticConsumer clang_TextDiagnosticPrinter_create(CXDiagnosticOptions Opts,
                                                        CXInit_Error *ErrorCode) {
  CXInit_Error Err = CXInit_NoError;
  std::unique_ptr<clang::DiagnosticConsumer> ptr =
      std::make_unique<clang::TextDiagnosticPrinter>(
          llvm::errs(), static_cast<clang::DiagnosticOptions *>(Opts));

  if (!ptr) {
    fprintf(stderr, "LIBCLANGEX ERROR: failed to create `clang::TextDiagnosticPrinter`\n");
    Err = CXInit_CanNotCreate;
  }

  if (ErrorCode)
    *ErrorCode = Err;

  return ptr.release();
}

void clang_DiagnosticConsumer_dispose(CXDiagnosticConsumer DC) {
  delete static_cast<clang::DiagnosticConsumer *>(DC);
}

void clang_DiagnosticConsumer_BeginSourceFile(CXDiagnosticConsumer DC,
                                              CXLangOptions LangOpts, CXPreprocessor PP) {
  static_cast<clang::DiagnosticConsumer *>(DC)->BeginSourceFile(
      *static_cast<clang::LangOptions *>(LangOpts), static_cast<clang::Preprocessor *>(PP));
}

void clang_DiagnosticConsumer_EndSourceFile(CXDiagnosticConsumer DC) {
  static_cast<clang::DiagnosticConsumer *>(DC)->EndSourceFile();
}

// DiagnosticsEngine

CXDiagnosticsEngine clang_DiagnosticsEngine_create(CXDiagnosticIDs ID,
                                                   CXDiagnosticOptions DO,
                                                   CXDiagnosticConsumer DC,
                                                   bool ShouldOwnClient,
                                                   CXInit_Error *ErrorCode) {
  CXInit_Error Err = CXInit_NoError;
  std::unique_ptr<clang::DiagnosticsEngine> ptr =
      std::make_unique<clang::DiagnosticsEngine>(
          llvm::IntrusiveRefCntPtr<clang::DiagnosticIDs>(
              static_cast<clang::DiagnosticIDs *>(ID)),
          llvm::IntrusiveRefCntPtr<clang::DiagnosticOptions>(
              static_cast<clang::DiagnosticOptions *>(DO)),
          static_cast<clang::DiagnosticConsumer *>(DC), ShouldOwnClient);

  if (!ptr) {
    fprintf(stderr, "LIBCLANGEX ERROR: failed to create `clang::DiagnosticsEngine`\n");
    Err = CXInit_CanNotCreate;
  }

  if (ErrorCode)
    *ErrorCode = Err;

  return ptr.release();
}

void clang_DiagnosticsEngine_dispose(CXDiagnosticsEngine DE) {
  delete static_cast<clang::DiagnosticsEngine *>(DE);
}

void clang_DiagnosticsEngine_setShowColors(CXDiagnosticsEngine DE, bool ShowColors) {
  static_cast<clang::DiagnosticsEngine *>(DE)->setShowColors(ShowColors);
}
