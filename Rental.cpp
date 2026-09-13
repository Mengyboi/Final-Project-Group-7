#include "Rental.h"
#include <iostream>

using namespace std;

Rental::Rental()
    : rentalId(0),
      customerId(0),
      vehicleId(""),
      days(0),
      totalCost(0.0),
      isReturned(false) {}

Rental::Rental(int id,
               int custId,
               const string& vehId,
               int days,
               double totalCost)
    : rentalId(id),
      customerId(custId),
      vehicleId(vehId),
      days(days),
      totalCost(totalCost),
      isReturned(false) {}

int Rental::getRentalId() const {
    return rentalId;
}

int Rental::getCustomerId() const {
    return customerId;
}

const string& Rental::getVehicleId() const {
    return vehicleId;
}

int Rental::getDays() const {
    return days;
}

double Rental::getTotalCost() const {
    return totalCost;
}

bool Rental::getIsReturned() const {
    return isReturned;
}

void Rental::setDays(int newDays) {
    days = newDays;
}

void Rental::setIsReturned(bool returned) {
    isReturned = returned;
}

void Rental::displayRental() const {
    cout << "Rental ID: " << rentalId
         << " | Customer ID: " << customerId
         << " | Vehicle ID: " << vehicleId
         << " | Days: " << days
         << " | Total: $" << totalCost
         << " | Status: " << (isReturned ? "Returned" : "Active")
         << endl;
}
