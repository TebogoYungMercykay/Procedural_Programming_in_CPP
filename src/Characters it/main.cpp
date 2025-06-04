#include "Iterative.h"
#include <iostream>
#include <string>

int main() {
  Iterative::printInReverse("Hello");
  Iterative::printInReverse("");

  bool isAPalindrome = Iterative::isPalindrome("a");
  bool isMadamPalindrome = Iterative::isPalindrome("madam");
  bool isDeedPalindrome = Iterative::isPalindrome("deed");
  bool isEmptyPalindrome = Iterative::isPalindrome("");
  bool isHelloPalindrome = Iterative::isPalindrome("hello");
  bool isWorldPalindrome = Iterative::isPalindrome("world");

  char mostFreqMiss = Iterative::mostFrequentLetter("Mississippi");

  std::cout << "Most frequent in 'Mississippi': " << mostFreqMiss << std::endl;

  char mostFreqHello = Iterative::mostFrequentLetter("Hello");
  std::cout << "Most frequent in 'Hello': " << mostFreqHello << std::endl;

  char mostFreqAbcba = Iterative::mostFrequentLetter("abcba");
  std::cout << "Most frequent in 'abcba': " << mostFreqAbcba << std::endl;

  char mostFreqA = Iterative::mostFrequentLetter("a");
  std::cout << "Most frequent in 'a': " << mostFreqA << std::endl;

  Iterative::printout("Hello");

  Iterative::printout("");

  int countI = Iterative::countOccurrences("Mississippi", 'i');
  std::cout << "Num of 'i' in 'Mississippi': " << countI << std::endl;

  int countL = Iterative::countOccurrences("Hello", 'l');
  std::cout << "Num of 'l' in 'Hello': " << countL << std::endl;

  int countZ = Iterative::countOccurrences("Hello", 'z');
  std::cout << "Num of 'z' in 'Hello': " << countZ << std::endl;

  int countEmptyA = Iterative::countOccurrences("", 'a');
  std::cout << "Num of 'a' in empty string: " << countEmptyA << std::endl;

  std::cout << "Element at position 0 in 'Hello': "
            << Iterative::find("Hello", 0) << std::endl;
  std::cout << "Element at position 4 in 'Hello': "
            << Iterative::find("Hello", 4) << std::endl;

  char result = Iterative::find("Hello", 5);

  result = Iterative::find("Hello", -1);

  std::string s1 = "tomcat";
  std::string s2 = "warthog";

  int chars1 = Iterative::charactersBetween(&s1[0], &s1[4]);
  std::cout << "Len between 't' and 'a' in 'tomcat': " << chars1 << std::endl;

  int chars2 = Iterative::charactersBetween(&s1[0], &s2[0]);
  std::cout << "Len between 't' in 'tomcat' and 'w' in 'warthog': " << chars2
            << std::endl;

  int chars3 = Iterative::charactersBetween(&s1[0], &s1[0]);
  std::cout << "Len between 't' and 't' in 'tomcat': " << chars3 << std::endl;

  int chars4 = Iterative::charactersBetween(&s1[0], &s1[1]);
  std::cout << "Len between 't' and 'o' in 'tomcat': " << chars4 << std::endl;

  bool containsH = Iterative::contains("Hello", 'H');
  bool containsE = Iterative::contains("Hello", 'e');
  bool containsZ = Iterative::contains("Hello", 'z');
  bool emptyContainsA = Iterative::contains("", 'a');

  char str1[] = "Hello";
  char *lastChar1 = Iterative::findLastLetter(str1);
  std::cout << "Last character of 'Hello': " << *lastChar1 << std::endl;

  const char *str2 = "World";
  const char *lastChar2 = Iterative::findLastLetter(str2);
  std::cout << "Last character of 'World': " << *lastChar2 << std::endl;

  char str3[] = "";
  char *lastChar3 = Iterative::findLastLetter(str3);

  const char *str4 = "";
  const char *lastChar4 = Iterative::findLastLetter(str4);

  std::cout << "Evaluating length functionality..." << std::endl;
  std::cout << "Empty string length result: " << Iterative::length("")
            << std::endl;
  std::cout << "String 'Hello World' length result: "
            << Iterative::length("Hello World") << std::endl;
  std::cout << "String '123!@#' length result: " << Iterative::length("123!@#")
            << std::endl;

  char result1[10] = {0};
  Iterative::reverseWord("Hello", result1);
  std::cout << "Reversed 'Hello': " << result1 << std::endl;

  char result3[10] = {0};
  Iterative::reverseWord("", result3);
  std::cout << "Reversed empty string: " << result3 << std::endl;

  return 0;
}
