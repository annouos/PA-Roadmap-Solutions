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

void print_deffirents(info self_1, info self_2)
{
    cout << "The deffirents days are: " << get_deffrintes_days(self_1, self_2) << endl;
    cout << "The deffirents days plus current today are: " << get_deffrintes_days(self_1, self_2, true) << endl;
}

int main()
{
    info Dat_one = read_data();
    info Dat_tow = read_data();
    print_deffirents(Dat_one, Dat_tow);
    return 0;
}
