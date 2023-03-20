#ifndef ALLERGEN_H
#define ALLERGEN_H
#include <string>
#include <vector>
class Allergen
{
private:
    std::vector<std::string> listOfAllergens{"Milk", "Eggs", "Fish", "Shellfish", "Nuts", "Wheat", "Soya", "Moluscs", "Celery", "Sesame", "Mustard","Crustaceans"};
public:
    Allergen();
    std::vector<std::string> getAllergens();
    void addAllergen(std::string);


};

#endif // ALLERGEN_H
