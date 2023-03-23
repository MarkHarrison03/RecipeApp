#ifndef RECIPE_H
#define RECIPE_H
#include <string>
#include <vector>
#include <initializer_list>
#include "ingredient.h"
#include <QList>
#include "allergen.h"
using namespace std;

class Recipe : public Ingredient, public Allergen
{
public:
    string name;
    string category;
    int calories;
    string steps;
    int timeToCook;
    string allergens;
    QList<Ingredient *> listOfIngredients;


    Recipe(string, string, string, int, int, QList<Ingredient *>, string, bool);
    void addIngredients(std::vector<Ingredient*>);
    int getCalories(void);
    std::string isVegetarian();

};
#endif // RECIPE_H
