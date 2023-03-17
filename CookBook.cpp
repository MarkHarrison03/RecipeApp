#include "recipe.h"
#include "meat.h"
#include <vector>
class CookBook{
public:
        Recipe* chickenCurry;
        Recipe* chickenTikka;
        Recipe* vegetarianBolognaise;
        Recipe* recipies[3] = {0};
    CookBook(){
        std::string a = "Chicken Breast", b = "White Meat";
        Meat* m = new Meat(a, 250, 150, b);
        std::vector<Ingredient*> meats;
        meats.push_back(m);
        chickenCurry = new Recipe("Chicken Curry And Rice", "Dinner", "None",340);
        chickenCurry->addIngredients(meats);
        chickenTikka = new Recipe("Chicken Tikka Masala", "Dinner", "None",450);
        vegetarianBolognaise = new Recipe("Vegetarian Meatballs", "Dinner", "Vegetaian",370);
        //chickenCurry->addNutrition(1,2,3,4,5);
        //chickenTikka->addNutrition(2,4,6,8,10);

        recipies[0] = {chickenCurry};

        recipies[1] = {chickenTikka};
        recipies[2] = {vegetarianBolognaise};


    }


};
