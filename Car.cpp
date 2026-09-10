#include "Car.h"
#include <iostream>

Car::Car() : Vehicle(), totalSeats(0) {}

Car::Car(const std::string& newId,
         const std::string& newBrand,
         const std::string& newModel,
         double priceRate,
         int seats)
    : Vehicle(newId, newBrand, newModel, priceRate),
      totalSeats(seats) {}

int Car::getTotalSeats() const { return totalSeats; }

void Car::setTotalSeats(int seats) { totalSeats = seats; }

void Car::display() const {
    Vehicle::display();
    std::cout << "  -> Seats: " << totalSeats << std::endl;
}
