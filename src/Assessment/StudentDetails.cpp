#include "StudentDetails.h"
#include <iostream>
#include <sstream>
#include <string>

std::string capitalizeFirstLetter(std::string str) {
  if (!str.empty()) {
    if (str[0] >= 'a' && str[0] <= 'z') {
      str[0] = str[0] - 'a' + 'A';
    }
    for (size_t i = 1; i < str.length(); i++) {
      if (str[i] >= 'A' && str[i] <= 'Z') {
        str[i] = str[i] - 'A' + 'a';
      }
    }
  }
  return str;
}

StudentDetails *constructor(std::string line) {
  StudentDetails *student = new StudentDetails;

  std::stringstream ss(line);
  std::string token;

  std::getline(ss, token, ',');
  student->firstName = capitalizeFirstLetter(token);

  std::getline(ss, token, ',');
  student->lastName = capitalizeFirstLetter(token);

  std::getline(ss, token, ',');
  std::stringstream ssNum(token);
  ssNum >> student->studentNumber;

  std::getline(ss, token, ',');
  std::stringstream ssMark(token);
  ssMark >> student->mark;

  std::getline(ss, token, ',');
  student->didPrepWork = (token == "t" || token == "T");

  return student;
}

StudentDetails *constructor(std::string fName, std::string lName,
                            int studentNumber, float mark, bool didPrepWork) {
  StudentDetails *student = new StudentDetails;

  student->mark = mark;
  student->didPrepWork = didPrepWork;
  student->studentNumber = studentNumber;
  student->lastName = capitalizeFirstLetter(lName);
  student->firstName = capitalizeFirstLetter(fName);

  return student;
}

void destructor(StudentDetails *&stdDetails) {
  if (stdDetails != NULL) {
    delete stdDetails;
    stdDetails = NULL;
  }
}

std::string toString(StudentDetails &stdDetails) {
  std::stringstream ss;
  ss << stdDetails.firstName << "," << stdDetails.lastName << ","
     << stdDetails.studentNumber << "," << stdDetails.mark << ","
     << (stdDetails.didPrepWork ? "t" : "f");
  return ss.str();
}
