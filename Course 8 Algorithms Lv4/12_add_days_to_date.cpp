
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

info read_full_struct()
{
    info self;

    self.day = positiv_number("Please Enter A Day: ");
    self.month = positiv_number("Please Enter A Month: ");
    self.year = positiv_number("Please Enter A Year: ");

    return self;
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

info date_add_days(short days, info self)
{
    short remaining_days = days + days_from_begining(self.year, self.month, self.day);
    short month_days = 0;

    self.month = 1;

    while (true)
    {
        month_days = days_in_month(self.month, self.year);

        if (remaining_days > month_days)
        {
            remaining_days -= month_days;
            self.month++;

            if (self.month > 12)
            {
                self.month = 1;
                self.year++;
            }
        }
        else
        {
            self.day = remaining_days;
            break;
        }
    }
    return self;
}

void print_add_days()
{
    info Date = read_full_struct();
    short Days = positiv_number("How many days to add ? ");

    Date = date_add_days(Days, Date);
    cout << "Date after adding [" << Days << "] days is: ";
    cout << Date.day << "/" << Date.month << "/" << Date.year << endl;
}

int main()
{
    print_add_days();
    return 0;
} 
