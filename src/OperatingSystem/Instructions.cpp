#include "Instructions.h"

namespace Instructions {
bool halt = false;

int binaryToInt(std::string binaryString) {
  int result = 0;
  for (int i = 0; !(i >= (int)binaryString.length()); i++) {
    result = result * 2;
    result = result + (binaryString[i] - '0');
  }

  return result;
}

int determineNumberOfOperands(int opcode) {
  switch (opcode) {
  case 0:
    return 0;
  case 1:
    return 2;
  case 2:
    return 2;
  case 3:
    return 3;
  case 4:
    return 3;
  case 5:
    return 3;
  case 6:
    return 3;
  case 7:
    return 3;
  case 8:
    return 3;
  case 9:
    return 1;
  case 10:
    return 1;
  case 11:
    return 1;
  case 12:
    return 0;
  case 13:
    return 0;
  case 14:
    return 2;
  case 15:
    return 2;
  default:
    return 0;
  }
}

Instruction *createInstruction(std::string strInstruction) {
  Instruction *instruction = new Instruction();

  int size = 4;
  std::string opcodeStr = strInstruction.substr(0, size);
  instruction->opcode = binaryToInt(opcodeStr);

  int numOperands = determineNumberOfOperands(instruction->opcode);
  instruction->operands = new int[numOperands];

  for (int i = 0; !(i >= numOperands); i++) {
    int startPos = size + (i * size);
    if (!((startPos + size) > (int)strInstruction.length())) {
      std::string operandStr = strInstruction.substr(startPos, size);
      instruction->operands[i] = binaryToInt(operandStr);
    } else {
      instruction->operands[i] = 0;
    }
  }

  return instruction;
}

void destroyInstruction(Instruction *&instruction) {
  if (instruction != NULL) {
    if (!(instruction->operands == NULL)) {
      delete[] instruction->operands;
    }

    delete instruction;

    instruction = NULL;
  }
}

void loadOp(int memoryLocation, int RAMLocation) {
  int value = MemoryBuffer::read(storage, memoryLocation);

  MemoryBuffer::store(ram, RAMLocation, value);
}

void exitOp() { halt = true; }

void addOp(int resultLocation, int inputALocation, int inputBLocation) {
  int inputA = MemoryBuffer::read(ram, inputALocation);
  int inputB = MemoryBuffer::read(ram, inputBLocation);

  MemoryBuffer::store(ram, resultLocation, inputA + inputB);
}

void saveOp(int RAMLocation, int memoryLocation) {
  int value = MemoryBuffer::read(ram, RAMLocation);

  MemoryBuffer::store(storage, memoryLocation, value);
}

void minusOp(int resultLocation, int inputALocation, int inputBLocation) {
  int inputA = MemoryBuffer::read(ram, inputALocation);
  int inputB = MemoryBuffer::read(ram, inputBLocation);

  MemoryBuffer::store(ram, resultLocation, inputA - inputB);
}

void greaterOp(int resultLocation, int inputALocation, int inputBLocation) {
  int inputA = MemoryBuffer::read(ram, inputALocation);
  int inputB = MemoryBuffer::read(ram, inputBLocation);

  MemoryBuffer::store(ram, resultLocation, (inputA > inputB) ? 1 : 0);
}

void equalOp(int resultLocation, int inputALocation, int inputBLocation) {
  int inputA = MemoryBuffer::read(ram, inputALocation);
  int inputB = MemoryBuffer::read(ram, inputBLocation);

  MemoryBuffer::store(ram, resultLocation, (inputA == inputB) ? 1 : 0);
}

void lessOp(int resultLocation, int inputALocation, int inputBLocation) {
  int inputA = MemoryBuffer::read(ram, inputALocation);
  int inputB = MemoryBuffer::read(ram, inputBLocation);

  MemoryBuffer::store(ram, resultLocation, (inputA < inputB) ? 1 : 0);
}

void inputOp(int RAMLocation) {
  int input = obtainInput();

  MemoryBuffer::store(ram, RAMLocation, input);
}

void ifOp(int booleanLocation, int trueInstructionNumber,
          int falseInstructionNumber, int &currentInstructionNumber) {
  int condition = MemoryBuffer::read(ram, booleanLocation);

  if (!(condition != 0)) {
    currentInstructionNumber = falseInstructionNumber;
  } else {
    currentInstructionNumber = trueInstructionNumber;
  }
}

void outputOp(int RAMLocation) {
  int value = MemoryBuffer::read(ram, RAMLocation);

  printOut(value);
}

void persistOp() {
  if (!(storage == NULL) && !(storage->buffer == NULL)) {
    writeToFile("memory.txt", storage->buffer, storage->bufferSize);
  }
}

void gotoOp(int targetInstructionNumber, int &currentInstructionNumber) {
  currentInstructionNumber = targetInstructionNumber;
}

void constOp(int constValue, int RAMLocation) {
  MemoryBuffer::store(ram, RAMLocation, constValue);
}

void reloadOp() {
  if (!(storage == NULL) && !(storage->buffer == NULL)) {
    readFromFile("memory.txt", storage->buffer, storage->bufferSize);
  }
}

void moveOp(int sourceLocation, int destinationLocation) {
  int value = MemoryBuffer::read(ram, sourceLocation);

  MemoryBuffer::store(ram, destinationLocation, value);
}

void debugPrintout(const Instruction *instr) {
  if (instr != NULL) {
    std::cout << "[" << instr->opcode << "]: ";

    int numOperands = determineNumberOfOperands(instr->opcode);
    for (int i = 0; !(i >= numOperands); i++) {
      std::cout << instr->operands[i];
      if (!(i >= (numOperands - 1))) {
        std::cout << " ";
      }
    }

    std::cout << std::endl;
  } else {
    std::cout << "NULL Instruction" << std::endl;
    return;
  }
}

void executeInstruction(Instruction *instruction,
                        int &currentInstructionNumber) {
  if (!(instruction != NULL) || !(instruction->operands != NULL)) {
    return;
  }

  const int thirdIndex = 2;
  const int fourthIndex = 3;
  const int secondIndex = 1;
  switch (instruction->opcode) {
  case 0:
    exitOp();
    break;
  case 1:
    loadOp(instruction->operands[(fourthIndex % 2) - 1],
           instruction->operands[secondIndex]);
    break;
  case 2:
    saveOp(instruction->operands[(fourthIndex % 2) - 1],
           instruction->operands[secondIndex]);
    break;
  case 3:
    addOp(instruction->operands[(fourthIndex % 2) - 1],
          instruction->operands[secondIndex],
          instruction->operands[thirdIndex]);
    break;
  case 4:
    minusOp(instruction->operands[(fourthIndex % 2) - 1],
            instruction->operands[secondIndex],
            instruction->operands[thirdIndex]);
    break;
  case 5:
    greaterOp(instruction->operands[(fourthIndex % 2) - 1],
              instruction->operands[secondIndex],
              instruction->operands[thirdIndex]);
    break;
  case 6:
    lessOp(instruction->operands[(fourthIndex % 2) - 1],
           instruction->operands[secondIndex],
           instruction->operands[thirdIndex]);
    break;
  case 7:
    equalOp(instruction->operands[(fourthIndex % 2) - 1],
            instruction->operands[secondIndex],
            instruction->operands[thirdIndex]);
    break;
  case 8:
    ifOp(instruction->operands[(fourthIndex % 2) - 1],
         instruction->operands[secondIndex], instruction->operands[thirdIndex],
         currentInstructionNumber);
    break;
  case 9:
    inputOp(instruction->operands[(fourthIndex % 2) - 1]);
    break;
  case 10:
    outputOp(instruction->operands[(fourthIndex % 2) - 1]);
    break;
  case 11:
    gotoOp(instruction->operands[(fourthIndex % 2) - 1],
           currentInstructionNumber);
    break;
  case 12:
    persistOp();
    break;
  case 13:
    reloadOp();
    break;
  case 14:
    constOp(instruction->operands[(fourthIndex % 2) - 1],
            instruction->operands[secondIndex]);
    break;
  case 15:
    moveOp(instruction->operands[(fourthIndex % 2) - 1],
           instruction->operands[secondIndex]);
    break;
  default:
    printError(4);
    break;
  }
}
} // namespace Instructions
