
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

int revers(short digit, int number)
{
    int remainder = 0, sum = 0;
    while (number > 0)
    {
        remainder = number % 10;
        number /= 10;
        if(digit == remainder)
        {
            sum++;        
        }
    }
    return sum;
}

void print(int number)
{
    cout << endl;
    short digit = 0;
    for(int i = 0; i < 10; i++)
    {
        digit = revers(i, number);
        if(digit > 0)
        {
        cout << "Digit " << i << " Frequency is: " << digit << " Times\n" ;
        }
    }
}

int main()
{
    int number = positiv_number("Please enter a number: ");
    print(number);
    return 0;
}
