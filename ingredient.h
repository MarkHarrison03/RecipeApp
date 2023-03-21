#ifndef INGREDIENT_H
#define INGREDIENT_H

#include<string>
#include <vector>
class Ingredient
{
public:
    virtual ~Ingredient();
    Ingredient();
    Ingredient(std::string name, int calories);
    Ingredient(Ingredient& copyIngredient);
    inline std::string getName(){return name;};
    inline int getCalories(){return calories;};
    virtual bool isVegetarian();
    static std::vector<Ingredient*> getListOfIngredients();
    static void addIngredient(Ingredient*);


private:
    std::string name;
    static std::vector<Ingredient*> listOfIngredients;

protected:
    int calories;


};

#endif // INGREDIENT_H
