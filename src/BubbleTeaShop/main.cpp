#include "BubbleTeaShop.h"
#include <iostream>
#include <sstream>

void automateInput() {
  std::string input = "3\n3\n3\n";
  static std::stringstream inputStream(input);
  std::cin.rdbuf(inputStream.rdbuf());
}

void testTeaOrdering() {
  std::cout << "\n-- Testing Tea Ordering --\n";

  processTeaOption(1);
  processTeaOption(2);
  processTeaOption(3);
  processTeaOption(3);
  processTeaOption(4);
  processTeaOption(5);
  processTeaOption(0);
  processTeaOption(99);
}

void testBubbleOrdering() {
  std::cout << "\n-- Testing Bubble Ordering --\n";

  processBubbleOption(1);
  processBubbleOption(2);
  processBubbleOption(3);
  processBubbleOption(5);
  processBubbleOption(5);
  processBubbleOption(4);
  processBubbleOption(0);
  processBubbleOption(-1);
}

void testExtrasOrdering() {
  std::cout << "\n-- Testing Extras Ordering --\n";

  processExtrasOption(5);
  processExtrasOption(1);
  processExtrasOption(3);
  processExtrasOption(4);
  processExtrasOption(2);
  processExtrasOption(2);
  processExtrasOption(0);
  processExtrasOption(10);
}

void testProcessOrderAndBill() {
  std::cout << "\n-- Testing Main Order Options --\n";

  processOrder(1);
  processOrder(2);
  processOrder(3);

  processOrder(0);
  processOrder(100);

  std::cout << "\n-- Testing Bill Processing --\n";
  processBill();
}

void testGetters() {
  std::cout << "\n-- Testing Name/Price Getters --\n";

  std::cout << getTeaName(2) << " - Price: " << getTeaPrice(getTeaName(2))
            << "\n";
  std::cout << getBubbleName(3)
            << " - Price: " << getBubblePrice(getBubbleName(3)) << "\n";
  std::cout << getExtrasName(4)
            << " - Price: " << getExtrasPrice(getExtrasName(4)) << "\n";
}

int main() {
  automateInput();

  resetOrder();
  testTeaOrdering();
  testBubbleOrdering();
  testExtrasOrdering();
  testGetters();
  testProcessOrderAndBill();

  std::cout << "\n-- Manual Testing Completed --\n";
  return 0;
}
