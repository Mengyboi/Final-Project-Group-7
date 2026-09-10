#include "Vehicle.h"
#include <iostream>

using namespace std;

Vehicle::Vehicle()
    : id("Unknown"),
      brand("Unknown"),
      model("Unknown"),
      pricePerDay(0.0),
      isRented(false) {}

Vehicle::Vehicle(const string& newId,
                 const string& newBrand,
                 const string& newModel,
                 double priceRate)
    : id(newId),
      brand(newBrand),
      model(newModel),
      pricePerDay(priceRate),
      isRented(false) {}

string Vehicle::getId()          const { return id; }
string Vehicle::getBrand()       const { return brand; }
string Vehicle::getModel()       const { return model; }
double      Vehicle::getPricePerDay() const { return pricePerDay; }
bool        Vehicle::getIsRented()    const { return isRented; }

void Vehicle::setPricePerDay(double newPricePerDay) { pricePerDay = newPricePerDay; }
void Vehicle::setIsRented(bool rentedStatus)        { isRented    = rentedStatus; }

void Vehicle::display() const {
    cout << "ID: "       << id
              << " | Brand: "  << brand
              << " | Model: "  << model
              << " | $/Day: "  << pricePerDay
              << " | Status: " << (isRented ? "Rented" : "Available")
              << endl;
}
