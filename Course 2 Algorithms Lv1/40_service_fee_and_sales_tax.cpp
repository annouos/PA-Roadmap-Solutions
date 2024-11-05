
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

float services(int number)
{
    float services_fee = 1.1;
    float total = number * services_fee;
    return total;
}
float taxes(int number)
{
    float sales_tax = 1.16;
    float total = services(number) * sales_tax;
    return total;
}

void print(float number)
{
    cout << endl << "The total after services and taxes is: " << number << endl << endl;
}

int main()

{
    int total_bill = positiv_number("Please enter the total bill: ");
    print(taxes(total_bill));
    return 0;
}
