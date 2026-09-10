#include "Car.h"
#include <iostream>

using namespace std;

Car::Car() : Vehicle(), totalSeats(0) {}

Car::Car(const string& newId,
         const string& newBrand,
         const string& newModel,
         double priceRate,
         int seats)
    : Vehicle(newId, newBrand, newModel, priceRate),
      totalSeats(seats) {}

int Car::getTotalSeats() const { return totalSeats; }

void Car::setTotalSeats(int seats) { totalSeats = seats; }

void Car::display() const {
    Vehicle::display();
    cout << "  -> Seats: " << totalSeats << endl;
}
