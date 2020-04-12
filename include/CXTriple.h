#ifndef LIBCLANGEX_CXTRIPLE_H
#define LIBCLANGEX_CXTRIPLE_H

#include "CXError.h"
#include "clang-c/Platform.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void *CXTriple;

typedef enum {
  CXTriple_UnknownArch,
  CXTriple_x86_64,
  CXTriple_x86,
  CXTriple_i686 = CXTriple_x86,
  CXTriple_arm,
  CXTriple_armv7l = CXTriple_arm,
  CXTriple_aarch64,
  CXTriple_ppc64le,
  CXTriple_nvptx64,
  CXTriple_spir64,
  CXTriple_wasm64,
  CXTriple_LastArchType = CXTriple_wasm64
} CXTriple_ArchType;

typedef enum {
  CXTriple_UnknownVendor,
  CXTriple_Apple,
  CXTriple_PC,
  CXTriple_IBM,
  CXTriple_ImaginationTechnologies,
  CXTriple_NVIDIA,
  CXTriple_AMD,
  CXTriple_Mesa,
  CXTriple_SUSE,
  CXTriple_LastVendorType = CXTriple_SUSE
} CXTriple_VendorType;

typedef enum {
  CXTriple_UnknownOS,
  CXTriple_Darwin,
  CXTriple_FreeBSD,
  CXTriple_Linux,
  CXTriple_MacOSX,
  CXTriple_Win32,
  CXTriple_CUDA,
  CXTriple_NVCL,
  CXTriple_WASI,
  CXTriple_LastOSType = CXTriple_WASI
} CXTriple_OSType;

typedef enum {
  CXTriple_UnknownEnvironment,
  CXTriple_GNU,
  CXTriple_GNUEABIHF,
  CXTriple_Musl,
  CXTriple_MuslEABIHF,
  CXTriple_LastEnvironmentType = CXTriple_MuslEABIHF,
} CXTriple_EnvironmentType;

typedef enum {
  CXTriple_UnknownObjectFormat,
  CXTriple_COFF,
  CXTriple_ELF,
  CXTriple_MachO,
  CXTriple_Wasm,
  CXTriple_XCOFF,
} CXTriple_ObjectFormatType;

CINDEX_LINKAGE CXTriple clang_Triple_create(CXInit_Error *ErrorCode);

CINDEX_LINKAGE void clang_Triple_dispose(CXTriple T);

CINDEX_LINKAGE CXTriple_ArchType clang_Triple_getArch(CXTriple T);
CINDEX_LINKAGE CXTriple_VendorType clang_Triple_getVendor(CXTriple T);
CINDEX_LINKAGE CXTriple_OSType clang_Triple_getOS(CXTriple T);
CINDEX_LINKAGE CXTriple_EnvironmentType clang_Triple_getEnvironment(CXTriple T);
CINDEX_LINKAGE CXTriple_ObjectFormatType
clang_Triple_getObjectFormat(CXTriple T);

CINDEX_LINKAGE void clang_Triple_setArch(CXTriple T, CXTriple_ArchType AT);
CINDEX_LINKAGE void clang_Triple_setVendor(CXTriple T, CXTriple_VendorType VT);
CINDEX_LINKAGE void clang_Triple_setOS(CXTriple T, CXTriple_OSType OST);
CINDEX_LINKAGE void clang_Triple_setEnvironment(CXTriple T,
                                                CXTriple_EnvironmentType ET);
CINDEX_LINKAGE void clang_Triple_setObjectFormat(CXTriple T,
                                                 CXTriple_ObjectFormatType OF);

#ifdef __cplusplus
}
#endif
#endif
