
#include <iostream>
#include <iomanip>
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
    int ray[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return (month == 2) ? (is_leap_year(year) ? 29 : 28) : ray[month - 1];
}

short days_from_begining(short year, short month, short day)
{
    short total_day = 0;

    for (short i = 1; i < month; i++)
    {
        total_day += days_in_month(i, year);
    }

    total_day += day;

    return total_day;
}

int main()
{
    short day = positiv_number("Please Enter a Day: ");
    short month = positiv_number("Please Enter a Month: ");
    short year = positiv_number("Please Enter a Year: ");
    cout << "Days from the begining of year is: " << days_from_begining(year, month, day) << endl;
    return 0;
}
