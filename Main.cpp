#include <iostream>
#include <limits>
#include <string>

#include "RentalSystem.h"
#include "Vehicle.h"

using namespace std;

static bool readText(const string& prompt, string& value) {
    while (true) {
        cout << prompt;
        if (!getline(cin, value)) return false;
        if (!value.empty()) return true;
        cout << "Input cannot be empty. Please try again.\n";
    }
}

static bool readInt(const string& prompt, int& value) {
    while (true) {
        cout << prompt;
        if (cin >> value) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return true;
        }
        if (cin.eof()) return false;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter a whole number.\n";
    }
}

static bool readDouble(const string& prompt, double& value) {
    while (true) {
        cout << prompt;
        if (cin >> value) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return true;
        }
        if (cin.eof()) return false;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter a number.\n";
    }
}

static void printMenu() {
    cout << "\n===== Vehicle Rental System =====\n"
         << " 1. Add Car\n"
         << " 2. Add Motorcycle\n"
         << " 3. View Fleet\n"
         << " 4. Update Vehicle Daily Rate\n"
         << " 5. Delete Vehicle\n"
         << " 6. Search Vehicle by Make\n"
         << " 7. Register Customer\n"
         << " 8. View Customers\n"
         << " 9. Rent a Vehicle\n"
         << "10. Return a Vehicle\n"
         << "11. View Rentals\n"
         << " 0. Exit\n";
}

static void addCar(RentalSystem& system) {
    string brand, model;
    string vehicleId, error;
    double rate = 0.0;
    int seats = 0;
    if (!readText("Brand: ", brand) || !readText("Model: ", model) ||
        !readDouble("$/Day: ", rate) || !readInt("Seats: ", seats)) {
        return;
    }

    if (system.addCar(brand, model, rate, seats, vehicleId, error)) {
        cout << "Car added with ID " << vehicleId << ".\n";
    } else {
        cout << "Car was not added: " << error << "\n";
    }
}

static void addMotorcycle(RentalSystem& system) {
    string brand, model;
    string vehicleId, error;
    double rate = 0.0;
    int engineCC = 0;
    if (!readText("Brand: ", brand) || !readText("Model: ", model) ||
        !readDouble("$/Day: ", rate) || !readInt("Engine CC: ", engineCC)) {
        return;
    }

    if (system.addMotorcycle(brand, model, rate, engineCC, vehicleId, error)) {
        cout << "Motorcycle added with ID " << vehicleId << ".\n";
    } else {
        cout << "Motorcycle was not added: " << error << "\n";
    }
}

static void viewFleet(const RentalSystem& system) {
    if (system.getFleet().empty()) {
        cout << "(fleet is empty)\n";
        return;
    }
    for (const auto& vehicle : system.getFleet()) {
        vehicle->display();
    }
}

static void updateVehicleRate(RentalSystem& system) {
    string vehicleId, error;
    double newRate = 0.0;
    if (!readText("Vehicle ID: ", vehicleId) ||
        !readDouble("New $/Day: ", newRate)) return;

    if (system.updateVehicleRate(vehicleId, newRate, error)) {
        cout << "Rate updated.\n";
    } else {
        cout << error << "\n";
    }
}

static void deleteVehicle(RentalSystem& system) {
    string vehicleId, error;
    if (!readText("Vehicle ID: ", vehicleId)) return;

    if (system.deleteVehicle(vehicleId, error)) {
        cout << "Vehicle deleted.\n";
    } else {
        cout << error << "\n";
    }
}

static void searchByBrand(const RentalSystem& system) {
    string brand;
    if (!readText("Brand to search: ", brand)) return;

    const auto matches = system.searchByBrand(brand);
    if (matches.empty()) {
        cout << "No matches.\n";
        return;
    }
    for (const Vehicle* vehicle : matches) {
        vehicle->display();
    }
}

static void registerCustomer(RentalSystem& system) {
    string name, phone, email;
    string error;
    int customerId = 0;
    if (!readText("Name: ", name) || !readText("Phone: ", phone) ||
        !readText("Email: ", email)) {
        return;
    }

    if (system.registerCustomer(name, phone, email, customerId, error)) {
        cout << "Customer registered with ID " << customerId << ".\n";
    } else {
        cout << "Customer was not registered: " << error << "\n";
    }
}

static void viewCustomers(const RentalSystem& system) {
    if (system.getCustomers().empty()) {
        cout << "(no customers yet)\n";
        return;
    }
    for (const auto& customer : system.getCustomers()) {
        customer.displayCustomer();
    }
}

static void rentVehicle(RentalSystem& system) {
    string vehicleId, error;
    int customerId = 0;
    int days = 0;
    int rentalId = 0;
    double totalCost = 0.0;
    if (!readText("Vehicle ID: ", vehicleId) ||
        !readInt("Customer ID: ", customerId) || !readInt("Days: ", days)) {
        return;
    }

    if (system.rentVehicle(vehicleId, customerId, days, rentalId, totalCost,
                           error)) {
        cout << "Rented (rental #" << rentalId << "). Total: $" << totalCost
             << "\n";
    } else {
        cout << error << "\n";
    }
}

static void returnVehicle(RentalSystem& system) {
    string vehicleId, error;
    double finalCost = 0.0;
    if (!readText("Vehicle ID: ", vehicleId)) return;

    if (system.returnVehicle(vehicleId, finalCost, error)) {
        cout << "Returned. Final cost: $" << finalCost << "\n";
    } else {
        cout << error << "\n";
    }
}

static void viewRentals(const RentalSystem& system) {
    if (system.getRentals().empty()) {
        cout << "(no rentals yet)\n";
        return;
    }
    for (const auto& rental : system.getRentals()) {
        rental.displayRental();
    }
}

int main() {
    RentalSystem system;
    bool running = true;

    while (running) {
        printMenu();
        int choice = -1;
        if (!readInt("Choice: ", choice)) break;

        switch (choice) {
        case 1:
            addCar(system);
            break;
        case 2:
            addMotorcycle(system);
            break;
        case 3:
            viewFleet(system);
            break;
        case 4:
            updateVehicleRate(system);
            break;
        case 5:
            deleteVehicle(system);
            break;
        case 6:
            searchByBrand(system);
            break;
        case 7:
            registerCustomer(system);
            break;
        case 8:
            viewCustomers(system);
            break;
        case 9:
            rentVehicle(system);
            break;
        case 10:
            returnVehicle(system);
            break;
        case 11:
            viewRentals(system);
            break;
        case 0:
            running = false;
            break;
        default:
            cout << "Invalid choice.\n";
        }
    }
}
