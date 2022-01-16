#ifndef LIBCLANGEX_CXVISIBILITY_H
#define LIBCLANGEX_CXVISIBILITY_H

#ifdef __cplusplus
extern "C" {
#endif

enum CXVisibility {
  CXVisibility_HiddenVisibility,
  CXVisibility_ProtectedVisibility,
  CXVisibility_DefaultVisibility
};

#ifdef __cplusplus
}
#endif
#endif