
#include <iostream>

using namespace std;

int genric_number(string massage)
{
    int number = 0;
    cout << massage;
    cin >> number;
    return number;
}

int proces(int num_1, int num_2, int num_3)
{
    return num_1 + num_2 + num_3;
}

void print(int sum)
{
    cout << endl << sum << endl << endl;
}

int main()

{
    int number_1 = genric_number("Please enter a number one: ");
    int number_2 = genric_number("Please enter a number tow: ");
    int number_3 = genric_number("Please enter a number three: ");
    print(proces(number_1, number_2, number_3));
    return 0;
}