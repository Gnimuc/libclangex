#include "libclangex.h"
#include "clang/AST/DeclBase.h"
#include "clang/AST/Stmt.h"
#include "clang/Parse/ParseAST.h"

void clang_ParseAST(CXSema Sema, bool PrintStats, bool SkipFunctionBodies) {
  clang::ParseAST(*static_cast<clang::Sema *>(Sema), PrintStats, SkipFunctionBodies);
}

void clang_Decl_EnableStatistics(void) { clang::Decl::EnableStatistics(); }

void clang_Stmt_EnableStatistics(void) { clang::Stmt::EnableStatistics(); }

void clang_Decl_PrintStats(void) { clang::Decl::PrintStats(); }

void clang_Stmt_PrintStats(void) { clang::Stmt::PrintStats(); }