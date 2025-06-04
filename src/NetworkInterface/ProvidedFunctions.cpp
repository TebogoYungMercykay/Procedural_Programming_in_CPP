#include "ProvidedFunctions.h"

using namespace std;

int bitToInt(char bit) {
  if (bit == '0')
    return 0;
  return 1;
}

std::string intToBin(int number) {
  string res = "";
  switch (number % 2) {
  case 0:
    res += "0";
    break;

  default:
    res += "1";
  }

  return number <= 1 ? res : res += intToBin(number / 2);
}

std::string intToBin(int number, int length) {
  string bits = intToBin(number);
  string temp = "";
  for (int i = bits.length() - 1; i >= 0; i--) {
    temp += bits[i];
  }
  bits = temp;
  for (int i = bits.length(); i < length; i++) {
    bits = "0" + bits;
  }
  return bits;
}

std::string stringToBin(std::string str, int length) {
  string bits = "";
  for (int i = 0; i < str.length(); i++) {
    char c = toupper(str[i]);
    int diff = c - 'A';
    bits += intToBin(diff, length);
  }

  return bits;
}

std::string binToString(std::string str, int length) {
  string res = "";
  while (str.length() >= length) {
    string bits = str.substr(0, length);
    str = str.substr(length);
    int val = 0;
    for (int i = 0; i < bits.length(); i++) {
      int v = bitToInt(bits[i]);
      val += v * pow(2, bits.length() - 1 - i);
    }
    res += ('A' + val);
  }
  return res;
}
