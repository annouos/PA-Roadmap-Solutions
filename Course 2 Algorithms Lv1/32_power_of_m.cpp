
#include <iostream>

using namespace std;

int read_num(string massage)
{
    int num;
    cout << massage;
    cin >> num;
    return num;
}

int read_power(string massage)
{
    int num;
    cout << massage;
    cin >> num;
    return num;
}

int checking(int number, int power)
{
    if(power == 0)
    {
        return 1;
    }

    int p = 1;

    for(int counter = 1; counter <= power; counter++)
    {
        cout << p << " x " << number << endl;
        p *= number;
    }
    return p;
}

int main()

{
    cout << endl << checking(read_num("Please enter a number: "), read_power("Please enter the power: ")) << endl;
    return 0;
}
