#ifndef LIBCLANGEX_CXASTCONTEXT_H
#define LIBCLANGEX_CXASTCONTEXT_H

#include "CXTypes.h"
#include "clang-c/Platform.h"

#ifdef __cplusplus
extern "C" {
#endif

CINDEX_LINKAGE void clang_ASTContext_PrintStats(CXASTContext Ctx);

#ifdef __cplusplus
}
#endif
#endif