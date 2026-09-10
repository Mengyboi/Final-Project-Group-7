#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"


class Car : public Vehicle{
private:
    int totalSeat;
public:
    //defualt constructor
    Car();
    //parameterized contructor
    Car(string newId, string newBrand, string newModel, double priceRate, int seat);
    
    //getter
    int getTotalSeat();
    //setter
    void setTotalSeat(int Seat);

    //override function
    void display();

};

#endif