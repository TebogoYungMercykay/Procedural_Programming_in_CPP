#include "InputOutput.h"

std::string askForStringInput(const std::string message) {
  std::string input;
  printOut(message);
  std::getline(std::cin, input);
  return input;
}

int askForIntInput(const std::string message) {
  int input;
  printOut(message);
  std::cin >> input;
  std::cin.ignore();
  return input;
}

void printOut(const std::string message) { std::cout << message << std::endl; }
