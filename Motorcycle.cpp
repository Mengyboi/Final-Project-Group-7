#include <iostream>
using namespace std;

class Motorcycle{
private:
    string id; 
    string brand; //ex: honda or suzuki
    string model; // ex: scoopyi or dream018
    double pricePerDay; //rental price.
    bool available;// status: available or un available.
public:
    //defualt constructor
    Motorcycle(){
        id = "Unknown";
        brand = "Unknown";
        model = "Unknown";
        pricePerDay = 0;
        available = true;
    }
    //parameterized constructor
    Motorcycle(string id, string brand, string model, double price) :
        id(id), brand(brand), model(model), pricePerDay(price), available(true) {}
    //virtual destructor
    virtual ~Motorcycle(){}

    //getter
    string getId(){
        return id;
    }
    string getBrand(){
        return brand;
    }
    string getModel(){
        return model;
    }
    double getPricePerday(){
        return pricePerDay;
    }
    bool getAvailable(){
        return available;
    }
    //setter
    void setBrand(string brand){
        this->brand = brand;
    }
    void setModel(string model){
        this->model = model;
    }
    void setPricePerDay(double pricePerday){
        this->pricePerDay = pricePerDay;
    }
    void setAvailable(bool available){
        this->available = available;
    }
    //virtual function for polymorphism
    virtual void displayInfo() const{
        cout << "| ID: " << id 
            << " | Brand: " << brand 
            << " | Model: " << model 
            << " | Prece/Day : $" << pricePerDay 
            << " | Status: " << (available ? "Available" : "Rented") 
            << endl;
    }
    virtual string getType() const {
        return "sport bike";
    }
    
};

class SportBike : public Motorcycle {
private:
    int engineCC;

public:

    // Default constructor
    SportBike() : Motorcycle() {
        engineCC = 0;
    }

    // Parameterized constructor
    SportBike(string id, string brand, string model,
              double pricePerDay, int engineCC)
        : Motorcycle(id, brand, model, pricePerDay) {

        this->engineCC = engineCC;
    }

    // Destructor
    ~SportBike() override {
    }

    int getEngineCC() const {
        return engineCC;
    }

    void setEngineCC(int engineCC) {
        this->engineCC = engineCC;
    }

    // Override virtual function
    void displayInfo() const override {
        cout << "[Sport Bike] "<< endl;
        Motorcycle::displayInfo();
    }

    string getType() const override {
        return "Sport Bike";
    }
};
    

int main(){

}