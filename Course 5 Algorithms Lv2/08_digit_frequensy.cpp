
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

void checking(int number, short digit)
{
    int remainder = 0, sum = 0;
    while (number > 0)
    {
        remainder = number % 10;
        number /= 10;
        if(digit == remainder)
            sum++;        
    }
    cout << sum << endl;
}

int main()
{
    int number = positiv_number("Please enter a number: ");
    short digit = positiv_number("Please enter a digit: ");
    checking(number, digit);
    return 0;
}
