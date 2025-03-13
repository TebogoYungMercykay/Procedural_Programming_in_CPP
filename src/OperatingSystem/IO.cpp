#include "IO.h"

int strToInt(std::string str) {
  std::istringstream iss(str);
  if (!iss.fail()) {
    int result;
    iss >> result;

    return result;
  } else {
    return 0;
  }
}

std::string intToBin(int value, int size) {
  std::string binary;

  if (value != 0) {
    binary = "";
    int temp = value;
    const int denominator = 2;
    while (!(temp <= 0)) {
      binary = (temp % 2 == 0 ? "0" : "1") + binary;
      temp /= denominator;
    }
  } else {
    binary = "0";
  }

  int length = binary.length();

  if (length < size) {
    while (!((int)binary.length() >= size)) {
      binary = "0" + binary;
    }
  } else {
    binary = binary.substr(length - size);
  }

  return binary;
}

void writeToFile(std::string fileName, const int *array, int size) {
  if (array != NULL && size > 0) {
    std::ofstream outputFile(fileName.c_str());

    if (outputFile.is_open()) {
      for (int i = 0; !(i >= size); i++) {
        outputFile << array[i];
        outputFile << std::endl;
      }

      outputFile.close();
    }
  }
}

void readFromFile(std::string fileName, int *array, int size) {
  if (array != NULL && size > 0) {
    std::ifstream inputFile(fileName.c_str());

    if (inputFile.is_open()) {
      int i = 0;
      int value;

      while (!(i >= size) && inputFile >> value) {
        array[i] = value;
        i += 1;
      }

      while (!(i >= size)) {
        array[i] = 0;
        i += 1;
      }

      inputFile.close();
    }
  }
}

void printError(int errorCode) {
  switch (errorCode) {
  case 2:
    std::cout << "Error: Segfault" << std::endl;
    break;
  case 3:
    std::cout << "Error: Invalid buffer size" << std::endl;
    break;
  case 4:
    std::cout << "Error: Unknown Instruction" << std::endl;
    break;
  case 0:
    std::cout << "Error: Buffer Is Null" << std::endl;
    break;
  default:
    break;
  }
}

void printOut(int value) { std::cout << "Printout: " << value << std::endl; }

int obtainInput() {
  std::cout << "Please enter an input:" << std::endl;

  int userInput;
  std::cin >> userInput;

  return userInput;
}
