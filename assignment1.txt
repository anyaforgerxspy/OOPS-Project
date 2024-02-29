#include <iostream>
#include <stdlib.h>
using namespace std;

class atm {
    int id, pass, login_id, login_pass, bal = 0, dep, with;
    char choice;

public:
    void printIntroMenu() {
        cout << "Please choose an alternative from the menu below:" << endl;
        cout << "l-> Login \n"<< endl;
        cout << "c-> create account\n"<<endl;
        cout << "q-> quit\n"<<endl;
        cin >> choice;
    }

    void printMainMenu() {
        cout << "d -> Deposit Money \n" << endl;
        cout << "w -> Withdraw Money \n" << endl;
        cout << "r -> Request balance Money \n" << endl;
        cout << "q -> Quit \n" << endl;
        cin >> choice;
    }

    void login() {
        cout << "Please enter your user id: ";
        cin >> login_id;
        cout << "Please enter your password: ";
        cin >> login_pass;
    }

    void createAccount() {
        cout << "Please enter your user id: ";
        cin >> id;
        cout << "Please enter your password: ";
        cin >> pass;
        cout << "Congratulations! Your account has been created!" << endl;
    }

    void start() {
        printIntroMenu();
        while (true) {
            switch (choice) {
                case 'l':
                    login();
                    if (id == login_id && pass == login_pass) {
                        cout << "Access Granted!" << endl;
                        while (true) {
                            printMainMenu();
                            switch (choice) {
                                case 'd':
                                    cout << "Amount of deposit: ?";
                                    cin >> dep;
                                    bal += dep;
                                    break;
                                case 'w':
                                    cout << "Amount of withdrawal: ?";
                                    cin >> with;
                                    if (with <= bal) {
                                        bal -= with;
                                    } else {
                                        cout << "Insufficient balance!" << endl;
                                    }
                                    break;
                                case 'r':
                                    cout << "Your balance is ?" << bal << endl;
                                    break;
                                case 'q':
                                    cout << "Thanks for stopping by!" << endl;
                                    exit(0);
                                    break;
                                default:
                                    cout << "Invalid option.\n" << endl;
                                    break;
                            }
                        }
                    } else {
                        cout << "* LOGIN FAILED! *" << endl;
                        printIntroMenu();
                    }
                    break;
                case 'c':
                    createAccount();
                    printIntroMenu();
                    break;
                case 'q':
                    cout << "Program quiting!" << endl;
                    exit(0);
                    break;
                default:
                    cout << "Invalid option." << endl;
                    printIntroMenu();
                    break;
            }
        }
    }
};

int main() {
    atm a1;
    cout << "Welcome to D's machine" << endl;
    a1.start();
    return 0;
}