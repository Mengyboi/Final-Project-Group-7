#include "Rental.h"
#include <iostream>

using std::cout;
using std::endl;

Rental::Rental(int rentalId,
               int customerId,
               const std::string& vehicleId,
               int days,
               double totalCost)
    : rentalId(rentalId),
      customerId(customerId),
      vehicleId(vehicleId),
      days(days),
      totalCost(totalCost),
      isReturned(false) {
}

int Rental::getRentalId() const {
    return rentalId;
}

int Rental::getCustomerId() const {
    return customerId;
}

const std::string& Rental::getVehicleId() const {
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

void Rental::setIsReturned(bool returned) {
    isReturned = returned;
}

void Rental::displayRental() const {
    cout << "Rental ID: " << rentalId
         << " | Customer ID: " << customerId
         << " | Vehicle ID: " << vehicleId
         << " | Days: " << days
         << " | Total Cost: $" << totalCost
         << " | Returned: " << (isReturned ? "Yes" : "No")
         << endl;
}