#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

class Vehicle {
private:
    std::string id;
    std::string brand;
    std::string model;
    double pricePerDay;
    bool        isRented;

public:
    Vehicle();
    Vehicle(const std::string& newId,
            const std::string& newBrand,
            const std::string& newModel,
            double priceRate);

    virtual ~Vehicle() = default;

    const std::string& getId() const;
    const std::string& getBrand() const;
    const std::string& getModel() const;
    double getPricePerDay() const;
    bool getIsRented() const;

    void setPricePerDay(double newPricePerDay);
    void setIsRented(bool rentedStatus);

    virtual void display() const;
};

#endif // VEHICLE_H
