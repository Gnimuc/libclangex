#include "clang-ex/Basic/CXSourceLocation.h"
#include "clang/Basic/SourceLocation.h"

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
  std::unique_ptr<char[]> ptr = std::make_unique<char[]>(str.size() + 1);
  ptr[str.size() + 1] = '\0';
  std::copy(str.begin(), str.end(), ptr.get());
  return ptr.release();
}

void clang_SourceLocation_disposeString(char *Str) { delete[] Str; }

CXSourceLocation_ clang_SourceLocation_getLocWithOffset(CXSourceLocation_ Loc, int Offset) {
  return clang::SourceLocation::getFromPtrEncoding(Loc)
      .getLocWithOffset(Offset)
      .getPtrEncoding();
}
