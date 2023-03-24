#ifndef ALLERGEN_H
#define ALLERGEN_H
#include <string>
#include <sstream>
#include <vector>
#include <QDebug>
#include "basefooditem.h"

class Allergen : public BaseFoodItem
{

private:
    std::string name;

public:
    static std::vector<Allergen*> listOfAllergens;
    Allergen();
    Allergen(std::string, bool);
   static std::vector<Allergen*> getListOfAllergens();
    bool isVegetarianBool;
    std::string getName() override;
    bool isVegetarian() override;
    
};
namespace staticAllergens{


static std::string getAllergens(){
    std::stringstream s;
    std::vector<Allergen*> list = Allergen::getListOfAllergens();
    for(Allergen* a : list){
        s << a->getName() << " " ;
    }

    return s.str();
}

static void addAllergen(Allergen* a){

    Allergen::listOfAllergens.push_back(a);
    qDebug() << QString::fromStdString(staticAllergens::getAllergens());
}

static int getAllergenSize(){
    std::vector<Allergen*> list = Allergen::getListOfAllergens();
    return list.size();
}


}


#endif // ALLERGEN_H
