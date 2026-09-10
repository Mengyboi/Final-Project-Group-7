#include "Customer.h"
#include <iostream>

using namespace std;

//default constructor
Customer::Customer(){
    customerId = 0;
    name = "";
    phone = "";
    email = "";
}
//parameterized constractor
Customer::Customer(int id, string name, string phone, string email){
    customerId = id;
    this->name = name;
    this->phone = phone;
    this->email = email;
}
//get customer ID
int Customer::getCustomerId() const{
    return customerId;
}
//get customer name
string Customer::getName() const{
    return name;
}
// get customer phone
string Customer::getPhone() const{
    return phone;
}
// get customer email
string Customer::getEmail() const{
    return email;
}

//set customer name
void Customer::setName(string name){
    this->name = name;
}
//set customer phone
void Customer::setPhone(string phone){
    this->phone = phone;
}
//set customer email
void Customer::setEmail(string email){
    this->email = email;
}

//add a rental ID to the customer's history
void Customer::addRentalId(int rentalId){
    rentalIds.push_back(rentalId);
}
//add a remove ID to the customer's history
void Customer::removeRental(int rentalId){
    for (auto it = rentalIds.begin(); it != rentalIds.end(); ++it){
        if (*it == rentalId){
            rentalIds.erase(it);
            break;
        }
    }
}