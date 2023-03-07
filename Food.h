#ifndef FOOD_H
#define FOOD_H

class Food{
  public:
    typedef struct nutrition{
        int calories = 0;
        int carbohydrates = 0;
        int protein = 0;
        int fat = 0;
        int sodium = 0;
    } nutrition;

    //virtual methods go here
};

#endif // FOOD_H
