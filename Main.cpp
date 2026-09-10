#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "Vehicle.h"
#include "Car.h"
#include "Motorcycle.h"
#include "Customer.h"
#include "Rental.h"

// ---------- In-memory storage ----------
static std::vector<std::unique_ptr<Vehicle>> g_fleet;
static std::vector<Customer>                  g_customers;
static std::vector<Rental>                    g_rentals;

static int g_nextVehicleId  = 1;
static int g_nextCustomerId = 1;
static int g_nextRentalId   = 1;

// ---------- Menu ----------
static void printMenu() {
    std::cout << "\n===== Vehicle Rental System =====\n";
    std::cout << " 1. Add Car\n";
    std::cout << " 2. Add Motorcycle\n";
    std::cout << " 3. View Fleet\n";
    std::cout << " 4. Update Vehicle Daily Rate\n";
    std::cout << " 5. Delete Vehicle\n";
    std::cout << " 6. Search Vehicle by Make\n";
    std::cout << " 7. Register Customer\n";
    std::cout << " 8. View Customers\n";
    std::cout << " 9. Rent a Vehicle\n";
    std::cout << "10. Return a Vehicle\n";
    std::cout << "11. View Rentals\n";
    std::cout << " 0. Exit\n";
    std::cout << "Choice: ";
}

// ---------- Small helpers ----------
static std::string nextVehicleId() {
    std::string id = "V" + std::to_string(g_nextVehicleId++);
    return id;
}

static Vehicle* findVehicle(const std::string& id) {
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

static Rental* findActiveRental(const std::string& vehicleId) {
    for (auto& r : g_rentals) {
        if (r.getVehicleId() == vehicleId && !r.getIsReturned()) {
            return &r;
        }
    }
    return nullptr;
}

// ---------- Menu actions ----------
static void addCar() {
    std::string brand, model;
    double      rate   = 0.0;
    int         seats  = 0;

    std::cout << "Brand: ";     std::cin >> brand;
    std::cout << "Model: ";     std::cin >> model;
    std::cout << "$/Day: ";     std::cin >> rate;
    std::cout << "Seats: ";     std::cin >> seats;

    g_fleet.push_back(std::make_unique<Car>(nextVehicleId(), brand, model, rate, seats));
    std::cout << "Car added.\n";
}

static void addMotorcycle() {
    std::string brand, model;
    double      rate = 0.0;
    int         cc   = 0;

    std::cout << "Brand: ";  std::cin >> brand;
    std::cout << "Model: ";  std::cin >> model;
    std::cout << "$/Day: ";  std::cin >> rate;
    std::cout << "Engine CC: "; std::cin >> cc;

    g_fleet.push_back(std::make_unique<Motorcycle>(nextVehicleId(), brand, model, rate, cc));
    std::cout << "Motorcycle added.\n";
}

static void viewFleet() {
    if (g_fleet.empty()) {
        std::cout << "(fleet is empty)\n";
        return;
    }
    for (const auto& v : g_fleet) v->display();
}

static void updateVehicleRate() {
    std::string id;
    double      newRate = 0.0;
    std::cout << "Vehicle ID: ";  std::cin >> id;
    std::cout << "New $/Day: ";   std::cin >> newRate;

    Vehicle* v = findVehicle(id);
    if (!v) { std::cout << "Not found.\n"; return; }
    v->setPricePerDay(newRate);
    std::cout << "Rate updated.\n";
}

static void deleteVehicle() {
    std::string id;
    std::cout << "Vehicle ID: "; std::cin >> id;

    auto it = g_fleet.end();
    for (auto i = g_fleet.begin(); i != g_fleet.end(); ++i) {
        if ((*i)->getId() == id) { it = i; break; }
    }
    if (it == g_fleet.end()) { std::cout << "Not found.\n"; return; }
    if ((*it)->getIsRented()) {
        std::cout << "Cannot delete: vehicle is currently rented.\n";
        return;
    }
    g_fleet.erase(it);
    std::cout << "Vehicle deleted.\n";
}

static void searchByMake() {
    std::string brand;
    std::cout << "Brand to search: "; std::cin >> brand;

    bool any = false;
    for (const auto& v : g_fleet) {
        if (v->getBrand() == brand) {
            v->display();
            any = true;
        }
    }
    if (!any) std::cout << "No matches.\n";
}

static void registerCustomer() {
    std::string name, phone, email;
    std::cout << "Name: ";   std::cin >> name;
    std::cout << "Phone: ";  std::cin >> phone;
    std::cout << "Email: ";  std::cin >> email;

    g_customers.emplace_back(g_nextCustomerId++, name, phone, email);
    std::cout << "Customer registered.\n";
}

static void viewCustomers() {
    if (g_customers.empty()) {
        std::cout << "(no customers yet)\n";
        return;
    }
    for (const auto& c : g_customers) c.displayCustomer();
}

static void rentVehicle() {
    if (g_fleet.empty() || g_customers.empty()) {
        std::cout << "Need at least one vehicle and one customer first.\n";
        return;
    }

    std::string vehicleId;
    int         customerId = 0;
    int         days       = 0;

    std::cout << "Vehicle ID: ";  std::cin >> vehicleId;
    std::cout << "Customer ID: "; std::cin >> customerId;
    std::cout << "Days: ";        std::cin >> days;

    Vehicle* v = findVehicle(vehicleId);
    if (!v)                          { std::cout << "Vehicle not found.\n"; return; }
    if (v->getIsRented())            { std::cout << "Already rented.\n";  return; }
    if (!findCustomer(customerId))   { std::cout << "Customer not found.\n"; return; }
    if (days <= 0)                   { std::cout << "Days must be > 0.\n";  return; }

    double total = days * v->getPricePerDay();
    int    rentalId = g_nextRentalId++;
    g_rentals.emplace_back(rentalId, customerId, vehicleId, days, total);
    v->setIsRented(true);
    findCustomer(customerId)->addRentalId(rentalId);

    std::cout << "Rented (rental #" << rentalId << "). Total: $" << total << "\n";
}

static void returnVehicle() {
    std::string vehicleId;
    std::cout << "Vehicle ID: "; std::cin >> vehicleId;

    Vehicle* v = findVehicle(vehicleId);
    if (!v) { std::cout << "Vehicle not found.\n"; return; }

    Rental* r = findActiveRental(vehicleId);
    if (!r) { std::cout << "No active rental for that vehicle.\n"; return; }

    r->setIsReturned(true);
    v->setIsRented(false);
    std::cout << "Returned. Final cost: $" << r->getTotalCost() << "\n";
}

static void viewRentals() {
    if (g_rentals.empty()) {
        std::cout << "(no rentals yet)\n";
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
        std::cin >> choice;

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
            default: std::cout << "Invalid choice.\n";
        }
    }
    return 0;
}
