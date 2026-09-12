#include "Rental.h"
#include <iostream>

using namespace std;

//default constructor
Rental::Rental(){
    rentalId = 0;
    customerId = 0;
    vehicleId = 0;
    rentalDays = 0;
    dailyRate = 0.0;
    totalCost = 0.0;
    active = false;
}

//parameterized constructor
Rental::Rental(int rentalId, int customerId, int vehicleId, int rentalDays, double dailyRate){
    this->rentalId = rentalId;
    this->customerId = customerId;
    this->vehicleId = vehicleId;
    this->rentalDays = rentalDays;
    this->dailyRate = dailyRate;

    //A new rental is active
    active = true;

    //calculate the total rental cost
    calculateTotal();
}

//get rental ID
int Rental::getRentalId() const{
    return rentalId;
}
//get customer ID
int Rental::getCustomerId() const{
    return customerId;
}
//get vehicle ID
int Rental::getVehicleId() const{
    return vehicleId;
}
//get number of rental days
int Rental::getRentalDays() const{
    return rentalDays;
}
//get daily rental rate
double Rental::getDailyRate() const{
    return dailyRate;
}
//get total rental cost
double Rental::getTotalCost() const{
    return totalCost;
}
//check whetter the renatal is still active
bool Rental::isActive() const{
    return active;
}
//change rental days
void Rental::setRentalDays(int days){
    if (days>0){
        rentalDays = days;
        calculateTotal();
    }
}
//change daily rental rate
void Rental::setDailyRate(double rate){
    if (rate>=0){
        dailyRate = rate;
        calculateTotal();
    }
}
//calculate the total rental cost
void Rental::calculateTotal(){
    totalCost = rentalDays * dailyRate;
}
//Mark the rental as completed
void Rental::returnVehicle(){
    active = false;
}
//Display rental information
void Rental::displayRental() const{
    cout << "Rental ID: " << rentalId << endl;
    cout << "Customer ID: " << customerId << endl;
    cout << "Vehicle ID: " << vehicleId << endl;
    cout << "Rental Days: " << rentalDays << endl;
    cout << "Dialy Rate: $" << dailyRate << endl;
    cout << "Total Cost: $" << totalCost << endl;

    cout <<"Status: ";
    if (active){
        cout << "Active";
    }
    else{
        cout << "Returned";
    }
    cout << endl;
}