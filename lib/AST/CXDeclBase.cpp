#include "clang-ex/AST/CXDeclBase.h"
#include "clang/AST/Decl.h"
#include "clang/AST/DeclBase.h"
#include "clang/AST/DeclCXX.h"

CXTagDecl clang_DeclContext_castToTagDecl(CXDeclContext DC) {
  return llvm::dyn_cast<clang::TagDecl>(static_cast<clang::DeclContext *>(DC));
}

CXRecordDecl clang_DeclContext_castToRecordDecl(CXDeclContext DC) {
  return llvm::dyn_cast<clang::RecordDecl>(static_cast<clang::DeclContext *>(DC));
}

CXCXXRecordDecl clang_DeclContext_castToCXXRecordDecl(CXDeclContext DC) {
  return llvm::dyn_cast<clang::CXXRecordDecl>(static_cast<clang::DeclContext *>(DC));
}

const char *clang_DeclContext_getDeclKindName(CXDeclContext DC) {
  return static_cast<clang::DeclContext *>(DC)->getDeclKindName();
}

CXDeclContext clang_DeclContext_getParent(CXDeclContext DC) {
  return static_cast<clang::DeclContext *>(DC)->getParent();
}

CXDeclContext clang_DeclContext_getLexicalParent(CXDeclContext DC) {
  return static_cast<clang::DeclContext *>(DC)->getLexicalParent();
}

CXDeclContext clang_DeclContext_getLookupParent(CXDeclContext DC) {
  return static_cast<clang::DeclContext *>(DC)->getLookupParent();
}

CXASTContext clang_DeclContext_getParentASTContext(CXDeclContext DC) {
  return &static_cast<clang::DeclContext *>(DC)->getParentASTContext();
}

bool clang_DeclContext_isClosure(CXDeclContext DC) {
  return static_cast<clang::DeclContext *>(DC)->isClosure();
}

bool clang_DeclContext_isFunctionOrMethod(CXDeclContext DC) {
  return static_cast<clang::DeclContext *>(DC)->isFunctionOrMethod();
}

bool clang_DeclContext_isLookupContext(CXDeclContext DC) {
  return static_cast<clang::DeclContext *>(DC)->isLookupContext();
}

bool clang_DeclContext_isFileContext(CXDeclContext DC) {
  return static_cast<clang::DeclContext *>(DC)->isFileContext();
}

bool clang_DeclContext_isTranslationUnit(CXDeclContext DC) {
  return static_cast<clang::DeclContext *>(DC)->isTranslationUnit();
}

bool clang_DeclContext_isRecord(CXDeclContext DC) {
  return static_cast<clang::DeclContext *>(DC)->isRecord();
}

bool clang_DeclContext_isNamespace(CXDeclContext DC) {
  return static_cast<clang::DeclContext *>(DC)->isNamespace();
}

bool clang_DeclContext_isStdNamespace(CXDeclContext DC) {
  return static_cast<clang::DeclContext *>(DC)->isStdNamespace();
}

bool clang_DeclContext_isInlineNamespace(CXDeclContext DC) {
  return static_cast<clang::DeclContext *>(DC)->isInlineNamespace();
}

bool clang_DeclContext_isDependentContext(CXDeclContext DC) {
  return static_cast<clang::DeclContext *>(DC)->isDependentContext();
}

bool clang_DeclContext_isTransparentContext(CXDeclContext DC) {
  return static_cast<clang::DeclContext *>(DC)->isTransparentContext();
}

bool clang_DeclContext_isExternCContext(CXDeclContext DC) {
  return static_cast<clang::DeclContext *>(DC)->isExternCContext();
}

bool clang_DeclContext_isExternCXXContext(CXDeclContext DC) {
  return static_cast<clang::DeclContext *>(DC)->isExternCXXContext();
}

bool clang_DeclContext_Equals(CXDeclContext DC, CXDeclContext DC2) {
  return static_cast<clang::DeclContext *>(DC)->Equals(
      static_cast<clang::DeclContext *>(DC2));
}

CXDeclContext clang_DeclContext_getPrimaryContext(CXDeclContext DC) {
  return static_cast<clang::DeclContext *>(DC)->getPrimaryContext();
}

void clang_DeclContext_addDecl(CXDeclContext DC, CXDecl D) {
  static_cast<clang::DeclContext *>(DC)->addDecl(static_cast<clang::Decl *>(D));
}

void clang_DeclContext_addDeclInternal(CXDeclContext DC, CXDecl D) {
  static_cast<clang::DeclContext *>(DC)->addDeclInternal(static_cast<clang::Decl *>(D));
}

void clang_DeclContext_addHiddenDecl(CXDeclContext DC, CXDecl D) {
  static_cast<clang::DeclContext *>(DC)->addHiddenDecl(static_cast<clang::Decl *>(D));
}

void clang_DeclContext_removeDecl(CXDeclContext DC, CXDecl D) {
  static_cast<clang::DeclContext *>(DC)->removeDecl(static_cast<clang::Decl *>(D));
}

void clang_DeclContext_containsDecl(CXDeclContext DC, CXDecl D) {
  static_cast<clang::DeclContext *>(DC)->containsDecl(static_cast<clang::Decl *>(D));
}

void clang_DeclContext_dumpDeclContext(CXDeclContext DC) {
  static_cast<clang::DeclContext *>(DC)->dumpDeclContext();
}

void clang_DeclContext_dumpLookups(CXDeclContext DC) {
  static_cast<clang::DeclContext *>(DC)->dumpLookups();
}