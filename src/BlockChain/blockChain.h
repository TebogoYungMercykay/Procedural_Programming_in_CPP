#ifndef BLOCK_CHAIN_H
#define BLOCK_CHAIN_H

#include <fstream>
#include <sstream>
#include <string>

#include "providedFiles.h"

namespace blockChain {
  const int blockSize = 5;
  float **createBlock();
  int insert(float **&block, const float value);
  int remove(float **&block, const float value);
  void sort(float **block);
  float *toArray(float **block);
  void destroy(float **&block);
  bool isEmpty(float **&block);
  void repack(float **&block);
  bool search(float **block, const float value);
  float *get(float **block, int position);
  int numberOfBlocks(float **block);
  int numberOfFloats(float **block);
  int maxPossibleFloats(float **block);
  float total(float **block);
  float average(float **block);
  void adjust(float **block, float value);
  float **loadFromFile(std::string csvFileName);
}; // namespace blockChain

#endif /*BLOCK_CHAIN_H*/