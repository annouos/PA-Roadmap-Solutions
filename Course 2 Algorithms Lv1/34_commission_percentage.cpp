
#include <iostream>

using namespace std;

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

float checking(int number)
{
    if (number >= 1000000) {
        return number * 0.01;
    }
    else if (number >= 500000) {
        return number * 0.02;
    }
    else if (number >= 100000) {
        return number * 0.03;
    }
    else if (number >= 50000) {
        return number * 0.05;
    }
    else {
        return (float) number;
    }
}

void print(float number)
{
    cout << endl << number << endl << endl;
}

int main()
{
    int sales = positiv_number("Please enter your sales: ");
    print(checking(sales));
    return 0;
}
