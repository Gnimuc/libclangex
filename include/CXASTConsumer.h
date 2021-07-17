#ifndef LIBCLANGEX_CXASTCONSUMER_H
#define LIBCLANGEX_CXASTCONSUMER_H

#include "CXTypes.h"
#include "clang-c/Platform.h"

#ifdef __cplusplus
extern "C" {
#endif

CINDEX_LINKAGE void clang_ASTConsumer_Initialize(CXASTConsumer Csr, CXASTContext Ctx);

CINDEX_LINKAGE void clang_ASTConsumer_HandleTranslationUnit(CXASTConsumer Csr, CXASTContext Ctx);

CINDEX_LINKAGE void clang_ASTConsumer_PrintStats(CXASTConsumer Csr);

#ifdef __cplusplus
}
#endif
#endif