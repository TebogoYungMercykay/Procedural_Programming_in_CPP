#ifndef MEMORY_H
#define MEMORY_H

#include <iostream>

#include "IO.h"

namespace MemoryBuffer {
struct MemoryBufferObject {
  int *buffer;
  int bufferSize;
};

void printOutContents(MemoryBufferObject *memoryBufferObject);
int *dereference(MemoryBufferObject *memoryBufferObject, int memoryAddress);
void store(MemoryBufferObject *memoryBufferObject, int memoryAddress,
           int value);
int read(MemoryBufferObject *memoryBufferObject, int memoryAddress);

void createBuffer(MemoryBuffer::MemoryBufferObject *&memoryBufferObject,
                  int bufferSize);
void destroyBuffer(MemoryBuffer::MemoryBufferObject *&memoryBufferObject);

} // namespace MemoryBuffer

extern MemoryBuffer::MemoryBufferObject *ram;
extern MemoryBuffer::MemoryBufferObject *storage;

#endif /*MEMORY_H*/