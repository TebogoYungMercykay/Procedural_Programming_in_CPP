#ifndef IO_H
#define IO_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

int strToInt(std::string);
std::string intToBin(int value, int size);

void writeToFile(std::string fileName, const int *array, int size);
void readFromFile(std::string fileName, int *array, int size);

void printError(int errorCode);

int obtainInput();
void printOut(int value);

#endif /*IO_H*/