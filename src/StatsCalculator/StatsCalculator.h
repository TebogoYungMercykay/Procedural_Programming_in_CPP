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

/// @brief This function sets the data files name
/// @param fileName is the name of the file
void setFileName(std::string fileName);

/// @brief This function reads the contents of the data file and correctly sets
/// the variables.
void processFile();

/// @brief Converts from string to float
/// @param v input string
/// @return a float of the input string
float stof(std::string v);

/// @brief Converts from float to string
/// @param v input float
/// @return a string representation of the float
std::string ftos(float v);

/// @brief This function returns the position of the last data point in the
/// structure
int getPositionOfLastDataPoint();

/// @brief This function will return the sum of all the data points by starting
/// at the START position and moving till it is at the END position, travelling
/// in the direction specified by MOVETONEXT.
float sumDataPoints();

/// @brief This function will return the average of all the data points by
/// starting at the START position and moving till it is at the END position,
/// travelling in the direction specified by MOVETONEXT.
float average();

/// @brief This function will return the standard deviation of all the data
/// points by starting at the START position and moving till it is at the END
/// position, travelling in the direction specified by MOVETONEXT. This function
/// also requires that the AVERAGE variable is set with the average of all of
/// the data points.
float standardDiv();

/// @brief This function will return a string representation of the data points
/// starting at the START position and move till it is at the END position,
/// travelling in the direction specified by MOVETONEXT.
std::string getPointsInOrder();

/// @brief This function determines if the value, specified by the VALUE
/// variable is contained in the list. The algorithm starts at the START
/// position and moves till it is at the END position, travelling in the
/// direction specified by MOVETONEXT. This function also requires that the
/// AVERAGE variable is set with the average of all of the data points.
bool isValueInList();

/// @brief This function MUST be called before returning 0 in the main function.
void clearMemory();

} // namespace STATSCALCULATOR

#endif // STATSCALCULATOR_H