
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

bool checking(int number)
{
    return number == revers(number);
}

void print(int number)
{
    if(checking(number))
        cout << " It's palindrome " << endl;
    else
        cout << " It's NOT palindrome " << endl;
}

int main()

{
    print(positiv_number("Please enter a number: "));
    return 0;
}
