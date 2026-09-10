#include "Motorcycle.h"
#include <iostream>

using namespace std;

Motorcycle::Motorcycle()
    : Vehicle(), engineCC(0) {}

Motorcycle::Motorcycle(const string& newId,
                       const string& newBrand,
                       const string& newModel,
                       double priceRate,
                       int cc)
    : Vehicle(newId, newBrand, newModel, priceRate),
      engineCC(cc) {}

int Motorcycle::getEngineCC() const { return engineCC; }

void Motorcycle::setEngineCC(int cc) { engineCC = cc; }

void Motorcycle::display() const {
    Vehicle::display();
    cout << "  -> Engine: " << engineCC << "cc" << endl;
}
