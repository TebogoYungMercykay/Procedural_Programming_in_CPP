#include "Lines.h"

float implicitLineEquation(int p0x, int p0y, int p1x, int p1y, float x,
                           float y) {
  return (p0y - p1y) * x + (p1x - p0x) * y + (p0x * p1y) - (p1x * p0y);
}

int min(int v1, int v2) {
  if (v1 < v2)
    return v1;
  return v2;
}

int max(int v1, int v2) {
  if (v1 > v2)
    return v1;
  return v2;
}

int absV(int v) {
  if (v < 0)
    return -v;
  return v;
}

float absV(float v) {
  if (v < 0)
    return -v;
  return v;
}

float gradient(int p0x, int p0y, int p1x, int p1y) {
  if (p1x - p0x == 0)
    return 0;

  return static_cast<float>(p1y - p0y) / (p1x - p0x);
}

void drawLineA(int p0x, int p0y, int p1x, int p1y, char symbol) {
  for (int y = min(p0y, p1y); y <= max(p0y, p1y); y++)
    Screen::draw(p0x, y, symbol);
}

void drawLineB(int p0x, int p0y, int p1x, int p1y, char symbol) {
  for (int x = min(p0x, p1x); x <= max(p0x, p1x); x++)
    Screen::draw(x, p0y, symbol);
}

void drawLineC(int p0x, int p0y, int p1x, int p1y, char symbol) {
  if (p0x > p1x) {
    drawLineC(p1x, p1y, p0x, p0y, symbol);
    return;
  }

  int y = p0y;
  for (int x = p0x; x <= p1x; x++) {
    Screen::draw(x, y, symbol);
    if (implicitLineEquation(p0x, p0y, p1x, p1y, x + 1, y + 0.5) < 0)
      y = y + 1;
  }
}

void drawLineD(int p0x, int p0y, int p1x, int p1y, char symbol) {
  if (p0x > p1x) {
    drawLineD(p1x, p1y, p0x, p0y, symbol);
    return;
  }

  int y = p0y;
  for (int x = p0x; x <= p1x; x++) {
    Screen::draw(x, y, symbol);
    if (implicitLineEquation(p0x, p0y, p1x, p1y, x + 1, y - 0.5) > 0)
      y = y - 1;
  }
}

void drawLineE(int p0x, int p0y, int p1x, int p1y, char symbol) {
  if (p0x > p1x) {
    drawLineE(p1x, p1y, p0x, p0y, symbol);
    return;
  }

  int x = p0x;
  for (int y = p0y; y <= p1y; y++) {
    Screen::draw(x, y, symbol);
    if (implicitLineEquation(p0x, p0y, p1x, p1y, x + 0.5, y + 1) > 0)
      x = x + 1;
  }
}

void drawLineF(int p0x, int p0y, int p1x, int p1y, char symbol) {
  if (p0x > p1x) {
    drawLineF(p1x, p1y, p0x, p0y, symbol);
    return;
  }

  int x = p0x;
  for (int y = p0y; y >= p1y; y--) {
    Screen::draw(x, y, symbol);
    if (implicitLineEquation(p0x, p0y, p1x, p1y, x + 0.5, y - 1) < 0)
      x = x + 1;
  }
}

void drawLine(int p0x, int p0y, int p1x, int p1y, char symbol) {
  float m = gradient(p0x, p0y, p1x, p1y);

  if (p0x == p1x) {
    drawLineA(p0x, p0y, p1x, p1y, symbol);
  } else if (p0y == p1y) {
    drawLineB(p0x, p0y, p1x, p1y, symbol);
  } else if (m >= 1) {
    drawLineE(p0x, p0y, p1x, p1y, symbol);
  } else if (m <= -1) {
    drawLineF(p0x, p0y, p1x, p1y, symbol);
  } else if (m > 0 && m < 1) {
    drawLineC(p0x, p0y, p1x, p1y, symbol);
  } else if (m < 0 && m > -1) {
    drawLineD(p0x, p0y, p1x, p1y, symbol);
  }
}