#ifndef STATSINTERFACE_H
#define STATSINTERFACE_H

#include <iostream>
#include <string>

#include "AlgorithmConfiguration.h"
#include "StatsCalculator.h"

// See spec for descriptions of these functions

float sumDataPoints();

float sumDataPointsRev();

float getAverageOfDataPoints();

float getAverageOfDataPointsRev();

float getStandardDeviation();

float getStandardDeviationRev();

std::string getListOfPointsInOrder();

std::string getPointsInReverseOrder();

bool isTheValueInTheList(float value);

bool isTheValueInTheListRev(float value);

void printValueF(std::string message, float value);

void printValueS(std::string message, std::string value);

void printValueB(std::string message, bool value);

#endif // STATSINTERFACE_H