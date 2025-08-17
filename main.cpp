
#include <iostream>
#include <iomanip> 
#include <cmath>
using namespace std;

// constants 
const double ASSIGN_PERCENT = 0.6; // 60% 
const double MIDTERM_PERCENT = 0.2; // 20%
const double FINAL_PERCENT = 0.2; // 20%

void welcome();
void bye();
int readInt(string prompt);
double readScore(string prompt);
double assignAverage(int numAssigns);
double calcFinalScore(double assignAvg, double midterm, double finalExam);
char calcLetterGrade(double finalScore);

void welcome() {
    cout << "Welcome to my Final Grade Calculator!" << endl;
    cout << "Please enter the following information and I will calculate your Final Numerical Grade and Letter Grade for you!" << endl;
    cout << "The number of assignments must be between 0 and 10." << endl;
    cout << "All scores entered must be between 0 and 4." << endl;
}

int readInt(string prompt) {
    int value;
    cout << prompt;
    cin >> value;

    while (cin.fail() || value < 0 || value > 10) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Illegal Value! Please try again!!" << endl;
        cout << prompt;
        cin >> value;
    }
    return value;
}

double readScore(string prompt) {
    double score;
    cout << prompt;
    cin >> score;

    while (cin.fail() || score < 0 || score > 4) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Illegal Score! Please try again!" << endl;
        cout << prompt;
        cin >> score;
    }
    return score;
}

double assignAverage(int numAssigns) {
    double sum = 0.0;

    for (int i = 1; i <= numAssigns; i++) {
        double s = readScore("Enter score " + to_string(i) + ": ");
        sum += s;
    }
    if (numAssigns == 0) return 0.0;
    return sum / numAssigns;
}
    
double calcFinalScore(double assignAvg, double midterm, double finalExam) {
    return assignAvg * ASSIGN_PERCENT + midterm * MIDTERM_PERCENT + finalExam * FINAL_PERCENT;
}

char calcLetterGrade(double finalScore) {
    if (finalScore >= 3.5) return 'A';
    else if (finalScore >= 2.5) return 'B';
    else if (finalScore >= 1.5) return 'C';
    else if (finalScore >= 1.0) return 'D';
    else return 'F';
}

void bye() {
    cout << "Thank you for using my Grade Calculator!" << endl;
}

int main() {

    welcome();
     int numAssigns = readInt("Enter the number of assignments (0 to 10): ");

    // average assignment score
    double assignAvg = assignAverage(numAssigns);

    // midterm & final exam
    double midterm = readScore("Enter your midterm exam score: ");
    double finalExam = readScore("Enter your final exam score: ");

    // calculate final numeric score
    double finalScore = calcFinalScore(assignAvg, midterm, finalExam);

    // calculate letter grade
    char grade = calcLetterGrade(finalScore);

    cout << fixed << setprecision(1) << endl;
    cout << "Your Final Numeric score is " << finalScore << endl;
    cout << "Your Final Grade is " << grade << endl;
    bye();
    return 0;
}



// ------------- DESIGN -------------
/* 
Program Name: Grade Calculator

Program Description: This program calculates student’s final grade based on assignment scores, 
// midterm exam, and a final exam. The assignments count for 60% of the grade, and the midterm and final exam 20% each.
// Then the program outputs both the final numeric score and the letter grade.

Design:
A. INPUT
numAssigns as int
score as double
midterm as double
finalExam as double

B. OUTPUT
finalScore as double
assignAvg as double

C. CALCULATIONS
finalScore = assignAvg * ASSIGN_PERCENT + midterm * MIDTERM_PERCENT + finalExam * FINAL_PERCENT;
assignAvg = sum / numAssigns;

D. LOGIC and ALGORITHMS
    WELCOME
    READ 
    SET sum = 0
    FOR each assignment
        READ score
        ADD score to sum
    END FOR
    CALCULATE assignAvg = sum / numAssigns
    IF numAssigns = 0 THEN assignAvg = 0
    READ midterm
    READ finalExam
    CALCULATE finalScore = (assignAvg * 0.6) + (midterm * 0.2) + (finalExam * 0.2)
    DETERMINE letter grade:
        IF score >= 3.5 THEN grade = 'A'
        ELSE IF score >= 2.5 THEN grade = 'B'
        ELSE IF score >= 1.5 THEN grade = 'C'
        ELSE IF score >= 1.0 THEN grade = 'D'
        ELSE grade = 'F'

    DISPLAY finalScore 
    DISPLAY letter grade
    GOODBYE

SAMPLE RUNS

Welcome to my Final Grade Calculator!
Please enter the following information and I will calculate your Final Numerical Grade and Letter Grade for you!
The number of assignments must be between 0 and 10.
All scores entered must be between 0 and 4.
Enter the number of assignments (0 to 10): 6
Enter score 1: 3.4 
Enter score 2: 4 
Enter score 3: 2.5 
Enter score 4: 3.3
Enter score 5: 3.1
Enter score 6: 2.5
Enter your midterm exam score: 3.5
Enter your final exam score: 4
Your Final Numeric score is 3.4
Your Final Grade is A
Thank you for using my Grade Calculator!


Welcome to my Final Grade Calculator!
Please enter the following information and I will calculate your Final Numerical Grade and Letter Grade for you!
The number of assignments must be between 0 and 10.
All scores entered must be between 0 and 4.
Enter the number of assignments (0 to 10): 3
Enter score 1: 3 
Enter score 2: 4 
Enter score 3: 2.5 
Enter your midterm exam score: 2.5
Enter your final exam score: 2
Your Final Numeric score is 2.8
Your Final Grade is B
Thank you for using my Grade Calculator!


Welcome to my Final Grade Calculator!
Please enter the following information and I will calculate your Final Numerical Grade and Letter Grade for you!
The number of assignments must be between 0 and 10.
All scores entered must be between 0 and 4.
Enter the number of assignments (0 to 10): 12
Illegal Value! Please try again!!
Enter the number of assignments (0 to 10): 5
Enter score 1: 3.4 
Enter score 2: 4 
Enter score 3: 2.5 
Enter score 4: 5.5
Illegal Score! Please try again!
Enter score 4: 3.5
Enter score 5: 3.1
Enter your midterm exam score: 3.5
Enter your final exam score: 4
Your Final Numeric score is 3.5
Your Final Grade is A
Thank you for using my Grade Calculator!


*/
