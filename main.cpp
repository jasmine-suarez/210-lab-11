// COMSC-210 | Lab 11 | Jasmine Suarez
// IDE used: VS Code

#include <iostream>
using namespace std;

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

int main() {

    return 0;
}

void inputCustomer(Customer * cptr) {
    cout << "Enter customer name: ";
    getline(cin, cptr->name);
    cout << "Enter table number: ";
    cin >> cptr->tableNum;
    cout << "How many orders? ";
    cin >> cptr->numOrders;

    cptr -> orders = new string[cptr->numOrders];
    for (int i = 0; i < cptr->numOrders; i++) {
        cout << "Enter order #" << i + 1 << ": ";
        getline(cin, cptr->orders[i]);
    }

    cin.ignore();

    cout << endl;
}