#ifndef LIBCLANGEX_CXSOURCELOCATION_H
#define LIBCLANGEX_CXSOURCELOCATION_H

#include "clang-ex/CXTypes.h"
#include "clang-c/Platform.h"

#ifdef __cplusplus
extern "C" {
#endif

CINDEX_LINKAGE CXSourceLocation_ clang_SourceLocation_createInvalid(void);

CINDEX_LINKAGE bool clang_SourceLocation_isFileID(CXSourceLocation_ Loc);

CINDEX_LINKAGE bool clang_SourceLocation_isMacroID(CXSourceLocation_ Loc);

CINDEX_LINKAGE bool clang_SourceLocation_isValid(CXSourceLocation_ Loc);

CINDEX_LINKAGE bool clang_SourceLocation_isInvalid(CXSourceLocation_ Loc);

CINDEX_LINKAGE bool clang_SourceLocation_isPairOfFileLocations(CXSourceLocation_ Start,
                                                               CXSourceLocation_ End);

CINDEX_LINKAGE unsigned clang_SourceLocation_getHashValue(CXSourceLocation_ Loc);

CINDEX_LINKAGE void clang_SourceLocation_dump(CXSourceLocation_ Loc, CXSourceManager SM);

CINDEX_LINKAGE char *clang_SourceLocation_printToString(CXSourceLocation_ Loc,
                                                        CXSourceManager SM);

CINDEX_LINKAGE void clang_SourceLocation_disposeString(char *Str);

CINDEX_LINKAGE CXSourceLocation_
clang_SourceLocation_getLocWithOffset(CXSourceLocation_ Loc, int Offset);

#ifdef __cplusplus
}
#endif
#endif