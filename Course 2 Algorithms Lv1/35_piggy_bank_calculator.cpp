
#include <iostream>

using namespace std;

enum eninfo {penny = 1, nickle = 5, dime = 10, quarter = 25, dollar = 100};

int positiv_number(string massage)
{
    int number = 0;
    do
    {
        cout << massage;
        cin >> number;
    } while (number < 0);
    return number;
}

struct info
{
    int penny = positiv_number("Please enter how many pennies: ");
    int nickel = positiv_number("Please enter how many nickels: ");
    int dime = positiv_number("Please enter how many dimes: ");
    int quarter = positiv_number("Please enter how many quarters: ");
    int dollar = positiv_number("Please enter how many dollars: ");
};

float calc()
{
    info self;
    float total = self.penny * eninfo::penny + 
                  self.nickel * eninfo::nickle + 
                  self.dime * eninfo::dime +
                  self.quarter * eninfo::quarter +
                  self.dollar * eninfo::dollar;
    return (float) total;
}

void print(float number)
{
    cout << endl << number << " Penny " << endl << endl;
}

int main() 
{
    print(calc());
    return 0;
}
