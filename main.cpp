#include <iostream>
using namespace std;

int main() {
    int pinAttempts = 0;
    string pin = "0000";
    bool isAuthenticated = false;
    bool exitProgram = false;

    while (!exitProgram) {
        // Prompt user to enter PIN
        pinAttempts = 0;
        isAuthenticated = false;
        while (!isAuthenticated && pinAttempts < 3) {
            string userInput;
            cout << "Enter PIN: ";
            cin >> userInput;

            if (userInput == pin) {
                isAuthenticated = true;
            } else {
                cout << "Incorrect PIN. Please try again." << endl;
                pinAttempts++;
            }
        }

        // Present menu options if authenticated
        if (isAuthenticated) {
            int option;
            cout << "Select an option:" << endl;
            cout << "1. Reset PIN" << endl;
            cout << "2. Check balance" << endl;
            cout << "3. Send money" << endl;
            cout << "4. Exit program" << endl;
            cin >> option;

            switch (option) {
                case 1:
                    cout << "Enter new PIN: ";
                    cin >> pin;
                    cout << "PIN reset successfully." << endl;
                    break;
                case 2:
                    cout << "Your balance is $100." << endl;
                    break;
                case 3:
                    cout << "Enter recipient's account number: ";
                    string accountNumber;
                    cin >> accountNumber;
                    cout << "Enter amount to send: ";
                    int amount;
                    cin >> amount;
                    cout << "$" << amount << " sent to account number " << accountNumber << "." << endl;
                    break;
                case 4:
                    cout << "Exiting program." << endl;
                    exitProgram = true;
                    break;
                default:
                    cout << "Invalid option selected." << endl;
            }
        } else {
            cout << "Too many incorrect attempts. Program exiting." << endl;
            exitProgram = true;
        }
    }

    return 0;
}
