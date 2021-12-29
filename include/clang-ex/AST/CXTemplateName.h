#ifndef LIBCLANGEX_CXTEMPLATENAME_H
#define LIBCLANGEX_CXTEMPLATENAME_H

#include "clang-ex/CXTypes.h"
#include "clang-c/Platform.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum CXTemplateName_NameKind {
  CXTemplateName_NameKind_Template,
  CXTemplateName_NameKind_OverloadedTemplate,
  CXTemplateName_NameKind_AssumedTemplate,
  CXTemplateName_NameKind_QualifiedTemplate,
  CXTemplateName_NameKind_DependentTemplate,
  CXTemplateName_NameKind_SubstTemplateTemplateParm,
  CXTemplateName_NameKind_SubstTemplateTemplateParmPack
} CXTemplateName_NameKind;

CINDEX_LINKAGE bool clang_TemplateName_isNull(CXTemplateName TN);

CINDEX_LINKAGE CXTemplateName_NameKind clang_TemplateName_getKind(CXTemplateName TN);

CINDEX_LINKAGE CXTemplateDecl clang_TemplateName_getAsTemplateDecl(CXTemplateName TN);

CINDEX_LINKAGE CXTemplateName clang_TemplateName_getUnderlying(CXTemplateName TN);

CINDEX_LINKAGE CXTemplateName clang_TemplateName_getNameToSubstitute(CXTemplateName TN);

CINDEX_LINKAGE bool clang_TemplateName_isDependent(CXTemplateName TN);

CINDEX_LINKAGE bool clang_TemplateName_isInstantiationDependent(CXTemplateName TN);

CINDEX_LINKAGE bool clang_TemplateName_containsUnexpandedParameterPack(CXTemplateName TN);

CINDEX_LINKAGE void clang_TemplateName_dump(CXTemplateName TN);

#ifdef __cplusplus
}
#endif
#endif