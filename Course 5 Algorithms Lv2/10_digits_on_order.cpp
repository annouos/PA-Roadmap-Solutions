
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

int revers(int number)
{
    int remainder = 0, new_num = 0;
    while (number > 0)
    {
        remainder = number % 10;
        number /= 10;
        new_num = new_num * 10 + remainder;        
    }
    return new_num;
}

void print(int number)
{
    int remainder = 0;
    while (number > 0)
    {
        remainder = number % 10;
        number /= 10;
        cout << remainder;
    }
    cout << endl ;
}

int main()

{
    print(revers(positiv_number("Please enter a number: ")));
    return 0;
}
