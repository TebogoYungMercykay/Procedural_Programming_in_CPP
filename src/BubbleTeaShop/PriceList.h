#ifndef PRICE_LIST_H
#define PRICE_LIST_H

const char currencySymbol = '$';
const float vat = 0.14;

namespace Teas {
const float blackTeaPrice = 4;
const float passionFruitTeaPrice = 5;
const float lemonTeaPrice = 3;
const float mangoTeaPrice = 3;
const float honeyLemonTeaPrice = 4;
const std::string blackTeaStr = "Black Tea";
const std::string passionFruitTeaStr = "Passion Fruit Tea";
const std::string lemonTeaStr = "Lemon Tea";
const std::string mangoTeaStr = "Mango Tea";
const std::string honeyLemonTeaStr = "Honey Lemon Tea";
} // namespace Teas

namespace Bubbles {
const float litchiPopPrice = 8;
const float strawberryPopPrice = 8;
const float pomegranatePopPrice = 8;
const float blueberryPopPrice = 8;
const float passionFruitPopPrice = 8;
const std::string litchiPopStr = "Litchi Bubble";
const std::string strawberryPopStr = "Strawberry Bubble";
const std::string pomegranatePopStr = "Pomegranate Bubble";
const std::string blueberryPopStr = "Blueberry Bubble";
const std::string passionFruitPopStr = "Passion Fruit Bubble";
} // namespace Bubbles

namespace Extras {
const float mangoSlushPrice = 2;
const float coffeeSlushPrice = 2;
const float extraIcePrice = 3;
const float freshTaroPrice = 4;
const float almondPearlsPrice = 5;
const std::string mangoSlushStr = "Mango Slush";
const std::string coffeeSlushStr = "Coffee Slush";
const std::string extraIceStr = "Extra Ice";
const std::string freshTaroStr = "Fresh Taro";
const std::string almondPearlsStr = "Almond Pearls";
} // namespace Extras

#endif /*PRICE_LIST_H*/