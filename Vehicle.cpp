#include "Vehicle.h"
#include <iostream>

Vehicle::Vehicle()
    : id("Unknown"),
      brand("Unknown"),
      model("Unknown"),
      pricePerDay(0.0),
      isRented(false) {}

Vehicle::Vehicle(const std::string& newId,
                 const std::string& newBrand,
                 const std::string& newModel,
                 double priceRate)
    : id(newId),
      brand(newBrand),
      model(newModel),
      pricePerDay(priceRate),
      isRented(false) {}

std::string Vehicle::getId()          const { return id; }
std::string Vehicle::getBrand()       const { return brand; }
std::string Vehicle::getModel()       const { return model; }
double      Vehicle::getPricePerDay() const { return pricePerDay; }
bool        Vehicle::getIsRented()    const { return isRented; }

void Vehicle::setPricePerDay(double newPricePerDay) { pricePerDay = newPricePerDay; }
void Vehicle::setIsRented(bool rentedStatus)        { isRented    = rentedStatus; }

void Vehicle::display() const {
    std::cout << "ID: "       << id
              << " | Brand: "  << brand
              << " | Model: "  << model
              << " | $/Day: "  << pricePerDay
              << " | Status: " << (isRented ? "Rented" : "Available")
              << std::endl;
}
