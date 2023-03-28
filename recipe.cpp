#include "recipe.h"
#include <string>
#include <initializer_list>
#include <type_traits>
#include <QDebug>

#include <vector>
using namespace std;

Recipe::Recipe(string name, string category, string Steps, int time, QList<Ingredient* > listOfIngs, string allergens, bool isVegetarian){
            qDebug() << listOfIngs;
            this->name = name;
            this->category = category;
            this->steps = Steps;
            this->timeToCook = time;
            this->listOfIngredients = listOfIngs;
            this->allergens = allergens;
            this->isVegetarianBool = isVegetarian;
        };

    Recipe::~Recipe(){};

Recipe::Recipe(const Recipe&a){
    name = a.name;
    category = a.category;
    steps = a.steps;
    timeToCook = a.timeToCook;
    listOfIngredients = a.listOfIngredients;
    allergens = a.allergens;
    isVegetarianBool = a.isVegetarianBool;
}

int Recipe::getCalories(){
    //overriding virtual function
    int calories = 0;
    for(Ingredient * i : listOfIngredients){
        addStuff(calories, i->getCalories());
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
string Recipe::getSteps(){
    return steps;
};
int Recipe::getTimeToCook(){
    return timeToCook;
};

string Recipe::getAllergens(){
    return allergens;
};
QList<Ingredient*> Recipe::getListOfIngredients(){
    return listOfIngredients;
};
string Recipe::getCategory(){
    return category;
}
