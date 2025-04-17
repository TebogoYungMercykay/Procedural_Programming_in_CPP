#include <iostream>

#include "StatsCalculator.h"
#include "StatsInterface.h"

using namespace std;

int main() {
  STATSCALCULATOR::setFileName("studentData.txt");
  STATSCALCULATOR::processFile();

  printStart();
  printEnd();
  printAverage();
  printMoveToNext();
  printValue();

  printValueF("TEST CASE 01: ", sumDataPoints());
  printValueF("TEST CASE 02: ", getStandardDeviation());
  printValueB("TEST CASE 03: ", isTheValueInTheList(2));
  printValueB("TEST CASE 04: ", isTheValueInTheList(50));
  printValueF("TEST CASE 05: ", sumDataPointsRev());
  printValueF("TEST CASE 06: ", getStandardDeviationRev());
  printValueS("TEST CASE 07: ", getPointsInReverseOrder());
  printValueB("TEST CASE 08: ", isTheValueInTheListRev(22));
  printValueF("TEST CASE 09: ", getAverageOfDataPointsRev());
  printValueF("TEST CASE 10: ", getAverageOfDataPoints());
  printValueB("TEST CASE 11: ", isTheValueInTheListRev(2));
  printValueS("TEST CASE 12: ", getListOfPointsInOrder());

  STATSCALCULATOR::clearMemory();

  return 0;
}

/*
The expected output is:
The average of the data points is: 7.75
2 is contained in the list of data points: 0
The list contains: 1 5 10 15
START: 0
END: 3
*/
