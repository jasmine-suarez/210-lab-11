// COMSC-210 | Lab 11 | Jasmine Suarez
// IDE used: VS Code

#include <iostream>
using namespace std;

// hello
struct Customer {
    string name;
    int tableNum;
    int numOrders;
    string * orders;

    ~Customer() {
        if (orders)
            delete [] orders;
        orders = nullptr;
    }
};

void inputCustomer(Customer *);
void displayCustomer(Customer *);

int main() {
    int numCustomers;
    cout << "How many customers? ";
    cin >> numCustomers;
    cin.ignore();

    Customer *list = new Customer[numCustomers];

    for (int i = 0; i < numCustomers; i++)
        inputCustomer(&list[i]);

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