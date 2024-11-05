
#include <iostream>

using namespace std;

int genric_number(string massage)
{
    int number = 0;
    cout << massage;
    cin >> number;
    return number;
}

float proces(int number)
{
    return (float) number / 2;
}

void print(float number)
{
    cout << endl << number << endl << endl;
}

int main() 
{
    int number = genric_number("Please enter a number: ");
    print(proces(number));
    return 0;   
}
