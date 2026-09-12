#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
using namespace std;

class Vehicle{
protected:
    string id;
    string brand;
    string model;
    double pricePerDay;
    bool isRented;

public:
    //defualt constructor
    Vehicle();

    //parameterized constructor
    Vehicle(string newId, string newBrand, string newModel, double priceRate);

    //destructor
    ~Vehicle();

    //getter
    string getId();
    string getBrand();
    string getModel();
    double getPricePerDay();
    bool getIsRented();

    //setter
    void setPricePerDay(double newPricePerDay);
    void setIsRented(bool RentedStatus);

    // Virtual functions (can be overridden by derived classes)
    
    virtual void display();
};

#endif
