// Here i have used complex number system to complete this assignment as i know what is complex numbers

#include <iostream>
using namespace std;

class Complex_Number
{
private:
    int real, imaginary;

public:
    Complex_Number(int r = 0, int i = 0)
    {
        real = r;
        imaginary = i;
    }

    // Overloading + operator using a friend function
    friend Complex_Number operator+(Complex_Number c1, Complex_Number c2);

    // Overloading - operator using a friend function
    friend Complex_Number operator-(Complex_Number c1, Complex_Number c2);

    void print() { cout << real << " + " << imaginary << "i" << endl; }
};

// Implementation of + operator as friend function
Complex_Number operator+(Complex_Number c1, Complex_Number c2)
{
    return Complex_Number(c1.real + c2.real, c1.imaginary + c2.imaginary);
}

// Implementation of - operator as friend function
Complex_Number operator-(Complex_Number c1, Complex_Number c2)
{
    return Complex_Number(c1.real - c2.real, c1.imaginary - c2.imaginary);
}

int main()
{
    Complex_Number c1(27, 14), c2(19, 9);
    Complex_Number c3 = c1 + c2;
    Complex_Number c4 = c1 - c2;
    cout << "The result of addition is ";
    c3.print();
    cout << "\n";
    cout << "The result of subtraction is ";
    c4.print();
    return 0;
}
