#include "converter.hpp"
#include <iostream>

using namespace std;

// tqassar: this file holds conversion functions for main.cpp. Constants are held in converter.hpp
double inchesToCentimeters(double inches) { // takes only positive values
    return inches * CENTIMETERS_PER_INCH; 
}

double centimetersToInches(double centimeters) { //takes only positive values
    return centimeters / CENTIMETERS_PER_INCH;
}

double poundsToKilograms(double pounds) { // takes only positive
    return pounds / POUNDS_PER_KILOGRAM;
}

double kilogramsToPounds(double kilograms) { // takes only positive values
    return kilograms * POUNDS_PER_KILOGRAM;
}

double fahrenheitToCelsius(double fahrenheit) { // either pos or negative
    return (fahrenheit - 32) * 5.0/9.0; // tqassar: only one of these needs to be a double since fahrenheit is a double
}

double celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0/5.0) + 32; // same here; 32.0 is unnecessary because it's already a double and divison is finished.
}

bool isValidMenuChoice(int choice) {
    return (choice >= EXIT_CHOICE && choice <= CELSIUS_TO_FAHRENHEIT); // tqassar: notate that these choice constants equate to numbers.

}

bool requiresNonNegativeValue(int choice) {
    return (choice >= 1 && choice <= 4);
}

bool isValidValueForChoice(int choice, double value) { // tqassar: very concise, good job here! 
    if (!isValidMenuChoice(choice))
        return false;

    if(requiresNonNegativeValue(choice) && value < 0.0)
        return false;

    return true;
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
