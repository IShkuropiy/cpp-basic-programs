
#include <iostream>
#include <string>
using namespace std;


int main() {
    // declare strings variables
    string s1 = "";
    string s2 = "";
    // welcome message
    cout << "Welcome to the Phrases and Subphrases program!" << endl;
    // prompt user to enter phrase 1, read the entire line and display it
    cout << "Enter Phrase 1: ";
    getline(cin, s1);
    cout << "You entered: " << s1 << endl;
    // prompt user to enter phrase 2, read the entire line and display it
    cout << "Enter Phrase 2: ";
    getline(cin, s2);
    cout << "You entered: " << s2 << endl;
    // check if the phrases are exactlythe same 
    if (s1 == s2) {
      cout << "\nBoth phrases match." << endl;
   }
   // check if phrase 1 found in phrase 2 and display it using .substr
   else if (s2.find(s1) != string::npos) {
      cout << "\n" << s1 << " is found in " << s2 << endl;
      cout << s2.substr(s2.find(s1)) << endl;
   }
   // check if phrase 2 found in phrase 1 and display it using .substr
   else if (s1.find(s2) != string::npos) {
      cout << "\n" << s2 << " is found in " << s1 << endl;
      cout << s1.substr(s1.find(s2)) << endl;
   }
   // in case there are no match it returns "not found"
   else {
      cout << "\nNo match." << endl;
   }
   // goodbye message 
    cout << "Thank you for using my program!" << endl;

    return 0;
}