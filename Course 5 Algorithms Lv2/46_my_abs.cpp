
#include <iostream>

using namespace std;

int genric_number(string massage)
{
    int number = 0;
    cout << massage;
    cin >> number;
    return number;
}

int my_abs(int number)
{
    if(number >= 0)
        return number;
    else
        return number * -1;
}


int main()

{
    int number = genric_number("Please enter a number: ");
    cout << "In my abs the number: " << my_abs(number) << endl;
    return 0;
}
