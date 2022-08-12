#ifndef LIBCLANGEX_CXPARTIALTRANSLATIONUNIT_H
#define LIBCLANGEX_CXPARTIALTRANSLATIONUNIT_H

#include "clang-ex/CXTypes.h"
#include "clang-c/Platform.h"
#include "llvm-c/Types.h"

#ifdef __cplusplus
extern "C" {
#endif

CINDEX_LINKAGE CXTranslationUnitDecl
clang_PartialTranslationUnit_get_TUPart(CXPartialTranslationUnit PTU);

CINDEX_LINKAGE LLVMModuleRef
clang_PartialTranslationUnit_get_TheModule(CXPartialTranslationUnit PTU);

#ifdef __cplusplus
}
#endif
#endif