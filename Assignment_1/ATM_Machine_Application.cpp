#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class Bank
{
    string ids[1000];
    string passwords[1000];
    double balances[1000];
    int num_users = 0;
    string id;
    string password;

public:
    void start()
    {
        cout << "**********Welcome To Indi ATM**********" << endl
             << "***Please select the option from below according to your need***" << endl;
        char option;
        do
        {
            printIntroMenu();
            cin >> option;
            switch (option)
            {
            case 'l':
                login();
                break;
            case 'c':
                create_new_account();
                break;
            case 'q':
                cout << "Thanks using Indi ATM!\n";
                break;
            default:
                cout << "Invalid option. Please select some other valid option.\n";
                break;
            }
        } while (option != 'q');
    }
    void printIntroMenu()
    {
        cout << "Press 'l' for Login" << endl
             << "Press 'c' for Create New Account" << endl
             << "Press 'q' for Quit" << endl;
    }
    void printMainMenu()
    {
        cout << "Press 'd' for Deposit Money" << endl
             << "Press 'w' for Withdraw Money" << endl
             << "Press 'r' for Request Balance" << endl
             << "Press 'q' for quit" << endl;
    }
    void create_new_account()
    {
        cout << "Please enter your user id: ";
        cin >> id;
        cout << "Please enter your password: ";
        cin >> password;
        ids[num_users] = id;
        passwords[num_users] = password;
        balances[num_users] = 0.0;
        num_users++;
        cout << "Thank You! Your account has been created!\n";
    }

    void login()
    {
        cout << "Please enter your user id: ";
        cin >> id;
        cout << "Please enter your password: ";
        cin >> password;
        int user_index = -1;
        for (int i = 0; i < num_users; i++)
        {
            if (ids[i] == id && passwords[i] == password)
            {
                user_index = i;
                break;
            }
        }
        if (user_index != -1)
        {
            cout << "Access Granted!\n";
            char option;
            do
            {
                printMainMenu();
                cin >> option;
                switch (option)
                {
                case 'd':
                {
                    double amount;
                    cout << "Amount of deposit: $";
                    cin >> amount;
                    balances[user_index] += amount;
                    break;
                }
                case 'w':
                {
                    double amount;
                    cout << "Amount of withdrawal: $";
                    cin >> amount;
                    if (amount <= balances[user_index])
                    {
                        balances[user_index] -= amount;
                    }
                    else
                    {
                        cout << "Insufficient balance.\n";
                    }
                    break;
                }
                case 'r':
                {
                    cout << "Your balance is $" << balances[user_index] << ".\n";
                    break;
                }
                case 'q':
                {
                    cout << "Thanks for stopping by!\n";
                    break;
                }
                default:
                {
                    cout << "Invalid option. Please try again.\n";
                    break;
                }
                }
            } while (option != 'q');
        }
        else
        {
            cout << "******** LOGIN FAILED! ********\n";
        }
    }
};
int main()
{
    Bank obj;
    obj.start();
    return 0;
}
