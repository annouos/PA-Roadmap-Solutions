
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
    } while (number < 0);
    return number;
}

bool is_leap_year(short year)
{
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

short days_in_month(short month, short year)
{
    if(month < 1 || month > 12)
        return 0;
    if (month == 2)
    {
        return is_leap_year(year) ? 29 : 28;
    }

    short ray_days[7] = {1, 3, 5, 7, 8, 10, 12};

    for (short i = 1; i <= 7; i++)
    {
        if (ray_days[i-1] == month)
            return 31;
    }
    return 30;
}

short hours_in_month(short month, short year)
{
    return days_in_month(month, year) * 24;
}

int minutes_in_month(short month, short year)
{
    return hours_in_month(month, year) * 60;
}

int seconds_in_month(short month, short year)
{
    return minutes_in_month(month, year) * 60;
}

int main()
{
    short year = positiv_number("Please Enter a Year: ");
    short month = positiv_number("Please Enter a Month: ");
    cout << "Days: " << days_in_month(month, year) << endl;
    cout << "Hours: " << hours_in_month(month, year) << endl;
    cout << "Minutes: " << minutes_in_month(month, year) << endl;
    cout << "Seconds: " << seconds_in_month(month, year) << endl;
    return 0;
}
