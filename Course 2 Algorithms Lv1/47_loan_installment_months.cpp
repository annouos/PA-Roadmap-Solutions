
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
    float remainder = number_1 / number_2;
    return remainder;
}

void print(float number)
{
    cout << endl << "In: " << number << " Months" << endl << endl;
}

int main()

{
    int loan_amount = positiv_number("Please enter loan amount: ");
    int payment_monthly = positiv_number("Please enter payment monthly: ");
    print(calc(loan_amount, payment_monthly));
    return 0;
}
