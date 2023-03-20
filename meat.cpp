#include "meat.h"

Meat::Meat(std::string name, int calories, int cookingTemperature, std::string color) : Ingredient(name, calories){
    this->cookingTemperature = cookingTemperature;
    this->color = color;
};
Meat::~Meat(){};
bool Meat::isVegetarian(){
    return true;
}
