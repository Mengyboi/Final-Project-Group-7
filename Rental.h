#ifndef RENTAL_H
#define RENTAL_H

<<<<<<< HEAD
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
    Rental();
    Rental(int id,
           int custId,
           const std::string& vehId,
           int days,
           double totalCost);

    int getRentalId() const;
    int getCustomerId() const;
    const std::string& getVehicleId() const;
    int getDays() const;
    double getTotalCost() const;
    bool getIsReturned() const;

    void setDays(int days);
    void setIsReturned(bool returned);

    void displayRental() const;
};

#endif // RENTAL_H
=======
#include <iostream> 
using namespace std;

class Rental{
    //private data members for encapulation
    private : 
    int rentalId;
    int customerId;
    int vehicleId;
    int rentalDays;
    double dailyRate;
    double totalCost;
    bool active;
    
    public:
    //default constructor
    Rental();

    //parameterized constructor 
    Rental(int rentalId, int customerId, int vehicleId, int rentalDays, double dailyRate);

    //getter
    int getRentalId() const;
    int getCustomerId() const;
    int getVehicleId() const;
    int getRentalDays() const;
    double getDailyRate() const;
    double getTotalCost()const;
    bool isActive() const;

    //setter
    void setRentalDays(int days);
    void setDailyRate(double rate);

    //calulate rental cost
    void calculateTotal();

    //complete the rental
    void returnVehicle();

    //Display rental informatiom
    void displayRental() const;

};
#endif
>>>>>>> 2cb217444a0ceebf63c78afdb2b4233aa243bca2
