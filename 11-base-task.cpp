#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    //variables declared for compute todays dose of Griseofulvin
    int pigWeight = 0;
    int totalDays = 0; //total Griseofulvin course diration
    float dailyDose = 0;
    float griseofulvinTotal = 1.5; //total dose in mg for 1000g pig over 
    //the full course

    //user input
  cout << "Welcome to the Vet Pharmacy Conversions!" << endl;
  cout << "Enter guinea pig weight in grams: ";
  cin >> pigWeight;

  cout << "Enter the number of days for this medication: ";
  cin >> totalDays;

  //calculations
  dailyDose = (griseofulvinTotal / totalDays) * (pigWeight / 1000.0);
  //output to the user
  cout << "Daily dose of Griseofulvin for your guinea pig is: " << dailyDose << "mg" << endl;
  cout << "This tool is for general estimations only." << endl;
  cout << "Consult a veterinarian before administering any medication." << endl;
  //end program
  return 0;
}
