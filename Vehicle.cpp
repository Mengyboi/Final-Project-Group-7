#include "Vehicle.h"
#include <iostream>
using namespace std;

//defualt constructor
Vehicle::Vehicle(){

    id = "Unknown";
    brand = "Unknown";
    model = "Unknown";
    pricePerDay = 0.0;
    isRented = false;
}
//parameterized constructor
Vehicle::Vehicle(string newId, string newBrand, string newModel, double priceRate){
    id = newId;
    brand = newBrand;
    model = newModel;
    pricePerDay = priceRate;
    isRented = false;
}
//destructor
Vehicle::~Vehicle(){}
//getter
string Vehicle::getId(){
    return id;
}
string Vehicle::getBrand(){
    return brand;
}
string Vehicle::getModel(){
    return model;
}
double Vehicle::getPricePerDay(){
    return pricePerDay;
}
bool Vehicle::getIsRented(){
    return isRented;
}
//setter
void Vehicle::setPricePerDay(double newPriceRate){
    pricePerDay = newPriceRate;
}
void Vehicle::setIsRented(bool rentedStatus){
    isRented = rentedStatus;
}

//function
void Vehicle::display(){
    cout << "ID : " << id 
        << " | Brand : " << brand 
        << " | Model : " << model 
        << " | Price/Day : $" << pricePerDay ;
        if(isRented){
            cout << " | Status : Rented "<< endl;
        } else{
            cout << " | Status : Available " << endl;
        }
}

 