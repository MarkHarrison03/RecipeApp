#ifndef INGREDIENT_H
#define INGREDIENT_H

#include<string>
#include <vector>
class Ingredient
{
public:
     ~Ingredient();
    Ingredient();
    bool isVegetarianBool;
    Ingredient(std::string name, int calories);
    Ingredient(Ingredient& copyIngredient);
    inline std::string getName(){return name;};
    virtual inline int getCalories(){return calories;};
    bool isVegetarian();
    static std::vector<Ingredient*> getListOfIngredients();
    static void addIngredient(Ingredient*);
    void setIsVegetarian(bool);

private:
    std::string name;
    static std::vector<Ingredient*> listOfIngredients;

protected:
    int calories;


};

#endif // INGREDIENT_H
