#include "blockChain.h"
#include "providedFiles.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

namespace blockChain {
float **createBlock() {
  float **block = new float *[blockSize];

  for (int i = 0; i < blockSize; i++) {
    block[i] = NULL;
  }

  return block;
}

int insert(float **&block, const float value) {
  if (block == NULL) {
    block = createBlock();

    float *newValue = new float;
    *newValue = value;
    block[0] = newValue;

    return 0;
  }

  int position = 0;
  float **currentBlock = block;

  while (true) {
    for (int i = 0; i < blockSize - 1; i++) {
      if (currentBlock[i] == NULL) {
        float *newValue = new float;
        *newValue = value;
        currentBlock[i] = newValue;
        return position;
      }
      position++;
    }

    if (currentBlock[blockSize - 1] == NULL) {
      float **newBlock = createBlock();

      currentBlock[blockSize - 1] = providedFunctions::convert(newBlock);

      float *newValue = new float;
      *newValue = value;
      newBlock[0] = newValue;

      return position;
    } else {
      currentBlock = providedFunctions::convert(currentBlock[blockSize - 1]);
    }
  }
}

int remove(float **&block, const float value) {
  if (block == NULL) {
    return 0;
  }

  int count = 0;
  float **currentBlock = block;

  while (currentBlock != NULL) {
    for (int i = 0; i < blockSize - 1; i++) {
      if (currentBlock[i] != NULL && *(currentBlock[i]) == value) {
        delete currentBlock[i];
        currentBlock[i] = NULL;
        count++;
      }
    }

    if (currentBlock[blockSize - 1] != NULL) {
      currentBlock = providedFunctions::convert(currentBlock[blockSize - 1]);
    } else {
      break;
    }
  }

  return count;
}

void sort(float **block) {
  if (block == NULL) {
    return;
  }

  int count = numberOfFloats(block);

  if (count == 0) {
    return;
  }

  float *allValues = toArray(block);

  bool swapped;
  for (int i = 0; i < count - 1; i++) {
    swapped = false;
    for (int j = 0; j < count - i - 1; j++) {
      if (allValues[j] > allValues[j + 1]) {
        float temp = allValues[j];
        allValues[j] = allValues[j + 1];
        allValues[j + 1] = temp;
        swapped = true;
      }
    }

    if (!swapped) {
      break;
    }
  }

  float **currentBlock = block;
  int valueIndex = 0;

  while (currentBlock != NULL && valueIndex < count) {
    for (int i = 0; i < blockSize - 1 && valueIndex < count; i++) {
      if (currentBlock[i] != NULL) {
        *(currentBlock[i]) = allValues[valueIndex++];
      } else {
        float *newValue = new float;
        *newValue = allValues[valueIndex++];
        currentBlock[i] = newValue;
      }
    }

    if (currentBlock[blockSize - 1] != NULL) {
      currentBlock = providedFunctions::convert(currentBlock[blockSize - 1]);
    } else {
      break;
    }
  }

  delete[] allValues;

  currentBlock = block;

  while (currentBlock != NULL) {
    for (int i = 0; i < blockSize - 1; i++) {
      if (valueIndex <= 0) {
        if (currentBlock[i] != NULL) {
          delete currentBlock[i];
          currentBlock[i] = NULL;
        }
      } else {
        valueIndex--;
      }
    }

    if (currentBlock[blockSize - 1] != NULL) {
      currentBlock = providedFunctions::convert(currentBlock[blockSize - 1]);
    } else {
      break;
    }
  }
}

float *toArray(float **block) {
  if (block == NULL) {
    return NULL;
  }

  int count = numberOfFloats(block);

  if (count == 0) {
    return NULL;
  }

  float *result = new float[count];

  float **currentBlock = block;
  int index = 0;

  while (currentBlock != NULL) {
    for (int i = 0; i < blockSize - 1; i++) {
      if (currentBlock[i] != NULL) {
        result[index++] = *(currentBlock[i]);
      }
    }

    if (currentBlock[blockSize - 1] != NULL) {
      currentBlock = providedFunctions::convert(currentBlock[blockSize - 1]);
    } else {
      break;
    }
  }

  return result;
}

void destroy(float **&block) {
  if (block == NULL) {
    return;
  }

  bool currentBlockEmpty = true;
  for (int i = 0; i < blockSize - 1; i++) {
    if (block[i] != NULL) {
      currentBlockEmpty = false;
      break;
    }
  }

  float **nextBlock = NULL;
  if (block[blockSize - 1] != NULL) {
    nextBlock = providedFunctions::convert(block[blockSize - 1]);
  }

  if (currentBlockEmpty) {
    delete[] block;
    block = nextBlock;
    destroy(block);
  } else {
    float **current = block;

    if (nextBlock != NULL) {
      destroy(nextBlock);
      current[blockSize - 1] = providedFunctions::convert(nextBlock);
    }
  }
}

bool isEmpty(float **&block) {
  if (block == NULL) {
    return true;
  }

  float **currentBlock = block;

  while (currentBlock != NULL) {
    for (int i = 0; i < blockSize - 1; i++) {
      if (currentBlock[i] != NULL) {
        return false;
      }
    }

    if (currentBlock[blockSize - 1] != NULL) {
      currentBlock = providedFunctions::convert(currentBlock[blockSize - 1]);
    } else {
      break;
    }
  }

  return true;
}

void repack(float **&block) {
  if (block == NULL || isEmpty(block)) {
    return;
  }

  int count = numberOfFloats(block);
  float *allValues = toArray(block);

  float **currentBlock = block;
  while (currentBlock != NULL) {
    for (int i = 0; i < blockSize - 1; i++) {
      if (currentBlock[i] != NULL) {
        delete currentBlock[i];
        currentBlock[i] = NULL;
      }
    }

    if (currentBlock[blockSize - 1] != NULL) {
      currentBlock = providedFunctions::convert(currentBlock[blockSize - 1]);
    } else {
      break;
    }
  }

  currentBlock = block;
  int valueIndex = 0;

  while (valueIndex < count) {
    for (int i = 0; i < blockSize - 1 && valueIndex < count; i++) {
      float *newValue = new float;
      *newValue = allValues[valueIndex++];
      currentBlock[i] = newValue;
    }

    if (valueIndex < count) {
      if (currentBlock[blockSize - 1] == NULL) {
        float **newBlock = createBlock();
        currentBlock[blockSize - 1] = providedFunctions::convert(newBlock);
      }
      currentBlock = providedFunctions::convert(currentBlock[blockSize - 1]);
    }
  }

  if (currentBlock != NULL && currentBlock[blockSize - 1] != NULL) {
    float **nextBlock = providedFunctions::convert(currentBlock[blockSize - 1]);
    delete[] nextBlock;
    currentBlock[blockSize - 1] = NULL;
  }

  delete[] allValues;
}

bool search(float **block, const float value) {
  if (block == NULL) {
    return false;
  }

  float **currentBlock = block;

  while (currentBlock != NULL) {
    for (int i = 0; i < blockSize - 1; i++) {
      if (currentBlock[i] != NULL && *(currentBlock[i]) == value) {
        return true;
      }
    }

    if (currentBlock[blockSize - 1] != NULL) {
      currentBlock = providedFunctions::convert(currentBlock[blockSize - 1]);
    } else {
      break;
    }
  }

  return false;
}

float *get(float **block, int position) {
  if (block == NULL || position < 0) {
    return NULL;
  }

  float **currentBlock = block;
  int currentPosition = 0;

  while (currentBlock != NULL) {
    for (int i = 0; i < blockSize - 1; i++) {
      if (currentBlock[i] != NULL) {
        if (currentPosition == position) {
          return currentBlock[i];
        }
        currentPosition++;
      }
    }

    if (currentBlock[blockSize - 1] != NULL) {
      currentBlock = providedFunctions::convert(currentBlock[blockSize - 1]);
    } else {
      break;
    }
  }

  return NULL;
}

int numberOfBlocks(float **block) {
  if (block == NULL) {
    return 0;
  }

  int count = 1;
  float **currentBlock = block;

  while (currentBlock != NULL && currentBlock[blockSize - 1] != NULL) {
    count++;
    currentBlock = providedFunctions::convert(currentBlock[blockSize - 1]);
  }

  return count;
}

int numberOfFloats(float **block) {
  if (block == NULL) {
    return 0;
  }

  int count = 0;
  float **currentBlock = block;

  while (currentBlock != NULL) {
    for (int i = 0; i < blockSize - 1; i++) {
      if (currentBlock[i] != NULL) {
        count++;
      }
    }

    if (currentBlock[blockSize - 1] != NULL) {
      currentBlock = providedFunctions::convert(currentBlock[blockSize - 1]);
    } else {
      break;
    }
  }

  return count;
}

int maxPossibleFloats(float **block) {
  int blocks = numberOfBlocks(block);
  return blocks * (blockSize - 1);
}

float total(float **block) {
  if (block == NULL) {
    return 0;
  }

  float sum = 0;
  float **currentBlock = block;

  while (currentBlock != NULL) {
    for (int i = 0; i < blockSize - 1; i++) {
      if (currentBlock[i] != NULL) {
        sum += *(currentBlock[i]);
      }
    }

    if (currentBlock[blockSize - 1] != NULL) {
      currentBlock = providedFunctions::convert(currentBlock[blockSize - 1]);
    } else {
      break;
    }
  }

  return sum;
}

float average(float **block) {
  if (block == NULL) {
    return 0;
  }

  int count = numberOfFloats(block);

  if (count == 0) {
    return 0;
  }

  return total(block) / count;
}

void adjust(float **block, float value) {
  if (block == NULL || isEmpty(block)) {
    return;
  }

  float **currentBlock = block;

  while (currentBlock != NULL) {
    for (int i = 0; i < blockSize - 1; i++) {
      if (currentBlock[i] != NULL) {
        *(currentBlock[i]) += value;
      }
    }

    if (currentBlock[blockSize - 1] != NULL) {
      currentBlock = providedFunctions::convert(currentBlock[blockSize - 1]);
    } else {
      break;
    }
  }
}

float **loadFromFile(std::string csvFileName) {
  std::fstream file(csvFileName.c_str());

  if (!file.is_open()) {
    return NULL;
  }

  float **chain = NULL;
  std::string line;

  while (std::getline(file, line)) {
    std::stringstream ss(line);
    std::string valueStr;

    while (std::getline(ss, valueStr, ',')) {
      try {
        std::stringstream valueStream(valueStr);
        float value;
        valueStream >> value;
        insert(chain, value);
      } catch (const std::exception &e) {
      }
    }
  }

  file.close();

  return chain;
}
} // namespace blockChain
