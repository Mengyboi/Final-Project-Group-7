#ifndef RENTAL_H
#define RENTAL_H

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