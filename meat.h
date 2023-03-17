#ifndef MEAT_H
#define MEAT_H

#include "ingredient.h"

class Meat : public Ingredient
{
public:
    Meat(std::string name, int calories, double cookingTemperature, std::string color, int averageShelfLife, ) : Ingredient(name, calories){};
    std::string isVegetarian();
    double cookingTemperature
};

#endif // MEAT_H
