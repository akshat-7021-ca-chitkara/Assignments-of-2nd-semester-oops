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
    /**


    Function: start


    Description: This function is the starting point of the Indi ATM program. It displays a welcome message and a menu of options for the user to choose from. It then takes the user's input and performs the corresponding action based on the selected option.


    Parameters: None


    Returns: None
    */

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
    /**
     * Function: printIntroMenu
     *
     * Description: Prints the introductory menu options for the user.
     *
     * Parameters: None
     *
     * Returns: None
     */
    void printIntroMenu()
    {
        cout << "Press 'l' for Login" << endl
             << "Press 'c' for Create New Account" << endl
             << "Press 'q' for Quit" << endl;
    }
    /**
     * Function: printMainMenu
     * -----------------------
     * Displays the main menu options for a banking system.
     * The user can choose to deposit money, withdraw money,
     * request balance, or quit the program.
     *
     * Parameters: None
     *
     * Returns: None
     */
    void printMainMenu()
    {
        cout << "Press 'd' for Deposit Money" << endl
             << "Press 'w' for Withdraw Money" << endl
             << "Press 'r' for Request Balance" << endl
             << "Press 'q' for quit" << endl;
    }
    /**
     * Function: create_new_account
     * ---------------------------
     * Prompts the user to enter their user id and password, and creates a new account with the entered information.
     * The new account is stored in the ids, passwords, and balances arrays.
     * The num_users variable is incremented to keep track of the number of users.
     * Prints a confirmation message after the account is created.
     */
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

    /**
     * Function to handle user login.
     */
    void login()
    {
        cout << "Please enter your user id: ";
        cin >> id;
        cout << "Please enter your password: ";
        cin >> password;

        // Variable to store the index of the user in the arrays
        int user_index = -1;

        // Loop through the arrays to find a matching user id and password
        for (int i = 0; i < num_users; i++)
        {
            if (ids[i] == id && passwords[i] == password)
            {
                user_index = i;
                break;
            }
        }

        // If a matching user is found
        if (user_index != -1)
        {
            cout << "Access Granted!\n";
            char option;

            // Loop to display the main menu and handle user options
            do
            {
                printMainMenu();
                cin >> option;

                // Switch statement to handle different user options
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

                    // Check if the withdrawal amount is less than or equal to the user's balance
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
            cout << "************ LOGIN FAILED! ************\n";
            cout << "**** INVALID USER ID OR PASSWORD! ****\n";
        }
    }
};
/**
 * @file main.cpp
 * @brief This file contains the main function to start the program.
 */

/**
 * @brief The main function of the program.
 * @return 0 indicating successful execution of the program.
 */
int main()
{
    Bank obj;    // Create an instance of the Bank class.
    obj.start(); // Call the start function of the Bank object.
    return 0;    // Return 0 to indicate successful execution of the program.
}
