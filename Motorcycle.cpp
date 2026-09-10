#include "Motorcycle.h"
#include <iostream>
using namespace std;


//defualt constructor
Motorcycle::Motorcycle(): Vehicle() {
    engincc = 0;
}
//parameterized constructor
Motorcycle::Motorcycle(string newId, string newBrand, string newModel, double priceRate, int engin) : Vehicle(newId, newBrand, newModel, priceRate){
    engincc == engin;
}
//getter
int Motorcycle::getEnginCC(){
    return engincc;
}
//setter
void Motorcycle::setEnginCC(int engin ){
    engincc = engin;
}

//display function derried with display from vehicle class
void Motorcycle::display(){
    Vehicle::display();
    cout << " | Engine : " << engincc << "cc" << endl;

}