
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

void checking(int number)
{
    int remainder = 0;
    while (number > 0)
    {
        remainder = number % 10;
        number /= 10;
        cout << remainder << endl;
    }
}

int main()

{
    checking(positiv_number("Please enter a number: "));
    return 0;
}
