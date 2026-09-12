#include "Utils.h"
#include <iostream>
#include <sstream>

using namespace std;

//Read an integer from the user
int Utils::readInt(string message){
    string input;
    int value;

    while (true){
        cout << message;
        getline(cin, input);

        stringstream ss(input);

        if ((ss >> value && ss.eof())){
            return value;   
        }
        cout << "Invalid input. Please enter enter an integer." << endl;
    }
}
// Read a positive integer
int Utils::readPositiveInt(string message){
    int value;
    while(true){

        value = readInt(message);
    
        if(value > 0){
            return value;
        }
        cout << "Please enter a number greater than 0." << endl;
    }
}
//Read a double value
double::readDouble(string message){
    string input;
    double value;

    while (true){
        cout << message;
        getline(cin, input);
        stringstream ss(input);

        if(ss >> value && ss.eof()){
            return value;
        }
        cout << "Invalid input. Please enter a number." << endl;
    }
}
// Read a positive double
double::readPositiveDouble(string message){
    double value;

    while (true){
        value = readDouble(message);
        if(value > 0){
            return value;
        }
        cout << "Please enter a number greater than 0." << endl;
    }
}