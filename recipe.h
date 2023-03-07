#ifndef RECIPE_H
#define RECIPE_H
#include <string>
#include "Food.h"
using namespace std;

class Recipe : public Food
{
public:
    string name;
    string category;
    int calories;
    string dietaryRestriction;


    Recipe(string, string, string, int);
    void addNutrition(int,int,int,int,int);
    int getCalories(void);
    string getNutrition(void);

};
#endif // RECIPE_H
