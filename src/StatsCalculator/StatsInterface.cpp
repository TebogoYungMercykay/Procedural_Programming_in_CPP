#include "StatsInterface.h"

using namespace std;

float sumDataPoints() {
  STATSCALCULATOR::processFile();
  // Initialise variables below this:
  END = STATSCALCULATOR::getPositionOfLastDataPoint();
  MOVETONEXT = true;
  START = 0;
  // Do not alter line below:
  return STATSCALCULATOR::sumDataPoints();
}

float sumDataPointsRev() {
  STATSCALCULATOR::processFile();
  // Initialise variables below this:
  START = STATSCALCULATOR::getPositionOfLastDataPoint();
  MOVETONEXT = false;
  END = 0;
  // Do not alter line below:
  return STATSCALCULATOR::sumDataPoints();
}

float getAverageOfDataPoints() {
  STATSCALCULATOR::processFile();
  // Initialise variables below this:
  END = STATSCALCULATOR::getPositionOfLastDataPoint();
  MOVETONEXT = true;
  START = 0;
  // Do not alter line below:
  return STATSCALCULATOR::average();
}

float getAverageOfDataPointsRev() {
  STATSCALCULATOR::processFile();
  // Initialise variables below this:
  START = STATSCALCULATOR::getPositionOfLastDataPoint();
  MOVETONEXT = false;
  END = 0;
  // Do not alter line below:
  return STATSCALCULATOR::average();
}

float getStandardDeviation() {
  STATSCALCULATOR::processFile();
  // Initialise variables below this:
  END = STATSCALCULATOR::getPositionOfLastDataPoint();
  MOVETONEXT = true;
  START = 0;
  AVERAGE = STATSCALCULATOR::average();
  // Do not alter line below:
  return STATSCALCULATOR::standardDiv();
}

float getStandardDeviationRev() {
  STATSCALCULATOR::processFile();
  // Initialise variables below this:
  START = STATSCALCULATOR::getPositionOfLastDataPoint();
  MOVETONEXT = false;
  END = 0;
  AVERAGE = STATSCALCULATOR::average();
  // Do not alter line below:
  return STATSCALCULATOR::standardDiv();
}

std::string getListOfPointsInOrder() {
  STATSCALCULATOR::processFile();
  // Initialise variables below this:
  END = STATSCALCULATOR::getPositionOfLastDataPoint();
  MOVETONEXT = true;
  START = 0;
  // Do not alter line below:
  return STATSCALCULATOR::getPointsInOrder();
}

std::string getPointsInReverseOrder() {
  STATSCALCULATOR::processFile();
  // Initialise variables below this:
  START = STATSCALCULATOR::getPositionOfLastDataPoint();
  MOVETONEXT = false;
  END = 0;
  // Do not alter line below:
  return STATSCALCULATOR::getPointsInOrder();
}

bool isTheValueInTheList(float value) {
  STATSCALCULATOR::processFile();
  // Initialise variables below this:
  END = STATSCALCULATOR::getPositionOfLastDataPoint();
  MOVETONEXT = true;
  START = 0;
  VALUE = value;
  // Do not alter line below:
  return STATSCALCULATOR::isValueInList();
}

bool isTheValueInTheListRev(float value) {
  STATSCALCULATOR::processFile();
  // Initialise variables below this:
  START = STATSCALCULATOR::getPositionOfLastDataPoint();
  MOVETONEXT = false;
  END = 0;
  VALUE = value;
  // Do not alter line below:
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
