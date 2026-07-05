#include "converter.hpp"
#include <iostream>

using namespace std;

double inchesToCentimeters(double inches) {
    // 2.54 cm to one in, so multiply by 2.54
    return inches*2.54;
}

double centimetersToInches(double centimeters) {
    // 2.54 centimeters to one inch. Therefore, divide the number by 2.54.
    return centimeters/2.54;
}

double poundsToKilograms(double pounds) {
    // 2.205 pounds to 1 kg. Therefore, divide by 2.205.
    return pounds/2.205;
}

double kilogramsToPounds(double kilograms) {
    // 2.205 pounds to 1 kg. So, multiply by 2.205
    return kilograms*2.205;
}

double fahrenheitToCelsius(double fahrenheit) {
    // Fahrenheit to Celsius: F - 32 / 9/5
    return (fahrenheit-32)/(9/5.0);
}

double celsiusToFahrenheit(double celsius) {
    // reverse the above formula: C * 9/5 + 32
    return (celsius*(9/5.0)) +32;
}

bool isValidMenuChoice(int choice) {
    // return true when choice is between EXIT_CHOICE and CELSIUS_TO_FAHRENHEIT.
    if (6 >= choice >=1){
        return true;
    }
    else{
        return false;
    }
}

bool requiresNonNegativeValue(int choice) {
    // Length and weight conversions cannot use negative values.
    // Temperature conversions may use negative values.
    // TODO: return true for choices 1 through 4.
    if (1 <= choice <= 4){
        return true;
    }
    return false; // return will break out of function, so the else is implicit and unneeded.
}

bool isValidValueForChoice(int choice, double value) {
    // 1. Invalid menu choices should return false.
    // 2. Length and weight conversions should reject negative values.
    // 3. Temperature conversions should allow negative values.

    // first check if the choice is valid with isValueMenuChoice.
    // then call check negative. If check negative is false, throw false if value < 0  
    bool valid = isValidMenuChoice(choice); 
    if (!requiresNonNegativeValue(choice)){ //if it's negative and not allowed, returnfalse now.
        if (value < 0){
            return false;
        }
    }
    if (valid){
        return true; //we've already filtered out invalid measurements, so just check if it's a valid choice.
    }
    else{
        return false; //catch edge cases
    }
}

void printMenu() {
    cout << endl;
    cout << "Unit Converter" << endl;
    cout << endl;
    cout << "1. Inches to centimeters" << endl;
    cout << "2. Centimeters to inches" << endl;
    cout << "3. Pounds to kilograms" << endl;
    cout << "4. Kilograms to pounds" << endl;
    cout << "5. Fahrenheit to Celsius" << endl;
    cout << "6. Celsius to Fahrenheit" << endl;
    cout << "0. Exit" << endl;
    cout << endl;
    cout << "Enter choice: ";
}
