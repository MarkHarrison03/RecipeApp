#include "recipe.h"

class CookBook{
public:
        Recipe* chickenCurry;
        Recipe* chickenTikka;
        Recipe* vegetarianBolognaise;
        Recipe* recipies[3] = {0};
    CookBook(){
        chickenCurry = new Recipe("Chicken Curry And Rice", "Dinner", "None");
        chickenTikka = new Recipe("Chicken Tikka Masala", "Dinner", "None");
        vegetarianBolognaise = new Recipe("Massive dick and balls", "Dinner", "Vegetaian");
        recipies[0] = {chickenCurry};

        recipies[1] = {chickenTikka};
        recipies[2] = {vegetarianBolognaise};


    }


};
