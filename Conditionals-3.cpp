
#include <iostream>
#include <iomanip>
//#include <cctype>
using namespace std;

int main() {
    // constants declared
    const double VEHICLE_FARE = 64.35;
    const double ADULT = 16.50;
    const double SENIOR = 7.40;
    const double YOUTH = 5.55;
    const double BIKE_CHARGE = 4.00;
    const int MAX_PASSENGERS = 20;
    const double FREE_TICKET = 100.00;
    // variables declared
    char hasVehicle;
    int numAdults, numSeniors, numYouths;
    // welcome message with a blank line \n
    cout << "Welcome to the Washington State Ferries Fare Calculator!\n" << endl;
    // deisplaing Ferries Fare Information menu and aligning it like a table with 55 characters wide
    cout << left << setw(55) << "Fare Description" << "Ticket $" << endl;
    cout << "--------------------------------------                     --------" << endl;
    cout << left << setw(55) << "Vehicle Under 14' (less than 168\") & Driver" << "$64.35" << endl;
    cout << left << setw(55) << "Adult (age 19 - 64)" << "$16.50" << endl;
    cout << left << setw(55) << "Senior (age 65 & over) / Disability" << "$7.40" << endl;
    cout << left << setw(55) << "Youth (age 6 - 18)" << "$5.55" << endl;
    cout << left << setw(55) << "Bicycle Surcharge (included with Vehicle)" << "$4.00\n" << endl;
    // prompt the user to input y/n usind tolower() so both uppercase and lowercase are accepted
    cout << "Are you riding a vehicle on the Ferry (Y/N): ";
    cin >> hasVehicle;
    hasVehicle = tolower(hasVehicle);
    // displaying an error message and ending the program if the user types anithing othen than y/n
    if (hasVehicle != 'y' && hasVehicle != 'n') {
        cout << "\nError!! Invalid answer!! Please try again later!!!" << endl;
        return 1;
    }
    // prompt the user to enter the info
    cout << "\nHow many adults? ";
    cin >> numAdults;
    cout << "How many seniors? ";
    cin >> numSeniors;
    cout << "How many youths? ";
    cin >> numYouths;
    // displaying error message and end the program if the user types negative or more than 20 
    if (numAdults < 0 || numSeniors < 0 || numYouths < 0 || 
        numAdults > MAX_PASSENGERS || numSeniors > MAX_PASSENGERS || numYouths > MAX_PASSENGERS) {
        cout << "\nError: Invalid passenger count." << endl;
        return 1;
    }
    // declaring and initializing totalCharge
    double totalCharge = 0.0;
    // calculating fare based of number of each type of passengeer
    if (hasVehicle == 'y') {
        totalCharge += VEHICLE_FARE;
    }

    totalCharge += numAdults * ADULT;
    totalCharge += numSeniors * SENIOR;
    totalCharge += numYouths * YOUTH;
    // display total 
    cout << fixed << setprecision(2);
    cout << "\nYour total charge is $" << totalCharge << endl;
    // free tickets
    if (totalCharge > FREE_TICKET) {
        cout << "\nYou are eligible for a free adult ticket for the next trip." << endl;
    } else {
        double diff = FREE_TICKET - totalCharge;
        cout << "\nIf you spend $" << diff << " more, you are eligible for a free adult ticket for the next trip." << endl;
    }
    // goodbye message 
    cout << "\nThank you for using Washington State Ferries Fare Calculator!" << endl;

    return 0;
}
