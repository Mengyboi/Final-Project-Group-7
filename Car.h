#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"


class Car : public Vehicle{
private:
    int totalChair;
public:
    //defualt constructor
    Car();
    //parameterized contructor
    Car(string newId, string newBrand, string newModel, double priceRate, int chair);
    

}

#endif