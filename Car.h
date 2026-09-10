#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"

class Car : public Vehicle {
private:
    int totalSeats;

public:
    Car();
    Car(const std::string& newId,
        const std::string& newBrand,
        const std::string& newModel,
        double priceRate,
        int seats);

    int  getTotalSeats() const;
    void setTotalSeats(int seats);

    void display() const override;
};

#endif // CAR_H
