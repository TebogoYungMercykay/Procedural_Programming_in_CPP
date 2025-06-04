#ifndef RECURSIVE_H
#define RECURSIVE_H

#include <iostream>

namespace Recursive {
int length(const char *str);
char find(const char *str, int index);
bool contains(const char *str, char letter);
void printout(const char *str);
void reverseWord(char *str, char *result);
int countOccurrences(const char *str, char c);
void printInReverse(const char *str);
char *findLastLetter(char *str);
const char *findLastLetter(const char *str);
int charactersBetween(const char *p1, const char *p2);
} // namespace Recursive

#endif /*RECURSIVE_H*/