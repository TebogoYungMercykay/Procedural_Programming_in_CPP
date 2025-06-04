#include "Screen.h"

using namespace std;

int Screen::nx;
int Screen::ny;
char **Screen::screenBuffer = NULL;

void Screen::setUpScreen(int x, int y) {
  if (x < 0 || y < 0)
    return;

  cleanUpMemory();

  nx = x;
  ny = y;
  screenBuffer = new char *[ny];
  for (int i = 0; i < ny; i++) {
    screenBuffer[i] = new char[nx];
  }

  cleanScreen();
}

void Screen::cleanScreen() {
  if (screenBuffer == NULL) {
    return;
  }

  for (int i = 0; i < ny; i++) {
    for (int j = 0; j < nx; j++) {
      screenBuffer[i][j] = ' ';
    }
  }
}

void Screen::draw(int x, int y, char symbol) {
  if ((x < 0 || x >= nx) || (y < 0 || y >= ny)) {
    return;
  }
  // cout << ny << " " << y << " " << nx << " " << x << endl;
  screenBuffer[ny - y - 1][x] = symbol;
}

void Screen::printScreen() {
  cout << "+";
  for (int x = 0; x < nx; x++) {
    cout << "-";
  }
  cout << "+" << endl;
  for (int y = 0; y < ny; y++) {
    cout << "|";
    for (int x = 0; x < nx; x++) {
      cout << screenBuffer[y][x];
    }
    cout << "|" << endl;
  }
  cout << "+";
  for (int x = 0; x < nx; x++) {
    cout << "-";
  }
  cout << "+" << endl;
}

void Screen::cleanUpMemory() {
  if (screenBuffer != NULL) {
    for (int y = 0; y < ny; y++) {
      if (screenBuffer[y] != NULL) {
        delete[] screenBuffer[y];
        screenBuffer[y] = NULL;
      }
    }
    delete[] screenBuffer;
    screenBuffer = NULL;
  }
}
