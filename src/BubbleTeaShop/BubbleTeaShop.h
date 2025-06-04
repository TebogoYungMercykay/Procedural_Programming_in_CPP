#ifndef BUBBLE_TEA_SHOP_H
#define BUBBLE_TEA_SHOP_H

#include <iostream>
#include <string>

#include "Menus.h"
#include "PriceList.h"

namespace Order {
extern float teaSubtotal;
extern float bubbleSubtotal;
extern float extraSubtotal;
extern std::string teas;
extern std::string bubbles;
extern std::string extras;
}; // namespace Order

void formOrder();
bool processOrder(int);

bool processTeaOption(int);
std::string getTeaName(int);
float getTeaPrice(std::string);

bool processBubbleOption(int);
std::string getBubbleName(int);
float getBubblePrice(std::string);

bool processExtrasOption(int);
std::string getExtrasName(int);
float getExtrasPrice(std::string);

void processBill();
void resetOrder();

#endif /*BUBBLE_TEA_SHOP_H*/