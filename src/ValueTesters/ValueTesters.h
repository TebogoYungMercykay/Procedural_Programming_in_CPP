#ifndef VALUETESTER_H
#define VALUETESTER_H

#include <iostream>
#include <string>

char isEqual(int valueA, int valueB);
char isEqual(float valueA, float valueB);
char isEqual(double valueA, double valueB);

char relation(int valueA, int valueB);
char relation(float valueA, float valueB);
char relation(double valueA, double valueB);

void printEqual(char symbol);
void printRelation(char symbol);

#endif /*VALUETESTER_H*/