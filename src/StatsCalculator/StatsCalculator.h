#ifndef STATSCALCULATOR_H
#define STATSCALCULATOR_H

#include <cmath>
#include <fstream>
#include <sstream>
#include <string>

#include "AlgorithmConfiguration.h"

namespace STATSCALCULATOR {
extern std::string fileName;
extern float *dataPoints;
extern int numberOfDataPoints;


void setFileName(std::string fileName);
void processFile();
float stof(std::string v);
std::string ftos(float v);
int getPositionOfLastDataPoint();
float sumDataPoints();
float average();
float standardDiv();
std::string getPointsInOrder();
bool isValueInList();
void clearMemory();

} // namespace STATSCALCULATOR

#endif // STATSCALCULATOR_H