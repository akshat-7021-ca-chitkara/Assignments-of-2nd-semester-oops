#include<iostream>
#include<cstring>
using namespace std;

class StringAnalyzer {
public:
    char* str;

    // Constructor to initialize string
    StringAnalyzer(char* s) {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }

    // Function to count words in string
    int countWords() {
        int count = 0;
        char* temp = new char[strlen(str) + 1];
        strcpy(temp, str);

        char* token = strtok(temp, " ");
        while(token != NULL) {
            count++;
            token = strtok(NULL, " ");
        }

        delete[] temp;
        return count;
    }

    ~StringAnalyzer() {
        delete[] str;
    }
};

int main() {
    char character[100];
    cout << "Enter a string: ";
    cin.ignore();
    cin.getline(character, 100);

    // char character[] = "Hello, this is a test string.";
    StringAnalyzer obj(character);

    cout << "The number of words in the string is: " << obj.countWords() << endl;

    return 0;
}
