#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>

class Customer {
private:
    int                customerId;
    std::string        name;
    std::string        phone;
    std::string        email;
    std::vector<int>   rentalIds;

public:
    Customer();
    Customer(int id,
             const std::string& name,
             const std::string& phone,
             const std::string& email);

    int                getCustomerId() const;
    const std::string& getName()       const;
    const std::string& getPhone()      const;
    const std::string& getEmail()      const;
    const std::vector<int>& getRentalIds() const;

    void setName(const std::string& name);
    void setPhone(const std::string& phone);
    void setEmail(const std::string& email);

    void addRentalId(int rentalId);
    void removeRentalId(int rentalId);

    void displayCustomer() const;
};

#endif // CUSTOMER_H
