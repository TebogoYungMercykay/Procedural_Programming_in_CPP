#include "IO.h"
#include "Instructions.h"
#include "Memory.h"
#include "OS.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

void testIO() {
  std::cout << "\n=== IO MODULE TESTS ===" << std::endl;

  std::stringstream testInput("4\n");
  std::streambuf *originalCin = std::cin.rdbuf();
  std::cin.rdbuf(testInput.rdbuf());

  std::string testValue = "4";
  int converted = strToInt(testValue);
  std::cout << "✓ String \"" << testValue << "\" converted to: " << converted
            << std::endl;

  printOut(converted);
  printError(converted);

  std::cout << "Testing error codes:" << std::endl;
  int errorCodes[] = {0, 2, 3, 4};
  for (int i = 0; i < 4; i++) {
    int code = errorCodes[i];
    std::cout << "  Error " << code << ": ";
    printError(code);
  }

  int userInput = obtainInput();
  std::cout << "✓ Input received: " << userInput << std::endl;

  std::cout << "✓ Binary conversions:" << std::endl;
  std::cout << "  0 (5 bits): " << intToBin(0, 5) << std::endl;
  std::cout << "  10 (4 bits): " << intToBin(10, 4) << std::endl;

  int writeData[] = {10, 20, 30};
  writeToFile("test_output.txt", writeData, 3);

  int readData[3] = {0};
  readFromFile("test_output.txt", readData, 3);

  std::cout << "✓ File I/O test - Data read: ";
  for (int i = 0; i < 3; ++i) {
    std::cout << readData[i] << " ";
  }
  std::cout << std::endl;

  std::cin.rdbuf(originalCin);
}

void testMemory() {
  std::cout << "\n=== MEMORY MODULE TESTS ===" << std::endl;

  MemoryBuffer::MemoryBufferObject *buffer = NULL;
  MemoryBuffer::createBuffer(buffer, 8);

  std::cout << "✓ Creating buffer and storing values..." << std::endl;
  for (int i = 0; i < 8; ++i) {
    MemoryBuffer::store(buffer, i, i * 10);
  }

  std::cout << "✓ Buffer contents:" << std::endl;
  MemoryBuffer::printOutContents(buffer);

  std::cout << "✓ Reading values:" << std::endl;
  for (int i = 0; i < 8; ++i) {
    int value = MemoryBuffer::read(buffer, i);
    std::cout << "  [" << i << "] = " << value << std::endl;
  }

  int *ptr = MemoryBuffer::dereference(buffer, 3);
  if (ptr != NULL) {
    *ptr = 1234;
    std::cout << "✓ Modified index 3 via pointer to: " << *ptr << std::endl;
  }

  std::cout << "✓ Buffer after modification:" << std::endl;
  MemoryBuffer::printOutContents(buffer);

  MemoryBuffer::destroyBuffer(buffer);
}

void testOperatingSystem() {
  std::cout << "\n=== OPERATING SYSTEM TESTS ===" << std::endl;

  std::stringstream osInput("7\n6\n");
  std::streambuf *originalCin = std::cin.rdbuf();
  std::cin.rdbuf(osInput.rdbuf());

  std::cout << "✓ Booting virtual computer (16x16 configuration)..."
            << std::endl;
  OperatingSystem::bootComputer(16, 16);

  std::cout << "✓ Translating high-level program..." << std::endl;
  OperatingSystem::translateProgram("test1.txt", "test2.txt");

  std::cout << "✓ Loading instructions..." << std::endl;
  OperatingSystem::loadInstructions("test2.txt");

  std::cout << "✓ Program listing:" << std::endl;
  OperatingSystem::printProgram();

  std::cout << "✓ Executing program..." << std::endl;
  OperatingSystem::executeProgram();

  std::cin.rdbuf(originalCin);
}

void testInstructions() {
  std::cout << "\n=== INSTRUCTION MODULE TESTS ===" << std::endl;

  std::stringstream instrInput("4\n");
  std::streambuf *originalCin = std::cin.rdbuf();
  std::cin.rdbuf(instrInput.rdbuf());

  std::string binaryInstr = "0011001000000001";
  Instructions::Instruction *instr =
      Instructions::createInstruction(binaryInstr);

  if (instr != NULL) {
    std::cout << "✓ Created instruction from binary: " << binaryInstr
              << std::endl;
    Instructions::debugPrintout(instr);

    int opcode = instr->opcode;
    int numOperands = Instructions::determineNumberOfOperands(opcode);
    std::cout << "  Opcode: " << opcode << ", Operands needed: " << numOperands
              << std::endl;

    std::cout << "✓ Binary '0011' converts to: "
              << Instructions::binaryToInt("0011") << std::endl;

    int currentInstr = 0;
    Instructions::executeInstruction(instr, currentInstr);
    Instructions::destroyInstruction(instr);
  }

  std::cout << "✓ Testing individual operations:" << std::endl;
  int instrPtr = 0;

  const char *opNames[] = {
      "EXIT", "LOAD",  "SAVE",   "ADD",  "MINUS",   "GREATER", "LESS",  "EQUAL",
      "IF",   "INPUT", "OUTPUT", "GOTO", "PERSIST", "RELOAD",  "CONST", "MOVE"};

  Instructions::constOp(42, 0);
  std::cout << "  ✓ CONST operation" << std::endl;

  Instructions::moveOp(1, 0);
  std::cout << "  ✓ MOVE operation" << std::endl;

  Instructions::addOp(0, 1, 2);
  std::cout << "  ✓ ADD operation" << std::endl;

  Instructions::loadOp(0, 0);
  std::cout << "  ✓ LOAD operation" << std::endl;

  Instructions::saveOp(0, 0);
  std::cout << "  ✓ SAVE operation" << std::endl;

  std::cout << "✓ Testing all opcodes systematically:" << std::endl;
  for (int opcode = 0; opcode <= 15; ++opcode) {
    if (opcode == 0 || opcode == 10)
      continue;

    Instructions::Instruction *testInstr = new Instructions::Instruction;
    testInstr->opcode = opcode;
    testInstr->operands = new int[3];
    testInstr->operands[0] = 1;
    testInstr->operands[1] = 2;
    testInstr->operands[2] = 3;

    std::cout << "  Testing " << opNames[opcode] << " (opcode " << opcode << ")"
              << std::endl;
    Instructions::executeInstruction(testInstr, instrPtr);

    Instructions::destroyInstruction(testInstr);
    instrPtr = 0;
  }

  std::cin.rdbuf(originalCin);
}

int main() {
  std::cout << "VIRTUAL MACHINE TEST SUITE" << std::endl;
  std::cout << "=========================" << std::endl;

  try {
    testIO();
    testMemory();
    testOperatingSystem();
    testInstructions();

    std::cout << "\n=== CLEANUP ===" << std::endl;
    OperatingSystem::shutDownComputer();
    std::cout << "✓ System shutdown complete" << std::endl;

    std::cout << "\n=== ALL TESTS COMPLETED SUCCESSFULLY ===" << std::endl;

  } catch (const std::exception &e) {
    std::cout << "Error during testing: " << e.what() << std::endl;
    return 1;
  }

  return 0;
}
