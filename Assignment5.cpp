
#include <iostream>
#include <iomanip>
#include <cmath> 
#include <cctype>
using namespace std;

int main() {
  // set constants
  const float TAX = 0.07;
  const float DELIVERY = 0.20;
  const int SLICES_PER_PIZZA = 8;
  // set variables 
  int totalEntries = 0;
  int totalPizzas = 0;
  int maxPeople = 0;
  float maxTotalCost = 0.0;

  char again = 'Y';

  cout << "Welcome to my Pizza Party Statistics program!\n"
       << endl;
  // loop that process party entries 
  while (toupper(again) == 'Y') {
    int people;
    float slicesPerPerson, costPerPizza;
    // prompt the user to enter an info
    cout << "Enter the number of people, average number of slices per person, and the cost of a pizza separated by a space: ";
    cin >> people >> slicesPerPerson >> costPerPizza;
    // calculations
    float totalSlices = people * slicesPerPerson;
    int pizzasNeeded = static_cast<int>(ceil(totalSlices / SLICES_PER_PIZZA));
    float cost = pizzasNeeded * costPerPizza;
    float tax = cost * TAX;
    float costWithTax = cost + tax;
    float delivery = costWithTax * DELIVERY;
    float totalCost = costWithTax + delivery;

    // Update totals
    totalEntries++;
    totalPizzas += pizzasNeeded;
    // update maxPeople and maxTotalCost
    if (people > maxPeople)
    {
      maxPeople = people;
    }

    if (totalCost > maxTotalCost)
    {
      maxTotalCost = totalCost;
    }

    // Display results
    cout << fixed << setprecision(2);
    cout << "\n"
         << left << setw(18) << "Number of pizzas:" << pizzasNeeded << endl;
    cout << left << setw(18) << "Cost of pizzas:" << "$" << setw(7) << right << cost << endl;
    cout << left << setw(18) << "Tax:" << "$" << setw(7) << right << tax << endl;
    cout << left << setw(18) << "Delivery:" << "$" << setw(7) << right << delivery << endl;
    cout << left << setw(18) << "Total Cost:" << "$" << setw(7) << right << totalCost << endl;
  // ask the user if they want to continue 
    cout << "\nDo you want to enter more (y/n): ";
    cin >> again;
    again = toupper(again);
    cout << endl;
  }

//summary
  cout << "\nSummary of all entries:\n";
  cout << "Total entries: " << totalEntries << endl;
// average number of pizzas per party 
  if (totalEntries > 0) {
    double avgPizzas = static_cast<double>(totalPizzas) / totalEntries;
    cout << fixed << setprecision(1);
    cout << "Average number of pizzas: " << avgPizzas << endl;
    cout << "Maximum people at a party: " << maxPeople << endl;
    cout << fixed << setprecision(2);
    cout << "Maximum total cost: $" << maxTotalCost << endl;
  }

  cout << "\nThank you for using the Pizza Party Statistics program. Goodbye!" << endl;

  return 0;
}


// ------------- DESIGN -------------
/* 
Program Name: Pizza Party Statistics

Program Description: This program helps calculate and summarise pizza party:
how many pizzas are needed, the total cost, including tax and delivery, and 
keeps track of statistics like how many parties were entered, the average 
number of pizzas per party, the largest number of people at a party. 

Design:
A. INPUT
people as int 
slisesPerPerson as float 
costPerPizzass float 
again as char

B. OUTPUT
pizzaNeeded as int 
cost as float 
tax as float
delivery as float 
totaCost as float 
avrPizzas as float 
maxPeople as int 
maxTotalCost as float 

C. CALCULATIONS
totalSlices = people * slicesPerPerson
pizzasNeeded = ceil(totalSlices / SLICES_PER_PIZZA)
coat = pizzasNeeded * costPerPizza
tax = cost * tax
costWithTax = cost + tax
delivery = costWithTax * DELIVERY
totalCost = costWithTax + delivery
avgPizzas = totalPizzas / totalEntries

D. LOGIC and ALGORITHMS

WELCOME
SET const TAX = 0.07
SET constDELIVERY = 0.20
SET constSLICES_PER_PIZZA = 8

SET totalEntries
SET totalPizzas = 0
SET maxPeople = 0
SET maxTotalCost = 0
SET again = 'Y'

WHILE again is 'Y' 
  PROMPT user for number of people
  PROMPT user for  average slices per person
  PROMPT user for cost of one pizza

  CALCULATE totalSlices = people * slicesPerPerson
  CALCULATE pizzasNeeded = ceil(totalSlices / slices per pizza)
  CALCULATE cost = pizzasNeeded * costPerPizza
  CALCULATE tax = cost * TAX
  CALCULATE costWithTax = cost + tax
  CALCULATE delivery = costWithTax * DELIVERY
  CALCULATE totalCost = costWithTax + delivery


    totalEntries += 1
    totalPizzas += pizzasNeeded

    IF people > maxPeople:
      SET maxPeople = people

    IF totalCost > maxTotalCost:
      SET maxTotalCost = totalCost

  DISPLAY pizzas needed
  DISPLAY cost
  DISPLAY tax
  DISPLAY delivery
  DISPLAY total cost

  PROMPT the user if they want to continue (y/n)
  READ again

  IF totalEntries > 0:
  CALCULATE avgPizzas = totalPizzas / totalEntries
  DISPLAY average pizzas
  DISPLAY total entries
  DISPLAY max people
  DISPLAY max total cost

GOODBYE 

SAMPLE RUNS

Welcome to my Pizza Party Statistics program!

Enter the number of people, average number of slices per person, and the cost of a pizza separated by a space: 10  2.6  10.50

Number of pizzas: 4
Cost of pizzas:  $42.00
Tax:             $2.94
Delivery:        $8.99
Total Cost:      $53.93

Do you want to enter more (y/n): y

Enter the number of people, average number of slices per person, and the cost of a pizza separated by a space: 9   2.5   10.95

Number of pizzas: 3
Cost of pizzas:  $32.85
Tax:             $2.30
Delivery:        $7.03
Total Cost:      $42.18

Do you want to enter more (y/n): y

Enter the number of people, average number of slices per person, and the cost of a pizza separated by a space: 14   3.2   14.95

Number of pizzas: 6
Cost of pizzas:  $89.70
Tax:             $6.28
Delivery:        $19.20
Total Cost:      $115.17

Do you want to enter more (y/n): n

Number of entries: 3
Total number of pizzas: 13
Average number of pizzas: 4.3
Maximum number of people: 14
Maximum cost of pizzas: $115.17

Thank you for using my program!

*/
