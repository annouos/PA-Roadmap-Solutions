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

short days_in_year(short year)
{
    return is_leap_year(year) ? 366 : 365;
}

short days_in_month(short month, short year) // necessary for problem decrease one month by teacher, but not for best sulotion forever.
{
    if(month < 1 || month > 12)
        return 0;
    int ray[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return (month == 2) ? (is_leap_year(year) ? 29 : 28) : ray[month - 1];
}

short day_in_week(short day, short month, short year) // it has overload
{
    short a, y, m;
    a = (14 - month) / 12;
    y = year - a;
    m = month + (12 * a) - 2;
    return (day + y + (y/4) - (y/100) + (y/400) + ((31 * m) / 12)) % 7; // Gregorian Calender start week wiht Dimanch
    // return (5 + day + y + (y/4) + ((31 * m) / 12)) % 7; // Julian Calender start week with Lundi
}

short day_in_week(info self) // overload (strong way from teacher)
{
    return day_in_week(self.day, self.month, self.year);
}

string short_day(short day)
{
    string ray[7] = {"Dim", "Lun", "Mar", "Mer", "Jeu", "Van", "Sam"};
    return ray[day];
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

info get_system_date()
{
    info self;

    time_t t = time(0);
    tm* now = localtime(&t);

    self.year = now->tm_year + 1900;
    self.month = now->tm_mon + 1;
    self.day = now->tm_mday;

    return self;
}

bool is_it_end_of_week(info self)
{
    return day_in_week(self) == 5;
}

bool is_it_weekend(info self)
{
    short day = day_in_week(self);
    return (day == 4 || day == 5);
}

bool is_it_business_day(info self)
{
    // short day = day_in_week(self);
    // return !(day == 5 || day == 6);
    return !is_it_weekend(self);
}

short days_until_end_of_week(info self)
{
    short days = day_in_week(self);
    return 5 - days;
}

short days_until_end_of_month(info self)
{
    short month = days_in_month(self.month, self.year);
    return month - self.day;
}

short days_until_end_of_year(info selfo)
{
    info selfa;
    selfa.day = 1;
    selfa.month = 1;
    selfa.year = selfo.year;

    short days = get_deffrintes_days(selfa, selfo, true);
    short year = days_in_year(selfo.year);
    return year - days;
}

void print_today_now(info self)
{
    short today = day_in_week(self);
    cout << "Today is " << short_day(today) << " , " << self.day << "/" << self.month << "/" << self.year << endl;
}

void print_is_it_end_of_week(info self)
{
    if (is_it_end_of_week(self))
        cout << "Yes, It's End of week \n";
    else
        cout << "No, It's not End of week \n";
}

void print_is_it_weekend(info self)
{
    if (is_it_weekend(self))
        cout << "Yes, It's a Weekend \n";
    else
        cout << "No, It's not a Weekend \n";
}

void print_is_it_business_day(info self)
{
    if (is_it_business_day(self))
        cout << "Yes, It's a Business day \n";
    else
        cout << "No, It's not a Business day \n";
}

void print_days_until_end_of_week(info self)
{
    cout << "Days until end of Week is: " << days_until_end_of_week(self) << " Day(s).\n";
}

void print_days_until_end_of_month(info self)
{
    cout << "Days until end of Month is: " << days_until_end_of_month(self) << " Day(s).\n";
}

void print_days_until_end_of_year(info self)
{
    cout << "Days until end of Year is: " << days_until_end_of_year(self) << " Day(s).\n";
}

int main()
{
    info self = get_system_date();

    print_today_now(self);
    print_is_it_end_of_week(self);
    print_is_it_weekend(self);
    print_is_it_business_day(self);
    print_days_until_end_of_week(self);
    print_days_until_end_of_month(self);
    print_days_until_end_of_year(self);

    return 0;
}
