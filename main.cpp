//
//  main.cpp
//  Carbon Calculator
//
//  Created by Joseph Ravalese III on 9/12/17.
//  Copyright © 2017 Joseph Ravalese. All rights reserved.
//

#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <math.h>

using namespace std;

//  Classes

class consumptionType {
public:
    string name;
    string quantityName;
    string units;
    string efficiencyUnits;
    string consumedWord;
    float inputValue;
    float efficiencyValue;
    float MJ;
    float carbon;
    void editValue(float minValue);
    void clearValue();
    void summary();
};

//  Global Variables

float totalkWh = 0;
float totalMJ = 0;
float totalCarbon = 0;
string currentMenu;
bool userQuit = false;

//  Global Constants

const float kWhToMJ = 3.6;
const float MJTokWh = 1 / kWhToMJ;
const float kWhToCal = 8.6 * pow(10, 5);
const float calTokWh = 1 / kWhToCal;
const float petrolLitersToMJ = 43;
const float autoPetrolPoundsCarbonPerMJ = 0.147;
const float autoElecPoundsCarbonPerMJ = 0.318;

//  US Energy Generation Breakdown

//  Add something here ^^^

//  Function Prototypes

//float travelByPlane();
//float travelByGasCar();
void mainMenu();
void consumptionMenu();
void carbonBreakdownMenu();
void conservationMenu();
float calcTotalMJ();
float calcTotalCarbon();
float round(float &userInput, int numDigits);
void previousMenu();

//  Main Function

int main() {
    /*consumptionType airTravel;
    airTravel.name = "Air Travel";
    airTravel.units = "Miles";
    airTravel.quantityName = "Distance";
    airTravel.consumedWord = "Flown";
    airTravel.editValue(0);
    
    airTravel.summary();*/
    
    while (userQuit == false) {
        mainMenu();
    }
    cout << endl << "Thank you for using our carbon calculator. Goodbye!" << endl << endl;
    return 0;
}

//  Function Declarations

void mainMenu() {
    int userInput = 0;
    bool validEntry = false;
    currentMenu = "main";
    
    totalCarbon = calcTotalCarbon();
    totalMJ = calcTotalMJ();
    
    cout << endl;
    cout << "     ***** Main Menu *****     " << endl << endl;
    cout << "Total Energy Consumption: " << totalMJ << " MJ" << endl;
    cout << "Estimated Total Carbon Footprint: " << totalCarbon << " lb carbon" << endl << endl;
    cout << "1. View/edit consumption by category" << endl;
    cout << "2. View breakdown of carbon footprint" << endl;
    cout << "3. View ways to reduce your carbon footprint" << endl;
    cout << "4. Exit program" << endl << endl;
    
    cout << "Please select an option: ";
    
    do {
        cin >> userInput;
        cin.ignore();
        
        switch (userInput) {
            case 1:
                validEntry = true;
                consumptionMenu();
                break;
            case 2:
                validEntry = true;
                carbonBreakdownMenu();
                break;
            case 3:
                validEntry = true;
                conservationMenu();
                break;
            case 4:
                validEntry = true;
                userQuit = true;
                break;
            default:
                cout << "Please select a valid option: ";
                break;
        }
    }
    while (validEntry == false);
}

void consumptionMenu() {
    int userInput = 0;
    bool validEntry = false;
    currentMenu = "consumption";

    cout << endl;
    cout << "     ***** View/Edit Consumption *****     " << endl << endl;
    cout << "1. Household" << endl;
    cout << "2. Transportation" << endl;
    cout << "3. Work/School" << endl;
    cout << "4. Return to main menu" << endl << endl;
    
    cout << "Please select an option: ";
    
    do {
        cin >> userInput;
        cin.ignore();
        
        switch (userInput) {
            case 4:
                validEntry = true;
                mainMenu();
                break;
            default:
                cout << "Please select a valid option: ";
                break;
        }
    }
    while (validEntry == false);
}

void carbonBreakdownMenu() {
    currentMenu = "carbonBreakdown";
}

void conservationMenu() {
    currentMenu = "conservation";
}

float calcTotalMJ() {
    //  Sum all MJ consumption levels by category
    return 0;
}

float calcTotalCarbon() {
    //  Sum all carbon emission levels by category
    return 0;
}

//  Rounds float values to the nearest n digit (after decimal) for use when displaying to user, and stores it to the original variable
float round(float &userInput, int numDigits) {
    userInput = roundf(userInput * pow(10, numDigits)) / pow(10, numDigits);
    return userInput;
}

void consumptionType::editValue(float minValue) {
    float userInput;
    bool validInput = false;
    
    cout << "Current " << name << " consumption: " << inputValue << " " << units << "." << endl;
    cout << "Please enter a new value for " << name << ": ";
    
    do {
        cin >> userInput;
        cin.ignore();
        
        if (userInput >= minValue) {
            validInput = true;
        }
        else {
            cout << quantityName << " cannot be less than " << minValue << " " << units << "." << endl;
        }
    }
    while (validInput == false);
    
    inputValue = userInput;
    cout << "New " << name << " consumption: " << inputValue << " " << units << "." << endl;
}

void consumptionType::clearValue() {
    inputValue = 0;
}

void consumptionType::summary() {
    cout << name << ":" << endl;
    cout << "Total " << units << " " << consumedWord << ": " << inputValue << " " << units << endl;
    cout << "MJ Equivalent: " << MJ << " MJ" << endl;
    cout << "Estimated Carbon Footprint: " << carbon << " lb Carbon Dioxide" << endl << endl;
}

/*
//Calculates The total carbon footprint of using a gas car using user input of MPG, Distance traveled, etc
float travelByPlane() {
    float mpg;
    float distance;
    float gallonsNeeded;
    float totalCarbonfootprint;
    
    cout << "Please enter fuel efficiency of Car (miles per gallon)" << endl;
    cin >> mpg;
    if (mpg < 0) {
        cout << "mpg cannot be less than zero" << endl;
    }
    
    else {
        cout << "please enter total distance travelled in miles" << endl;
        cin >> distance;

        if (distance < 0) {
            cout << "distance cannot be less than zero" << endl;
        }
        
        else {
            gallonsNeeded = distance/mpg;
            cout << "Gallons of Gasoline needed: " << gallonsNeeded << endl;
        }
    }
    
    return totalCarbonfootprint;
}

//  Calculates The total carbon footprint of using a gas car using user input of MPG, Distance traveled, etc
float travelByGasCar() {
    float mpg;
    float distance;
    float gallonsNeeded;
    float totalCarbonfootprint;
    
    cout << "Please enter fuel efficiency of Car (miles per gallon)" << endl;
    cin >> mpg;
    if (mpg < 0) {
        cout << "mpg cannot be less than zero" << endl;
    }
    
    else {
        cout << "please enter total distance travelled in miles" << endl;
        cin >> distance;
        
        if (distance < 0) {
            cout << "distance cannot be less than zero" << endl;
        }
        
        else {
            gallonsNeeded = distance/mpg;
            cout << "Gallons of Gasoline needed: " << gallonsNeeded << endl;
        }
    }
    
    return totalCarbonfootprint;
}*/

