#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>

using namespace std;

class Customer{
    //private data members encapulation
    private:
    int customerId;
    string name;
    string phone;
    string email;

    //store the rental IDs
    vector<int> rentalIds;
    
    public:
    //default constructor
    Customer();

    //parameterized constructor
    Customer(int id, string name, string phone, string email);

    //getter
    int getCustomerId() const;
    string getName() const;
    string getPhone() const;
    string getEmail() const;

    //setter
    void setName(string name);
    void setPhone(string phone);
    void setEmail(string email); 

    //rental management
    void addRentalId(int rentalId);
    void removeRental(int rentalId);

    void displayCustomer() const;
};
#endif