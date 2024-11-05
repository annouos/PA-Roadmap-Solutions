
#include <iostream>

using namespace std;

bool boolian_input(string massage)
{
    int number = 0;
    do
    {
        cout << massage;
        cin >> number;
    } while (number != 1 && number != 0);
    return number;
}

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

bool check_licens(int age, bool licens)
{
    return age > 21 && licens == 1;
}

void print(int age, bool licens)
{
    if (check_licens(age, licens))
        cout << "Hired " << endl;
    else
        cout << "Rejected " << endl;
}

int main()
{
    int age = positiv_number("Please enter your age: ");
    bool licens = boolian_input("Do you have a licens driver? (enter 0 or 1): ");
    print(age, licens);
    return 0;
}
