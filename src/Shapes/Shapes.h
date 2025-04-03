#ifndef SHAPES_H
#define SHAPES_H

#include "Lines.h"
#include "Screen.h"

void drawTriangle(int p1x, int p1y, int p2x, int p2y, int p3x, int p3y,
                  char symbol = 'x');
void drawSquare(int pTLx, int pTLy, int pTRx, int pTRy, int pBRx, int pBRy,
                int pBLx, int pBLy, char symbol = 'x');

#endif /*SHAPES_H*/