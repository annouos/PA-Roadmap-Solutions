
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

bool loop(int number)
{
    int sum = 0;
    for(int i = 1; i < number; i++)
    {
        if(number % i == 0)
        {
            cout << i << endl;
            sum += i;
        }
    }
    return number == sum;
}

void print(int number)
{
    if(loop(number))
        cout << number << " it's a perfect number" << endl;
    else
        cout << number << " it's NOT a perfect number" << endl;
}

int main()
{
    int perfect = positiv_number("Please enter a number: ");
    print(perfect);
    return 0;
}
