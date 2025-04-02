#ifndef LINES_H
#define LINES_H

#include "Screen.h"

float implicitLineEquation(int p0x, int p0y, int p1x, int p1y, float x,
                           float y);
int min(int v1, int v2);
int max(int v1, int v2);
int absV(int v);
float absV(float v);

float gradient(int p0x, int p0y, int p1x, int p1y);

// Vertical line
void drawLineA(int p0x, int p0y, int p1x, int p1y, char symbol = '*');

// Horizontal line
void drawLineB(int p0x, int p0y, int p1x, int p1y, char symbol = '*');

// 0 < m < 1
void drawLineC(int p0x, int p0y, int p1x, int p1y, char symbol = '*');

//-1 < m < 0
void drawLineD(int p0x, int p0y, int p1x, int p1y, char symbol = '*');

// m >= 1
void drawLineE(int p0x, int p0y, int p1x, int p1y, char symbol = '*');

// m <= -1
void drawLineF(int p0x, int p0y, int p1x, int p1y, char symbol = '*');

void drawLine(int p0x, int p0y, int p1x, int p1y, char symbol = '*');

#endif /*LINES_H*/