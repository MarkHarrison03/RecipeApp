#ifndef MEAT_H
#define MEAT_H

#include "ingredient.h"
#include "allergen.h"

class Meat : public Ingredient, public Allergen
{
public:
    virtual ~Meat();
    Meat(std::string, int, int, std::string);
    bool isVegetarian();
    double cookingTemperature = 0;
    std::string color;
};

#endif // MEAT_H
