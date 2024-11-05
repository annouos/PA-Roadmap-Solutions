
#include <iostream>
#include <cmath>

using namespace std;

int genric_number(string massage)
{
    int number = 0;
    cout << massage;
    cin >> number;
    return number;
}

int my_sqrt(int number)
{
    return pow(number, 0.5);
}

int main()
{
    float number = genric_number("Please enter a number: ");
    cout << "In my round the number: " << my_sqrt(number) << endl;
    return 0;
}
