// A Portland Paints has determined that for every 110 square feet of wall space, one gallon of paint and eight hours of labor will be required. The company charges $35.00 per hour for labor. Write a modular program that allows the user to enter the length, width, and height of a room (in feet) and the price of the paint per gallon.

// Calculate the square foot area of the four walls, do not add the floor or ceiling.
// It should then display the following data:

// The number of gallons of paint required (integer, round up to the next gallon)
// The cost of the paint (double)
// The number of labor hours (integer, round up all fractions of an hours to whole hour)
// The labor charges (double)
// The total cost to paint the room (double)
// Input validation: Do not accept values less than 5 for the length, width, and height dimensions. Do not accept a value less than $10.00 for the price of paint.

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
// const 
const double PAY_PER_HOUR = 35.00;
const double COVERAGE_SQFT_PER_GAL = 110.0;  // 1 gallon per 110 sq ft
const double HOURS_PER_110_SQFT = 8.0;       // 8 hours per 110 sq ft
// input  int length, int width, int height, double paintPrice
// output double pricePerGallon, double paintCost, int laborHours, double laborCharges, double totalCost

void readInputs(int &length, int &width, int &height, double &pricePerGallon);
double calcWallArea(int length, int width, int height);
int gallonsRequired(double area);
double calcPaintCost(int gallons, double pricePerGallon);
int calcLaborHours(double area);
double calcLaborCharges(int hours);
double calcTotal(double paintCost, double laborCost);


void readInput(int &length, int &width, int &height, double &pricePerGallon) {

    while (true) {
        cout << "Enter room length in feet (>= 5): ";
        cin >> length;
        cout << "Enter room width in feet (>= 5): ";
        cin >> width;
        cout << "Enter room height in feet (>= 5): ";
        cin >> height;
        cout << "Enter paint price per gallon (>= 10.00): ";
        cin >> pricePerGallon;

        bool dimensions = (length >= 5) && (width >= 5) && (height >= 5);
        bool price = (pricePerGallon >= 10.00);

        if (!dimensions) {
            cout << "ERROR: Length, width, and height must each be at least 5 feet.\n\n";
            continue;
        }
        if (!price) {
            cout << "ERROR: Paint price must be $10.00 or greater.\n\n";
            continue;
        }
        break;
    }
}
// Calculate the square foot area of the four walls, do not add the floor or ceiling.
// perimeter * height = 2 * (L + W) * H
double calcWallArea(int length, int width, int height) {
    return 2.0 * (static_cast<double>(length) + static_cast<double>(width)) * static_cast<double>(height);
}
//110 square feet of wall space, one gallon, 8 hours
int gallonsRequired(double area) {
    return static_cast<int>(ceil(area / COVERAGE_SQFT_PER_GAL));
}
double calcPaintCost(int gallons, double pricePerGallon) {
    return static_cast<double>(gallons) * pricePerGallon;
}

int calcLaborHours(double area) {
    double hoursExact = (area / COVERAGE_SQFT_PER_GAL) * HOURS_PER_110_SQFT;
    return static_cast<int>(ceil(hoursExact));
}

double calcLaborCharges(int hours) {
    return static_cast<double>(hours) * PAY_PER_HOUR;
}

double calcTotal(double paintCost, double laborCost) {
    return paintCost + laborCost;
}

int main() {
    int length = 0, width = 0, height = 0;
    double pricePerGallon = 0.0;

    readInputs(length, width, height, pricePerGallon);

    double area = calcWallArea(length, width, height);
    int gallons = gallonsRequired(area);
    double paintCost = calcPaintCost(gallons, pricePerGallon);
    int hours = calcLaborHours(area);
    double laborCost = calcLaborCharges(hours);
    double total = calcTotal(paintCost, laborCost);

    cout << fixed << setprecision(2);
    cout << "Gallons of paint:  " << gallons << '\n';
    cout << "Paint cost:       $" << paintCost << '\n';
    cout << "Hours of labor:    " << hours << '\n';
    cout << "Labor cost:       $" << laborCost << '\n';
    cout << "Total charges:    $" << total << '\n';

    return 0;
}