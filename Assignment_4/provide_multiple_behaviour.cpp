#include <iostream>

using namespace std;

class computation {
public:
    // Method to perform calculation on two integer parameters
    int compute(int a, int b) {
        return a + b;
    }

    // Method to perform calculation on one integer and one float parameter
    float compute(int a, float b) {
        return static_cast<float>(a) + b;
    }

    // Method to perform calculation on one integer and one double parameter
    double compute(int a, double b) {
        return static_cast<double>(a) + b;
    }

    // Method to perform calculation on character parameters (addition of ASCII values)
    int compute(char c1, char c2) {
        return static_cast<int>(c1) + static_cast<int>(c2);
    }

    // Method to convert character into its ASCII equivalent
    int compute(char c, int num) {
        return static_cast<int>(c) + num;
    }

    // Method to handle no value provided (default behavior)
    int compute() {
        return 0; 
    }
};

int main() {
    computation num_cal;

    cout << "\n*****Here are the exmaple of different behaviour shown : *****\n\n";
    cout << "(Integer and Integer)Sum of 5 and 10: " << num_cal.compute(5, 10) << endl;
    cout << "(Integer and Float)Sum of 3 and 7.5: " << num_cal.compute(3, 7.5f) << endl;
    cout << "(Integer and Double)Sum of 2 and 4.5 (double): " << num_cal.compute(2, 4.5) << endl;
    cout << "\n*****The below values are from ASCII through characters*****\n";
    cout << "(Character and Character) sum of 'A' and 'B': " << num_cal.compute('A', 'B') << endl;
    cout << "(Character and Integer) value of 'C' + 10: " << num_cal.compute('C', 10) << endl;
    cout << "Default result: " << num_cal.compute() << endl;

    return 0;
}