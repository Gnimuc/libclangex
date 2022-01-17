#ifndef LIBCLANGEX_CXSPECIFIERS_H
#define LIBCLANGEX_CXSPECIFIERS_H

#ifdef __cplusplus
extern "C" {
#endif

enum CXTemplateSpecializationKind {
  CXTemplateSpecializationKind_TSK_Undeclared = 0,
  CXTemplateSpecializationKind_TSK_ImplicitInstantiation,
  CXTemplateSpecializationKind_TSK_ExplicitSpecialization,
  CXTemplateSpecializationKind_TSK_ExplicitInstantiationDeclaration,
  CXTemplateSpecializationKind_TSK_ExplicitInstantiationDefinition
};

enum CXThreadStorageClassSpecifier {
  CXThreadStorageClassSpecifier_TSCS_unspecified,
  CXThreadStorageClassSpecifier_TSCS___thread,
  CXThreadStorageClassSpecifier_TSCS_thread_local,
  CXThreadStorageClassSpecifier_TSCS__Thread_local
};

enum CXStorageClass {
  CXStorageClass_SC_None,
  CXStorageClass_SC_Extern,
  CXStorageClass_SC_Static,
  CXStorageClass_SC_PrivateExtern,
  CXStorageClass_SC_Auto,
  CXStorageClass_SC_Register
};

enum CXStorageDuration {
  CXStorageDuration_SD_FullExpression,
  CXStorageDuration_SD_Automatic,
  CXStorageDuration_SD_Thread,
  CXStorageDuration_SD_Static,
  CXStorageDuration_SD_Dynamic
};

#ifdef __cplusplus
}
#endif
#endif