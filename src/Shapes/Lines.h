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

void drawLineA(int p0x, int p0y, int p1x, int p1y, char symbol = '*');
void drawLineB(int p0x, int p0y, int p1x, int p1y, char symbol = '*');
void drawLineC(int p0x, int p0y, int p1x, int p1y, char symbol = '*');
void drawLineD(int p0x, int p0y, int p1x, int p1y, char symbol = '*');

void drawLineE(int p0x, int p0y, int p1x, int p1y, char symbol = '*');
void drawLineF(int p0x, int p0y, int p1x, int p1y, char symbol = '*');
void drawLine(int p0x, int p0y, int p1x, int p1y, char symbol = '*');

#endif /*LINES_H*/