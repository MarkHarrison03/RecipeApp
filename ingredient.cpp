#include "ingredient.h"
#include <string>
#include <vector>
std::vector<Ingredient*> Ingredient::listOfIngredients;

Ingredient::Ingredient(){}; //default constructor noargs

Ingredient::Ingredient(std::string name, int calories) : name(name), calories(calories){}; //initializer list


Ingredient::Ingredient(Ingredient& copyIngredient){ //copy constructor
    name = copyIngredient.name;
    calories = copyIngredient.calories;
};

std::vector<Ingredient*> Ingredient::getListOfIngredients(){ //static method that returns lists of all ingredients
    return listOfIngredients;
};

Ingredient::~Ingredient(){};
//destructor
bool Ingredient::isVegetarian(){
    return true;
}

void Ingredient::addIngredient(Ingredient* newIng){
    listOfIngredients.push_back(newIng);
}

