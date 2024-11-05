
#include <iostream>
#include <cmath>

using namespace std;

enum eninfo {odd = 1, even = 2};

int positiv_number(string massage)
{
    int number = 0;
    do 
    {
        cout << massage;
        cin >> number;
    } while(number < 0);
    return number;
}

eninfo checking(int number)
{
    int remainder = round(number / 2);
    for(int i = 2; i <= remainder; i++)
    {
        if(number % i == 0)
            return eninfo::even;
    }
    return eninfo::odd;
}

void print(int number)
{
    for(int i = 1; i <= number; i++)
    {
        if(checking(i) == eninfo::odd)
            cout << i << endl;
    }
}

int main()
{
    int number = positiv_number("Please enter a number: ");
    print(number);
    return 0;
}
