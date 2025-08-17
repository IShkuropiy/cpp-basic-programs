// ------------- FILE HEADER -------------
// Author: Yryna Shkuropii
// Assignment: 6
// Date: 08/10/2025
// Description: This program is coffee and tea vending machine simulator that accepts coins of 5, 10, or 25 cents, tracks the user’s balance, and allows selecting a drink for $0.25 each. The program processes purchases if there are enough coins or prompts for additional until the transaction is complete or canceled.
// Sources: Assignment 6 specifications


// ------------- ZYBOOKS SCORES -------------
// https://learn.zybooks.com/zybook/PCCCS161ASummer25
// Chapter: Loops 2
// Participation: 100%
// Challenge: 69%
// Labs: 100%


// ------------- DISCORD POSTS -------------
// https://discord.com/invite/URYKKf8YHm
// Count: 0


// ------------- DESIGN DOCUMENT -------------
// A. INPUT [yes/no]: yes
// B. OUTPUT [yes/no]: yes 
// C. CALCULATIONS [yes/no]: yes
// D. LOGIC and ALGORITHMS [yes/no]: yes



// ------------- TESTING -------------
// PASS ALL GIVEN SAMPLE RUN TESTS [yes/no]: yes


// ------------- CODE -------------
#include <iostream>     
#include <iomanip>     
#include <limits> 
#include <cctype>
using namespace std;

int main() {
    const double PRICE_C = 0.25;
    const double PRICE_T = 0.25;
    const int NICKEL = 5;
    const int DIME = 10;
    const int QUARTER = 25;

    double balance = 0.0;

    cout << "Welcome to my Coffee/Tea Vending Machine!" << endl;

    bool moreCoins = true;   // loop control flag 
    while (moreCoins) {    // coin collector loop 
        cout << "Enter coins - 5, 10, or 25 only: \n";
        int coin;

        cin >> coin;

        if (!cin) {             
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        } else if (coin == 0) {
            moreCoins = false;
        } else if (coin == NICKEL || coin == DIME || coin == QUARTER) {
            balance += coin / 100.0;     
        } else {
            
        }
    }

    cout << "\nYour balance is $" << fixed << setprecision(2) << balance << endl;

    // loop for menu and payments
    bool isRunning = true; // flag: exit when done
    while (isRunning) {

        char choice = '\0'; 
        bool validChoice = false; 

        while (!validChoice) { // looping until a valid letter is entered
            cout << "\nPlease pick an option ($0.25 each):" << endl;
            cout << "    C/c: Coffee" << endl;
            cout << "    T/t: Tea" << endl;
            cout << "    Q/q: Quit" << endl;
            cout << ">> ";

            cin >> choice;
            if (!cin) {                   
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid Option! Please choose a valid option!" << endl;
            } else {
                char c = static_cast<char>(tolower(static_cast<unsigned char>(choice)));
                if (c == 'c' || c == 't' || c == 'q') {
                    validChoice = true;
                    choice = c;
                } else {
                    cout << "Invalid Option! Please choose a valid option!" << endl;
                }
            }
        }

     
        if (choice == 'q') { // handle quit: print balance and end program
            cout << "\nYour balance: $" << fixed << setprecision(2) << balance << endl;
            cout << "Thank you for using my Vending Machine Program!" << endl;
            isRunning = false;
        } else {
            double unitPrice = (choice == 'c') ? PRICE_C : PRICE_T;

            int quantity = 0; // validation loop
            bool validQuantity = false; 
            while (!validQuantity) {
                cout << "How many would you like?" << endl;
                cout << ">> ";
                cin >> quantity;

                if (!cin) { 
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid Option!" << endl;
                } else if (quantity <= 0) {     // if entered zero or negative - invalid
                    cout << "Invalid Option!" << endl;
                } else {
                    validQuantity = true;
                }
            }

            double total = unitPrice * quantity; // compute purchase total

            if (balance >= total) {
                cout << "\nYour total: $" << fixed << setprecision(2) << total << endl;
                balance -= total;          // deduct
                cout << "Your balance: $" << fixed << setprecision(2) << balance << endl;
                cout << "Thank you for using my Vending Machine Program!" << endl;
                isRunning = false;         // purchase complete → end program
            } else {
                bool addMoreCoins = true;  //need more coins
                while (addMoreCoins) {
                    cout << "Enter coins - 5, 10, or 25 only: ";
                    int coin;
                    cin >> coin;

                    if (!cin) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    } else if (coin == 0) {
                        addMoreCoins = false;   // end coin collection
                    } else if (coin == NICKEL || coin == DIME || coin == QUARTER) {
                        balance += coin / 100.0;
                    } else {
                        // ignore invalid numeric values
                    }
                }

                // updated balance
                cout << "\nYour balance is $" << fixed << setprecision(2) << balance << endl;
            }
        }
    }

    return 0;
}

// ------------- DESIGN -------------
/* 
Program Name: Coffee/Tea Vending Machine!

Program Description: 
 This program is coffee and tea vending machine simulator that accepts coins of 5, 10, or 25
cents, tracks the user’s balance, and allows selecting a drink for $0.25 each. The program 
processes purchases if there are enough coins or prompts for additional until the transaction
is complete or canceled.

Design:
A. INPUT
coin as int 
choice as char
quantity as int

B. OUTPUT
balance as double
total as double

C. CALCULATIONS
balance += coin / 100.0 // add coin to balance
unitPrice = (choice == 'c') ? PRICE_C : PRICE_T //Select unit price
total = unitPrice * quantity // compute purchase total
balance -= total // deduct purchase cost


D. LOGIC and ALGORITHMS
SET PRICE_C = 0.25
SET PRICE_T = 0.25
SET NICKEL = 5, DIME = 10, QUARTER = 25
SET balance = 0.0

WELCOME
SET moreCoins = true
WHILE moreCoins:
    PROMPT "Enter coins"
    READ coin 
    IF input failed:
        clear/ignore input
        CONTINUE
    ELSE IF coin == 0:
        moreCoins = false
    ELSE IF coin is 5 or 10 or 25:
        balance += coin / 100.0
    ELSE:
        // ignore invalid numeric coin
END WHILE

DISPLAY balance 

SET isRunning = true
WHILE isRunning:
    SET validChoice = false
    WHILE NOT validChoice:
        DISPLAY menu
        READ choice 
        IF input failed:
            clear/ignore input
            DISPLAY "Invalid Option!"
        ELSE:
            IF choice in {'c','t','q'}:
                validChoice = true
            ELSE:
                DISPLAY "Invalid Option!"
    END WHILE

    IF choice == 'q':
        DISPLAY balance
        isRunning = false
        BREAK

    IF choice == 'c':
        unitPrice = PRICE_C
    ELSE:
        unitPrice = PRICE_T

    SET validQuantity = false
    WHILE NOT validQuantity:
        PROMPT "How many would you like?"
        READ quantity 
        IF input failed:
            clear/ignore
            PRINT "Invalid Option!"
        ELSE IF quantity <= 0:
            DISPLAY "Invalid Option!"
        ELSE:
            validQuantity = true
    END WHILE

    total = unitPrice * quantity

    IF balance >= total:
        DISPLAY total
        balance -= total
       DISPLAY balance
        isRunning = false   // program ends after successful purchase
    ELSE:
        SET addMoreCoins = true
        WHILE addMoreCoins:
            PROMPT "Enter coins - 5, 10, or 25 only: "
            READ coin 
            IF input failed:
                clear/ignore
                CONTINUE
            ELSE IF coin == 0:
                addMoreCoins = false
            ELSE IF coin is 5 or 10 or 25:
                balance += coin / 100.0
            ELSE:
                // ignore invalid coin
        END WHILE

       DISPLAY balance
    END IF

END WHILE

RETURN 0


SAMPLE RUNS
Welcome to my Coffee/Tea Vending Machine!

Enter coins - 5, 10, or 25 only: 5
Enter coins - 5, 10, or 25 only: 25
Enter coins - 5, 10, or 25 only: 25
Enter coins - 5, 10, or 25 only: 5
Enter coins - 5, 10, or 25 only: 10
Enter coins - 5, 10, or 25 only: 10
Enter coins - 5, 10, or 25 only: 0

Your balance is $0.80

Please pick an option ($0.25 each):
    C/c: Coffee
    T/t: Tea
    Q/q: Quit
>> k
Invalid Option! Please choose a valid option!
>> 9
Invalid Option! Please choose a valid option!
>> c
How many would you like?
>> f
Invalid Option!
How many would you like?
>> 2

Your total: $0.50
Your balance: $0.30
Thank you for using my Vending Machine Program!



Welcome to my Coffee/Tea Vending Machine!

Enter coins - 5, 10, or 25 only: 5
Enter coins - 5, 10, or 25 only: 25
Enter coins - 5, 10, or 25 only: 0

Your balance is $0.30

Please pick an option ($0.25 each):
    C/c: Coffee
    T/t: Tea
    Q/q: Quit
>> c

How many would you like?
>> 2

Your total is $0.50
Your balance is $0.30
Not enough change!! Please add more coins.

Enter coins - 5, 10, or 25 only: 5
Enter coins - 5, 10, or 25 only: 25
Enter coins - 5, 10, or 25 only: 0

Your balance: $0.60

Please pick an option ($0.25 each):
    C/c: Coffee
    T/t: Tea
    Q/q: Quit
>> T

How many would you like?
>> 1

Your total is $0.25
Your balance is $0.35

Thank you for using my Vending Machine Program!




Welcome to my Coffee/Tea Vending Machine!

Enter coins - 5, 10, or 25 only: 5
Enter coins - 5, 10, or 25 only: 25
Enter coins - 5, 10, or 25 only: 0
Your balance is $0.30

Please pick an option ($0.25 each):
    C/c: Coffee
    T/t: Tea
    Q/q: Quit
>> q

Your total is $0
Your balance is $0.30

Thank you for using my Vending Machine Program!


*/
