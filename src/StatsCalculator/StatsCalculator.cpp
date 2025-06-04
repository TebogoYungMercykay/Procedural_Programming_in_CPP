#include "StatsCalculator.h"

using namespace std;

std::string STATSCALCULATOR::fileName;
float *STATSCALCULATOR::dataPoints = NULL;
int STATSCALCULATOR::numberOfDataPoints = 0;

void STATSCALCULATOR::setFileName(std::string fN) {
  STATSCALCULATOR::fileName = fN;
}

void STATSCALCULATOR::clearMemory() {

  if (dataPoints != NULL) {
    delete[] dataPoints;
  }

  dataPoints = NULL;
}

void STATSCALCULATOR::processFile() {
  clearMemory();
  numberOfDataPoints = 0;
  {
    ifstream f((fileName).c_str());
    string line = "";

    while (getline(f, line)) {
      (numberOfDataPoints)++;
    }

    f.close();
  }
  dataPoints = new float[numberOfDataPoints];
  {
    int count = 0;
    ifstream f((fileName).c_str());
    string line = "";

    while (getline(f, line)) {
      dataPoints[count++] = STATSCALCULATOR::stof(line);
    }

    f.close();
  }
}

float STATSCALCULATOR::stof(std::string v) {
  stringstream ss(v);
  float temp;
  ss >> temp;
  return temp;
}

std::string STATSCALCULATOR::ftos(float v) {
  stringstream ss;
  ss << v;
  return ss.str();
}

int STATSCALCULATOR::getPositionOfLastDataPoint() {
  return numberOfDataPoints - 1;
}

float STATSCALCULATOR::sumDataPoints() {
  if (dataPoints == NULL) {
    return nanf(NULL);
  }

  float sum = 0;
  if (MOVETONEXT) {
    for (int i = START; i <= END; i++) {
      sum += dataPoints[i];
    }
  } else {
    for (int i = START; i >= END; i--) {
      sum += dataPoints[i];
    }
  }

  return sum;
}

float STATSCALCULATOR::average() {
  if (dataPoints == NULL) {
    return nanf(NULL);
  }

  float sum = 0;
  if (MOVETONEXT) {
    for (int i = START; i <= END; i++) {
      sum += dataPoints[i];
    }
  } else {
    for (int i = START; i >= END; i--) {
      sum += dataPoints[i];
    }
  }
  return sum / (numberOfDataPoints);
}

float STATSCALCULATOR::standardDiv() {
  if (dataPoints == NULL) {
    return nanf(NULL);
  }

  float sum = 0;
  if (MOVETONEXT) {
    for (int i = START; i <= END; i++) {
      sum += (dataPoints[i] - AVERAGE) * (dataPoints[i] - AVERAGE);
    }
  } else {
    for (int i = START; i >= END; i--) {
      sum += (dataPoints[i] - AVERAGE) * (dataPoints[i] - AVERAGE);
    }
  }
  return sqrt(sum / (numberOfDataPoints));
}

string STATSCALCULATOR::getPointsInOrder() {
  if (dataPoints == NULL) {
    return "";
  }

  string result = "";
  if (MOVETONEXT) {
    for (int i = START; i <= END; i++) {
      result += ftos(dataPoints[i]) + " ";
    }
  } else {
    for (int i = START; i >= END; i--) {
      result += ftos(dataPoints[i]) + " ";
    }
  }
  return result;
}

bool STATSCALCULATOR::isValueInList() {
  if (dataPoints == NULL) {
    return false;
  }

  if (MOVETONEXT) {
    for (int i = START; i <= END; i++) {
      if (dataPoints[i] == VALUE) {
        return true;
      }
    }
  } else {
    for (int i = START; i >= END; i--) {
      if (dataPoints[i] == VALUE) {
        return true;
      }
    }
  }
  return false;
}
