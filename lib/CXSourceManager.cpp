#include "clang-ex/CXSourceManager.h"
#include "clang/Basic/FileManager.h"
#include "clang/Basic/SourceLocation.h"
#include "clang/Basic/SourceManager.h"
#include "llvm/Support/MemoryBuffer.h"
#include <cstdio>

CXSourceManager clang_SourceManager_create(CXDiagnosticsEngine Diag, CXFileManager FileMgr,
                                           bool UserFilesAreVolatile,
                                           CXInit_Error *ErrorCode) {
  CXInit_Error Err = CXInit_NoError;
  std::unique_ptr<clang::SourceManager> ptr = std::make_unique<clang::SourceManager>(
      *(static_cast<clang::DiagnosticsEngine *>(Diag)),
      *(static_cast<clang::FileManager *>(FileMgr)), UserFilesAreVolatile);

  if (!ptr) {
    fprintf(stderr, "LIBCLANGEX ERROR: failed to create `clang::SourceManager`\n");
    Err = CXInit_CanNotCreate;
  }

  if (ErrorCode)
    *ErrorCode = Err;

  return ptr.release();
}

void clang_SourceManager_dispose(CXSourceManager SM) {
  delete static_cast<clang::SourceManager *>(SM);
}

void clang_SourceManager_PrintStats(CXSourceManager SM) {
  static_cast<clang::SourceManager *>(SM)->PrintStats();
}

CXFileID clang_SourceManager_createFileIDFromMemoryBuffer(CXSourceManager SM,
                                                          LLVMMemoryBufferRef MB) {
  std::unique_ptr<clang::FileID> ptr =
      std::make_unique<clang::FileID>(static_cast<clang::SourceManager *>(SM)->createFileID(
          std::unique_ptr<llvm::MemoryBuffer>(llvm::unwrap(MB)), clang::SrcMgr::C_User));
  return ptr.release();
}

CXFileID clang_SourceManager_createFileIDFromFileEntry(CXSourceManager SM, CXFileEntry FE,
                                                       CXSourceLocation_ Loc) {
  std::unique_ptr<clang::FileID> ptr =
      std::make_unique<clang::FileID>(static_cast<clang::SourceManager *>(SM)->createFileID(
          static_cast<clang::FileEntry *>(FE),
          clang::SourceLocation::getFromPtrEncoding(Loc), clang::SrcMgr::C_User));
  return ptr.release();
}

// this allocates because `static FileID get(int V)` is a private method and this is
// intended.
CXFileID clang_SourceManager_getMainFileID(CXSourceManager SM) {
  std::unique_ptr<clang::FileID> ptr = std::make_unique<clang::FileID>(
      static_cast<clang::SourceManager *>(SM)->getMainFileID());
  return ptr.release();
}

unsigned clang_FileID_getHashValue(CXFileID FID) {
  return static_cast<clang::FileID *>(FID)->getHashValue();
}

void clang_FileID_dispose(CXFileID FID) { delete static_cast<clang::FileID *>(FID); }

void clang_SourceManager_setMainFileID(CXSourceManager SM, CXFileID FID) {
  static_cast<clang::SourceManager *>(SM)->setMainFileID(
      *static_cast<clang::FileID *>(FID));
}

void clang_SourceManager_overrideFileContents(CXSourceManager SM, CXFileEntry FE,
                                              LLVMMemoryBufferRef MB) {
  static_cast<clang::SourceManager *>(SM)->overrideFileContents(
      static_cast<clang::FileEntry *>(FE),
      std::unique_ptr<llvm::MemoryBuffer>(llvm::unwrap(MB)));
}

// SourceLocation
CXSourceLocation_ clang_SourceLocation_createInvalid(void) {
  return clang::SourceLocation().getPtrEncoding();
}

bool clang_SourceLocation_isFileID(CXSourceLocation_ Loc) {
  return clang::SourceLocation::getFromPtrEncoding(Loc).isFileID();
}

bool clang_SourceLocation_isMacroID(CXSourceLocation_ Loc) {
  return clang::SourceLocation::getFromPtrEncoding(Loc).isMacroID();
}

bool clang_SourceLocation_isValid(CXSourceLocation_ Loc) {
  return clang::SourceLocation::getFromPtrEncoding(Loc).isValid();
}

bool clang_SourceLocation_isInvalid(CXSourceLocation_ Loc) {
  return clang::SourceLocation::getFromPtrEncoding(Loc).isInvalid();
}

bool clang_SourceLocation_isPairOfFileLocations(CXSourceLocation_ Start,
                                                CXSourceLocation_ End) {
  return clang::SourceLocation::isPairOfFileLocations(
      clang::SourceLocation::getFromPtrEncoding(Start),
      clang::SourceLocation::getFromPtrEncoding(End));
}

unsigned clang_SourceLocation_getHashValue(CXSourceLocation_ Loc) {
  return clang::SourceLocation::getFromPtrEncoding(Loc).getHashValue();
}

void clang_SourceLocation_dump(CXSourceLocation_ Loc, CXSourceManager SM) {
  return clang::SourceLocation::getFromPtrEncoding(Loc).dump(
      *static_cast<clang::SourceManager *>(SM));
}

char *clang_SourceLocation_printToString(CXSourceLocation_ Loc, CXSourceManager SM) {
  auto str = clang::SourceLocation::getFromPtrEncoding(Loc).printToString(
      *static_cast<clang::SourceManager *>(SM));
  std::unique_ptr<char[]> ptr = std::make_unique<char[]>(str.size()+1);
  ptr[str.size()+1] = '\0';
  std::copy(str.begin(), str.end(), ptr.get());
  return ptr.release();
}

void clang_SourceLocation_disposeString(char *Str) { delete[] Str; }