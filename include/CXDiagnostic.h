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

// DiagnosticConsumer
CINDEX_LINKAGE CXDiagnosticConsumer
clang_DiagnosticConsumer_create(CXInit_Error *ErrorCode);

CINDEX_LINKAGE void clang_DiagnosticConsumer_dispose(CXDiagnosticConsumer DC);

CINDEX_LINKAGE CXIgnoringDiagConsumer clang_IgnoringDiagConsumer_create(CXInit_Error *ErrorCode);

CINDEX_LINKAGE void clang_IgnoringDiagConsumer_dispose(CXIgnoringDiagConsumer DC);

// DiagnosticsEngine
CINDEX_LINKAGE CXDiagnosticsEngine clang_DiagnosticsEngine_create(CXDiagnosticIDs ID,
                                                                  CXDiagnosticOptions DO,
                                                                  CXDiagnosticConsumer DC,
                                                                  bool ShouldOwnClient,
                                                                  CXInit_Error *ErrorCode);

CINDEX_LINKAGE void clang_DiagnosticsEngine_dispose(CXDiagnosticsEngine DE);

#ifdef __cplusplus
}
#endif
#endif
