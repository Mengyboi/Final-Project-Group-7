#include "Motorcycle.h"
#include <iostream>

Motorcycle::Motorcycle()
    : Vehicle(), engineCC(0) {}

Motorcycle::Motorcycle(const std::string& newId,
                       const std::string& newBrand,
                       const std::string& newModel,
                       double priceRate,
                       int cc)
    : Vehicle(newId, newBrand, newModel, priceRate),
      engineCC(cc) {}

int Motorcycle::getEngineCC() const { return engineCC; }

void Motorcycle::setEngineCC(int cc) { engineCC = cc; }

void Motorcycle::display() const {
    Vehicle::display();
    std::cout << "  -> Engine: " << engineCC << "cc" << std::endl;
}
