#ifndef TESTHELPERS_H
#define TESTHELPERS_H

#include <iostream>

void passedPrinter(int expected, int received);
void failedPrinter(int expected, int received);
void passedPrinter(float expected, float received);
void failedPrinter(float expected, float received);
void passedPrinter(double expected, double received);
void failedPrinter(double expected, double received);

bool isSame(int expected, int received);
bool isDifferent(int expected, int received);
bool isSame(float expected, float received);
bool isDifferent(float expected, float received);
bool isSame(double expected, double received);
bool isDifferent(double expected, double received);

int compareTo(int expected, int received);
int compareTo(float expected, float received);
int compareTo(double expected, double received);

#endif /*TESTHELPERS_H*/