#ifndef ASSESSMENT_H
#define ASSESSMENT_H

#include <cmath>
#include <fstream>
#include <iostream>

#include "StudentDetails.h"

struct Assessment {
  StudentDetails ***roster;
  int *numberOfStudents;

  std::string assessmentName;
  float fullMarks;
};

Assessment *constructor(std::string assessmentName, float fullMarks);
void destructor(Assessment *&assessment);

void insertStudent(Assessment *&assessment, StudentDetails newStudent);

void sort(Assessment *assessment);

float avg(Assessment *assessment);
int totalNumberOfStudents(Assessment *assessment);
int numberThatCompletedPrep(Assessment *assessment);
float passRate(Assessment *assessment);
int distinction(Assessment *assessment);
int fullMarks(Assessment *assessment);

StudentDetails *bestStudent(Assessment *assessment);
StudentDetails *worstStudent(Assessment *assessment);

// 11x26 table
char **marksHistogram(Assessment *assessment);

void loadFromCSV(Assessment *assignment, std::string fileName);

#endif /*ASSESSMENT_H*/