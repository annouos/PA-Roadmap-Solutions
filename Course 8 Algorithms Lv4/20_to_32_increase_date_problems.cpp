#include <iostream>
#include <limits>

using namespace std;

struct info
{
    short year = 0;
    short month = 0;
    short day = 0;
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

bool is_leap_year(short year)
{
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

short days_in_month(short month, short year) // necessary for problem increase one month by teacher, but not for best sulotion forever.
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

info increase_x_day(short days, info self)
{
    for (short i = 1; i <= days; i++)
    {
        self = increase_one_day(self);
    }
    return self;
}

info increase_one_week(info self)
{
    for (short i = 1; i <= 7; i++)
    {
        self = increase_one_day(self);
    }
    return self;
}

info increase_x_week(short week, info self)
{
    for (short i = 1; i <= week; i++)
    {
        self = increase_one_week(self);
    }
    return self;
}

info increase_one_month(info self) // best sulotion forever.
{
    for (short i = 1; i <= 30; i++)
    {
        self = increase_one_day(self);
    }
    return self;
}

// info increase_one_month(info self) // teacher sulotion.
// {
//     if (self.month == 12)
//     {
//         self.month = 1;
//         self.year++;
//     }
//     else
//     {
//         self.month++;
//     }

//     //last check day in date should not exceed max days in the current month
//     // example if date is 31/1/2022 increasing one month should not be 31 / 2 / 2022, it should be 28/2/2022.

//     short number_day_in_current_month = days_in_month(self.month, self.year);
//     if (self.day > number_day_in_current_month)
//     {
//         self.day = number_day_in_current_month;
//     }
//     return self;
// }

info increase_x_month(short month, info self)
{
    for (short i = 1; i <= month; i++)
    {
        self = increase_one_month(self);
    }
    return self;
}

info increase_one_year(info self)
{
    self.year++;
    return self;
}

info increase_x_year(short year, info self)
{
    for (short i = 1; i <= year; i++)
    {
        self = increase_one_year(self);
    }
    return self;
}

info increase_x_year_faster(short year, info self)
{
    self.year += year;
    return self;
}

info increase_one_decade(info self)
{
    self.year += 10;
    return self;
}

info increase_x_decade(short decade, info self)
{
    for (short i = 1; i <= decade; i++)
    {
        self = increase_one_decade(self);
    }
    return self;
}

info increase_x_decade_faster(short decade, info self)
{
    self.year += (decade * 10);
    return self;
}

info increase_one_century(info self)
{
    self.year += 100;
    return self;
}

info increase_one_millenuim(info self)
{
    self.year += 1000;
    return self;
}

void print_increase_x_day(info selfo)
{
    info self = increase_x_day(10, selfo);
    cout << "Date after adding ten days is: " << self.day << "/" << self.month << "/" << self.year << endl;
}

void print_increase_one_week(info selfo)
{
    info self = increase_one_week(selfo);
    cout << "Date after adding a week is: " << self.day << "/" << self.month << "/" << self.year << endl;
}

void print_increase_x_week(info selfo)
{
    info self = increase_x_week(4, selfo);
    cout << "Date after adding four weeks is: " << self.day << "/" << self.month << "/" << self.year << endl;
}

void print_increase_one_month(info selfo)
{
    info self = increase_one_month(selfo);
    cout << "Date after adding a month is: " << self.day << "/" << self.month << "/" << self.year << endl;
}

void print_increase_x_month(info selfo)
{
    info self = increase_x_month(3, selfo);
    cout << "Date after adding three months is: " << self.day << "/" << self.month << "/" << self.year << endl;
}

void print_increase_one_year(info selfo)
{
    info self = increase_one_year(selfo);
    cout << "Date after adding a year is: " << self.day << "/" << self.month << "/" << self.year << endl;
}

void print_increase_x_year(info selfo)
{
    info self = increase_x_year(6, selfo);
    cout << "Date after adding six years is: " << self.day << "/" << self.month << "/" << self.year << endl;
}

void print_increase_x_year_faster(info selfo)
{
    info self = increase_x_year_faster(8, selfo);
    cout << "Date after adding eight years (faster) is: " << self.day << "/" << self.month << "/" << self.year << endl;
}

void print_increase_one_decade(info selfo)
{
    info self = increase_one_decade(selfo);
    cout << "Date after adding a decade is: " << self.day << "/" << self.month << "/" << self.year << endl;
}

void print_increase_x_decade(info selfo)
{
    info self = increase_x_decade(5, selfo);
    cout << "Date after adding five decades is: " << self.day << "/" << self.month << "/" << self.year << endl;
}

void print_increase_x_decade_faster(info selfo)
{
    info self = increase_x_decade_faster(9, selfo);
    cout << "Date after adding nine decades (faster) is: " << self.day << "/" << self.month << "/" << self.year << endl;
}

void print_increase_one_century(info selfo)
{
    info self = increase_one_century(selfo);
    cout << "Date after adding a century is: " << self.day << "/" << self.month << "/" << self.year << endl;
}

void print_increase_one_millenuim(info selfo)
{
    info self = increase_one_millenuim(selfo);
    cout << "Date after adding a millenuim is: " << self.day << "/" << self.month << "/" << self.year << endl;
}

int main()
{
    info self = read_data();

    cout << "After Adding: \n" << endl;

    print_increase_x_day(self);
    print_increase_one_week(self);
    print_increase_x_week(self);
    print_increase_one_month(self);
    print_increase_x_month(self);
    print_increase_one_year(self);
    print_increase_x_year(self);
    print_increase_x_year_faster(self);
    print_increase_one_decade(self);
    print_increase_x_decade(self);
    print_increase_x_decade_faster(self);
    print_increase_one_century(self);
    print_increase_one_millenuim(self);

    return 0;
}
