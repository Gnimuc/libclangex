#include "CXTriple.h"
#include "llvm/ADT/Triple.h"
#include <cstdio>

CXTriple clang_Triple_create(CXInit_Error *ErrorCode) {
  CXInit_Error Err = CXInit_NoError;
  std::unique_ptr<llvm::Triple> ptr = std::make_unique<llvm::Triple>();

  if (!ptr) {
    fprintf(stderr, "LIBCLANGEX ERROR: failed to create `llvm::Triple`\n");
    Err = CXInit_CanNotCreate;
  }

  if (ErrorCode)
    *ErrorCode = Err;

  return ptr.release();
}

void clang_Triple_dispose(CXTriple T) { delete static_cast<llvm::Triple *>(T); }

CXTriple_ArchType clang_Triple_getArch(CXTriple T) {
  auto AT = static_cast<llvm::Triple *>(T)->getArch();
  CXTriple_ArchType at = CXTriple_UnknownArch;
  switch (AT) {
  case llvm::Triple::x86_64:
    at = CXTriple_x86_64;
    break;
  case llvm::Triple::x86:
    at = CXTriple_x86;
    break;
  case llvm::Triple::arm:
    at = CXTriple_arm;
    break;
  case llvm::Triple::aarch64:
    at = CXTriple_aarch64;
    break;
  case llvm::Triple::ppc64le:
    at = CXTriple_ppc64le;
    break;
  case llvm::Triple::nvptx64:
    at = CXTriple_nvptx64;
    break;
  case llvm::Triple::spir64:
    at = CXTriple_spir64;
    break;
  case llvm::Triple::wasm64:
    at = CXTriple_wasm64;
    break;
  default:
    at = CXTriple_UnknownArch;
  }
  return at;
}

CXTriple_VendorType clang_Triple_getVendor(CXTriple T) {
  auto VT = static_cast<llvm::Triple *>(T)->getVendor();
  CXTriple_VendorType vt = CXTriple_UnknownVendor;
  switch (VT) {
  case llvm::Triple::Apple:
    vt = CXTriple_Apple;
    break;
  case llvm::Triple::PC:
    vt = CXTriple_PC;
    break;
  case llvm::Triple::IBM:
    vt = CXTriple_IBM;
    break;
  case llvm::Triple::ImaginationTechnologies:
    vt = CXTriple_ImaginationTechnologies;
    break;
  case llvm::Triple::NVIDIA:
    vt = CXTriple_NVIDIA;
    break;
  case llvm::Triple::AMD:
    vt = CXTriple_AMD;
    break;
  case llvm::Triple::Mesa:
    vt = CXTriple_Mesa;
    break;
  case llvm::Triple::SUSE:
    vt = CXTriple_SUSE;
    break;
  default:
    vt = CXTriple_UnknownVendor;
  }
  return vt;
}

CXTriple_OSType clang_Triple_getOS(CXTriple T) {
  auto OST = static_cast<llvm::Triple *>(T)->getOS();
  CXTriple_OSType ost = CXTriple_UnknownOS;
  switch (OST) {
  case llvm::Triple::Darwin:
    ost = CXTriple_Darwin;
    break;
  case llvm::Triple::FreeBSD:
    ost = CXTriple_FreeBSD;
    break;
  case llvm::Triple::Linux:
    ost = CXTriple_Linux;
    break;
  case llvm::Triple::MacOSX:
    ost = CXTriple_MacOSX;
    break;
  case llvm::Triple::Win32:
    ost = CXTriple_Win32;
    break;
  case llvm::Triple::CUDA:
    ost = CXTriple_CUDA;
    break;
  case llvm::Triple::NVCL:
    ost = CXTriple_NVCL;
    break;
  case llvm::Triple::WASI:
    ost = CXTriple_WASI;
    break;
  default:
    ost = CXTriple_UnknownOS;
  }
  return ost;
}

CXTriple_EnvironmentType clang_Triple_getEnvironment(CXTriple T) {
  auto ET = static_cast<llvm::Triple *>(T)->getEnvironment();
  CXTriple_EnvironmentType et = CXTriple_UnknownEnvironment;
  switch (ET) {
  case llvm::Triple::GNU:
    et = CXTriple_GNU;
    break;
  case llvm::Triple::GNUEABIHF:
    et = CXTriple_GNUEABIHF;
    break;
  case llvm::Triple::Musl:
    et = CXTriple_Musl;
    break;
  case llvm::Triple::MuslEABIHF:
    et = CXTriple_MuslEABIHF;
    break;
  default:
    et = CXTriple_UnknownEnvironment;
  }
  return et;
}

CXTriple_ObjectFormatType clang_Triple_getObjectFormat(CXTriple T) {
  auto OF = static_cast<llvm::Triple *>(T)->getObjectFormat();
  CXTriple_ObjectFormatType of = CXTriple_UnknownObjectFormat;
  switch (OF) {
  case llvm::Triple::COFF:
    of = CXTriple_COFF;
    break;
  case llvm::Triple::ELF:
    of = CXTriple_ELF;
    break;
  case llvm::Triple::MachO:
    of = CXTriple_MachO;
    break;
  case llvm::Triple::Wasm:
    of = CXTriple_Wasm;
    break;
  case llvm::Triple::XCOFF:
    of = CXTriple_XCOFF;
    break;
  default:
    of = CXTriple_UnknownObjectFormat;
  }
  return of;
}

void clang_Triple_setArch(CXTriple T, CXTriple_ArchType AT) {
  switch (AT) {
  case CXTriple_x86_64:
    static_cast<llvm::Triple *>(T)->setArch(llvm::Triple::x86_64);
    break;
  case CXTriple_x86:
    static_cast<llvm::Triple *>(T)->setArch(llvm::Triple::x86);
    break;
  case CXTriple_arm:
    static_cast<llvm::Triple *>(T)->setArch(llvm::Triple::arm);
    break;
  case CXTriple_aarch64:
    static_cast<llvm::Triple *>(T)->setArch(llvm::Triple::aarch64);
    break;
  case CXTriple_ppc64le:
    static_cast<llvm::Triple *>(T)->setArch(llvm::Triple::ppc64le);
    break;
  case CXTriple_nvptx64:
    static_cast<llvm::Triple *>(T)->setArch(llvm::Triple::nvptx64);
    break;
  case CXTriple_spir64:
    static_cast<llvm::Triple *>(T)->setArch(llvm::Triple::spir64);
    break;
  case CXTriple_wasm64:
    static_cast<llvm::Triple *>(T)->setArch(llvm::Triple::wasm64);
    break;
  default:
    static_cast<llvm::Triple *>(T)->setArch(llvm::Triple::UnknownArch);
  }
}

void clang_Triple_setVendor(CXTriple T, CXTriple_VendorType VT) {
  switch (VT) {
  case CXTriple_Apple:
    static_cast<llvm::Triple *>(T)->setVendor(llvm::Triple::Apple);
    break;
  case CXTriple_PC:
    static_cast<llvm::Triple *>(T)->setVendor(llvm::Triple::PC);
    break;
  case CXTriple_IBM:
    static_cast<llvm::Triple *>(T)->setVendor(llvm::Triple::IBM);
    break;
  case CXTriple_ImaginationTechnologies:
    static_cast<llvm::Triple *>(T)->setVendor(
        llvm::Triple::ImaginationTechnologies);
    break;
  case CXTriple_NVIDIA:
    static_cast<llvm::Triple *>(T)->setVendor(llvm::Triple::NVIDIA);
    break;
  case CXTriple_AMD:
    static_cast<llvm::Triple *>(T)->setVendor(llvm::Triple::AMD);
    break;
  case CXTriple_Mesa:
    static_cast<llvm::Triple *>(T)->setVendor(llvm::Triple::Mesa);
    break;
  case CXTriple_SUSE:
    static_cast<llvm::Triple *>(T)->setVendor(llvm::Triple::SUSE);
    break;
  default:
    static_cast<llvm::Triple *>(T)->setVendor(llvm::Triple::UnknownVendor);
  }
}

void clang_Triple_setOS(CXTriple T, CXTriple_OSType OST) {
  switch (OST) {
  case CXTriple_Darwin:
    static_cast<llvm::Triple *>(T)->setOS(llvm::Triple::Darwin);
    break;
  case CXTriple_FreeBSD:
    static_cast<llvm::Triple *>(T)->setOS(llvm::Triple::FreeBSD);
    break;
  case CXTriple_Linux:
    static_cast<llvm::Triple *>(T)->setOS(llvm::Triple::Linux);
    break;
  case CXTriple_MacOSX:
    static_cast<llvm::Triple *>(T)->setOS(llvm::Triple::MacOSX);
    break;
  case CXTriple_Win32:
    static_cast<llvm::Triple *>(T)->setOS(llvm::Triple::Win32);
    break;
  case CXTriple_CUDA:
    static_cast<llvm::Triple *>(T)->setOS(llvm::Triple::CUDA);
    break;
  case CXTriple_NVCL:
    static_cast<llvm::Triple *>(T)->setOS(llvm::Triple::NVCL);
    break;
  case CXTriple_WASI:
    static_cast<llvm::Triple *>(T)->setOS(llvm::Triple::WASI);
    break;
  default:
    static_cast<llvm::Triple *>(T)->setOS(llvm::Triple::UnknownOS);
  }
}

void clang_Triple_setEnvironment(CXTriple T, CXTriple_EnvironmentType ET) {
  switch (ET) {
  case CXTriple_GNU:
    static_cast<llvm::Triple *>(T)->setEnvironment(llvm::Triple::GNU);
    break;
  case CXTriple_GNUEABIHF:
    static_cast<llvm::Triple *>(T)->setEnvironment(llvm::Triple::GNUEABIHF);
    break;
  case CXTriple_Musl:
    static_cast<llvm::Triple *>(T)->setEnvironment(llvm::Triple::Musl);
    break;
  case CXTriple_MuslEABIHF:
    static_cast<llvm::Triple *>(T)->setEnvironment(llvm::Triple::MuslEABIHF);
    break;
  default:
    static_cast<llvm::Triple *>(T)->setEnvironment(
        llvm::Triple::UnknownEnvironment);
  }
}

void clang_Triple_setObjectFormat(CXTriple T, CXTriple_ObjectFormatType OF) {
  switch (OF) {
  case CXTriple_COFF:
    static_cast<llvm::Triple *>(T)->setObjectFormat(llvm::Triple::COFF);
    break;
  case CXTriple_ELF:
    static_cast<llvm::Triple *>(T)->setObjectFormat(llvm::Triple::ELF);
    break;
  case CXTriple_MachO:
    static_cast<llvm::Triple *>(T)->setObjectFormat(llvm::Triple::MachO);
    break;
  case CXTriple_Wasm:
    static_cast<llvm::Triple *>(T)->setObjectFormat(llvm::Triple::Wasm);
    break;
  case CXTriple_XCOFF:
    static_cast<llvm::Triple *>(T)->setObjectFormat(llvm::Triple::XCOFF);
    break;
  default:
    static_cast<llvm::Triple *>(T)->setObjectFormat(
        llvm::Triple::UnknownObjectFormat);
  }
}
