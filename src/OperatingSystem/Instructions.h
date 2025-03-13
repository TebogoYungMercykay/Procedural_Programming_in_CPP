#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include <cmath>
#include <iostream>
#include <string>

#include "IO.h"
#include "Memory.h"

namespace Instructions {
extern bool halt;
struct Instruction {
  int opcode;
  int *operands;
};

Instruction *createInstruction(std::string strInstruction);
void destroyInstruction(Instruction *&instruction);

int binaryToInt(std::string binaryString);
int determineNumberOfOperands(int opcode);

void executeInstruction(Instruction *instruction,
                        int &currentInstructionNumber);

void exitOp();
void loadOp(int memoryLocation, int RAMLocation);
void saveOp(int RAMLocation, int memoryLocation);
void addOp(int resultLocation, int inputALocation, int inputBLocation);
void minusOp(int resultLocation, int inputALocation, int inputBLocation);
void greaterOp(int resultLocation, int inputALocation, int inputBLocation);
void lessOp(int resultLocation, int inputALocation, int inputBLocation);
void equalOp(int resultLocation, int inputALocation, int inputBLocation);
void ifOp(int booleanLocation, int trueInstructionNumber,
          int falseInstructionNumber, int &currentInstructionNumber);
void inputOp(int RAMLocation);
void outputOp(int RAMLocation);
void gotoOp(int targetInstructionNumber, int &currentInstructionNumber);
void persistOp();
void reloadOp();
void constOp(int constValue, int RAMLocation);
void moveOp(int sourceLocation, int destinationLocation);

void debugPrintout(const Instruction *instr);

} // namespace Instructions

#endif /*INSTRUCTIONS_H*/