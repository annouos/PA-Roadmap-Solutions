
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

void print(int number)
{
    for(int i = 1; i <= number; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            cout << char(64+i);
        }
        cout << endl;
    }
}

int main()
{
    print(positiv_number("Please enter a number: "));
    return 0;
}