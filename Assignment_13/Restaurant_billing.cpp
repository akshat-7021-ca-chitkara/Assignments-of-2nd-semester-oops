#include<iostream>
using namespace std;

class Product {
public:
    char name[50];
    double price;

    void setProductDetails() {
        cout << "Enter product name: ";
        cin >> name;
        cout << "Enter product price: ";
        cin >> price;
    }
};

class Bill : public Product {
public:
    int quantity;
    double total;

    void setBillDetails() {
        setProductDetails();
        cout << "Enter quantity: ";
        cin >> quantity;
        total = price * quantity;
    }

    void displayBill() {
        cout << "Product: " << name << endl;
        cout << "Price: " << price << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Total: " << total << endl;
    }
};

int main() {
    Bill bill[30]; // Array of 30 bills to store maximum 30 bills
    int n;
    double grandTotal = 0;

    cout << "Enter the number of products: ";
    cin >> n;

    for(int i = 0; i < n; i++) {
        cout << "Enter details for product " << i+1 << ":" << endl;
        bill[i].setBillDetails();
        grandTotal += bill[i].total;
    }

    cout << "\n****** Bill Details ******" << endl;
    for(int i = 0; i < n; i++) {
        cout << "\nProduct " << i+1 << ":" << endl;
        bill[i].displayBill();
    }

    cout << "\n****** Grand Total: " << grandTotal << " ******" << endl;

    return 0;
}
