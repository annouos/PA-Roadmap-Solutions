
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
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

short days_in_year(short year)
{
    return is_leap_year(year) ? 366 : 365;
}

short hours_in_year(short year)
{
    return days_in_year(year) * 24;
    // return check_year(number) ? 366 * 24 : 365 * 24;
}

short minutes_in_year(short year)
{
    return hours_in_year(year) * 60;
    // return check_year(number) ? 366 * 24 * 60 : 365 * 24 * 60;
}

int seconds_in_year(short year)
{
    return minutes_in_year(year) * 60;
    // return check_year(number) ? 366 * 24 * 60 * 60 : 365 * 24 * 60 * 60;
}

int main()
{
    short year = positiv_number("Please Enter a Year: ");
    cout << days_in_year(year) << endl;
    cout << hours_in_year(year) << endl;
    cout << minutes_in_year(year) << endl;
    cout << seconds_in_year(year) << endl;
    return 0;
}
