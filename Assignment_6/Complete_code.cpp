#include<iostream>
using namespace std;

class Sample {
public:
    typedef double (Sample::*MathFunction)(double);

    double Compute(MathFunction func, double n) {
        return (this->*func)(n);
    }

    double FindFactorial(double n) {
        double factorial = 1;
        for(int i = 1; i <= n; i++) {
            factorial *= i;
        }
        return factorial;
    }

    double FindSquare(double n) {
        return n * n;
    }

    double FindCube(double n) {
        return n * n * n;
    }
};

void PrintMenu() {
    cout << "Choose an operation:\n";
    cout << "1. Factorial\n";
    cout << "2. Square\n";
    cout << "3. Cube\n";
    cout << "Enter your choice: ";
}

int main() {
    Sample obj;
    int choice;
    double n;

    PrintMenu();
    cin >> choice;

    cout << "Enter a number: ";
    cin >> n;

    switch(choice) {
        case 1:
            cout << "Factorial: " << obj.Compute(&Sample::FindFactorial, n) << endl;
            break;
        case 2:
            cout << "Square: " << obj.Compute(&Sample::FindSquare, n) << endl;
            break;
        case 3:
            cout << "Cube: " << obj.Compute(&Sample::FindCube, n) << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
    }

    return 0;
}
