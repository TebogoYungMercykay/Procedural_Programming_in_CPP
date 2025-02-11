#include "BubbleTeaShop.h"

namespace Order {
float teaSubtotal = 0;
float bubbleSubtotal = 0;
float extraSubtotal = 0;
std::string teas = "";
std::string bubbles = "";
std::string extras = "";
}; // namespace Order

void resetOrder() {
  Order::teas = "";
  Order::bubbles = "";
  Order::extras = "";

  Order::teaSubtotal = 0;
  Order::bubbleSubtotal = 0;
  Order::extraSubtotal = 0;
}

void processBill() {
  std::cout << "Your bill is:" << std::endl << std::endl;

  std::cout << "Teas:" << std::endl;
  std::cout << Order::teas << std::endl;
  std::cout << "Tea total: " << currencySymbol << Order::teaSubtotal
            << std::endl
            << std::endl;

  std::cout << "Bubbles:" << std::endl;
  std::cout << Order::bubbles << std::endl;
  std::cout << "Bubble total: " << currencySymbol << Order::bubbleSubtotal
            << std::endl
            << std::endl;

  std::cout << "Extras:" << std::endl;
  std::cout << Order::extras << std::endl;
  std::cout << "Extra total: " << currencySymbol << Order::extraSubtotal
            << std::endl
            << std::endl;

  float subtotal =
      Order::teaSubtotal + Order::bubbleSubtotal + Order::extraSubtotal;
  float vatValue = subtotal * vat;
  float total = subtotal + vatValue;

  std::cout << "Subtotal: " << currencySymbol << subtotal << std::endl;
  std::cout << "Vat value: " << currencySymbol << vatValue << std::endl;
  std::cout << "Total: " << currencySymbol << total << std::endl;
}

// TODO: Flowchart Diagram
std::string getTeaName(int teaNumber) {
  switch (teaNumber) {
  case 1:
    return Teas::blackTeaStr;
  case 2:
    return Teas::passionFruitTeaStr;
  case 3:
    return Teas::lemonTeaStr;
  case 4:
    return Teas::mangoTeaStr;
  case 5:
    return Teas::honeyLemonTeaStr;
  default:
    return "Unknown Tea";
  }
}

// TODO: Flowchart Diagram
float getTeaPrice(std::string teaName) {
  if (teaName == Teas::blackTeaStr) {
    return Teas::blackTeaPrice;
  } else if (teaName == Teas::passionFruitTeaStr) {
    return Teas::passionFruitTeaPrice;
  } else if (teaName == Teas::lemonTeaStr) {
    return Teas::lemonTeaPrice;
  } else if (teaName == Teas::mangoTeaStr) {
    return Teas::mangoTeaPrice;
  } else if (teaName == Teas::honeyLemonTeaStr) {
    return Teas::honeyLemonTeaPrice;
  } else {
    return 0;
  }
}

// TODO: Flowchart Diagram
bool processTeaOption(int option) {
  if (option == 0) {
    return true;
  } else {
    if (option >= 1 && option <= 5) {
      std::string teaName = getTeaName(option);
      float teaPrice = getTeaPrice(teaName);

      Order::teas += teaName + "\n";
      Order::teaSubtotal += teaPrice;

      return true;
    } else {
      displayInvalidOption(option);
      return false;
    }
  }
}

std::string getBubbleName(int bubbleNumber) {
  switch (bubbleNumber) {
  case 1:
    return Bubbles::litchiPopStr;
  case 2:
    return Bubbles::strawberryPopStr;
  case 3:
    return Bubbles::pomegranatePopStr;
  case 4:
    return Bubbles::blueberryPopStr;
  case 5:
    return Bubbles::passionFruitPopStr;
  default:
    return "Unknown Bubble";
  }
}

float getBubblePrice(std::string bubbleName) {
  if (bubbleName == Bubbles::litchiPopStr) {
    return Bubbles::litchiPopPrice;
  } else if (bubbleName == Bubbles::strawberryPopStr) {
    return Bubbles::strawberryPopPrice;
  } else if (bubbleName == Bubbles::pomegranatePopStr) {
    return Bubbles::pomegranatePopPrice;
  } else if (bubbleName == Bubbles::blueberryPopStr) {
    return Bubbles::blueberryPopPrice;
  } else if (bubbleName == Bubbles::passionFruitPopStr) {
    return Bubbles::passionFruitPopPrice;
  } else {
    return 0;
  }
}

bool processBubbleOption(int option) {
  if (option == 0) {
    return true;
  } else {
    if (option >= 1 && option <= 5) {
      std::string bubbleName = getBubbleName(option);
      float bubblePrice = getBubblePrice(bubbleName);

      Order::bubbles += bubbleName + "\n";
      Order::bubbleSubtotal += bubblePrice;

      return true;
    } else {
      displayInvalidOption(option);
      return false;
    }
  }
}

std::string getExtrasName(int extraNumber) {
  switch (extraNumber) {
  case 1:
    return Extras::mangoSlushStr;
  case 2:
    return Extras::coffeeSlushStr;
  case 3:
    return Extras::extraIceStr;
  case 4:
    return Extras::freshTaroStr;
  case 5:
    return Extras::almondPearlsStr;
  default:
    return "Unknown Extra";
  }
}

float getExtrasPrice(std::string extraName) {
  if (extraName == Extras::mangoSlushStr) {
    return Extras::mangoSlushPrice;
  } else if (extraName == Extras::coffeeSlushStr) {
    return Extras::coffeeSlushPrice;
  } else if (extraName == Extras::extraIceStr) {
    return Extras::extraIcePrice;
  } else if (extraName == Extras::freshTaroStr) {
    return Extras::freshTaroPrice;
  } else if (extraName == Extras::almondPearlsStr) {
    return Extras::almondPearlsPrice;
  } else {
    return 0;
  }
}

bool processExtrasOption(int option) {
  if (option == 0) {
    return true;
  } else {
    if (option >= 1 && option <= 5) {
      std::string extraName = getExtrasName(option);
      float extraPrice = getExtrasPrice(extraName);

      Order::extras += extraName + "\n";
      Order::extraSubtotal += extraPrice;

      return true;
    } else {
      displayInvalidOption(option);
      return false;
    }
  }
}

// TODO: Flowchart Diagram
bool processOrder(int option) {
  if (option == 0) {
    return false;
  } else {
    if (option == 1) {
      displayTeaMenus();
      int teaOption = getMenuOption();
      bool result = processTeaOption(teaOption);

      if (!result) {
        displayInvalidOption(teaOption);
      }
    } else if (option == 2) {
      displayBubbleMenu();
      int bubbleOption = getMenuOption();
      bool result = processBubbleOption(bubbleOption);

      if (!result) {
        displayInvalidOption(bubbleOption);
      }
    } else if (option == 3) {
      displayExtraMenu();
      int extraOption = getMenuOption();
      bool result = processExtrasOption(extraOption);

      if (!result) {
        displayInvalidOption(extraOption);
      }
    } else {
      return false;
    }
  }

  return true;
}

void formOrder() {
  resetOrder();
  displayWelcome();

  bool continueOrdering = true;

  while (continueOrdering) {
    displayMainMenu();

    int option = getMenuOption();
    continueOrdering = processOrder(option);

    if (!continueOrdering) {
      processBill();
      displayGoodBye();
    }
  }
}
