#include "recipe.h"
#include "recipe.h"
class CookBook{
public:
        Recipe* chickenCurry;
        Recipe* chickenTikka;
        Recipe* vegetarianBolognaise;
        Recipe* recipies[3] = {0};
    CookBook(){
        chickenCurry = new Recipe("Chicken Curry And Rice", "Dinner", "None",340);
        chickenTikka = new Recipe("Chicken Tikka Masala", "Dinner", "None",450);
        vegetarianBolognaise = new Recipe("Vegetarian Meatballs", "Dinner", "Vegetaian",370);
        //chickenCurry->addNutrition(1,2,3,4,5);
        //chickenTikka->addNutrition(2,4,6,8,10);

        recipies[0] = {chickenCurry};

        recipies[1] = {chickenTikka};
        recipies[2] = {vegetarianBolognaise};


    }


};
