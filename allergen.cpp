#include "allergen.h"
#include <sstream>
#include <vector>

Allergen *a = new Allergen("Milk",true);
Allergen *b = new Allergen("Eggs",true);
Allergen *c = new Allergen("Fish",false);
Allergen *d = new Allergen("Shellfish",false);
Allergen *e = new Allergen("Nuts",true);
Allergen *f = new Allergen("Wheat",true);
Allergen *g = new Allergen("Soya",true);
Allergen *h = new Allergen("Moluscs",false);
Allergen *i = new Allergen("Celery",true);
Allergen *j = new Allergen("Mustard",true);
Allergen *k = new Allergen("Crustaceans",false);
//C++ Object COnstruction Sequence
std::vector<Allergen*> Allergen::listOfAllergens{a,b,c,d,e,f,g,h,i,j,k};

Allergen::Allergen(std::string name, bool vegetarian){
    this->name = name;
    this->isVegetarianBool = vegetarian;
};



std::vector<Allergen*> Allergen::getListOfAllergens(){
    return listOfAllergens;
}
std::string Allergen::getName(){
    return name;
}
bool Allergen::isVegetarian(){
    if(isVegetarianBool){
        return true;
    }else{
        return false;
    }
}
