#include "RentalSystem.h"

#include <algorithm>
#include <memory>

#include "Car.h"
#include "Motorcycle.h"
#include "Vehicle.h"

using namespace std;

RentalSystem::RentalSystem()
    : nextVehicleNumber(1), nextCustomerId(1), nextRentalId(1) {}

RentalSystem::~RentalSystem() = default;

bool RentalSystem::addCar(const string& newBrand,
                          const string& newModel,
                          double pricePerDay,
                          int totalSeats,
                          string& vehicleId,
                          string& error) {
    if (pricePerDay <= 0.0) {
        error = "Daily rate must be greater than zero.";
        return false;
    }
    if (totalSeats <= 0) {
        error = "A car must have at least one seat.";
        return false;
    }

    vehicleId = "V" + to_string(nextVehicleNumber++);
    fleet.push_back(make_unique<Car>(vehicleId, newBrand, newModel,
                                     pricePerDay, totalSeats));
    return true;
}

bool RentalSystem::addMotorcycle(const string& newBrand,
                                 const string& newModel,
                                 double pricePerDay,
                                 int engineCC,
                                 string& vehicleId,
                                 string& error) {
    if (pricePerDay <= 0.0) {
        error = "Daily rate must be greater than zero.";
        return false;
    }
    if (engineCC <= 0) {
        error = "Engine capacity must be positive.";
        return false;
    }

    vehicleId = "V" + to_string(nextVehicleNumber++);
    fleet.push_back(make_unique<Motorcycle>(vehicleId, newBrand, newModel,
                                            pricePerDay, engineCC));
    return true;
}

bool RentalSystem::registerCustomer(const string& name,
                                    const string& phone,
                                    const string& email,
                                    int& customerId,
                                    string& error) {
    if (name.empty() || phone.empty() || email.empty()) {
        error = "Customer fields cannot be empty.";
        return false;
    }

    customerId = nextCustomerId++;
    customers.emplace_back(customerId, name, phone, email);
    return true;
}

bool RentalSystem::updateVehicleRate(const string& vehicleId,
                                     double newRate,
                                     string& error) {
    Vehicle* vehicle = findVehicle(vehicleId);
    if (!vehicle) {
        error = "Vehicle not found.";
        return false;
    }
    if (vehicle->getIsRented()) {
        error = "Cannot update a vehicle that is currently rented.";
        return false;
    }
    if (newRate <= 0.0) {
        error = "Daily rate must be greater than zero.";
        return false;
    }

    vehicle->setPricePerDay(newRate);
    return true;
}

bool RentalSystem::deleteVehicle(const string& vehicleId, string& error) {
    const auto it = find_if(
        fleet.begin(), fleet.end(),
        [&vehicleId](const unique_ptr<Vehicle>& vehicle) {
            return vehicle->getId() == vehicleId;
        });

    if (it == fleet.end()) {
        error = "Vehicle not found.";
        return false;
    }
    if ((*it)->getIsRented()) {
        error = "Cannot delete a vehicle that is currently rented.";
        return false;
    }

    fleet.erase(it);
    return true;
}

vector<const Vehicle*> RentalSystem::searchByBrand(
    const string& searchBrand) const {
    vector<const Vehicle*> matches;
    for (const auto& vehicle : fleet) {
        if (vehicle->getBrand() == searchBrand) {
            matches.push_back(vehicle.get());
        }
    }
    return matches;
}

bool RentalSystem::rentVehicle(const string& vehicleId,
                               int customerId,
                               int days,
                               int& rentalId,
                               double& totalCost,
                               string& error) {
    Vehicle* vehicle = findVehicle(vehicleId);
    if (!vehicle) {
        error = "Vehicle not found.";
        return false;
    }
    if (vehicle->getIsRented()) {
        error = "Vehicle is already rented.";
        return false;
    }
    if (!findCustomer(customerId)) {
        error = "Customer not found.";
        return false;
    }
    if (days <= 0) {
        error = "Rental days must be greater than zero.";
        return false;
    }

    rentalId = nextRentalId++;
    totalCost = days * vehicle->getPricePerDay();
    rentals.emplace_back(rentalId, customerId, vehicleId, days, totalCost);
    vehicle->setIsRented(true);
    findCustomer(customerId)->addRentalId(rentalId);
    return true;
}

bool RentalSystem::returnVehicle(const string& vehicleId,
                                 double& finalCost,
                                 string& error) {
    Vehicle* vehicle = findVehicle(vehicleId);
    if (!vehicle) {
        error = "Vehicle not found.";
        return false;
    }

    Rental* rental = findActiveRental(vehicleId);
    if (!rental) {
        error = "No active rental for that vehicle.";
        return false;
    }

    rental->setIsReturned(true);
    vehicle->setIsRented(false);
    finalCost = rental->getTotalCost();
    return true;
}

Vehicle* RentalSystem::findVehicle(const string& vehicleId) {
    for (auto& vehicle : fleet) {
        if (vehicle->getId() == vehicleId) {
            return vehicle.get();
        }
    }
    return nullptr;
}

const Vehicle* RentalSystem::findVehicle(const string& vehicleId) const {
    for (const auto& vehicle : fleet) {
        if (vehicle->getId() == vehicleId) {
            return vehicle.get();
        }
    }
    return nullptr;
}

Customer* RentalSystem::findCustomer(int customerId) {
    for (auto& customer : customers) {
        if (customer.getCustomerId() == customerId) {
            return &customer;
        }
    }
    return nullptr;
}

const Customer* RentalSystem::findCustomer(int customerId) const {
    for (const auto& customer : customers) {
        if (customer.getCustomerId() == customerId) {
            return &customer;
        }
    }
    return nullptr;
}

Rental* RentalSystem::findActiveRental(const string& vehicleId) {
    for (auto& rental : rentals) {
        if (rental.getVehicleId() == vehicleId && !rental.getIsReturned()) {
            return &rental;
        }
    }
    return nullptr;
}

const vector<unique_ptr<Vehicle>>& RentalSystem::getFleet() const {
    return fleet;
}

const vector<Customer>& RentalSystem::getCustomers() const {
    return customers;
}

const vector<Rental>& RentalSystem::getRentals() const {
    return rentals;
}
