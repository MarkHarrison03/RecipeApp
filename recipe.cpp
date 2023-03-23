#include "recipe.h"
#include <string>
#include <initializer_list>
#include <type_traits>
#include "./ui_mainwindow.h"

#include <vector>
using namespace std;


Recipe::Recipe(string name, string category, string Steps, int calories, int time, QList<Ingredient *> listOfIngs, string allergens, bool isVegetarian){
            this->name = name;
            this->category = category;
            this->steps = Steps;
            this->calories = calories;
            this->timeToCook = time;
            this->listOfIngredients = listOfIngs;
            this->allergens = allergens;
            this->isVegetarianBool = isVegetarian;
        };



int Recipe::getCalories(){

    return calories;
};

std::string Recipe::isVegetarian(){
    if(isVegetarianBool){
        return "Vegetarian";
    }else{
        return "No Dietary Restriction";
    }
}
