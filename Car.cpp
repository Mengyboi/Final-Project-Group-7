#include "Car.h"
#include <iostream>
using namespace std;

Car::Car() : Vehicle(){
    totalChair = 0;
}
Car::Car(string newId, string newBrand, string newModel, double priceRate, int chair) :
    Vehicle(newId, newBrand, newModel, priceRate), totalChair(chair){}
int Car::getTotalChair(){
    return totalChair;
}
void Car::setTotalChair(int chair){
    this->totalChair = chair;
}
void Car::display(){
    cout << " | Chair: " << totalChair << endl;
}