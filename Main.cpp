#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "Vehicle.h"
#include "Car.h"
#include "Motorcycle.h"
#include "Customer.h"
#include "Rental.h"

using namespace std;

// ---------- In-memory storage ----------
static vector<unique_ptr<Vehicle>> g_fleet;
static vector<Customer>                  g_customers;
static vector<Rental>                    g_rentals;

static int g_nextVehicleId  = 1;
static int g_nextCustomerId = 1;
static int g_nextRentalId   = 1;

// ---------- Menu ----------
static void printMenu() {
    cout << "\n===== Vehicle Rental System =====\n";
    cout << " 1. Add Car\n";
    cout << " 2. Add Motorcycle\n";
    cout << " 3. View Fleet\n";
    cout << " 4. Update Vehicle Daily Rate\n";
    cout << " 5. Delete Vehicle\n";
    cout << " 6. Search Vehicle by Make\n";
    cout << " 7. Register Customer\n";
    cout << " 8. View Customers\n";
    cout << " 9. Rent a Vehicle\n";
    cout << "10. Return a Vehicle\n";
    cout << "11. View Rentals\n";
    cout << " 0. Exit\n";
    cout << "Choice: ";
}

// ---------- Small helpers ----------
static string nextVehicleId() {
    string id = "V" + to_string(g_nextVehicleId++);
    return id;
}

static Vehicle* findVehicle(const string& id) {
    for (auto& v : g_fleet) {
        if (v->getId() == id) return v.get();
    }
    return nullptr;
}

static Customer* findCustomer(int id) {
    for (auto& c : g_customers) {
        if (c.getCustomerId() == id) return &c;
    }
    return nullptr;
}

static Rental* findActiveRental(const string& vehicleId) {
    for (auto& r : g_rentals) {
        if (r.getVehicleId() == vehicleId && !r.getIsReturned()) {
            return &r;
        }
    }
    return nullptr;
}

// ---------- Menu actions ----------
static void addCar() {
    string brand, model;
    double      rate   = 0.0;
    int         seats  = 0;

    cout << "Brand: ";     cin >> brand;
    cout << "Model: ";     cin >> model;
    cout << "$/Day: ";     cin >> rate;
    cout << "Seats: ";     cin >> seats;

    g_fleet.push_back(make_unique<Car>(nextVehicleId(), brand, model, rate, seats));
    cout << "Car added.\n";
}

static void addMotorcycle() {
    string brand, model;
    double      rate = 0.0;
    int         cc   = 0;

    cout << "Brand: ";  cin >> brand;
    cout << "Model: ";  cin >> model;
    cout << "$/Day: ";  cin >> rate;
    cout << "Engine CC: "; cin >> cc;

    g_fleet.push_back(make_unique<Motorcycle>(nextVehicleId(), brand, model, rate, cc));
    cout << "Motorcycle added.\n";
}

static void viewFleet() {
    if (g_fleet.empty()) {
        cout << "(fleet is empty)\n";
        return;
    }
    for (const auto& v : g_fleet) v->display();
}

static void updateVehicleRate() {
    string id;
    double      newRate = 0.0;
    cout << "Vehicle ID: ";  cin >> id;
    cout << "New $/Day: ";   cin >> newRate;

    Vehicle* v = findVehicle(id);
    if (!v) { cout << "Not found.\n"; return; }
    v->setPricePerDay(newRate);
    cout << "Rate updated.\n";
}

static void deleteVehicle() {
    string id;
    cout << "Vehicle ID: "; cin >> id;

    auto it = g_fleet.end();
    for (auto i = g_fleet.begin(); i != g_fleet.end(); ++i) {
        if ((*i)->getId() == id) { it = i; break; }
    }
    if (it == g_fleet.end()) { cout << "Not found.\n"; return; }
    if ((*it)->getIsRented()) {
        cout << "Cannot delete: vehicle is currently rented.\n";
        return;
    }
    g_fleet.erase(it);
    cout << "Vehicle deleted.\n";
}

static void searchByMake() {
    string brand;
    cout << "Brand to search: "; cin >> brand;

    bool any = false;
    for (const auto& v : g_fleet) {
        if (v->getBrand() == brand) {
            v->display();
            any = true;
        }
    }
    if (!any) cout << "No matches.\n";
}

static void registerCustomer() {
    string name, phone, email;
    cout << "Name: ";   cin >> name;
    cout << "Phone: ";  cin >> phone;
    cout << "Email: ";  cin >> email;

    g_customers.emplace_back(g_nextCustomerId++, name, phone, email);
    cout << "Customer registered.\n";
}

static void viewCustomers() {
    if (g_customers.empty()) {
        cout << "(no customers yet)\n";
        return;
    }
    for (const auto& c : g_customers) c.displayCustomer();
}

static void rentVehicle() {
    if (g_fleet.empty() || g_customers.empty()) {
        cout << "Need at least one vehicle and one customer first.\n";
        return;
    }

    string vehicleId;
    int         customerId = 0;
    int         days       = 0;

    cout << "Vehicle ID: ";  cin >> vehicleId;
    cout << "Customer ID: "; cin >> customerId;
    cout << "Days: ";        cin >> days;

    Vehicle* v = findVehicle(vehicleId);
    if (!v)                          { cout << "Vehicle not found.\n"; return; }
    if (v->getIsRented())            { cout << "Already rented.\n";  return; }
    if (!findCustomer(customerId))   { cout << "Customer not found.\n"; return; }
    if (days <= 0)                   { cout << "Days must be > 0.\n";  return; }

    double total = days * v->getPricePerDay();
    int    rentalId = g_nextRentalId++;
    g_rentals.emplace_back(rentalId, customerId, vehicleId, days, total);
    v->setIsRented(true);
    findCustomer(customerId)->addRentalId(rentalId);

    cout << "Rented (rental #" << rentalId << "). Total: $" << total << "\n";
}

static void returnVehicle() {
    string vehicleId;
    cout << "Vehicle ID: "; cin >> vehicleId;

    Vehicle* v = findVehicle(vehicleId);
    if (!v) { cout << "Vehicle not found.\n"; return; }

    Rental* r = findActiveRental(vehicleId);
    if (!r) { cout << "No active rental for that vehicle.\n"; return; }

    r->setIsReturned(true);
    v->setIsRented(false);
    cout << "Returned. Final cost: $" << r->getTotalCost() << "\n";
}

static void viewRentals() {
    if (g_rentals.empty()) {
        cout << "(no rentals yet)\n";
        return;
    }
    for (const auto& r : g_rentals) r.displayRental();
}

// ---------- Entry point ----------
int main() {
    bool running = true;
    while (running) {
        printMenu();
        int choice = -1;
        cin >> choice;

        switch (choice) {
            case  1: addCar();          break;
            case  2: addMotorcycle();   break;
            case  3: viewFleet();       break;
            case  4: updateVehicleRate(); break;
            case  5: deleteVehicle();   break;
            case  6: searchByMake();    break;
            case  7: registerCustomer();break;
            case  8: viewCustomers();   break;
            case  9: rentVehicle();     break;
            case 10: returnVehicle();   break;
            case 11: viewRentals();     break;
            case  0: running = false;   break;
            default: cout << "Invalid choice.\n";
        }
    }
    return 0;
}
