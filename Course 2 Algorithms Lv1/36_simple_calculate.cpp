
#include <iostream>
#include <string>

using namespace std;

enum eninfo {add = '+', minos = '-', darp = '*', vide = '/'};

int read(string massage)
{
    int number;
    cout << massage;
    cin >> number;
    return number;
}

eninfo read_operation(string massage)
{
    char operation;
    cout << massage;
    cin >> operation;
    return (eninfo) operation;
}

float calc(int number_1, int number_2, eninfo self)
{
    switch (self)
    {
        case eninfo::add :
        return number_1 + number_2;
        case eninfo::minos :
        return number_1 - number_2;
        case eninfo::darp :
        return number_1 * number_2;
        case eninfo::vide :
        return number_1 / number_2;
        default :
        return number_1 * number_2 / number_1;
    }
}

int main()
{
    int num_1 = read("Enter a first number: ");
    int num_2 = read("Enter a second number: ");
    eninfo opy = read_operation("Enter an operation (+ - * /): ");
    cout << calc(num_1, num_2, opy) << endl;
    return 0;
}
