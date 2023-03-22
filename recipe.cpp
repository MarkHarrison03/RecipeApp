#include "recipe.h"
#include <string>
#include <initializer_list>
#include <type_traits>
#include <vector>
using namespace std;


Recipe::Recipe(string name, string category, string Steps, int calories, int time, QList<Ingredient *> listOfIngs){
            this->name = name;
            this->category = category;
            this->steps = steps;
            this->timeToCook = time;
            this->listOfIngredients = listOfIngs;
        };




int Recipe::getCalories(){

    return calories;
};

