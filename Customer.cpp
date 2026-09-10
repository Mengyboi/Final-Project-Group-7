#include "Customer.h"
#include <algorithm>
#include <iostream>

using namespace std;

Customer::Customer()
    : customerId(0), name(""), phone(""), email("") {}

Customer::Customer(int id,
                   const string& name,
                   const string& phone,
                   const string& email)
    : customerId(id), name(name), phone(phone), email(email) {}

int Customer::getCustomerId() const { return customerId; }

const string& Customer::getName()  const { return name; }
const string& Customer::getPhone() const { return phone; }
const string& Customer::getEmail() const { return email; }

const vector<int>& Customer::getRentalIds() const { return rentalIds; }

void Customer::setName(const string& name)  { this->name  = name; }
void Customer::setPhone(const string& phone) { this->phone = phone; }
void Customer::setEmail(const string& email) { this->email = email; }

void Customer::addRentalId(int rentalId) {
    rentalIds.push_back(rentalId);
}

void Customer::removeRentalId(int rentalId) {
    rentalIds.erase(remove(rentalIds.begin(), rentalIds.end(), rentalId),
                    rentalIds.end());
}

void Customer::displayCustomer() const {
    cout << "ID: "      << customerId
              << " | Name: "  << name
              << " | Phone: " << phone
              << " | Email: " << email
              << " | Rentals: " << rentalIds.size()
              << endl;
}
