
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




// ------------- DESIGN -------------
/* 
Program Name: Phrases and Subphrases program

Program Description: This program asks the user to enter two phrases, checks
and compares them and displays the message showing the results: whether the 
phrases are same or not, or if one contains other. 

Design:
A. INPUT
s1 as string
s2 as string

B. OUTPUT
 message "both phrases match"
 message "s1 is found in s2"
 message "s2 is found in s1"
 message "no match"
 message "Thank you for using my program!"

C. CALCULATIONS
There are no computations needed for this program but it uses
string comparisons and conditions to check matches between the phrases.

if s1 == s2 -> match;
s2.find(s1) -> check if s1 is inside s2;
s1.find(s2) -> check if s2 is inside s1;
substr() function returns the part of the phrase from where the match was found
if none are mathing -> no match;


D. LOGIC and ALGORITHMS

WELCOME
DECLARE strings s1, s2
PROMPT the user to enter first string
READ the string s1
DISPLAY string s1
PROMPT the user to enter secondfirst string
READ the string s2
DISPLAY string s2
IF s1 is equal to s2 
DISPLAY “match”
ELSE IF s1 was found in s2 THEN 
DISPLAY “found”
ELSE IF s2 was found  in s1 THEN
DISPLAY “found”
ELSE 
DISPLAY “no match”
GOODBYE


*/
