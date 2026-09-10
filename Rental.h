#ifndef RENTAL_H
#define RENTAL_H

#include <string>

class Rental {
private:
    int         rentalId;
    int         customerId;
    std::string vehicleId;
    int         days;
    double      totalCost;
    bool        isReturned;

public:
    Rental();
    Rental(int id,
           int custId,
           const std::string& vehId,
           int days,
           double totalCost);

    int                getRentalId()   const;
    int                getCustomerId() const;
    const std::string& getVehicleId()  const;
    int                getDays()       const;
    double             getTotalCost()  const;
    bool               getIsReturned() const;

    void setDays(int days);
    void setIsReturned(bool returned);

    void displayRental() const;
};

#endif // RENTAL_H
