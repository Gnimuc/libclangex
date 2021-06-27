#ifndef LIBCLANGEX_CXDIAGNOSTICOPTIONS_H
#define LIBCLANGEX_CXDIAGNOSTICOPTIONS_H

#include "CXError.h"
#include "clang-c/Platform.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void *CXDiagnosticOptions;

CINDEX_LINKAGE CXDiagnosticOptions clang_DiagnosticOptions_create(CXInit_Error *ErrorCode);

CINDEX_LINKAGE void clang_DiagnosticOptions_dispose(CXDiagnosticOptions DO);

#ifdef __cplusplus
}
#endif
#endif
