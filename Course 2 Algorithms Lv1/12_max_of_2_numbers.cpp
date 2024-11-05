
#include <iostream>

using namespace std;

int genric_number(string massage)
{
    int number = 0;
    cout << massage;
    cin >> number;
    return number;
}

int proces(int num_1, int num_2)
{
    if(num_1 > num_2)
        return num_1;
    else
        return num_2;
}

void print(int number)
{
    cout << endl << "The max number is: " << number << endl << endl;
}

int main()

{
    int number_1 = genric_number("Please enter number one: ");
    int number_2 = genric_number("Please enter number tow: ");
    print(proces(number_1,number_2));
    return 0;
}