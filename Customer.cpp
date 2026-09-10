#include "Customer.h"
#include <algorithm>
#include <iostream>

Customer::Customer()
    : customerId(0), name(""), phone(""), email("") {}

Customer::Customer(int id,
                   const std::string& name,
                   const std::string& phone,
                   const std::string& email)
    : customerId(id), name(name), phone(phone), email(email) {}

int Customer::getCustomerId() const { return customerId; }

const std::string& Customer::getName()  const { return name; }
const std::string& Customer::getPhone() const { return phone; }
const std::string& Customer::getEmail() const { return email; }

const std::vector<int>& Customer::getRentalIds() const { return rentalIds; }

void Customer::setName(const std::string& name)  { this->name  = name; }
void Customer::setPhone(const std::string& phone) { this->phone = phone; }
void Customer::setEmail(const std::string& email) { this->email = email; }

void Customer::addRentalId(int rentalId) {
    rentalIds.push_back(rentalId);
}

void Customer::removeRentalId(int rentalId) {
    rentalIds.erase(std::remove(rentalIds.begin(), rentalIds.end(), rentalId),
                    rentalIds.end());
}

void Customer::displayCustomer() const {
    std::cout << "ID: "      << customerId
              << " | Name: "  << name
              << " | Phone: " << phone
              << " | Email: " << email
              << " | Rentals: " << rentalIds.size()
              << std::endl;
}
