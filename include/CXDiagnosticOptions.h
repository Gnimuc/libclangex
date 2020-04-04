#ifndef LIBCLANGEX_CXDIAGNOSTICOPTIONS_H
#define LIBCLANGEX_CXDIAGNOSTICOPTIONS_H

#include "clang-c/Platform.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void *CXDiagnosticOptions;

typedef enum {
  CXDiagnosticOptions_NoError = 0,
  CXDiagnosticOptions_CanNotCreate = 1
} CXDiagnosticOptions_Error;

CINDEX_LINKAGE CXDiagnosticOptions
clang_DiagnosticOptions_create(CXDiagnosticOptions_Error *ErrorCode);

CINDEX_LINKAGE void clang_DiagnosticOptions_dispose(CXDiagnosticOptions DO);

#ifdef __cplusplus
}
#endif
#endif
