
#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

struct info
{
    short year = 0;
    short month = 0;
    short day = 0;
};

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

info get_order_day(short date_order, short year)
{
    info self;
    short remain_days = date_order;
    short month_days = 0;

    self.year = year;
    self.month = 1;

    while (true)
    {
        month_days = days_in_month(self.month, year);

        if (remain_days > month_days)
        {
            remain_days -= month_days;
            self.month++;
        }
        else
        {
            self.day = remain_days;
            break;
        }
    }

    return self;
}

void order_days()
{
    short day = positiv_number("Please Enter a Day: ");
    short month = positiv_number("Please Enter a Month: ");
    short year = positiv_number("Please Enter a Year: ");
    short days_order = days_from_begining(year, month, day);
    cout << "Days from the begining of year is: " << days_order << endl;

    info self;
    self = get_order_day(days_order, year);
    cout << "Date for [" << days_order << "] is: ";
    cout << self.day << "/" << self.month << "/" << self.year << endl;
}

int main()
{
    order_days();
    return 0;
} 
