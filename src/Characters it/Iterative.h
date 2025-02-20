#ifndef ITERATIVE_H
#define ITERATIVE_H

#include <iostream>

namespace Iterative {
int length(const char *start);
char find(const char *start, int index);
bool contains(const char *start, char letter);
void printout(const char *start);
void reverseWord(char *start, char *result);
int countOccurrences(const char *start, char c);
char mostFrequentLetter(const char *start);
void printInReverse(const char *start);
char *findLastLetter(char *start);
const char *findLastLetter(const char *start);
bool isPalindrome(const char *start);
int charactersBetween(const char *p1, const char *p2);
} // namespace Iterative

#endif /*ITERATIVE_H*/