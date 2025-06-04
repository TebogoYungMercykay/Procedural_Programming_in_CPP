#include "Assessment.h"
#include "StudentDetails.h"
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

void createTestCSV(const std::string &filename) {
  std::ofstream file(filename.c_str());
  {
    file << "John,Doe,12265309,57.75,f\n";
    file << "Jane,Smith,47907523,22.28,t\n";
    file << "Peter,Jones,86266278,1.76,f\n";
    file << "Sarah,Williams,60379200,27.51,t\n";
    file << "Alice,Anderson,12345678,85.5,t\n";
    file << "Bob,Brown,23456789,92.0,t\n";
    file << "Charlie,Clark,34567890,67.25,f\n";
    file << "David,Davis,45678901,45.75,t\n";
  }
  file.close();
}

void testStudentDetails() {
  std::cout << "(OUT - 1) Testing StudentDetails..." << std::endl;

  StudentDetails *student1 = constructor("john,doe,12345678,75.5,t");
  if (student1 == NULL) {
    return;
  }
  if (student1->firstName != "John") {
    return;
  }
  if (student1->lastName != "Doe") {
    return;
  }
  if (student1->studentNumber != 12345678) {
    return;
  }
  if (fabs(student1->mark - 75.5) > 0.01) {
    return;
  }
  if (student1->didPrepWork != true) {
    return;
  }

  StudentDetails *student2 =
      constructor("jane", "smith", 87654321, 88.25, false);
  if (student2 == NULL) {
    return;
  }
  if (student2->firstName != "Jane") {
    return;
  }
  if (student2->lastName != "Smith") {
    return;
  }
  if (student2->studentNumber != 87654321) {
    return;
  }
  if (fabs(student2->mark - 88.25) > 0.01) {
    return;
  }
  if (student2->didPrepWork != false) {
    return;
  }

  std::string str1 = toString(*student1);
  if (str1.find("John") == std::string::npos) {
    return;
  }
  if (str1.find("Doe") == std::string::npos) {
    return;
  }
  if (str1.find("t") == std::string::npos) {
    return;
  }

  std::string str2 = toString(*student2);
  if (str2.find("Jane") == std::string::npos) {
    return;
  }
  if (str2.find("Smith") == std::string::npos) {
    return;
  }
  if (str2.find("f") == std::string::npos) {
    return;
  }

  destructor(student1);
  destructor(student2);
  if (student1 != NULL) {
    return;
  }
  if (student2 != NULL) {
    return;
  }

  StudentDetails *nullStudent = NULL;
  destructor(nullStudent);

  std::cout << "(OUT - 2) StudentDetails tests passed!" << std::endl;
}

void testAssessment() {
  std::cout << "(OUT - 3) Testing Assessment..." << std::endl;

  Assessment *assessment = constructor("Test Assessment", 100.0f);
  if (assessment == NULL) {
    return;
  }
  if (assessment->assessmentName != "Test Assessment") {
    return;
  }
  if (fabs(assessment->fullMarks - 100.0f) > 0.01) {
    return;
  }
  if (assessment->roster == NULL) {
    return;
  }
  if (assessment->numberOfStudents == NULL) {
    return;
  }

  for (int i = 0; i < 26; i++) {
    {
      if (assessment->numberOfStudents[i] != 0) {
        return;
      }
      if (assessment->roster[i] == NULL) {
        return;
      }
    }
  }

  if (totalNumberOfStudents(assessment) != 0) {
    return;
  }

  StudentDetails student1;
  student1.firstName = "Alice";
  student1.lastName = "Anderson";
  student1.mark = 85.5f;
  student1.studentNumber = 12345678;
  student1.didPrepWork = true;
  insertStudent(assessment, student1);
  if (totalNumberOfStudents(assessment) != 1) {
    return;
  }
  if (assessment->numberOfStudents[0] != 1) {
    return;
  }

  StudentDetails student2;
  student2.firstName = "Bob";
  student2.lastName = "Brown";
  student2.mark = 92.0f;
  student2.studentNumber = 23456789;
  student2.didPrepWork = true;
  insertStudent(assessment, student2);
  if (totalNumberOfStudents(assessment) != 2) {
    return;
  }
  if (assessment->numberOfStudents[1] != 1) {
    return;
  }

  StudentDetails student3;
  student3.firstName = "Adam";
  student3.lastName = "Apple";
  student3.mark = 78.0f;
  student3.studentNumber = 11111111;
  student3.didPrepWork = false;
  insertStudent(assessment, student3);
  if (totalNumberOfStudents(assessment) != 3) {
    return;
  }
  if (assessment->numberOfStudents[0] != 2) {
    return;
  }

  sort(assessment);
  if (assessment->roster[0][0]->mark >= assessment->roster[0][1]->mark) {
    return;
  }

  StudentDetails *best = bestStudent(assessment);
  StudentDetails *worst = worstStudent(assessment);
  if (best == NULL) {
    return;
  }
  if (worst == NULL) {
    return;
  }
  if (best->mark < worst->mark) {
    return;
  }

  int prepCount = numberThatCompletedPrep(assessment);
  if (prepCount < 0) {
    return;
  }

  float pRate = passRate(assessment);
  if (pRate < 0.0f || pRate > 1.0f) {
    return;
  }

  float dCount = distinction(assessment);
  if (dCount < 0) {
    return;
  }

  float fmCount = fullMarks(assessment);
  if (fmCount < 0) {
    return;
  }

  float average = avg(assessment);
  if (average < 0) {
    return;
  }

  char **histogram = marksHistogram(assessment);
  if (histogram == NULL) {
    return;
  }
  for (int i = 0; i < 26; i++) {
    {
      if (histogram[10][i] != 'A' + i) {
        return;
      }
    }
  }

  for (int i = 0; i < 11; i++) {
    { delete[] histogram[i]; }
  }
  delete[] histogram;

  destructor(assessment);
  if (assessment != NULL) {
    return;
  }

  Assessment *nullAssessment = NULL;
  destructor(nullAssessment);

  std::cout << "(OUT - 4) Assessment tests passed!" << std::endl;
}

void testLoadFromCSV() {
  std::cout << "(OUT - 5) Testing loadFromCSV..." << std::endl;

  createTestCSV("main.csv");

  Assessment *assessment = constructor("CSV Test", 100.0f);
  loadFromCSV(assessment, "main.csv");

  int totalStudents = totalNumberOfStudents(assessment);
  if (totalStudents <= 0) {
    return;
  }

  StudentDetails *best = bestStudent(assessment);
  StudentDetails *worst = worstStudent(assessment);
  if (best == NULL) {
    return;
  }
  if (worst == NULL) {
    return;
  }

  float average = avg(assessment);
  if (average <= 0) {
    return;
  }

  int prepCount = numberThatCompletedPrep(assessment);
  if (prepCount < 0) {
    return;
  }

  destructor(assessment);

  std::cout << "(OUT - 6) loadFromCSV tests passed!" << std::endl;
}

void testEdgeCases() {
  std::cout << "(OUT - 7) Testing edge cases..." << std::endl;

  if (totalNumberOfStudents(NULL) != 0) {
    return;
  }
  if (avg(NULL) != 0) {
    return;
  }
  if (numberThatCompletedPrep(NULL) != 0) {
    return;
  }
  if (passRate(NULL) != 0) {
    return;
  }
  if (distinction(NULL) != 0) {
    return;
  }
  if (fullMarks(NULL) != 0) {
    return;
  }
  if (bestStudent(NULL) != NULL) {
    return;
  }
  if (worstStudent(NULL) != NULL) {
    return;
  }

  Assessment *emptyAssessment = constructor("Empty", 100.0f);
  if (totalNumberOfStudents(emptyAssessment) != 0) {
    return;
  }
  if (avg(emptyAssessment) != 0) {
    return;
  }
  if (bestStudent(emptyAssessment) != NULL) {
    return;
  }
  if (worstStudent(emptyAssessment) != NULL) {
    return;
  }

  char **histogram = marksHistogram(emptyAssessment);
  if (histogram == NULL) {
    return;
  }
  for (int i = 0; i < 26; i++) {
    {
      if (histogram[10][i] != 'A' + i) {
        return;
      }
    }
  }

  for (int i = 0; i < 11; i++) {
    { delete[] histogram[i]; }
  }
  delete[] histogram;

  destructor(emptyAssessment);

  std::cout << "(OUT - 8) Edge case tests passed!" << std::endl;
}

void testComprehensiveScenario() {
  std::cout << "(OUT - 9) Testing comprehensive scenario..." << std::endl;

  Assessment *assessment = constructor("Final Exam", 100.0f);

  std::string testData[8];
  {
    testData[0] = "Alice,Anderson,12345678,85.5,t";
    testData[1] = "Bob,Brown,23456789,92.0,t";
    testData[2] = "Charlie,Clark,34567890,67.25,f";
    testData[3] = "David,Davis,45678901,45.75,t";
    testData[4] = "Eve,Evans,56789012,100.0,t";
    testData[5] = "Frank,Fisher,67890123,30.5,f";
    testData[6] = "Grace,Green,78901234,88.75,t";
    testData[7] = "Henry,Harris,89012345,72.0,f";
  }

  for (int i = 0; i < 8; i++) {
    {
      StudentDetails *student = constructor(testData[i]);
      insertStudent(assessment, *student);
      delete student;
    }
  }

  if (totalNumberOfStudents(assessment) != 8) {
    return;
  }

  sort(assessment);

  StudentDetails *best = bestStudent(assessment);
  StudentDetails *worst = worstStudent(assessment);
  if (best->mark != 100.0f) {
    return;
  }
  if (worst->mark != 30.5f) {
    return;
  }

  float pRate = passRate(assessment);
  if (pRate <= 0.0f || pRate > 1.0f) {
    return;
  }

  int distinctionCount = (int)distinction(assessment);
  if (distinctionCount < 0) {
    return;
  }

  int fullMarksCount = (int)fullMarks(assessment);
  if (fullMarksCount != 1) {
    return;
  }

  int prepCount = numberThatCompletedPrep(assessment);
  if (prepCount != 5) {
    return;
  }

  char **histogram = marksHistogram(assessment);
  if (histogram == NULL) {
    return;
  }

  for (int i = 0; i < 11; i++) {
    { delete[] histogram[i]; }
  }
  delete[] histogram;

  destructor(assessment);

  std::cout << "(OUT - 10) Comprehensive scenario tests passed!" << std::endl;
}

int main() {
  std::cout << "(OUT - 0) Starting comprehensive testing suite..." << std::endl;

  testStudentDetails();
  testAssessment();
  testLoadFromCSV();
  testEdgeCases();
  testComprehensiveScenario();

  return 0;
}