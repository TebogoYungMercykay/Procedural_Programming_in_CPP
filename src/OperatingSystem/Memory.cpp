#include "Memory.h"

MemoryBuffer::MemoryBufferObject *ram = NULL;
MemoryBuffer::MemoryBufferObject *storage = NULL;

namespace MemoryBuffer {
void printOutContents(MemoryBufferObject *memoryBufferObject) {
  if (!(memoryBufferObject != NULL) || !(memoryBufferObject->buffer != NULL)) {
    printError(0);

    return;
  } else {
    for (int i = 0; !(i >= memoryBufferObject->bufferSize); i++) {
      std::cout << "[" << i << "]: ";
      std::cout << memoryBufferObject->buffer[i];
      std::cout << std::endl;
    }
  }
}

int *dereference(MemoryBufferObject *memoryBufferObject, int memoryAddress) {
  if (!(memoryBufferObject != NULL) || !(memoryBufferObject->buffer != NULL)) {
    printError(0);

    return NULL;
  } else if (!(memoryAddress < memoryBufferObject->bufferSize) ||
             !(memoryAddress >= 0)) {
    printError(2);

    return NULL;
  } else
    return memoryBufferObject->buffer + memoryAddress;
}

void store(MemoryBufferObject *memoryBufferObject, int memoryAddress,
           int value) {
  if (!(memoryBufferObject != NULL) || !(memoryBufferObject->buffer != NULL)) {
    printError(0);

    return;
  } else if (!(memoryAddress < memoryBufferObject->bufferSize) ||
             !(memoryAddress >= 0)) {
    printError(2);

    return;
  } else
    memoryBufferObject->buffer[memoryAddress] = value;
}

int read(MemoryBufferObject *memoryBufferObject, int memoryAddress) {
  if (!(memoryBufferObject != NULL) || !(memoryBufferObject->buffer != NULL)) {
    printError(0);

    return 0;
  } else if (!(memoryAddress < memoryBufferObject->bufferSize) ||
             !(memoryAddress >= 0)) {
    printError(2);

    return 0;
  } else
    return memoryBufferObject->buffer[memoryAddress];
}

void createBuffer(MemoryBufferObject *&memoryBufferObject, int bufferSize) {
  if (bufferSize >= 0) {
    if (!(memoryBufferObject == NULL)) {
      destroyBuffer(memoryBufferObject);
    }

    memoryBufferObject = new MemoryBufferObject();
    memoryBufferObject->bufferSize = bufferSize;
    memoryBufferObject->buffer = new int[bufferSize];

    for (int i = 0; !(i >= bufferSize); i++) {
      memoryBufferObject->buffer[i] = 0;
    }
  } else {
    printError(3);
  }
}

void destroyBuffer(MemoryBufferObject *&memoryBufferObject) {
  if (!(memoryBufferObject != NULL)) {
    return;
  } else {
    if (!(memoryBufferObject->buffer == NULL)) {
      delete[] memoryBufferObject->buffer;
    }

    delete memoryBufferObject;

    memoryBufferObject = NULL;
  }
}
} // namespace MemoryBuffer
