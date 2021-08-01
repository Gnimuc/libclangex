#ifndef LIBCLANGEX_CXSOURCEMANAGER_H
#define LIBCLANGEX_CXSOURCEMANAGER_H

#include "clang-ex/CXDiagnostic.h"
#include "clang-ex/CXError.h"
#include "clang-ex/CXFileManager.h"
#include "clang-ex/CXTypes.h"
#include "clang-c/Platform.h"
#include "llvm-c/Types.h"

#ifdef __cplusplus
extern "C" {
#endif

CINDEX_LINKAGE CXSourceManager clang_SourceManager_create(CXDiagnosticsEngine Diag,
                                                          CXFileManager FileMgr,
                                                          bool UserFilesAreVolatile,
                                                          CXInit_Error *ErrorCode);

CINDEX_LINKAGE void clang_SourceManager_dispose(CXSourceManager SM);

CINDEX_LINKAGE void clang_SourceManager_PrintStats(CXSourceManager SM);

CINDEX_LINKAGE unsigned clang_FileID_getHashValue(CXFileID FID);

CINDEX_LINKAGE void clang_FileID_dispose(CXFileID FID);

CINDEX_LINKAGE CXFileID clang_SourceManager_createFileIDFromMemoryBuffer(
    CXSourceManager SM, LLVMMemoryBufferRef MB);

CINDEX_LINKAGE
CXFileID clang_SourceManager_createFileIDFromFileEntry(CXSourceManager SM, CXFileEntry FE,
                                                       CXSourceLocation_ Loc);

CINDEX_LINKAGE CXFileID clang_SourceManager_getMainFileID(CXSourceManager SM);

CINDEX_LINKAGE void clang_SourceManager_setMainFileID(CXSourceManager SM, CXFileID ID);

CINDEX_LINKAGE void clang_SourceManager_overrideFileContents(CXSourceManager SM,
                                                             CXFileEntry FE,
                                                             LLVMMemoryBufferRef MB);

// SourceLocation
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

#ifdef __cplusplus
}
#endif
#endif
