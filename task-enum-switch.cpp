
#include <iostream>
#include <iomanip>
using namespace std;

void welcome();
void getInput();
void collectData();
int calcTotal();

enum Day { SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY };

void welcome() {
    cout << "Welcome to my Miles Tracker program." << endl;
}

void getInput(int &goal) {
    cout << "How many miles do you want to ride this week? ";
    cin >> goal;
}

static void collectData(Day d) {
    switch (d) {
        case SUNDAY:    cout << "How many miles did you ride on Sunday? "; break;
        case MONDAY:    cout << "How many miles did you ride on Monday? "; break;
        case TUESDAY:   cout << "How many miles did you ride on Tuesday? "; break;
        case WEDNESDAY: cout << "How many miles did you ride on Wednesday? "; break;
        case THURSDAY:  cout << "How many miles did you ride on Thursday? "; break;
        case FRIDAY:    cout << "How many miles did you ride on Friday? "; break;
        case SATURDAY:  cout << "How many miles did you ride on Saturday? "; break;
    }
}

int calcTotal() {
    int total = 0;
    for (int d = 0; d < 7;) {
        collectData(static_cast<Day>(d));
        int miles;
        cin >> miles;

        if (miles < 0) {
            cout << "Miles must be 0 or greater!" << endl;
            continue;
        }

        total += miles;
        ++d;
    }
    return total;
}

int main() {
    welcome();

    int goal = 0;
    getInput(goal);

    if (goal <= 0) {
        cout << "No miles were tracked this week." << endl;
        cout << "Keep riding!" << endl;
        return 0;
    }

    int totalMiles = calcTotal();

    cout << "You rode " << totalMiles << " miles this week." << endl;

    if (totalMiles == goal) {
        cout << "Good job! You met your goal!" << endl;
    } else if (totalMiles > goal) {
        cout << "Great job! You exceeded your goal by " << (totalMiles - goal) << " miles!" << endl;
    } else {
        cout << "Uh oh! You missed your goal by " << (goal - totalMiles) << " miles!" << endl;
    }
    cout << "Keep riding!" << endl;

    return 0;
}
