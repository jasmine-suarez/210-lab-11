// COMSC-210 | Lab 11 | Jasmine Suarez
// IDE used: VS Code

#include <iostream>
using namespace std;

// struct to represent a restaurant customer
struct Customer {
    string name;        // customer's name
    int tableNum;       // table number customer is sitting at
    int numOrders;      // amount of orders
    string * orders;    // dynamic array of order numbers

    // destructor, cleans up memory
    ~Customer() {
        if (orders)
            delete [] orders;
        orders = nullptr;
    }
};

// inputCustomer() inputs data for a customer
// arguments: Customer
// returns: nothing
void inputCustomer(Customer *);

// displayCustomer() display data for a customer
// arguments: Customer
// returns: nothing
void displayCustomer(Customer *);

int main() {
    int numCustomers;
    cout << "How many customers? ";
    cin >> numCustomers; // input number of customers
    cin.ignore();

    // dynamically allocates an array of 'Customer' structs
    Customer *list = new Customer[numCustomers];

    // loop for inputting data of customer
    for (int i = 0; i < numCustomers; i++)
        inputCustomer(&list[i]);

    // loop for displaying data of customer
    for (int i = 0; i < numCustomers; i++)
        displayCustomer(&list[i]);

    return 0;
}

void inputCustomer(Customer * cptr) {
    cout << "Enter customer name: ";
    getline(cin, cptr->name);
    cout << "Enter table number: ";
    cin >> cptr->tableNum;
    cout << "How many orders? ";
    cin >> cptr->numOrders;

    cin.ignore();

    cptr -> orders = new string[cptr->numOrders];
    for (int i = 0; i < cptr->numOrders; i++) {
        cout << "Enter order #" << i + 1 << ": ";
        getline(cin, cptr->orders[i]);
    }
    cout << endl;
    cout << "need to commit";
}

void displayCustomer(Customer * cptr) {
    cout << "Customer summary:\n\n";
    cout << "Name: " << cptr->name << endl;
    cout << "Table number: " << cptr->tableNum << endl;
    for (int i = 0; i < cptr->numOrders; i++) {
        cout << "Order #" << i + 1 << ": " << cptr->orders[i] << endl;
    }

    cout << endl;
}