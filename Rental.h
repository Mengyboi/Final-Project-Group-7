#ifndef RENTAL_H
#define RENTAL_H

#include <string>


class Rental {
private:
    int rentalId;
    int customerId;
    std::string vehicleId;
    int days;
    double totalCost;
    bool isReturned;

public:
    void displayRental() const;
    Rental(int rentalId,
           int customerId,
           const std::string& vehicleId,
           int days,
           double totalCost);

    int getRentalId() const;
    int getCustomerId() const;
    const std::string& getVehicleId() const;

    int getDays() const;
    double getTotalCost() const;

    bool getIsReturned() const;
    void setIsReturned(bool returned);
};

#endif  