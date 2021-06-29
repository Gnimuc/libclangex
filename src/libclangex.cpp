#include "libclangex.h"
#include "clang/Parse/ParseAST.h"

void clang_ParseAST(CXSema Sema, bool PrintStats, bool SkipFunctionBodies) {
  clang::ParseAST(*static_cast<clang::Sema *>(Sema), PrintStats, SkipFunctionBodies);
}