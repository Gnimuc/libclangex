#ifndef LIBCLANGEX_CXMEMORYBUFFER_H
#define LIBCLANGEX_CXMEMORYBUFFER_H

#include "CXError.h"
#include "clang-c/Platform.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void *CXMemoryBuffer;

CINDEX_LINKAGE CXMemoryBuffer clang_MemoryBuffer_getMemBuffer(const char *InputData,
                                                              unsigned InputDataSize,
                                                              const char *BufferName,
                                                              unsigned BufferNameSize,
                                                              bool RequiresNullTerminator);

CINDEX_LINKAGE CXMemoryBuffer clang_MemoryBuffer_getMemBufferCopy(const char *InputData,
                                                                  unsigned InputDataSize,
                                                                  const char *BufferName,
                                                                  unsigned BufferNameSize);

#ifdef __cplusplus
}
#endif
#endif
