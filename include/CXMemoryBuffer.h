#ifndef LIBCLANGEX_CXMEMORYBUFFER_H
#define LIBCLANGEX_CXMEMORYBUFFER_H

#include "CXError.h"
#include "CXTypes.h"
#include "clang-c/Platform.h"

#ifdef __cplusplus
extern "C" {
#endif

CINDEX_LINKAGE CXMemoryBuffer clang_MemoryBuffer_getMemBuffer(const char *InputData,
                                                              unsigned InputDataSize,
                                                              const char *BufferName,
                                                              unsigned BufferNameSize,
                                                              bool RequiresNullTerminator);

CINDEX_LINKAGE CXMemoryBuffer clang_MemoryBuffer_getMemBufferCopy(const char *InputData,
                                                                  unsigned InputDataSize,
                                                                  const char *BufferName,
                                                                  unsigned BufferNameSize);

CINDEX_LINKAGE size_t clang_MemoryBuffer_getBufferSize(CXMemoryBuffer MB);

#ifdef __cplusplus
}
#endif
#endif
