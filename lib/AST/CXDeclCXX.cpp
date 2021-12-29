#include "clang-ex/AST/CXDeclCXX.h"
#include "clang/AST/DeclCXX.h"

CXCXXRecordDecl clang_CXXRecordDecl_getCanonicalDecl(CXCXXRecordDecl CXXRD) {
  return static_cast<clang::CXXRecordDecl *>(CXXRD)->getCanonicalDecl();
}

CXCXXRecordDecl clang_CXXRecordDecl_getPreviousDecl(CXCXXRecordDecl CXXRD) {
  return static_cast<clang::CXXRecordDecl *>(CXXRD)->getPreviousDecl();
}

CXCXXRecordDecl clang_CXXRecordDecl_getMostRecentDecl(CXCXXRecordDecl CXXRD) {
  return static_cast<clang::CXXRecordDecl *>(CXXRD)->getMostRecentDecl();
}

CXCXXRecordDecl clang_CXXRecordDecl_getMostRecentNonInjectedDecl(CXCXXRecordDecl CXXRD) {
  return static_cast<clang::CXXRecordDecl *>(CXXRD)->getMostRecentNonInjectedDecl();
}

CXCXXRecordDecl clang_CXXRecordDecl_getDefinition(CXCXXRecordDecl CXXRD) {
  return static_cast<clang::CXXRecordDecl *>(CXXRD)->getDefinition();
}

bool clang_CXXRecordDecl_hasDefinition(CXCXXRecordDecl CXXRD) {
  return static_cast<clang::CXXRecordDecl *>(CXXRD)->hasDefinition();
}

bool clang_CXXRecordDecl_isLambda(CXCXXRecordDecl CXXRD) {
  return static_cast<clang::CXXRecordDecl *>(CXXRD)->isLambda();
}

bool clang_CXXRecordDecl_isGenericLambda(CXCXXRecordDecl CXXRD) {
  return static_cast<clang::CXXRecordDecl *>(CXXRD)->isGenericLambda();
}

CXTemplateParameterList
clang_CXXRecordDecl_getGenericLambdaTemplateParameterList(CXCXXRecordDecl CXXRD) {
  return static_cast<clang::CXXRecordDecl *>(CXXRD)
      ->getGenericLambdaTemplateParameterList();
}

bool clang_CXXRecordDecl_isAggregate(CXCXXRecordDecl CXXRD) {
  return static_cast<clang::CXXRecordDecl *>(CXXRD)->isAggregate();
}

bool clang_CXXRecordDecl_isPOD(CXCXXRecordDecl CXXRD) {
  return static_cast<clang::CXXRecordDecl *>(CXXRD)->isPOD();
}

bool clang_CXXRecordDecl_isCLike(CXCXXRecordDecl CXXRD) {
  return static_cast<clang::CXXRecordDecl *>(CXXRD)->isCLike();
}

bool clang_CXXRecordDecl_isEmpty(CXCXXRecordDecl CXXRD) {
  return static_cast<clang::CXXRecordDecl *>(CXXRD)->isEmpty();
}