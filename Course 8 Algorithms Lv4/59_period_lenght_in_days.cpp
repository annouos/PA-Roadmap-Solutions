
#include <iostream>
#include <limits>
// #include "#library_8_date.h"

using namespace std;
// using namespace confidate;

struct info
{
    short year = 0;
    short month = 0;
    short day = 0;
};

struct period
{
    info start;
    info end;
};

short positive_number(string massege)
{
    short number = 0;
    cout << massege << endl;
    cin >> number;

    while (cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        cout << "Please Tray Again: ";
        cin >> number;
    }
    return number;
}

info read_data()
{
    info self;
    self.day = positive_number("Please Enter The Day: ");
    self.month = positive_number("Please Enter The Month: ");
    self.year = positive_number("Please Enter The Year: ");

    return self;
}

period read_data_period()
{
    period self;
    cout << "Enter Start Date: \n";
    self.start = read_data();
    cout << "Enter End Date: \n";
    self.end = read_data();
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

bool similar_day(info self)
{
    return (self.day == days_in_month(self.month, self.year) ? true : false);
}

bool similar_month(short number)
{
    return (number == 12);
}

info increase_one_day(info self)
{
    if (similar_day(self))
    {
        if (similar_month(self.month))
        {
            self.day = 1;
            self.month = 1;
            self.year++;
        }
        else
        {
            self.day = 1;
            self.month++;
        }
    }
    else
        self.day++;
    return self;
}

bool is_it_equal_date(info self_1, info self_2)
{
    return (self_1.year < self_2.year) ? true : ((self_1.year == self_2.year && self_1.month < self_2.month) ? true : ((self_1.month == self_2.month && self_1.day < self_2.day) ? true : false));
}

int get_deffrintes_days(info self_1, info self_2, bool increase = false)
{
    int days = 0;
    while (is_it_equal_date(self_1, self_2))
    {
        days++;
        self_1 = increase_one_day(self_1);
    }
    return increase ? ++days : days;
}

int period_lenght(period perio, bool increase = false)
{
    return get_deffrintes_days(perio.start, perio.end, increase);
}

void print_period_lenght(period perio)
{
    cout << "Period lenght is: " << period_lenght(perio) << endl; //confidate:: the result = 0
    cout << "Period increase lenght is: " << period_lenght(perio, true) << endl; //confidate:: the result = 0
}

int main()
{
    period perio = read_data_period();
    print_period_lenght(perio);
    return 0;
}
