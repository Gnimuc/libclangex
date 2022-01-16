#ifndef LIBCLANGEX_CXPRAGMAKINDS_H
#define LIBCLANGEX_CXPRAGMAKINDS_H

#ifdef __cplusplus
extern "C" {
#endif

enum CXPragmaMSCommentKind {
  CXPragmaMSCommentKind_PCK_Unknown,
  CXPragmaMSCommentKind_PCK_Linker,
  CXPragmaMSCommentKind_PCK_Lib,
  CXPragmaMSCommentKind_PCK_Compiler,
  CXPragmaMSCommentKind_PCK_ExeStr,
  CXPragmaMSCommentKind_PCK_User
};

enum CXPragmaMSStructKind { CXPragmaMSStructKind_PMSST_OFF, CXPragmaMSStructKind_PMSST_ON };

enum CXPragmaFloatControlKind {
  CXPragmaFloatControlKind_PFC_Unknown,
  CXPragmaFloatControlKind_PFC_Precise,
  CXPragmaFloatControlKind_PFC_NoPrecise,
  CXPragmaFloatControlKind_PFC_Except,
  CXPragmaFloatControlKind_PFC_NoExcept,
  CXPragmaFloatControlKind_PFC_Push,
  CXPragmaFloatControlKind_PFC_Pop
};

#ifdef __cplusplus
}
#endif
#endif