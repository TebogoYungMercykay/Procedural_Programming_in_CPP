#ifndef OS_H
#define OS_H

#include <fstream>
#include <string>

#include "IO.h"
#include "Instructions.h"
#include "Memory.h"

namespace OperatingSystem {
extern Instructions::Instruction **programInstructions;
extern int numberOfInstructions;
extern int currentInstructionNumber;

void bootComputer(int ramSize, int storageSize);
void shutDownComputer();

void loadHardDrive(std::string hardDriveDiskName);
int determineNumberOfInstructions(std::string programFile);
void loadInstructions(std::string programFile);

void executeProgram();

void printProgram();
void translateProgram(std::string highLevelFile, std::string lowLevelFile);

} // namespace OperatingSystem

#endif /*OS_H*/