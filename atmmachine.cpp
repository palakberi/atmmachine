#include <iostream>
#include <string>

using namespace std;

void printIntroMenu();
void printMainMenu();
void start();
void login();
void createAccount();

char menuInput;
string userId;
string password;
double balance = 0.0;
bool isLoggedIn = false;
string storedUserId = "";
string storedPassword = "";


int main() {
    cout << "Hi! Welcome to the ATM Machine!" << endl;
    start();
    return 0;
}

void printIntroMenu() {
    cout << "Please select an option from the menu below:" << endl;
    cout << "l -> Login" << endl;
    cout << "c -> Create New Account" << endl;
    cout << "q -> Quit" << endl;
    cout << "> ";
}

void printMainMenu() {
    cout << "d -> Deposit Money" << endl;
    cout << "w -> Withdraw Money" << endl;
    cout << "r -> Request Balance" << endl;
    cout << "q -> Quit" << endl;
    cout << "> ";
}

void start() {
    while (true) {
        printIntroMenu();
        cin >> menuInput;
        
        switch (menuInput) {
            case 'l':
                login();
                break;

            case 'c':
                createAccount();
                break;

            case 'q':
                cout << "Thanks for stopping by!" << endl;
                exit(0); 

            default:
                cout << "Invalid option. Please try again." << endl;
        }

        while (isLoggedIn) {
            printMainMenu();
            cin >> menuInput;

            switch (menuInput) {
                case 'd': {
                    double amount;
                    cout << "Amount of deposit: $";
                    cin >> amount;
                    balance += amount;
                    break;
                }

                case 'w': {
                    double amount;
                    cout << "Amount of withdrawal: $";
                    cin >> amount;
                    if (balance >= amount) {
                        balance -= amount;
                    } else {
                        cout << "Insufficient balance." << endl;
                    }
                    break;
                }

                case 'r':
                    cout << "Your balance is $" << balance << "." << endl;
                    break;

                case 'q':
                    isLoggedIn = false;
                    cout << "Thanks for stopping by!" << endl;
                    exit(0);
                    break;

                default:
                    cout << "Invalid option. Please try again." << endl;
            }
        }
    }
}

void createAccount() {
    cout << "Please enter your user name: ";
    cin >> storedUserId;
    cout << "Please enter your password: ";
    cin >> storedPassword;
    balance = 0.0;
    cout << "Thank You! Your account has been created!" << endl;
}

void login() {
    cout << "Please enter your user id: ";
    cin >> userId;
    cout << "Please enter your password: ";
    cin >> password;

    if (userId == storedUserId && password == storedPassword) {
        cout << "Access Granted!" << endl;
        isLoggedIn = true;
    } 
    else {
        cout << "******** LOGIN FAILED! ********" << endl;
    }
}
