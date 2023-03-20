#include "allergen.h"
#include <sstream>
std::vector<std::string> Allergen::listOfAllergens{"Milk", "Eggs", "Fish", "Shellfish", "Nuts", "Wheat", "Soya", "Moluscs", "Celery", "Sesame", "Mustard","Crustaceans"};

Allergen::Allergen(){
};
std::string Allergen::getAllergens(){
    std::stringstream s;
    for(std::string strings : listOfAllergens){
        s << strings << " " ;
    }

    return s.str();
}
void Allergen::addAllergen(std::string name){
    listOfAllergens.push_back(name);
}
