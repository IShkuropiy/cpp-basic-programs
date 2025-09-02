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