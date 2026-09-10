#include "Car.h"
#include <iostream>
using namespace std;

Car::Car() : Vehicle(){
    totalSeat = 0;
}

Car::Car(string newId, string newBrand, string newModel, double priceRate, int Seat) :
    Vehicle(newId, newBrand, newModel, priceRate), totalSeat(Seat){}

int Car::getTotalSeat(){
    return totalSeat;
}
void Car::setTotalSeat(int Seat){
    this->totalSeat = Seat;
}
void Car::display(){
    cout << " | Chair: " << totalSeat << endl;
}