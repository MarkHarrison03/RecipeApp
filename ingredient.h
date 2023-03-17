#ifndef INGREDIENT_H
#define INGREDIENT_H

#include<string>
class Ingredient
{
public:
    Ingredient();
    Ingredient(std::string name, int calories);
    Ingredient(Ingredient& copyIngredient);
    inline std::string getName(){return name;};
    inline int getCalories(){return calories;};
    virtual std::string isVegetarian();

private:
    std::string name;
protected:
    int calories;


};

#endif // INGREDIENT_H
