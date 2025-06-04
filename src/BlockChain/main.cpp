#include "blockChain.h"
#include <fstream>
#include <iostream>

void printBlockChain(float **block) {
  if (block == NULL) {
    std::cout << "Block chain is NULL" << std::endl;
    return;
  }

  if (blockChain::isEmpty(block)) {
    std::cout << "Block chain is empty" << std::endl;
    return;
  }

  std::cout << "Block chain contents:" << std::endl;
  float **currentBlock = block;
  int blockIndex = 0;

  while (currentBlock != NULL) {
    std::cout << "Block " << blockIndex << ": ";
    for (int i = 0; i < blockChain::blockSize - 1; i++) {
      if (currentBlock[i] != NULL) {
        std::cout << *(currentBlock[i]) << " ";
      } else {
        std::cout << "NULL ";
      }
    }
    std::cout << std::endl;

    if (currentBlock[blockChain::blockSize - 1] != NULL) {
      currentBlock =
          providedFunctions::convert(currentBlock[blockChain::blockSize - 1]);
      blockIndex++;
    } else {
      break;
    }
  }
}

void createTestCSVFile(const std::string &filename,
                       const std::string &content) {
  std::ofstream file(filename.c_str());
  file << content;
  file.close();
}

int main() {
  std::cout << "BlockChain <Test> Program" << std::endl;
  std::cout << "----------------------" << std::endl;

  std::cout << "\n=== Test 1: Basic Operations ===" << std::endl;

  std::cout << "\nCreating two empty blocks:" << std::endl;
  float **block1 = blockChain::createBlock();
  float **block2 = blockChain::createBlock();

  std::cout << "Is block1 empty? "
            << (blockChain::isEmpty(block1) ? "Yes" : "No") << std::endl;
  std::cout << "Is block2 empty? "
            << (blockChain::isEmpty(block2) ? "Yes" : "No") << std::endl;

  std::cout << "\nInserting values into block1:" << std::endl;
  float values1[] = {10.5f, 20.3f, 30.7f, 15.2f};
  for (int i = 0; i < 4; i++) {
    blockChain::insert(block1, values1[i]);
  }

  std::cout << "Inserting values into block2:" << std::endl;
  float values2[] = {50.1f, 60.8f};
  for (int i = 0; i < 2; i++) {
    blockChain::insert(block2, values2[i]);
  }

  std::cout << "\nAfter insertions:" << std::endl;
  std::cout << "Is block1 empty? "
            << (blockChain::isEmpty(block1) ? "Yes" : "No") << std::endl;
  std::cout << "Is block2 empty? "
            << (blockChain::isEmpty(block2) ? "Yes" : "No") << std::endl;

  std::cout << "\nBlock1 contents:" << std::endl;
  printBlockChain(block1);

  std::cout << "\nBlock2 contents:" << std::endl;
  printBlockChain(block2);

  std::cout << "\nSearching values in block1:" << std::endl;
  std::cout << "Is 10.5 in block1? "
            << (blockChain::search(block1, 10.5f) ? "Yes" : "No") << std::endl;
  std::cout << "Is 40.0 in block1? "
            << (blockChain::search(block1, 40.0f) ? "Yes" : "No") << std::endl;

  std::cout << "Searching values in block2:" << std::endl;
  std::cout << "Is 50.1 in block2? "
            << (blockChain::search(block2, 50.1f) ? "Yes" : "No") << std::endl;
  std::cout << "Is 30.7 in block2? "
            << (blockChain::search(block2, 30.7f) ? "Yes" : "No") << std::endl;

  std::cout << "\nGetting values from block1:" << std::endl;
  float *value0 = blockChain::get(block1, 0);
  if (value0 != NULL) {
    std::cout << "Value at position 0: " << *value0 << std::endl;
  }

  float *value2 = blockChain::get(block1, 2);
  if (value2 != NULL) {
    std::cout << "Value at position 2: " << *value2 << std::endl;
  }

  std::cout << "\nCounting blocks and floats:" << std::endl;
  std::cout << "Number of blocks in block1: "
            << blockChain::numberOfBlocks(block1) << std::endl;
  std::cout << "Number of floats in block1: "
            << blockChain::numberOfFloats(block1) << std::endl;
  std::cout << "Number of blocks in block2: "
            << blockChain::numberOfBlocks(block2) << std::endl;
  std::cout << "Number of floats in block2: "
            << blockChain::numberOfFloats(block2) << std::endl;

  std::cout << "\n\n=== Test 2: Advanced Operations ===" << std::endl;

  std::cout << "\nCalculating totals and averages:" << std::endl;
  std::cout << "Total of block1: " << blockChain::total(block1) << std::endl;
  std::cout << "Average of block1: " << blockChain::average(block1)
            << std::endl;
  std::cout << "Total of block2: " << blockChain::total(block2) << std::endl;
  std::cout << "Average of block2: " << blockChain::average(block2)
            << std::endl;

  std::cout << "\nMaximum possible floats:" << std::endl;
  std::cout << "Max possible floats in block1: "
            << blockChain::maxPossibleFloats(block1) << std::endl;
  std::cout << "Max possible floats in block2: "
            << blockChain::maxPossibleFloats(block2) << std::endl;

  std::cout << "\nAdjusting values:" << std::endl;
  std::cout << "Adjusting block1 by +5.0" << std::endl;
  blockChain::adjust(block1, 5.0f);
  std::cout << "Adjusting block2 by -10.0" << std::endl;
  blockChain::adjust(block2, -10.0f);

  std::cout << "\nBlock1 after adjustment:" << std::endl;
  printBlockChain(block1);
  std::cout << "\nBlock2 after adjustment:" << std::endl;
  printBlockChain(block2);

  std::cout << "\nRecalculating totals and averages after adjustment:"
            << std::endl;
  std::cout << "Total of block1: " << blockChain::total(block1) << std::endl;
  std::cout << "Average of block1: " << blockChain::average(block1)
            << std::endl;
  std::cout << "Total of block2: " << blockChain::total(block2) << std::endl;
  std::cout << "Average of block2: " << blockChain::average(block2)
            << std::endl;

  std::cout << "\n\n=== Test 3: File Operations and More ===" << std::endl;

  std::string fileName = "test_data.csv";
  std::cout << "\nCreating a CSV file '" << fileName << "' with test data"
            << std::endl;
  createTestCSVFile(fileName, "45.6,22.1,33.9\n71.5,58.2");

  std::cout << "Loading data from file '" << fileName << "'" << std::endl;
  float **blockFromFile = blockChain::loadFromFile(fileName);

  std::cout << "\nBlock loaded from file:" << std::endl;
  printBlockChain(blockFromFile);

  std::cout << "\nTrying to load from non-existent file 'nonexistent.csv'"
            << std::endl;
  float **nonExistentBlock = blockChain::loadFromFile("nonexistent.csv");
  if (nonExistentBlock == NULL) {
    std::cout << "File not found, returned NULL as expected" << std::endl;
  }

  std::cout << "\nRemoving values:" << std::endl;
  std::cout << "Removing 15.2 from block1" << std::endl;
  int removed1 = blockChain::remove(block1, 15.2f + 5.0f);
  std::cout << "Removed " << removed1 << " occurrence(s)" << std::endl;

  std::cout << "Removing 22.1 from file-loaded block" << std::endl;
  int removed2 = blockChain::remove(blockFromFile, 22.1f);
  std::cout << "Removed " << removed2 << " occurrence(s)" << std::endl;

  std::cout << "\nBlock1 after removal:" << std::endl;
  printBlockChain(block1);
  std::cout << "\nFile-loaded block after removal:" << std::endl;
  printBlockChain(blockFromFile);

  std::cout << "\nConverting blocks to arrays:" << std::endl;

  float *array1 = blockChain::toArray(block1);
  if (array1 != NULL) {
    std::cout << "Block1 as array: ";
    for (int i = 0; i < blockChain::numberOfFloats(block1); i++) {
      std::cout << array1[i] << " ";
    }
    std::cout << std::endl;
  }

  float *array2 = blockChain::toArray(blockFromFile);
  if (array2 != NULL) {
    std::cout << "File-loaded block as array: ";
    for (int i = 0; i < blockChain::numberOfFloats(blockFromFile); i++) {
      std::cout << array2[i] << " ";
    }
    std::cout << std::endl;
  }

  std::cout << "\nSorting blocks:" << std::endl;
  std::cout << "Sorting block1" << std::endl;
  blockChain::sort(block1);
  std::cout << "Sorting file-loaded block" << std::endl;
  blockChain::sort(blockFromFile);

  std::cout << "\nBlock1 after sorting:" << std::endl;
  printBlockChain(block1);
  std::cout << "\nFile-loaded block after sorting:" << std::endl;
  printBlockChain(blockFromFile);

  std::cout << "\nRepacking blocks:" << std::endl;
  std::cout << "Repacking block1" << std::endl;
  blockChain::repack(block1);
  std::cout << "Repacking file-loaded block" << std::endl;
  blockChain::repack(blockFromFile);

  std::cout << "\nBlock1 after repacking:" << std::endl;
  printBlockChain(block1);
  std::cout << "\nFile-loaded block after repacking:" << std::endl;
  printBlockChain(blockFromFile);

  std::cout << "\nDestroying blocks:" << std::endl;

  std::cout << "Creating a block chain with some empty blocks" << std::endl;
  float **emptyChain = blockChain::createBlock();
  float **nextBlock = blockChain::createBlock();
  float **nextNextBlock = blockChain::createBlock();

  emptyChain[blockChain::blockSize - 1] = providedFunctions::convert(nextBlock);
  nextBlock[blockChain::blockSize - 1] =
      providedFunctions::convert(nextNextBlock);

  float *emptyValue = new float(42.0f);
  nextBlock[0] = emptyValue;

  std::cout << "Initial empty chain:" << std::endl;
  printBlockChain(emptyChain);

  std::cout << "\nDestroying empty blocks in the chain" << std::endl;
  blockChain::destroy(emptyChain);

  std::cout << "Chain after destroying empty blocks:" << std::endl;
  printBlockChain(emptyChain);

  std::cout << "\nDestroying block1" << std::endl;
  blockChain::destroy(block1);
  std::cout << "Destroying file-loaded block" << std::endl;
  blockChain::destroy(blockFromFile);

  std::cout << "\nBlock1 after destroy:" << std::endl;
  printBlockChain(block1);
  std::cout << "\nFile-loaded block after destroy:" << std::endl;
  printBlockChain(blockFromFile);

  float **blocks[] = {block1, block2, blockFromFile, emptyChain};
  for (int i = 0; i < 4; i++) {
    float **currentBlock = blocks[i];
    while (currentBlock != NULL) {
      float **nextBlock = NULL;
      if (currentBlock[blockChain::blockSize - 1] != NULL) {
        nextBlock =
            providedFunctions::convert(currentBlock[blockChain::blockSize - 1]);
      }

      for (int j = 0; j < blockChain::blockSize - 1; j++) {
        delete currentBlock[j];
      }
      delete[] currentBlock;

      currentBlock = nextBlock;
    }
  }

  delete[] array1;
  delete[] array2;

  std::cout << "\nBlockChain Test completed successfully!" << std::endl;
  return 0;
}
