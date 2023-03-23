#include "recipe.h"
#include <string>
#include <initializer_list>
#include <type_traits>
#include "./ui_mainwindow.h"

#include <vector>
using namespace std;


Recipe::Recipe(string name, string category, string Steps, int time, QList<Ingredient *> listOfIngs, string allergens, bool isVegetarian){
            this->name = name;
            this->category = category;
            this->steps = Steps;

            this->timeToCook = time;
            this->listOfIngredients = listOfIngs;
            this->allergens = allergens;
            this->isVegetarianBool = isVegetarian;
        };



int Recipe::getCalories(){
    //overriding virtual function
    int calories = 0;
    for(Ingredient * i : listOfIngredients){
        calories += i->getCalories();
    }
    return calories;
};

bool Recipe::isVegetarian(){
    if(isVegetarianBool){
        return true;
    }else{
        return false;
    }
}

string Recipe::getName(){
    return name;
}
