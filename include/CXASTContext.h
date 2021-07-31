#ifndef LIBCLANGEX_CXASTCONTEXT_H
#define LIBCLANGEX_CXASTCONTEXT_H

#include "CXTypes.h"
#include "clang-c/Platform.h"

#ifdef __cplusplus
extern "C" {
#endif

CINDEX_LINKAGE void clang_ASTContext_PrintStats(CXASTContext Ctx);

CINDEX_LINKAGE CXQualType clang_ASTContext_getPointerType(CXASTContext Ctx,
                                                          CXQualType OpaquePtr);

// Decls
CINDEX_LINKAGE CXTranslationUnitDecl
clang_ASTContext_getTranslationUnitDecl(CXASTContext Ctx);

// Builtin Types
CINDEX_LINKAGE CXType_ clang_ASTContext_VoidTy_getTypePtrOrNull(CXASTContext Ctx);
CINDEX_LINKAGE CXType_ clang_ASTContext_BoolTy_getTypePtrOrNull(CXASTContext Ctx);
CINDEX_LINKAGE CXType_ clang_ASTContext_CharTy_getTypePtrOrNull(CXASTContext Ctx);
CINDEX_LINKAGE CXType_ clang_ASTContext_WCharTy_getTypePtrOrNull(CXASTContext Ctx);
CINDEX_LINKAGE CXType_ clang_ASTContext_WideCharTy_getTypePtrOrNull(CXASTContext Ctx);
CINDEX_LINKAGE CXType_ clang_ASTContext_WIntTy_getTypePtrOrNull(CXASTContext Ctx);
CINDEX_LINKAGE CXType_ clang_ASTContext_Char8Ty_getTypePtrOrNull(CXASTContext Ctx);
CINDEX_LINKAGE CXType_ clang_ASTContext_Char16Ty_getTypePtrOrNull(CXASTContext Ctx);
CINDEX_LINKAGE CXType_ clang_ASTContext_Char32Ty_getTypePtrOrNull(CXASTContext Ctx);
CINDEX_LINKAGE CXType_ clang_ASTContext_SignedCharTy_getTypePtrOrNull(CXASTContext Ctx);
CINDEX_LINKAGE CXType_ clang_ASTContext_ShortTy_getTypePtrOrNull(CXASTContext Ctx);
CINDEX_LINKAGE CXType_ clang_ASTContext_IntTy_getTypePtrOrNull(CXASTContext Ctx);
CINDEX_LINKAGE CXType_ clang_ASTContext_LongTy_getTypePtrOrNull(CXASTContext Ctx);
CINDEX_LINKAGE CXType_ clang_ASTContext_LongLongTy_getTypePtrOrNull(CXASTContext Ctx);
CINDEX_LINKAGE CXType_ clang_ASTContext_Int128Ty_getTypePtrOrNull(CXASTContext Ctx);
CINDEX_LINKAGE CXType_ clang_ASTContext_UnsignedCharTy_getTypePtrOrNull(CXASTContext Ctx);
CINDEX_LINKAGE CXType_ clang_ASTContext_UnsignedShortTy_getTypePtrOrNull(CXASTContext Ctx);
CINDEX_LINKAGE CXType_ clang_ASTContext_UnsignedIntTy_getTypePtrOrNull(CXASTContext Ctx);
CINDEX_LINKAGE CXType_ clang_ASTContext_UnsignedLongTy_getTypePtrOrNull(CXASTContext Ctx);
CINDEX_LINKAGE CXType_
clang_ASTContext_UnsignedLongLongTy_getTypePtrOrNull(CXASTContext Ctx);
CINDEX_LINKAGE CXType_ clang_ASTContext_UnsignedInt128Ty_getTypePtrOrNull(CXASTContext Ctx);
CINDEX_LINKAGE CXType_ clang_ASTContext_FloatTy_getTypePtrOrNull(CXASTContext Ctx);
CINDEX_LINKAGE CXType_ clang_ASTContext_DoubleTy_getTypePtrOrNull(CXASTContext Ctx);
CINDEX_LINKAGE CXType_ clang_ASTContext_LongDoubleTy_getTypePtrOrNull(CXASTContext Ctx);
CINDEX_LINKAGE CXType_ clang_ASTContext_Float128Ty_getTypePtrOrNull(CXASTContext Ctx);
CINDEX_LINKAGE CXType_ clang_ASTContext_HalfTy_getTypePtrOrNull(CXASTContext Ctx);
CINDEX_LINKAGE CXType_ clang_ASTContext_BFloat16Ty_getTypePtrOrNull(CXASTContext Ctx);
CINDEX_LINKAGE CXType_ clang_ASTContext_Float16Ty_getTypePtrOrNull(CXASTContext Ctx);
CINDEX_LINKAGE CXType_ clang_ASTContext_FloatComplexTy_getTypePtrOrNull(CXASTContext Ctx);
CINDEX_LINKAGE CXType_ clang_ASTContext_DoubleComplexTy_getTypePtrOrNull(CXASTContext Ctx);
CINDEX_LINKAGE CXType_
clang_ASTContext_LongDoubleComplexTy_getTypePtrOrNull(CXASTContext Ctx);
CINDEX_LINKAGE CXType_
clang_ASTContext_Float128ComplexTy_getTypePtrOrNull(CXASTContext Ctx);
CINDEX_LINKAGE CXType_ clang_ASTContext_VoidPtrTy_getTypePtrOrNull(CXASTContext Ctx);
CINDEX_LINKAGE CXType_ clang_ASTContext_NullPtrTy_getTypePtrOrNull(CXASTContext Ctx);

#ifdef __cplusplus
}
#endif
#endif