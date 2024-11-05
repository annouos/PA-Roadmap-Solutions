
#include <iostream>
#include <cmath>

using namespace std;

enum eninfo {prime = 1, not_prime = 2};

int read(string massage)
{
    int number = 0;
    do
    {
        cout << massage;
        cin >> number;
    } while (number <=0);
    return number;
}

eninfo checking(int num)
{
    int devide = round(num / 2);
    for(int counter = 2; counter <= devide; counter++)
    {
        if(num % counter == 0)
            return eninfo::not_prime ;
    }
    return eninfo::prime;
}

void print(int num)
{
    switch(checking(num))
    {
        case eninfo::prime:
        cout << "This is a Prime number " << num << endl;
        break;
        case eninfo::not_prime:
        cout << "This is NOT a Prime number " << num << endl;
        break;
    }
}

int main()
{
    print(read("Please enter a number: "));
    return 0;
}
