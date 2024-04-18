#include<iostream>
using namespace std;

class smallUnit {
public:
    double inches;

    smallUnit(double in) : inches(in) {}
};

class largerUnit {
public:
    double feet;
    double inches;

    // Constructor to convert smallUnit (inches) to largerUnit (feet)
    largerUnit(const smallUnit &size) {
        feet = size.inches / 12;
        inches = size.inches;
    }

    void display() {
        cout << "Measurement in feet: " << feet << endl;
        cout << "Measurement in inches: " << inches << endl;
    }
};

int main() {
    smallUnit smallUnit_OBJ(72.5); // 72.5 inches
    largerUnit largerUnit_OBJ = smallUnit_OBJ; // Convert inches to feet

    largerUnit_OBJ.display(); // Display the measurement in feet and inches

    return 0;
}
