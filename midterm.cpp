
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main () {

const int NUM_PLAYERS = 3;
int rocksCount1, rocksCount2, rocksCount3;
string player1, player2, player3;
string firstPlace, secondPlace, thirdPlace;

cout << "Welcome to the Rock Collector Championship!" << endl;
cout << endl;

cout << "Enter player 1 name: ";
getline(cin, player1);
cout << "How many rocks did " << player1 << " collect? ";
cin >> rocksCount1;
cin .ignore(numeric_limits<streamsize>::max(), '\n');
if (rocksCount1 <= 0) {
    cout << "Invalid amount. 0 will be entered." << endl;
    rocksCount1 = 0;
}

cout << endl;

cout << "Enter player 2 name: ";
getline(cin,player2);
cout << "How many rocks did " << player2 << " collect? ";
cin >> rocksCount2;
cin .ignore(numeric_limits<streamsize>::max(), '\n');
if (rocksCount2 <= 0) {
    cout << "Invalid amount. 0 will be entered." << endl;
    rocksCount2 = 0;
}

cout << endl;

cout << "Enter player 3 name: ";
getline(cin,player3);
cout << "How many rocks did " << player3 << " collect? ";
cin >> rocksCount3;
cin .ignore(numeric_limits<streamsize>::max(), '\n');
if (rocksCount3 <= 0) {
    cout << "Invalid amount. 0 will be entered." << endl;
    rocksCount3 = 0;
}

cout << endl;

//cout << "NAME" << '\t'<< "COUNT" << endl;
//cout << player1 << '\t' << rocksCount1 << endl;
//cout << player2 << '\t' << rocksCount2 << endl;
//cout << player3 << '\t' << rocksCount3 << endl;

// calculations

 if (rocksCount1 == rocksCount2 && rocksCount2 == rocksCount3) {
      cout << player1 << ", " << player2 << ", and " << player3 << " are tied for first place!" << endl;
   }
   else if (rocksCount1 == rocksCount2 && rocksCount1 > rocksCount3) {
      cout << player1 << " and " << player2 << " are tied for first place." << endl;
      cout << player3 << " is in second place!" << endl;
   }
   else if (rocksCount1 == rocksCount3 && rocksCount1 > rocksCount2) {
      cout << player1 << " and " << player3 << " are tied for first place." << endl;
      cout << player2 << " is in second place!" << endl;
   }
   else if (rocksCount2 == rocksCount3 && rocksCount2 > rocksCount1) {
      cout << player2 << " and " << player3 << " are tied for first place." << endl;
      cout << player1 << " is in second place!" << endl;
   }
   else {

        if (rocksCount1 >= rocksCount2 && rocksCount1 >= rocksCount3) {
         firstPlace = player1;
         if (rocksCount2 >= rocksCount3) {
            secondPlace = player2;
            thirdPlace = player3;
         } else {
            secondPlace = player3;
            thirdPlace = player2;
         }
      }
      else if (rocksCount2 >= rocksCount1 && rocksCount2 >= rocksCount3) {
         firstPlace = player2;
         if (rocksCount1 >= rocksCount3) {
            secondPlace = player1;
            thirdPlace = player3;
         } else {
            secondPlace = player3;
            thirdPlace = player1;
         }
      }
      else {
         firstPlace = player3;
         if (rocksCount3 >= rocksCount2) {
            secondPlace = player1;
            thirdPlace = player2;
         } else {
            secondPlace = player2;
            thirdPlace = player1;
         }
      }
      
      // display results

      cout << firstPlace << " is in first place!" << endl;
      cout << secondPlace << " is in second place." << endl;
      cout << thirdPlace << " is in third place." << endl;
   }

   cout << endl;

   double average = static_cast<double>(rocksCount1 + rocksCount2 + rocksCount3) / NUM_PLAYERS;
   cout << endl;
   cout << fixed << setprecision(2);
   cout << "The average number of rocks collected by the top three players is " << average << " rocks!" << endl;
   
   cout << endl;

   cout << "Congratulations Rock Collectors!" << endl;

    return 0;
}


// ------------- DESIGN -------------
/* 
Program Name: Rock Collector

Program Description: This program replicate a competetion where three players collect rocks. 
The user is prompted to enter names of the players and number of rocks they collected.
Then the program validates rock counts, ranks the players and displays the winners in order.
At the end the program calculates and displays the average number of rocks collected.

Design:
A. INPUT
player1 as string
player2 as string
player3 as string
rockCounts1 as int 
rockCounts2 as int 
rockCounts3 as int 

B. OUTPUT
average as double 
firstPlace as string 
secondPlace as string
thirdPlace as string

C. CALCULATIONS

Ties and placing: 
Three players tie if all three rock counts are equal;
Two players tie for first, and the third is second if two players have equal and highest rock counts;
If there are no ties we'll use if/else logic to determine who has the highest count and assign him to firstPlace;
Compare the other two to assign secondPlace and thirdPlace.

average = (rocksCount1 + rocksCount2 + rocksCount3) / 3.0;

D. LOGIC and ALGORITHMS
 
SET NUM_PLAYERS to 3

DECLARE string player1, player2, player3
DECLARE int rocksCount1, rocksCount2, rocksCount3
DECLARE string firstPlace, secondPlace, thirdPlace

WELCOME MESSAGE

FOR each of the 3 players:
    PROMPT for player name
    PROMPT for number of rocks collected
        IF rocks collected <= 0:
           DISPLAY warning message
            SET rocks count to 0

    IF all three rock counts are equal:
        DISPLAY tie message
    ELSE IF two players have equal and highest rock count:
        DISPLAY tie message
        DISPLAY third player in second
    ELSE:
        Determine highest rock count:
            SET firstPlace to player with highest rocks
            COMPARE remaining two for second and third place
            SET secondPlace and thirdPlace accordingly
        DISPLAY first, second and third places

    COMPUTE average = (rocksCount1 + rocksCount2 + rocksCount3) / 3.0
    DISPLAY average
    DISPLAY goodbye message

SAMPLE RUNS
Welcome to the Rock Collector Championships!

Enter player 1 name: Gordan Freeman
How many rocks did Gordan Freeman collect? -9
Invalid amount. 0 will be entered.

Enter player 2 name: Link
How many rocks did Link collect? 45

Enter player 3 name: D. Va
How many rocks did D. Va collect? 45

Link and D. Va are tied for first place.
Gordan Freeman is in second place!

The average number of rocks collected by the top three players is 30.00 rocks!

Congratulations Rock Collectors!




Welcome to the Rock Collector Championships!

Enter player 1 name: Mario
How many rocks did Mario collect? 56

Enter player 2 name: Master Chief
How many rocks did Master Chief collect? 56

Enter player 3 name: Sonic
How many rocks did Sonic collect? 56

It is a three way tie!

The average number of rocks collected by the top three players is 56.00 rocks!

Congratulations Rock Collectors!




Welcome to the Rock Collector Championships!

Enter player 1 name: King Dedede
How many rocks did King Dedede collect? 57
Enter player 2 name: Samus
How many rocks did Samus collect? 102

Enter player 3 name: Kirby
How many rocks did Kirby collect? 62

Samus is in first place!
Kirby is in second place.
King Dedede is in third place.

The average number of rocks collected by the top three players is 73.67 rocks!

Congratulations Rock Collectors!



*/
