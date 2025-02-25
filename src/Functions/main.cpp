#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

#include "ROBOTS.h"

using namespace std;

void testAlgorithm(string input) {

  cout << "Enter droid name: ";
  cout << input << endl;
  if (ROBOTS::task1(input)) {
    cout << "Input was valid... progressing to next phase" << endl;
    string convertedInput = ROBOTS::task2(input);
    cout << "Converted: " << convertedInput << endl;
    string translatedInput = ROBOTS::task3(convertedInput);
    cout << "Translated: " << translatedInput << endl;
    string expandedInput = ROBOTS::task4(translatedInput);
    cout << "Expanded: " << expandedInput << endl;
  } else {
    cout << "Input was invalid... halting execution" << endl;
  }
}

int main(int argc, char const *argv[]) {
  testAlgorithm("R2D2");
  testAlgorithm("j1Kr(3b)");
  testAlgorithm("L3");
  testAlgorithm("G5N91");
  testAlgorithm(" ");
  testAlgorithm("9JD05D7O2");
}
