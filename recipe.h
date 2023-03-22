#ifndef RECIPE_H
#define RECIPE_H
#include <string>
#include "Food.h"
#include <vector>
#include <initializer_list>
#include "ingredient.h"
#include <QList>
#include "allergen.h"
using namespace std;

class Recipe : public Food, public Allergen
{
public:
    string name;
    string category;
    int calories;
    string steps;
    int timeToCook;
    QList<Ingredient *> listOfIngredients;


    Recipe(string, string, string, int, int, QList<Ingredient *>);
    void addIngredients(std::vector<Ingredient*>);
    int getCalories(void);

};
#endif // RECIPE_H
