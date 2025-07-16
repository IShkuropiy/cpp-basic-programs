/******************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

//constants for cookies per serving and calories per serving
 const int COOKIES_PER_SERV = 5;
 const int CALORIES = 160;

int main() {

    //variables declared
    int cookiesEaten = 0;
    double totalCalories = 0;
    double servings = 0;

    //welcome message 
    cout << "Welcome to the Oreo Calculator!" << endl;

    //user input
    cout << "\nEnter the number of Oreos eaten: ";
    cin >> cookiesEaten;
    
    // Calculations
    // converting the int into double and then calculating total calories 
    servings = static_cast<double>(cookiesEaten) / COOKIES_PER_SERV;
    totalCalories = servings * CALORIES;
    
    // Set output format 
    cout << fixed << setprecision(1);

    //blank line before displaing the results
    cout << "\n"; 
    
    // //output to the user
    cout << cookiesEaten << " Oreos equals " << servings << " servings!" << endl;
    cout << "You consumed " << totalCalories << " calories. " << endl;
    cout << "\nKeep eating Oreos! " <<endl;

}

/*
DEFINE const int COOKIES_PER_SERV 
DEFINE const int CALORIES 
DECLARE int cookiesEaten 
DECLARE double totalCalories 
DECLARE double servings
DISPLAY the welcome message
PROMPT the user to enter oreos they eated
CALCULATE servings = 
CALCULATE total calories = servings * CALORIES
DISPLAY output 

*/