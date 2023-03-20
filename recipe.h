#ifndef RECIPE_H
#define RECIPE_H
#include <string>
#include "Food.h"
#include <vector>
#include <initializer_list>
#include "ingredient.h"
#include "allergen.h"
using namespace std;

class Recipe : public Food, public allergen
{
public:
    string name;
    string category;
    int calories;
    string dietaryRestriction;


    Recipe(string, string, string, int);
    void addIngredients(std::vector<Ingredient*>);

    void addNutrition(int,int,int,int,int);
    int getCalories(void);
    string getNutrition(void);

};
#endif // RECIPE_H
