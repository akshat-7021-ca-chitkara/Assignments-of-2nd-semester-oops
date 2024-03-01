#include <iostream>
#include <string>

using namespace std;

class User {
private:
  string name;
  int birth_year;
  int birth_day;
  int birth_month;
  double salary;

public:
 //To take input of details of the users
  void getUserData() {
    cout << "Enter name: ";
    getline(cin, name);

    cout << "Enter birth year: ";
    cin >> birth_year;
    cin.ignore();

    cout << "Enter birth month: ";
    cin >> birth_month;
    cin.ignore();

    cout << "Enter birth day: ";
    cin >> birth_day;
    cin.ignore();

    cout << "Enter salary: ";
    cin >> salary;
    cin.ignore(); 
  }

  // Function to find the which user is elder or younger
  bool operator<(const User& other) const {
    if (birth_year != other.birth_year)
        return birth_year > other.birth_year;
    if (birth_month != other.birth_month)
        return birth_month > other.birth_month;
    return birth_day > other.birth_day;
}


 // Function for finding average salary of the two user
  double operator+(const User& other) const {
    return (salary + other.salary) / 2.0;
  }

 // Function for increment in salary according to the value of percentage passed in the function
  void increasing_salary(double percentage) {
    salary *= (1.0 + percentage / 100.0);
  }

 // Function to show the details of the users
  void displayDetails() const {
    cout << "Name: " << name << endl;
    cout << "Birth Date: " << birth_month << "/" << birth_day << "/" << birth_year << endl;
    cout << "Salary: Rs." << salary << "(This is the salary after increment)" << endl;
  }
};

int main() {
  // Create users and get user input for each user to store data
  User user1, user2;
  cout << "\n*****User 1 Information*****\n";
  user1.getUserData();

  cout << "\n*****User 2 Information*****\n";
  user2.getUserData();

  // Comparing users age , is user 1 elder or younger or of same age as user 2
  if (user1 < user2)
    cout << "User1 is younger." << endl;
  else if (user2 < user1)
    cout << "User1 is elder." << endl;
  else
    cout << "Both users are equal in age." << endl;

  // Compute average salary
  double average_sal = user1 + user2;
  cout << "Average Salary: Rs." << average_sal << endl;

  // Add annual increment (For user 1 5% and For user 2 10%)
  user1.increasing_salary(5.0); 
  user2.increasing_salary(10.0); 

  // Display user details after salary annual increment of both the users
  cout << "\nUser1 Details:" << endl;
  user1.displayDetails();

  cout << "\nUser2 Details:" << endl;
  user2.displayDetails();

  return 0;
}
