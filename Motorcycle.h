#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H

#include "Vehicle.h"

class Motorcycle : public Vehicle {
private:
    int engineCC;

public:
    Motorcycle();
    Motorcycle(const std::string& newId,
               const std::string& newBrand,
               const std::string& newModel,
               double priceRate,
               int cc);

    int  getEngineCC() const;
    void setEngineCC(int cc);

    void display() const override;
};

#endif // MOTORCYCLE_H
