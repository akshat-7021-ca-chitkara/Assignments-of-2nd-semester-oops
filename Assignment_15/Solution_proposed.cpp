//Friend function in C++ can access private members of a class
//I will use friend finction

#include<iostream>
using namespace std;

class ClassB; // Forward declaration

class ClassA {
private:
    int numA;
public:
    ClassA(int a) : numA(a) {}
    // Friend function
    friend int sum(ClassA, ClassB);
};

class ClassB {
private:
    int numB;
public:
    ClassB(int b) : numB(b) {}
    // Friend function
    friend int sum(ClassA, ClassB);
};

// Friend function definition
int sum(ClassA a, ClassB b) {
    return (a.numA + b.numB);
}

int main() {
    ClassA objA(10);
    ClassB objB(20);

    cout << "Sum: " << sum(objA, objB) << endl;

    return 0;
}
