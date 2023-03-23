#ifndef ALLERGEN_H
#define ALLERGEN_H
#include <string>
#include <vector>
#include "basefooditem.h"

class Allergen : public BaseFoodItem
{
private:
    static std::vector<Allergen*> listOfAllergens;

    std::string name;
public:
    Allergen();
    Allergen(std::string, bool);
    bool isVegetarianBool;
   static std::string getAllergens();
    static void addAllergen(Allergen*);
    static int getAllergenSize();
    static std::vector<Allergen*> getAllergensAsList();
    std::string getName() override;
    bool isVegetarian() override;
    
};

#endif // ALLERGEN_H
