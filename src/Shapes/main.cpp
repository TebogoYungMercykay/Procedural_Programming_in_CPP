#include "Lines.h"
#include "Screen.h"
#include "Shapes.h"
#include <iostream>

void testLines() {
  std::cout << "Testing implicitLineEquation: "
            << implicitLineEquation(0, 1, 5, 8, 0.1, 1.2) << std::endl;

  std::cout << "Testing utility functions:" << std::endl;
  std::cout << min(5, 10) << " " << max(5, 10) << " " << absV(-5) << " "
            << absV(5.5f) << std::endl;

  std::cout << "Testing gradient: " << gradient(0, 0, 5, 10) << std::endl;

  std::cout << "Testing line types:" << std::endl;
  drawLineA(5, 2, 5, 10, 'A');
  std::cout << std::endl;

  drawLineB(2, 5, 10, 5, 'B');
  std::cout << std::endl;

  drawLineC(2, 5, 10, 8, 'C');
  std::cout << std::endl;

  drawLineD(2, 8, 10, 5, 'D');
  std::cout << std::endl;

  drawLineE(2, 5, 5, 15, 'E');
  std::cout << std::endl;

  drawLineF(2, 15, 5, 5, 'F');
  std::cout << std::endl;

  std::cout << "Testing point swapping:" << std::endl;
  drawLineC(10, 8, 2, 5, 'c');
  std::cout << std::endl;

  std::cout << "Testing general drawLine:" << std::endl;
  drawLine(5, 2, 5, 10, '|');
  std::cout << std::endl;

  drawLine(2, 5, 10, 5, '-');
  std::cout << std::endl;

  drawLine(2, 5, 10, 8, '/');
  std::cout << std::endl;

  drawLine(2, 8, 10, 5, '\\');
  std::cout << std::endl;
}

void testShapes() {
  std::cout << "Testing triangle:" << std::endl;
  drawTriangle(5, 5, 15, 5, 10, 15, 'T');
  std::cout << std::endl;

  std::cout << "Testing square:" << std::endl;
  drawSquare(5, 5, 15, 5, 15, 15, 5, 15, 'S');
  std::cout << std::endl;

  std::cout << "Testing quadrilateral:" << std::endl;
  drawSquare(5, 5, 15, 3, 13, 12, 3, 10, 'Q');
  std::cout << std::endl;
}

int main() {
  Screen::setUpScreen(50, 30);

  testLines();
  testShapes();

  Screen::printScreen();

  Screen::cleanUpMemory();
  return 0;
}