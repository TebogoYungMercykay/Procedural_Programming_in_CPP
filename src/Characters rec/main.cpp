#include "Recursive.h"
#include <iostream>
#include <string>

int main() {
  Recursive::printInReverse("Hello");
  Recursive::printInReverse("");
  Recursive::printout("Hello");

  Recursive::printout("");

  int countI = Recursive::countOccurrences("Mississippi", 'i');
  std::cout << "Num of 'i' in 'Mississippi': " << countI << std::endl;

  int countL = Recursive::countOccurrences("Hello", 'l');
  std::cout << "Num of 'l' in 'Hello': " << countL << std::endl;

  int countZ = Recursive::countOccurrences("Hello", 'z');
  std::cout << "Num of 'z' in 'Hello': " << countZ << std::endl;

  int countEmptyA = Recursive::countOccurrences("", 'a');
  std::cout << "Num of 'a' in empty string: " << countEmptyA << std::endl;

  std::cout << "Element at position 0 in 'Hello': "
            << Recursive::find("Hello", 0) << std::endl;
  std::cout << "Element at position 4 in 'Hello': "
            << Recursive::find("Hello", 4) << std::endl;

  char result = Recursive::find("Hello", 5);

  result = Recursive::find("Hello", -1);

  std::string s1 = "tomcat";
  std::string s2 = "warthog";

  int chars1 = Recursive::charactersBetween(&s1[0], &s1[4]);
  std::cout << "Len between 't' and 'a' in 'tomcat': " << chars1 << std::endl;

  int chars2 = Recursive::charactersBetween(&s1[0], &s2[0]);
  std::cout << "Len between 't' in 'tomcat' and 'w' in 'warthog': " << chars2
            << std::endl;

  int chars3 = Recursive::charactersBetween(&s1[0], &s1[0]);
  std::cout << "Len between 't' and 't' in 'tomcat': " << chars3 << std::endl;

  int chars4 = Recursive::charactersBetween(&s1[0], &s1[1]);
  std::cout << "Len between 't' and 'o' in 'tomcat': " << chars4 << std::endl;

  bool containsH = Recursive::contains("Hello", 'H');
  bool containsE = Recursive::contains("Hello", 'e');
  bool containsZ = Recursive::contains("Hello", 'z');
  bool emptyContainsA = Recursive::contains("", 'a');

  char str1[] = "Hello";
  char *lastChar1 = Recursive::findLastLetter(str1);
  std::cout << "Last character of 'Hello': " << *lastChar1 << std::endl;

  const char *str2 = "World";
  const char *lastChar2 = Recursive::findLastLetter(str2);
  std::cout << "Last character of 'World': " << *lastChar2 << std::endl;

  char str3[] = "";
  char *lastChar3 = Recursive::findLastLetter(str3);

  const char *str4 = "";
  const char *lastChar4 = Recursive::findLastLetter(str4);

  std::cout << "Evaluating length functionality..." << std::endl;
  std::cout << "Empty string length result: " << Recursive::length("")
            << std::endl;
  std::cout << "String 'Hello World' length result: "
            << Recursive::length("Hello World") << std::endl;
  std::cout << "String '123!@#' length result: " << Recursive::length("123!@#")
            << std::endl;

  char result1[10] = {0};
  Recursive::reverseWord("Hello", result1);
  std::cout << "Reversed 'Hello': " << result1 << std::endl;

  char result3[10] = {0};
  Recursive::reverseWord("", result3);
  std::cout << "Reversed empty string: " << result3 << std::endl;

  return 0;
}
