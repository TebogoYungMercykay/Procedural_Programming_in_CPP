#include "TesterHelpers.h"
#include "ValueTesters.h"
#include <iostream>

void passedPrinter(int expected, int received) {
  std::cout << "Value " << received << " was same as expected value of "
            << expected << std::endl;
}

void failedPrinter(int expected, int received) {
  std::cout << "Value " << received << " was not the same as expected value of "
            << expected << std::endl;
}

bool isSame(int expected, int received) {
  if (isEqual(expected, received) == '=') {
    passedPrinter(expected, received);
    return true;
  } else {
    failedPrinter(expected, received);
    return false;
  }
}

bool isDifferent(int expected, int received) {
  if (isEqual(expected, received) == '!') {
    failedPrinter(expected, received);
    return true;
  } else {
    passedPrinter(expected, received);
    return false;
  }
}

int compareTo(int expected, int received) {
  if (isEqual(expected, received) == '=') {
    return 0;
  } else if (relation(expected, received) == '>') {
    return 1;
  } else {
    return -1;
  }
}

void passedPrinter(float expected, float received) {
  std::cout << "Value " << received << " was same as expected value of "
            << expected << std::endl;
}

void failedPrinter(float expected, float received) {
  std::cout << "Value " << received << " was not the same as expected value of "
            << expected << std::endl;
}

bool isSame(float expected, float received) {
  if (isEqual(expected, received) == '=') {
    passedPrinter(expected, received);
    return true;
  } else {
    failedPrinter(expected, received);
    return false;
  }
}

bool isDifferent(float expected, float received) {
  if (isEqual(expected, received) == '!') {
    failedPrinter(expected, received);
    return true;
  } else {
    passedPrinter(expected, received);
    return false;
  }
}

int compareTo(float expected, float received) {
  if (isEqual(expected, received) == '=') {
    return 0;
  } else if (relation(expected, received) == '>') {
    return 1;
  } else {
    return -1;
  }
}

void passedPrinter(double expected, double received) {
  std::cout << "Value " << received << " was same as expected value of "
            << expected << std::endl;
}

void failedPrinter(double expected, double received) {
  std::cout << "Value " << received << " was not the same as expected value of "
            << expected << std::endl;
}

bool isSame(double expected, double received) {
  if (isEqual(expected, received) == '=') {
    passedPrinter(expected, received);
    return true;
  } else {
    failedPrinter(expected, received);
    return false;
  }
}

bool isDifferent(double expected, double received) {
  if (isEqual(expected, received) == '!') {
    failedPrinter(expected, received);
    return true;
  } else {
    passedPrinter(expected, received);
    return false;
  }
}

int compareTo(double expected, double received) {
  if (isEqual(expected, received) == '=') {
    return 0;
  } else if (relation(expected, received) == '>') {
    return 1;
  } else {
    return -1;
  }
}
