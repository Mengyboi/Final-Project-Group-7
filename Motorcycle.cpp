#include <iostream>
using namespace std;

class Motocycle{
private:
    string id; 
    string brand; //ex: honda or suzuki
    string model; // ex: scoopyi or dream018
    double pricePerDay; //rental price.
    bool available;// status: available or un available.
public:
    //defualt constructor
    Motocycle(){
        id = "Unknown";
        brand = "Unknown";
        model = "Unknown";
        pricePerDay = 0;
        available = true;
    }
    //parameterized constructor
    Motocycle(string id, string brand, string model, double price) :
        id(id), brand(brand), model(model), pricePerDay(price), available(true) {}
    //virtual destructor
    virtual ~Motocycle(){}
};
    

int main(){

}