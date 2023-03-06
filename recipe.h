#ifndef RECIPE_H
#define RECIPE_H
#include <string>
class Recipe
{
public:
    std::string name;
    std::string category;
    std::string dietaryRestriction;


        //using a union to represent a nutrition table


    Recipe(std::string, std::string, std::string);
    void addNutrition(int,int,int,int,int);
    std::string getNutrition();
};
#endif // RECIPE_H
