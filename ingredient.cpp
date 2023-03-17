#include "ingredient.h"
#include <string>
Ingredient::Ingredient(){};
Ingredient::Ingredient(std::string name, int calories) : name(name), calories(calories){}; //initializer list
Ingredient::Ingredient(Ingredient& copyIngredient){
    name = copyIngredient.name;
    calories = copyIngredient.calories;
};
