#ifndef LIBCLANGEX_CXASTCONTEXT_H
#define LIBCLANGEX_CXASTCONTEXT_H

#include "clang-ex/CXTypes.h"
#include "clang-c/Platform.h"

#ifdef __cplusplus
extern "C" {
#endif

CINDEX_LINKAGE CXTranslationUnitDecl
clang_ASTContext_getTranslationUnitDecl(CXASTContext Ctx);

CINDEX_LINKAGE void clang_ASTContext_PrintStats(CXASTContext Ctx);

CINDEX_LINKAGE CXQualType clang_ASTContext_getPointerType(CXASTContext Ctx,
                                                          CXQualType OpaquePtr);

CINDEX_LINKAGE CXQualType clang_ASTContext_getLValueReferenceType(CXASTContext Ctx,
                                                                  CXQualType OpaquePtr);

CINDEX_LINKAGE CXQualType clang_ASTContext_getRValueReferenceType(CXASTContext Ctx,
                                                                  CXQualType OpaquePtr);

CINDEX_LINKAGE CXQualType clang_ASTContext_getMemberPointerType(CXASTContext Ctx,
                                                                CXQualType OpaquePtr,
                                                                CXType_ Cls);

CINDEX_LINKAGE CXIdentifierTable clang_ASTContext_getIdents(CXASTContext Ctx);

CINDEX_LINKAGE uint64_t clang_ASTContext_getTypeSize(CXASTContext Ctx, CXType_ T);

CINDEX_LINKAGE CXQualType clang_ASTContext_getTypeDeclType(CXASTContext Ctx,
                                                           CXTypeDecl Decl,
                                                           CXTypeDecl PrevDecl);

CINDEX_LINKAGE CXQualType clang_ASTContext_getRecordType(CXASTContext Ctx,
                                                         CXRecordDecl Decl);

// Builtin Types
CINDEX_LINKAGE CXQualType clang_ASTContext_VoidTy_getAsQualType(CXASTContext Ctx);
CINDEX_LINKAGE CXQualType clang_ASTContext_BoolTy_getAsQualType(CXASTContext Ctx);
CINDEX_LINKAGE CXQualType clang_ASTContext_CharTy_getAsQualType(CXASTContext Ctx);
CINDEX_LINKAGE CXQualType clang_ASTContext_WCharTy_getAsQualType(CXASTContext Ctx);
CINDEX_LINKAGE CXQualType clang_ASTContext_WideCharTy_getAsQualType(CXASTContext Ctx);
CINDEX_LINKAGE CXQualType clang_ASTContext_WIntTy_getAsQualType(CXASTContext Ctx);
CINDEX_LINKAGE CXQualType clang_ASTContext_Char8Ty_getAsQualType(CXASTContext Ctx);
CINDEX_LINKAGE CXQualType clang_ASTContext_Char16Ty_getAsQualType(CXASTContext Ctx);
CINDEX_LINKAGE CXQualType clang_ASTContext_Char32Ty_getAsQualType(CXASTContext Ctx);
CINDEX_LINKAGE CXQualType clang_ASTContext_SignedCharTy_getAsQualType(CXASTContext Ctx);
CINDEX_LINKAGE CXQualType clang_ASTContext_ShortTy_getAsQualType(CXASTContext Ctx);
CINDEX_LINKAGE CXQualType clang_ASTContext_IntTy_getAsQualType(CXASTContext Ctx);
CINDEX_LINKAGE CXQualType clang_ASTContext_LongTy_getAsQualType(CXASTContext Ctx);
CINDEX_LINKAGE CXQualType clang_ASTContext_LongLongTy_getAsQualType(CXASTContext Ctx);
CINDEX_LINKAGE CXQualType clang_ASTContext_Int128Ty_getAsQualType(CXASTContext Ctx);
CINDEX_LINKAGE CXQualType clang_ASTContext_UnsignedCharTy_getAsQualType(CXASTContext Ctx);
CINDEX_LINKAGE CXQualType clang_ASTContext_UnsignedShortTy_getAsQualType(CXASTContext Ctx);
CINDEX_LINKAGE CXQualType clang_ASTContext_UnsignedIntTy_getAsQualType(CXASTContext Ctx);
CINDEX_LINKAGE CXQualType clang_ASTContext_UnsignedLongTy_getAsQualType(CXASTContext Ctx);
CINDEX_LINKAGE CXQualType
clang_ASTContext_UnsignedLongLongTy_getAsQualType(CXASTContext Ctx);
CINDEX_LINKAGE CXQualType clang_ASTContext_UnsignedInt128Ty_getAsQualType(CXASTContext Ctx);
CINDEX_LINKAGE CXQualType clang_ASTContext_FloatTy_getAsQualType(CXASTContext Ctx);
CINDEX_LINKAGE CXQualType clang_ASTContext_DoubleTy_getAsQualType(CXASTContext Ctx);
CINDEX_LINKAGE CXQualType clang_ASTContext_LongDoubleTy_getAsQualType(CXASTContext Ctx);
CINDEX_LINKAGE CXQualType clang_ASTContext_Float128Ty_getAsQualType(CXASTContext Ctx);
CINDEX_LINKAGE CXQualType clang_ASTContext_HalfTy_getAsQualType(CXASTContext Ctx);
CINDEX_LINKAGE CXQualType clang_ASTContext_BFloat16Ty_getAsQualType(CXASTContext Ctx);
CINDEX_LINKAGE CXQualType clang_ASTContext_Float16Ty_getAsQualType(CXASTContext Ctx);
CINDEX_LINKAGE CXQualType clang_ASTContext_FloatComplexTy_getAsQualType(CXASTContext Ctx);
CINDEX_LINKAGE CXQualType clang_ASTContext_DoubleComplexTy_getAsQualType(CXASTContext Ctx);
CINDEX_LINKAGE CXQualType
clang_ASTContext_LongDoubleComplexTy_getAsQualType(CXASTContext Ctx);
CINDEX_LINKAGE CXQualType
clang_ASTContext_Float128ComplexTy_getAsQualType(CXASTContext Ctx);
CINDEX_LINKAGE CXQualType clang_ASTContext_VoidPtrTy_getAsQualType(CXASTContext Ctx);
CINDEX_LINKAGE CXQualType clang_ASTContext_NullPtrTy_getAsQualType(CXASTContext Ctx);

#ifdef __cplusplus
}
#endif
#endif