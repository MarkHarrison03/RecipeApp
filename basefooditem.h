#ifndef BASEFOODITEM_H
#define BASEFOODITEM_H
#include <string>

class BaseFoodItem
{
public:

    virtual ~BaseFoodItem(){};
    virtual std::string getName() = 0;
    virtual bool isVegetarian() = 0;

};

#endif // BASEFOODITEM_H
