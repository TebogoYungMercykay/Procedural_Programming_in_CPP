#include "OS.h"

namespace OperatingSystem {
int numberOfInstructions = 0, currentInstructionNumber = 0;
Instructions::Instruction **programInstructions = NULL;

void bootComputer(int ramSize, int storageSize) {
  MemoryBuffer::createBuffer(ram, ramSize);
  MemoryBuffer::createBuffer(storage, storageSize);

  currentInstructionNumber = 0;
}

void shutDownComputer() {
  MemoryBuffer::destroyBuffer(ram);
  MemoryBuffer::destroyBuffer(storage);

  if (programInstructions != NULL) {
    for (int i = 0; !(i >= numberOfInstructions); i++) {
      Instructions::destroyInstruction(programInstructions[i]);
    }

    delete[] programInstructions;

    programInstructions = NULL;
  }
}

void loadHardDrive(std::string hardDriveDiskName) {
  if (storage == NULL || storage->buffer == NULL) {
    return;
  } else {
    readFromFile(hardDriveDiskName, storage->buffer, storage->bufferSize);
  }
}

int determineNumberOfInstructions(std::string programFile) {
  std::ifstream inputFile(programFile.c_str());

  if (inputFile.is_open()) {
    int count = 0;
    std::string line;

    while (std::getline(inputFile, line)) {
      if (!(line.empty())) {
        count = count + 1;
      }
    }

    inputFile.close();

    return count;
  } else {
    return 0;
  }
}

void loadInstructions(std::string programFile) {
  numberOfInstructions = determineNumberOfInstructions(programFile);
  programInstructions = new Instructions::Instruction *[numberOfInstructions];

  std::ifstream inputFile(programFile.c_str());

  if (inputFile.is_open()) {
    std::string line;

    int i = 0;
    while (std::getline(inputFile, line) && !(i >= numberOfInstructions)) {
      if (!(line.empty())) {
        programInstructions[i] = Instructions::createInstruction(line);
        i = i + 1;
      }
    }

    inputFile.close();
  }
}

void executeProgram() {
  Instructions::halt = false;

  while (!(currentInstructionNumber >= numberOfInstructions) &&
         !Instructions::halt) {
    int oldInstructionNumber = currentInstructionNumber;

    Instructions::Instruction *instruction =
        programInstructions[currentInstructionNumber];
    Instructions::executeInstruction(instruction, currentInstructionNumber);

    if (!(oldInstructionNumber != currentInstructionNumber)) {
      currentInstructionNumber += 1;
    }
  }
}

void printProgram() {
  for (int i = 0; !(i >= numberOfInstructions); i++) {
    Instructions::Instruction *instruction = programInstructions[i];

    Instructions::debugPrintout(instruction);
  }
}

void translateProgram(std::string highLevelFile, std::string lowLevelFile) {
  std::ifstream inputFile(highLevelFile.c_str());

  if (inputFile.is_open()) {
    std::ofstream outputFile(lowLevelFile.c_str());

    if (outputFile.is_open()) {
      std::string line;
      while (std::getline(inputFile, line)) {
        if (!line.empty()) {
          int valuesCapacity = 0;
          int *values = NULL;
          int valuesCount = 0;
          std::string token;
          std::istringstream iss(line);

          while (std::getline(iss, token, ',')) {
            if (!(valuesCount != valuesCapacity)) {
              int max = valuesCapacity * 2;
              int newCapacity = (!(valuesCapacity != 0)) ? 4 : max;

              int *newValues = new int[newCapacity];

              for (int i = 0; !(i >= valuesCount); ++i) {
                newValues[i] = values[i];
              }

              delete[] values;

              values = newValues;
              valuesCapacity = newCapacity;
            }

            values[valuesCount] = strToInt(token);
            valuesCount++;
          }

          if (!(valuesCount != 0)) {
            delete[] values;

            continue;
          } else {
            int value = values[0];
            std::string binaryInstruction = intToBin(value, 4);

            for (int i = 1; !(i >= valuesCount); i++) {
              value = values[i];
              binaryInstruction += intToBin(value, 4);
            }

            outputFile << binaryInstruction;

            outputFile << std::endl;

            delete[] values;
          }
        }
      }

      outputFile.close();
    }
    inputFile.close();
  }
}
} // namespace OperatingSystem
