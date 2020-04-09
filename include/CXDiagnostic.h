#ifndef LIBCLANGEX_CXDIAGNOSTIC_H
#define LIBCLANGEX_CXDIAGNOSTIC_H

#include "CXIntrusiveRefCntPtr.h"
#include "clang-c/Platform.h"
#include "CXError.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void *CXDiagnosticConsumer;

CINDEX_LINKAGE CXDiagnosticConsumer
clang_DiagnosticConsumer_create(CXInit_Error *ErrorCode);

CINDEX_LINKAGE void clang_DiagnosticConsumer_dispose(CXDiagnosticConsumer DC);

typedef void *CXDiagnosticsEngine;

CINDEX_LINKAGE CXDiagnosticsEngine
clang_DiagnosticsEngineIntrusiveRefCntPtr_get(CXIntrusiveRefCntPtr ptr);

CINDEX_LINKAGE void
clang_DiagnosticsEngineIntrusiveRefCntPtr_dispose(CXIntrusiveRefCntPtr ptr);

#ifdef __cplusplus
}
#endif
#endif
