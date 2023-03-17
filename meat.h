#ifndef MEAT_H
#define MEAT_H

#include "ingredient.h"

class Meat : public Ingredient
{
public:
    Meat(std::string, int, int, std::string);
    std::string isVegetarian();
    double cookingTemperature = 0;
    std::string color;
};

#endif // MEAT_H
