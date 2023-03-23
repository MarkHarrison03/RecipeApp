#ifndef RECIPE_H
#define RECIPE_H
#include <string>
#include <vector>
#include <initializer_list>
#include "ingredient.h"
#include <QList>
#include "basefooditem.h"
using namespace std;

//multiple inheritance
class Recipe : public Ingredient, public BaseFoodItem
{

public:
    string name;
    string category;
    string steps;
    int timeToCook;
    string allergens;
    QList<Ingredient *> listOfIngredients;


    Recipe(string, string, string, int, QList<Ingredient *>, string, bool);
    void addIngredients(std::vector<Ingredient*>);
    int getCalories() override;
    string getName() override;
    bool isVegetarian() override;

};
#endif // RECIPE_H
