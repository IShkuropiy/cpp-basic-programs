
#include <iostream>
using namespace std;

void welcome();
void getInput(int &goal);
int  calcTotal();

void welcome() {
    cout << "Welcome to my Miles Tracker program." << endl;
}

void getInput(int &goal) {
    cout << "How many miles do you want to ride this week? ";
    cin >> goal;
}

int calcTotal() {
    int total = 0;

    for (int day = 0; day < 7;) {
        int miles;

        if (day == 0) cout << "How many miles did you ride on Sunday? ";
        else if (day == 1) cout << "How many miles did you ride on Monday? ";
        else if (day == 2) cout << "How many miles did you ride on Tuesday? ";
        else if (day == 3) cout << "How many miles did you ride on Wednesday? ";
        else if (day == 4) cout << "How many miles did you ride on Thursday? ";
        else if (day == 5) cout << "How many miles did you ride on Friday? ";
        else if (day == 6) cout << "How many miles did you ride on Saturday? ";

        cin >> miles;

        if (miles < 0) {
            cout << "Miles must be 0 or greater!" << endl;
            continue;  // warning message and ask again
        }

        total += miles;
        ++day; // if input is valid we are moving to the next day
    }
    return total;
}

int main() {
    welcome();

    int goal = 0;
    getInput(goal);

    if (goal <= 0) {
        cout << "No miles were tracked this week." << endl;
        return 0;
    }
    // calculate total
    int totalMiles = calcTotal();
    // results 
    cout << "You rode " << totalMiles << " miles this week." << endl;

    if (totalMiles == goal) {
        cout << "Good job! You met your goal!" << endl;
    } else if (totalMiles > goal) {
        cout << "Great job! You exceeded your goal by " << (totalMiles - goal) << " miles!" << endl;
    } else {
        cout << "Uh oh! You missed your goal by " << (goal - totalMiles) << " miles!" << endl;
    }

    return 0;
}


// ------------- DESIGN -------------
/* 
Program Name: Miles Tracker Program

Program Description: This program ask user for their daily miles (bike rides), 
tracks miles a user rides during this week, compares results with the goal they set 
and reports whether goal was met, misset or exceeded. 

C. CALCULATIONS
totalMiles = day1 + day2 + day3 + day4 + day5 + day6 + day7; 
day1 - day7 are not an actual variables, they just represent each loop cycle

if totalMiles == goal  -  met the goal
if totalMiles > goal - exceeded by 
if totalMiles < goal - missed by 

D. LOGIC and ALGORITHMS

WELCOME
FUNCTION getInput(goal)
    PROMPT the user to enter their goal
    READ goal

FUNCTION calcTotal RETURNS int
    FOR day = 0 TO 6
        PROMPT the user to enter miles per day
        READ miles
        IF miles < 0 THEN
            DISPLAY the warning message 
            REPEAT same day
        ELSE
            total = total + miles
        ENDIF
    ENDFOR
    RETURN total

MAIN
    CALL welcome
    CALL getInput(goal)
    IF goal <= 0 THEN
        DISPLAY "0 miles" message
        EXIT
    ENDIF

    totalMiles = CALL calcTotal()

   DISPLAY results
    IF totalMiles == goal THEN
        DISPLAY result
    ELSE IF totalMiles > goal THEN
       DISPLAY (another) result
    ELSE
        DISPLAY (another) result
    ENDIF

*/
