
#include <iostream>
#include <limits>

using namespace std;

short positiv_number(string massage)
{
    short number = 0;
    do
    {
        cout << massage;
        cin >> number;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            cout << "Please Tray Again: ";
            cin >> number;
        }
    } while (number < 500);
    return number;
}

bool is_leap_year(short year)
{
    if (year % 400 == 0)
    {
        return true;
    }
    else if (year % 4 == 0 && year % 100 != 0)
    {
        return true;
    }
    else
        return false;
}

void print_result(short year)
{
    if (is_leap_year(year))
        cout << "Yes, Year [" << year << "] It's Leap Year" << endl;
    else
        cout << "No, Year [" << year << "] It's Not Leap Year" << endl;

}

int main()
{
    short year = positiv_number("Please Enter a Year: ");
    print_result(year);
    return 0;
}
