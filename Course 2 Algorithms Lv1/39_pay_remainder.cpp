
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

float calc(int number_1, int number_2)
{
    float remainder = number_1 - number_2;
    return remainder;
}

void print(float number)
{
    cout << endl << "Reminder is: " << number << endl << endl;
}

int main()

{
    int total_bill = positiv_number("Please enter total bill: ");
    int cash_paid = positiv_number("Please enter cach paid: ");
    print(calc(total_bill, cash_paid));
    return 0;
}
