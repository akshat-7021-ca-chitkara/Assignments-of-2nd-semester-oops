/* 
 The concept initially used was shallow copy which leads to the problem of copying
 address of same memory instead of making new.

 we rewrite the function accordingly that on a new memory will from to store new data using deep copy

 also at end of class we use destructor
 */
#include <iostream>
#include <cstring>
using namespace std;

class Sample {
public:
    char *name;

    // Default constructor
    Sample() {
        name = nullptr;
    }

    // Parameterized constructor
    Sample(char *str) {
        name = new char[strlen(str) + 1];
        strcpy(name, str);
    }

    // Copy constructor for deep copy
    Sample(const Sample &s) {
        name = new char[strlen(s.name) + 1];
        strcpy(name, s.name);
    }

    // Destructor
    ~Sample() {
        delete[] name;
    }
};

int main() {
    Sample user1((char *)"chitkara");
    Sample user2 = user1;  // Deep copy happens here
    strcpy(user2.name, "dummy");
    cout << "User1's name: " << user1.name << endl;
    cout << "User2's name: " << user2.name << endl;
    return 0;
}
