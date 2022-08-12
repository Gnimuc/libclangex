#ifndef LIBCLANGEX_CXINTERPRETER_H
#define LIBCLANGEX_CXINTERPRETER_H

#include "clang-ex/CXTypes.h"
#include "clang-c/Platform.h"

#ifdef __cplusplus
extern "C" {
#endif

CINDEX_LINKAGE CXCompilerInstance clang_IncrementalCompilerBuilder_create(const char **Args, int N);

CINDEX_LINKAGE CXInterpreter clang_Interpreter_create(CXCompilerInstance CI);

CINDEX_LINKAGE void clang_Interpreter_dispose(CXInterpreter Interp);

CINDEX_LINKAGE CXCompilerInstance clang_Interpreter_getCompilerInstance(CXInterpreter Interp);

CINDEX_LINKAGE CXPartialTranslationUnit clang_Interpreter_Parse(CXInterpreter Interp, const char * Code);

CINDEX_LINKAGE void clang_Interpreter_Execute(CXInterpreter Interp, CXPartialTranslationUnit PTU);

CINDEX_LINKAGE void clang_Interpreter_ParseAndExecute(CXInterpreter Interp, const char * Code);

#ifdef __cplusplus
}
#endif
#endif