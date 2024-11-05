
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

bool check_wasta(bool wasta)
{
    return wasta == 1;
}

bool check_licens(int age, bool licens)
{
    return age > 21 && licens == 1;
}

void print(bool wasta, int number, bool licens)
{
    if (check_wasta(wasta))
        cout << "Hired " << endl;
    else if(check_licens(number, licens))
        cout << "Hired too " << endl;
    else
        cout << "Rejected " << endl;
}

int main()
{
    bool wasta = boolian_input("Do you have a Wasta: ");
    if(wasta)
        print(wasta, 0, 0);
    else
    {
        int age = positiv_number("Please enter your age: ");
        bool licens = boolian_input("Do you have a licens driver? (enter 0 or 1): ");
        print(0, age, licens);
    }
    return 0;
}
