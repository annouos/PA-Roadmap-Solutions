
#include <iostream>
#include <cmath>

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

void loop(int number)
{
    for(int counter = 2; counter <= 4; counter++)
    {
        cout << number << " power " << counter << " = " << pow(number, counter) << endl;
    }
}

int main()
{
    int number = positiv_number("Please enter a number: ");
    loop(number);
    return 0;
}
