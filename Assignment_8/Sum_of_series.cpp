#include <iostream>
using namespace std;

class Sum_Of_Series
{
public:
    // Function to compute the sum of first n natural numbers
    /**
Calculates the sum of the first n natural numbers.

@param n The number of natural numbers to sum.

@return The sum of the first n natural numbers.
*/
    int sum_Of_N_Natural_Numbers(int n)
    {
        return n * (n + 1) / 2;
    }

    // Function to compute the sum of series
    // This function computes the sum of the sum of the first n natural numbers
    // Parameters:
    //   n: an integer representing the number of natural numbers to compute the sum for
    // Returns:
    //   an integer representing the sum of the sum of the first n natural numbers

    int compute(int n)
    {
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            sum += sum_Of_N_Natural_Numbers(i);
        }
        return sum;
    }
};

/**
@file main.cpp

@brief This file contains the main function to compute the sum of a series.
*/
/**
@class Sum_Of_Series

@brief This class computes the sum of a series.
*/
/**
@brief The main function of the program.

@return 0 if successful.
*/
int main()
{
    Sum_Of_Series sum;
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;

    // Check if the input is a natural number or not
    if (n <= 0)
    {
        cout << "The input is not a natural number. Please enter a positive integer." << endl;
        return 0;
    }

    cout << "The sum of the series is: " << sum.compute(n) << endl;
    return 0;
}
