# Final Project — Group 7: Vehicle Rental System

A small console-based vehicle rental system written in C++17. Add cars
and motorcycles, register customers, rent and return vehicles, and view
the fleet, customer list, and rental history. Data lives in memory for
the duration of a run.

## Class layout

| Class        | Role                                                |
|--------------|-----------------------------------------------------|
| `Vehicle`    | Abstract-style base; stores id/brand/model/rate/status. |
| `Car`        | `Vehicle` subclass with `totalSeats`.                |
| `Motorcycle` | `Vehicle` subclass with `engineCC`.                  |
| `Customer`   | Customer record plus a list of rental IDs.           |
| `Rental`     | One rental agreement (customer, vehicle, days, cost). |
| `Main.cpp`   | Menu loop and storage (`std::vector` + `std::unique_ptr`). |

`display()` is `virtual` on `Vehicle` so fleet iteration polymorphically
prints the right subclass details.

```bash
g++ -std=c++17 -Wall -Wextra -o rental_app \
    Main.cpp Vehicle.cpp Car.cpp Motorcycle.cpp Customer.cpp Rental.cpp
```

On Windows with MinGW the same command works from Git Bash or PowerShell.

## Run

```bash
./rental_app
```

Follow the on-screen menu. Vehicles and customers get auto-incrementing
IDs (`V1`, `V2`, ... and `1`, `2`, ...) so you can refer to them by ID
when renting or returning.

## Menu

```
1.  Add Car
2.  Add Motorcycle
3.  View Fleet
4.  Update Vehicle Daily Rate
5.  Delete Vehicle
6.  Search Vehicle by Make
7.  Register Customer
8.  View Customers
9.  Rent a Vehicle
10. Return a Vehicle
11. View Rentals
0.  Exit
```
