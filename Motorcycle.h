#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H
#include "Vehicle.h"

class Motorcycle : public Vehicle{
private:
    int engincc;
public:
    //getter
    int getEnginCC();
    //setter
    void setEnginCC(int engin);
    //defualt constructor
    Motorcycle();
    //parameterized consrtuctor
    Motorcycle(string newId, string newBrand, string newModel, double priceRate, int engin);

    //virtual
    // Virtual functions (can be overridden by derived classes)
    virtual void display();
};

#endif