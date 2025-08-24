#include <iostream>
#include <iomanip> 
#include <limits>
using namespace std;


void welcome();
void instructions();
void readInt (const string& prompt, int &a); 
void readScore(const string& prompt, double &num);
double assignAverage(int numAssigns);
void getInput(double &midtermScore, double &finalExamScore);  
double calcFinalScore(double assignAvg, double midterm, double finalExam);
void calcLetterGrade(double finalScore, char &letter);
void bye();

void welcome() {
    cout << "Welcome to my Final Grade Calculator!" << endl;
}

void instructions() {
    cout << "Please enter the following information and I will calculate your Final Numerical Grade and Letter Grade for you!" << endl;
    cout << "The number of assignments must be between 0 and 10." << endl;
    cout << "All scores entered must be between 0 and 4." << endl;
}
// Reads and returns an int with validation
void readInt(const string& prompt, int &a) {
    while (true) {
        if (!prompt.empty()) cout << prompt;
        cin >> a;
        if (cin) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        // if wrong input
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter an integer.\n";
    }
}

// Reads a score into num with validation
void readScore(const string& prompt, double &num) {
    while (true) {
        if (!prompt.empty()) cout << prompt;
        double x;
        cin >> x;
        if (cin && x >= 0.0 && x <= 4.0) {
            num = x;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid score. Enter a number from 0.0 to 4.0.\n";
    }
}
// Reads assignment scores and returns their average
double assignAverage(int numAssigns) {
    if (numAssigns == 0) return 0.0;
    double sum = 0.0;
    for (int i = 1; i <= numAssigns; ++i) {
        double s = 0.0;
        readScore("Enter score " + to_string(i) + ": ", s);
        sum += s;
    }
    return sum / numAssigns;
}

// Reads midterm and final exam scores
void getInput(double &midtermScore, double &finalExamScore) {
    readScore("Enter your midterm exam score: ", midtermScore);
    readScore("Enter your final exam score: ", finalExamScore);
}

// Calculates final score using weights: assignments 60%, midterm 20%, final 20%
double calcFinalScore(double assignAvg, double midterm, double finalExam) {
    const double ASSIGN_W = 0.60;
    const double MIDTERM_W = 0.20;
    const double FINAL_W = 0.20;
    return assignAvg * ASSIGN_W + midterm * MIDTERM_W + finalExam * FINAL_W;
}

// Sets letter grade
void calcLetterGrade(double finalScore, char &letter) {
    if (finalScore >= 3.7)      letter = 'A';
    else if (finalScore >= 3.3) letter = 'B';
    else if (finalScore >= 2.7) letter = 'C';
    else if (finalScore >= 2.0) letter = 'D';
    else                        letter = 'F';
}

void bye() {
    cout << "Thank you for using my Grade Calculator!" << endl;
}

int main(){

    cout << fixed << setprecision(1);

    welcome();
    instructions();

    // read number of assignments with range validation (0..10)
    int numAssigns = -1;
    do {
       readInt("Enter the number of assignments (0 to 10): ", numAssigns);
        if (numAssigns < 0 || numAssigns > 10) {
            cout << "Please enter a number from 0 to 10." << endl;
        }
    } while (numAssigns < 0 || numAssigns > 10);

    // read assignment scores and compute average
    double assignAvg = assignAverage(numAssigns);

    // read exam scores
    double midterm = 0.0, finalExam = 0.0;
    getInput(midterm, finalExam);

    // compute final numeric score
    double finalScore = calcFinalScore(assignAvg, midterm, finalExam);

    // compute and print letter grade
    char letter = 'F';
    calcLetterGrade(finalScore, letter);

    cout << "Your Final Numeric score is " << finalScore << endl;
    cout << "Your Final Grade is " << letter << endl;

    bye();

    return 0;
}
