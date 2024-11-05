
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

void revers(int number)
{
    int remainder = 0, new_num = 0;
    while (number > 0)
    {
        remainder = number % 10;
        number /= 10;
        new_num = new_num * 10 + remainder;        
    }
    cout << new_num << endl;
}

int main()
{
    revers(positiv_number("Please enter a number: "));
    return 0;
}
