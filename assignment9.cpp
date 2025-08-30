
#include <iostream>
#include <iomanip>
using namespace std;

void getInput(int &num);
void doStats(int num);

void getInput(int &num) {
    cout << "How many positive integers do you want to process? ";
    cin >> num;
}

void doStats(int num) {
    int value;
    int minVal = 0, maxVal = 0;
    int minPos = 0, maxPos = 0;

    for (int i = 1; i <= num; i++) {
        cout << "Enter integer #" << i << ": ";
        cin >> value;

        while (value <= 0) {
            cout << "Enter a positive integer!" << endl;
            cout << "Enter integer #" << i << ": ";
            cin >> value;
        }

        if (i == 1) {
            minVal = maxVal = value;
            minPos = maxPos = 1;
        } else {
            if (value < minVal) {
                minVal = value;
                minPos = i;
            }
            if (value > maxVal) {
                maxVal = value;
                maxPos = i;
            }
        }
    }

    cout << "The minimum number entered was " << minVal
         << " entered in position " << minPos << "." << endl;
    cout << "The maximum number entered was " << maxVal
         << " entered in position " << maxPos << "." << endl;
}

int main() {
    int num = 0;

    cout << "Welcome to my Final Exam Practice." << endl;

    getInput(num);

    if (num <= 0) {
        cout << "No integers were entered." << endl;
    } else {
        doStats(num);
    }

    cout << "Thank you for using my program." << endl;
    return 0;
}