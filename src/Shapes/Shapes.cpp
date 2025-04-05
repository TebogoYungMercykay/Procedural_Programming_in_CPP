#include "Shapes.h"

void drawTriangle(int p1x, int p1y, int p2x, int p2y, int p3x, int p3y,
                  char symbol) {
  drawLine(p1x, p1y, p2x, p2y, symbol);
  drawLine(p2x, p2y, p3x, p3y, symbol);
  drawLine(p3x, p3y, p1x, p1y, symbol);
}

void drawSquare(int pTLx, int pTLy, int pTRx, int pTRy, int pBRx, int pBRy,
                int pBLx, int pBLy, char symbol) {
  drawLine(pTLx, pTLy, pTRx, pTRy, symbol);
  drawLine(pTRx, pTRy, pBRx, pBRy, symbol);
  drawLine(pBRx, pBRy, pBLx, pBLy, symbol);
  drawLine(pBLx, pBLy, pTLx, pTLy, symbol);
}
