#include "StatsInterface.h"

using namespace std;

float sumDataPoints() {
  STATSCALCULATOR::processFile();
  END = STATSCALCULATOR::getPositionOfLastDataPoint();
  MOVETONEXT = true;
  START = 0;
  return STATSCALCULATOR::sumDataPoints();
}

float sumDataPointsRev() {
  STATSCALCULATOR::processFile();
  START = STATSCALCULATOR::getPositionOfLastDataPoint();
  MOVETONEXT = false;
  END = 0;
  return STATSCALCULATOR::sumDataPoints();
}

float getAverageOfDataPoints() {
  STATSCALCULATOR::processFile();
  END = STATSCALCULATOR::getPositionOfLastDataPoint();
  MOVETONEXT = true;
  START = 0;
  return STATSCALCULATOR::average();
}

float getAverageOfDataPointsRev() {
  STATSCALCULATOR::processFile();
  START = STATSCALCULATOR::getPositionOfLastDataPoint();
  MOVETONEXT = false;
  END = 0;
  return STATSCALCULATOR::average();
}

float getStandardDeviation() {
  STATSCALCULATOR::processFile();
  END = STATSCALCULATOR::getPositionOfLastDataPoint();
  MOVETONEXT = true;
  START = 0;
  AVERAGE = STATSCALCULATOR::average();
  return STATSCALCULATOR::standardDiv();
}

float getStandardDeviationRev() {
  STATSCALCULATOR::processFile();
  START = STATSCALCULATOR::getPositionOfLastDataPoint();
  MOVETONEXT = false;
  END = 0;
  AVERAGE = STATSCALCULATOR::average();
  return STATSCALCULATOR::standardDiv();
}

std::string getListOfPointsInOrder() {
  STATSCALCULATOR::processFile();
  END = STATSCALCULATOR::getPositionOfLastDataPoint();
  MOVETONEXT = true;
  START = 0;
  return STATSCALCULATOR::getPointsInOrder();
}

std::string getPointsInReverseOrder() {
  STATSCALCULATOR::processFile();
  START = STATSCALCULATOR::getPositionOfLastDataPoint();
  MOVETONEXT = false;
  END = 0;
  return STATSCALCULATOR::getPointsInOrder();
}

bool isTheValueInTheList(float value) {
  STATSCALCULATOR::processFile();
  END = STATSCALCULATOR::getPositionOfLastDataPoint();
  MOVETONEXT = true;
  START = 0;
  VALUE = value;
  return STATSCALCULATOR::isValueInList();
}

bool isTheValueInTheListRev(float value) {
  STATSCALCULATOR::processFile();
  START = STATSCALCULATOR::getPositionOfLastDataPoint();
  MOVETONEXT = false;
  END = 0;
  VALUE = value;
  return STATSCALCULATOR::isValueInList();
}

void printValueF(std::string message, float value) {
  std::cout << message << value << std::endl;
}

void printValueS(std::string message, std::string value) {
  std::cout << message << value << std::endl;
}

void printValueB(std::string message, bool value) {
  std::cout << message << value << std::endl;
}
