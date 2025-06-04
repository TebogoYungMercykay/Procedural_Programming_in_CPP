#include "ROBOTS.h"

using namespace std;

std::string ROBOTS::intToString(int v) {
  std::stringstream ss;
  ss << v;
  std::string result;
  ss >> result;
  return result;
}

bool ROBOTS::task1(std::string input) {
  for (int i = 0; i < input.length(); i++) {
    char c = input[i];
    if (!((c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))) {
      return false;
    }
  }
  return true;
}

std::string ROBOTS::task2(std::string input) {
  std::string result = "";
  int base = 3;
  int count = 26;
  int wide = 4;
  for (int i = 0; i < input.length(); i++) {
    char c = input[i];
    int value = (c >= 'A' && c <= 'Z') ? (c - 'A') : (c - '0' + count);

    std::string base3 = "";
    for (int j = 0; j < wide; j++) {
      base3 = char('0' + (value % base)) + base3;
      value /= base;
    }
    result += base3;
  }
  return result;
}

std::string ROBOTS::task3(std::string input) {
  std::string result = "";
  for (int i = 0; i < input.length(); i++) {
    switch (input[i]) {
    case '0':
      result += 'A';
      break;
    case '1':
      result += 'B';
      break;
    case '2':
      result += 'C';
      break;
    default:
      result += '?';
    }
  }
  return result;
}

std::string ROBOTS::task4(std::string input) {
  std::stringstream ss;
  for (int i = 0; i < input.length(); i++) {
    char currentChar = input[i];
    int count = 1;

    for (; i + 1 < input.length() && input[i + 1] == currentChar; i++) {
      count++;
    }

    ss << count << currentChar;
  }
  return ss.str();
}
