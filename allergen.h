#ifndef ALLERGEN_H
#define ALLERGEN_H
#include <string>
#include <vector>

class Allergen
{
private:
    static std::vector<std::string> listOfAllergens;
public:
    Allergen();
   static std::string getAllergens();
    void addAllergen(std::string);
    static int getAllergenSize();
    
};

#endif // ALLERGEN_H
