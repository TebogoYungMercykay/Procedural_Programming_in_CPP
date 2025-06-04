#include "Menus.h"

using namespace std;

void displayWelcome() {
  cout << "Welcome to BubStop, a Taiwanese Bubble Tea shop" << endl;
}

void displayMainMenu() {
  cout << "Please select one of the following options for your drink" << endl;
  cout << "1 - Add a tea" << endl;
  cout << "2 - Add a bubble flavour" << endl;
  cout << "3 - Add an extra" << endl;
  cout << "0 - Bill please!" << endl;
}

void displayTeaMenus() {
  cout << "Please select one of the following tea flavours to add to your drink"
       << endl;
  cout << "1 - Black Tea " << currencySymbol << " " << Teas::blackTeaPrice
       << endl;
  cout << "2 - Passion Fruit Tea " << currencySymbol << " "
       << Teas::passionFruitTeaPrice << endl;
  cout << "3 - Lemon Tea " << currencySymbol << " " << Teas::lemonTeaPrice
       << endl;
  cout << "4 - Mango Tea " << currencySymbol << " " << Teas::mangoTeaPrice
       << endl;
  cout << "5 - Honey Lemon Tea " << currencySymbol << " "
       << Teas::honeyLemonTeaPrice << endl;
  cout << "0 - Nah no more tea!" << endl;
}

void displayBubbleMenu() {
  cout << "Please select one of the following bubble flavours to add to your "
          "drink"
       << endl;
  cout << "1 - Litchi Bubbles " << currencySymbol << " "
       << Bubbles::litchiPopPrice << endl;
  cout << "2 - Strawberry Bubbles " << currencySymbol << " "
       << Bubbles::strawberryPopPrice << endl;
  cout << "3 - Pomegranate Bubbles " << currencySymbol << " "
       << Bubbles::pomegranatePopPrice << endl;
  cout << "4 - Blueberry Bubbles " << currencySymbol << " "
       << Bubbles::blueberryPopPrice << endl;
  cout << "5 - Passion Fruit Bubbles " << currencySymbol << " "
       << Bubbles::passionFruitPopPrice << endl;
  cout << "0 - Nah no more bubbles!" << endl;
}

void displayExtraMenu() {
  cout << "Please select one of the following extras to add to your drink"
       << endl;
  cout << "1 - Mango Slush " << currencySymbol << " " << Extras::mangoSlushPrice
       << endl;
  cout << "2 - Coffee Slush " << currencySymbol << " "
       << Extras::coffeeSlushPrice << endl;
  cout << "3 - Extra Ice " << currencySymbol << " " << Extras::extraIcePrice
       << endl;
  cout << "4 - Fresh Taro " << currencySymbol << " " << Extras::freshTaroPrice
       << endl;
  cout << "5 - Almond Pearls " << currencySymbol << " "
       << Extras::almondPearlsPrice << endl;
  cout << "0 - Nah no more extras!" << endl;
}

void displayGoodBye() { cout << "Thank you for visiting BubStop" << endl; }

void displayInvalidOption(int option) {
  cout << "Invalid option provided: " << option << endl;
}

int getMenuOption() {
  int input = -1;
  cin >> input;
  return input;
}
