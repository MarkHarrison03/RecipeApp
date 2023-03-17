#include "recipe.h"
#include <string>
#include <initializer_list>
#include <type_traits>
#include <vector>
using namespace std;


Recipe::Recipe(string name, string category, string dietaryRestriction, int calories, std::vector<Ingredient> vectorOfIngredients){
            this->name = name;
            this->category = category;
            this->dietaryRestriction = dietaryRestriction;
            this->calories = calories;
            ingredients = vectorOfIngredients;
        };




Food::nutrition a;

void addNutrition(int calories, int carbohydrates, int protein, int fat, int sodium){

    a.calories = calories;
    a.carbohydrates = carbohydrates;
    a.protein = protein;
    a.fat = fat;
    a.sodium = sodium;

};
int getCalories(){

    return a.calories;
};

string getNutrition(){
    string s = "Calories: " + to_string(a.calories);
    s += "\nCarbohydrates: " + to_string(a.carbohydrates);
    s += "\nFat: " + to_string(a.fat);
    s += "\nProtein: " + to_string(a.protein);
    s += "\nSodium: " + to_string(a.sodium) + "\n";
    return s;
};

