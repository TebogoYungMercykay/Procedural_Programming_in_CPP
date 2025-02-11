#ifndef MENUS_H
#define MENUS_H

#include <iostream>
#include <string>

#include "PriceList.h"

void displayWelcome();
void displayMainMenu();
void displayTeaMenus();
void displayBubbleMenu();
void displayExtraMenu();
void displayGoodBye();
void displayInvalidOption(int option);

int getMenuOption();

#endif /*MENUS_H*/