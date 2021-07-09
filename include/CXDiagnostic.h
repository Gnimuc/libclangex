#ifndef LIBCLANGEX_CXDIAGNOSTIC_H
#define LIBCLANGEX_CXDIAGNOSTIC_H

#include "CXError.h"
#include "CXTypes.h"
#include "clang-c/Platform.h"

#ifdef __cplusplus
extern "C" {
#endif

// DiagnosticIDs
CINDEX_LINKAGE CXDiagnosticIDs clang_DiagnosticIDs_create(CXInit_Error *ErrorCode);

CINDEX_LINKAGE void clang_DiagnosticIDs_dispose(CXDiagnosticIDs ID);

// DiagnosticOptions
CINDEX_LINKAGE CXDiagnosticOptions clang_DiagnosticOptions_create(CXInit_Error *ErrorCode);

CINDEX_LINKAGE void clang_DiagnosticOptions_dispose(CXDiagnosticOptions DO);

CINDEX_LINKAGE void clang_DiagnosticOptions_PrintStats(CXDiagnosticOptions DO);

CINDEX_LINKAGE void clang_DiagnosticOptions_setShowColors(CXDiagnosticOptions DO,
                                                          bool ShowColors);

CINDEX_LINKAGE void clang_DiagnosticOptions_setShowPresumedLoc(CXDiagnosticOptions DO,
                                                               bool ShowPresumedLoc);

// DiagnosticConsumer
CINDEX_LINKAGE CXDiagnosticConsumer
clang_DiagnosticConsumer_create(CXInit_Error *ErrorCode);

CINDEX_LINKAGE void clang_DiagnosticConsumer_dispose(CXDiagnosticConsumer DC);

CINDEX_LINKAGE CXIgnoringDiagConsumer
clang_IgnoringDiagConsumer_create(CXInit_Error *ErrorCode);

CINDEX_LINKAGE void clang_IgnoringDiagConsumer_dispose(CXIgnoringDiagConsumer DC);

CINDEX_LINKAGE CXTextDiagnosticPrinter
clang_TextDiagnosticPrinter_create(CXDiagnosticOptions Opts, CXInit_Error *ErrorCode);

CINDEX_LINKAGE void clang_TextDiagnosticPrinter_dispose(CXTextDiagnosticPrinter DC);

CINDEX_LINKAGE void clang_TextDiagnosticPrinter_BeginSourceFile(CXTextDiagnosticPrinter DC,
                                                                CXLangOptions LangOpts,
                                                                CXPreprocessor PP);

CINDEX_LINKAGE void clang_TextDiagnosticPrinter_EndSourceFile(CXTextDiagnosticPrinter DC);

// DiagnosticsEngine
CINDEX_LINKAGE CXDiagnosticsEngine clang_DiagnosticsEngine_create(CXDiagnosticIDs ID,
                                                                  CXDiagnosticOptions DO,
                                                                  CXDiagnosticConsumer DC,
                                                                  bool ShouldOwnClient,
                                                                  CXInit_Error *ErrorCode);

CINDEX_LINKAGE void clang_DiagnosticsEngine_dispose(CXDiagnosticsEngine DE);

CINDEX_LINKAGE void clang_DiagnosticsEngine_setShowColors(CXDiagnosticsEngine DE,
                                                          bool ShowColors);

#ifdef __cplusplus
}
#endif
#endif
