#ifndef LIBCLANGEX_CXLINKAGE_H
#define LIBCLANGEX_CXLINKAGE_H

#ifdef __cplusplus
extern "C" {
#endif

enum CXLinkage : unsigned char {
  CXLinkage_NoLinkage = 0,
  CXLinkage_InternalLinkage,
  CXLinkage_UniqueExternalLinkage,
  CXLinkage_VisibleNoLinkage,
  CXLinkage_ModuleInternalLinkage,
  CXLinkage_ModuleLinkage,
  CXLinkage_ExternalLinkage
};

#ifdef __cplusplus
}
#endif
#endif