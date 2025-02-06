#include "Assessment.h"
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>

Assessment *constructor(std::string assessmentName, float fullMarks) {
  Assessment *assessment = new Assessment;

  assessment->assessmentName = assessmentName;
  assessment->fullMarks = fullMarks;

  assessment->roster = new StudentDetails **[26];
  for (int i = 0; i < 26; i++) {
    assessment->roster[i] = new StudentDetails *[0];
  }

  assessment->numberOfStudents = new int[26];
  for (int i = 0; i < 26; i++) {
    assessment->numberOfStudents[i] = 0;
  }

  return assessment;
}

void destructor(Assessment *&assessment) {
  if (assessment == NULL) {
    return;
  }

  if (assessment->roster != NULL && assessment->numberOfStudents != NULL) {
    for (int i = 0; i < 26; i++) {
      if (assessment->roster[i] != NULL) {
        for (int j = 0; j < assessment->numberOfStudents[i]; j++) {
          if (assessment->roster[i][j] != NULL) {
            delete assessment->roster[i][j];
          }
        }
        delete[] assessment->roster[i];
      }
    }
    delete[] assessment->roster;
  }

  if (assessment->numberOfStudents != NULL) {
    delete[] assessment->numberOfStudents;
  }

  delete assessment;
  assessment = NULL;
}

void insertStudent(Assessment *&assessment, StudentDetails newStudent) {
  if (assessment == NULL || assessment->roster == NULL ||
      assessment->numberOfStudents == NULL) {
    return;
  }

  char firstLetter = newStudent.lastName[0];
  if (firstLetter >= 'a' && firstLetter <= 'z') {
    firstLetter = firstLetter - 'a' + 'A';
  }
  int letterIndex = firstLetter - 'A';

  if (letterIndex < 0 || letterIndex >= 26) {
    return;
  }

  StudentDetails *student = new StudentDetails;
  student->mark = newStudent.mark;
  student->lastName = newStudent.lastName;
  student->firstName = newStudent.firstName;
  student->didPrepWork = newStudent.didPrepWork;
  student->studentNumber = newStudent.studentNumber;

  bool foundGap = false;
  int currentSize = assessment->numberOfStudents[letterIndex];

  for (int i = 0; i < currentSize; i++) {
    if (assessment->roster[letterIndex][i] == NULL) {
      assessment->roster[letterIndex][i] = student;
      foundGap = true;
      break;
    }
  }

  if (!foundGap) {
    StudentDetails **newArray = new StudentDetails *[currentSize + 1];

    for (int i = 0; i < currentSize; i++) {
      newArray[i] = assessment->roster[letterIndex][i];
    }

    newArray[currentSize] = student;

    delete[] assessment->roster[letterIndex];
    assessment->roster[letterIndex] = newArray;

    assessment->numberOfStudents[letterIndex]++;
  }
}

void loadFromCSV(Assessment *assignment, std::string fileName) {
  if (assignment == NULL) {
    return;
  }

  std::ifstream file(fileName.c_str());
  if (!file.is_open()) {
    return;
  }

  std::string line;
  while (std::getline(file, line)) {
    if (!line.empty()) {
      StudentDetails *studentPtr = constructor(line);
      if (studentPtr != NULL) {
        insertStudent(assignment, *studentPtr);

        destructor(studentPtr);
      }
    }
  }

  file.close();
}

void sort(Assessment *assessment) {
  if (assessment == NULL || assessment->roster == NULL ||
      assessment->numberOfStudents == NULL) {
    return;
  }

  for (int i = 0; i < 26; i++) {
    if (assessment->numberOfStudents[i] > 1) {

      for (int j = 0; j < assessment->numberOfStudents[i] - 1; j++) {
        for (int k = 0; k < assessment->numberOfStudents[i] - j - 1; k++) {
          if (assessment->roster[i][k]->mark >
              assessment->roster[i][k + 1]->mark) {
            StudentDetails *temp = assessment->roster[i][k];
            assessment->roster[i][k] = assessment->roster[i][k + 1];
            assessment->roster[i][k + 1] = temp;
          }
        }
      }
    }
  }
}

int totalNumberOfStudents(Assessment *assessment) {
  if (assessment == NULL || assessment->numberOfStudents == NULL ||
      assessment->roster == NULL) {
    return 0;
  }

  int total = 0;
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < assessment->numberOfStudents[i]; j++) {
      if (assessment->roster[i][j] != NULL) {
        total++;
      }
    }
  }
  return total;
}

float avg(Assessment *assessment) {
  if (assessment == NULL || assessment->roster == NULL ||
      assessment->numberOfStudents == NULL || assessment->fullMarks == 0) {
    return 0;
  }

  int totalStudents = totalNumberOfStudents(assessment);
  if (totalStudents == 0) {
    return 0;
  }

  float totalSum = 0;
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < assessment->numberOfStudents[i]; j++) {
      totalSum += assessment->roster[i][j]->mark;
    }
  }

  return totalSum / totalStudents;
}

int numberThatCompletedPrep(Assessment *assessment) {
  if (assessment == NULL || assessment->roster == NULL ||
      assessment->numberOfStudents == NULL) {
    return 0;
  }

  int count = 0;
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < assessment->numberOfStudents[i]; j++) {
      if (assessment->roster[i][j]->didPrepWork) {
        count++;
      }
    }
  }
  return count;
}

float passRate(Assessment *assessment) {
  if (assessment == NULL || assessment->roster == NULL ||
      assessment->numberOfStudents == NULL || assessment->fullMarks == 0) {
    return 0;
  }

  int totalStudents = totalNumberOfStudents(assessment);
  if (totalStudents == 0) {
    return 0;
  }

  int passCount = 0;
  float passMark = assessment->fullMarks * 0.5f;

  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < assessment->numberOfStudents[i]; j++) {
      if (assessment->roster[i][j]->mark >= passMark) {
        passCount++;
      }
    }
  }

  return (float)passCount / totalStudents;
}

int distinction(Assessment *assessment) {
  if (assessment == NULL || assessment->roster == NULL ||
      assessment->numberOfStudents == NULL || assessment->fullMarks == 0) {
    return 0;
  }

  int distinctionCount = 0;
  float distinctionMark = assessment->fullMarks * 0.75f;

  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < assessment->numberOfStudents[i]; j++) {
      if (assessment->roster[i][j]->mark >= distinctionMark) {
        distinctionCount++;
      }
    }
  }

  return distinctionCount;
}

int fullMarks(Assessment *assessment) {
  if (assessment == NULL || assessment->roster == NULL ||
      assessment->numberOfStudents == NULL || assessment->fullMarks == 0) {
    return 0;
  }

  int fullMarksCount = 0;

  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < assessment->numberOfStudents[i]; j++) {
      if (assessment->roster[i][j]->mark >= assessment->fullMarks) {
        fullMarksCount++;
      }
    }
  }

  return fullMarksCount;
}

StudentDetails *bestStudent(Assessment *assessment) {
  if (assessment == NULL || assessment->roster == NULL ||
      assessment->numberOfStudents == NULL) {
    return NULL;
  }

  if (totalNumberOfStudents(assessment) == 0) {
    return NULL;
  }

  StudentDetails *best = NULL;
  float highestMark = -1;

  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < assessment->numberOfStudents[i]; j++) {
      if (assessment->roster[i][j]->mark > highestMark) {
        highestMark = assessment->roster[i][j]->mark;
        best = assessment->roster[i][j];
      }
    }
  }

  return best;
}

StudentDetails *worstStudent(Assessment *assessment) {
  if (assessment == NULL || assessment->roster == NULL ||
      assessment->numberOfStudents == NULL) {
    return NULL;
  }

  if (totalNumberOfStudents(assessment) == 0) {
    return NULL;
  }

  StudentDetails *worst = NULL;
  float lowestMark = assessment->fullMarks + 1;

  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < assessment->numberOfStudents[i]; j++) {
      if (assessment->roster[i][j]->mark < lowestMark) {
        lowestMark = assessment->roster[i][j]->mark;
        worst = assessment->roster[i][j];
      }
    }
  }

  return worst;
}

char **marksHistogram(Assessment *assessment) {
  char **histogram = new char *[11];
  for (int i = 0; i < 11; i++) {
    histogram[i] = new char[26];
    for (int j = 0; j < 26; j++) {
      histogram[i][j] = ' ';
    }
  }

  for (int j = 0; j < 26; j++) {
    histogram[10][j] = 'A' + j;
  }

  if (assessment == NULL || assessment->roster == NULL ||
      assessment->numberOfStudents == NULL) {
    return histogram;
  }

  for (int letter = 0; letter < 26; letter++) {
    if (assessment->numberOfStudents[letter] > 0) {
      float sum = 0;
      for (int j = 0; j < assessment->numberOfStudents[letter]; j++) {
        sum += assessment->roster[letter][j]->mark;
      }

      float average = sum / assessment->numberOfStudents[letter];
      int rowsToFill = (int)floor((average / assessment->fullMarks) * 10);

      for (int row = 9; row >= (10 - rowsToFill); row--) {
        histogram[row][letter] = 'X';
      }
    }
  }

  return histogram;
}
