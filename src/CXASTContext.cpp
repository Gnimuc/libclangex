#include "CXASTContext.h"
#include "clang/AST/ASTContext.h"

void clang_ASTContext_PrintStats(CXASTContext Ctx) {
    static_cast<clang::ASTContext *>(Ctx)->PrintStats();
}