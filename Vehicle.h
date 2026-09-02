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
};

#endif
