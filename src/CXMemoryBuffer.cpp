#include "CXMemoryBuffer.h"
#include "llvm/Support/MemoryBuffer.h"

CXMemoryBuffer clang_MemoryBuffer_getMemBuffer(const char *InputData,
                                               unsigned InputDataSize,
                                               const char *BufferName,
                                               unsigned BufferNameSize,
                                               bool RequiresNullTerminator) {
  auto buffer = llvm::MemoryBuffer::getMemBuffer(
      llvm::StringRef(InputData, InputDataSize),
      llvm::StringRef(BufferName, BufferNameSize), RequiresNullTerminator);
  return buffer.release();
}

CXMemoryBuffer clang_MemoryBuffer_getMemBufferCopy(const char *InputData,
                                                   unsigned InputDataSize,
                                                   const char *BufferName,
                                                   unsigned BufferNameSize) {
  auto buffer = llvm::MemoryBuffer::getMemBufferCopy(
      llvm::StringRef(InputData, InputDataSize),
      llvm::StringRef(BufferName, BufferNameSize));
  return buffer.release();
}
