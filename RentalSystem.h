#ifndef RENTAL_SYSTEM_H
#define RENTAL_SYSTEM_H

#include <memory>
#include <string>
#include <vector>

#include "Customer.h"
#include "Rental.h"

class Vehicle;

class RentalSystem {
private:
    std::vector<std::unique_ptr<Vehicle>> fleet;
    std::vector<Customer> customers;
    std::vector<Rental> rentals;
    int nextVehicleNumber;
    int nextCustomerId;
    int nextRentalId;

    Rental* findActiveRental(const std::string& vehicleId);

public:
    RentalSystem();
    ~RentalSystem();

    bool addCar(const std::string& brand,
                const std::string& model,
                double pricePerDay,
                int totalSeats,
                std::string& vehicleId,
                std::string& error);
    bool addMotorcycle(const std::string& brand,
                       const std::string& model,
                       double pricePerDay,
                       int engineCC,
                       std::string& vehicleId,
                       std::string& error);
    bool registerCustomer(const std::string& name,
                          const std::string& phone,
                          const std::string& email,
                          int& customerId,
                          std::string& error);

    bool updateVehicleRate(const std::string& vehicleId,
                           double newRate,
                           std::string& error);
    bool deleteVehicle(const std::string& vehicleId, std::string& error);
    std::vector<const Vehicle*> searchByBrand(const std::string& brand) const;

    bool rentVehicle(const std::string& vehicleId,
                     int customerId,
                     int days,
                     int& rentalId,
                     double& totalCost,
                     std::string& error);
    bool returnVehicle(const std::string& vehicleId,
                       double& finalCost,
                       std::string& error);

    Vehicle* findVehicle(const std::string& vehicleId);
    const Vehicle* findVehicle(const std::string& vehicleId) const;
    Customer* findCustomer(int customerId);
    const Customer* findCustomer(int customerId) const;

    const std::vector<std::unique_ptr<Vehicle>>& getFleet() const;
    const std::vector<Customer>& getCustomers() const;
    const std::vector<Rental>& getRentals() const;
};

#endif // RENTAL_SYSTEM_H
