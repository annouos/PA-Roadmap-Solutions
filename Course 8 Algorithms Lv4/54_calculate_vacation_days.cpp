#include <iostream>
#include <limits>
#include "#library_8_date.h"

using namespace std;
using namespace confidate;

void print_today_now(info self)
{
    short today = day_in_week(self);
    cout << "Today is " << short_day(today) << " , " << self.day << "/" << self.month << "/" << self.year << endl;
}

void print_vacation_days()
{
    cout << "Vacation Starts on: \n";
    info date_from = read_data();
    cout << "Vacation Ends on: \n";
    info date_to = read_data();
    cout << endl;
    print_today_now(date_from);
    print_today_now(date_to);
    short vacation = confidate::actucal_vacation_day(date_from, date_to); // it is the function for this the course
    cout << "Total Actucal Vacation is: " << vacation << " Days" << endl;
}

int main()
{
    print_vacation_days();
    return 0;
}


// without library:


// #include <iostream>
// #include <limits>

// using namespace std;

// struct info
// {
//     short year = 0;
//     short month = 0;
//     short day = 0;
// };

// short positive_number(string massege)
// {
//     short number = 0;
//     cout << massege;
//     cin >> number;

//     while (cin.fail())
//     {
//         cin.clear();
//         cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

//         cout << "Please Tray Again: ";
//         cin >> number;
//     }
//     return number;
// }

// info read_data()
// {
//     info self;
//     self.day = positive_number("Enter The Day: ");
//     self.month = positive_number("Enter The Month: ");
//     self.year = positive_number("Enter The Year: ");

//     return self;
// }

// bool is_leap_year(short year)
// {
//     return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
// }

// short days_in_month(short month, short year)
// {
//     if(month < 1 || month > 12)
//         return 0;
//     int ray[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//     return (month == 2) ? (is_leap_year(year) ? 29 : 28) : ray[month - 1];
// }

// short day_in_week(short day, short month, short year) // it has overload
// {
//     short a, y, m;
//     a = (14 - month) / 12;
//     y = year - a;
//     m = month + (12 * a) - 2;
//     return (day + y + (y/4) - (y/100) + (y/400) + ((31 * m) / 12)) % 7; // Gregorian Calender start week wiht Dimanch
//     // return (5 + day + y + (y/4) + ((31 * m) / 12)) % 7; // Julian Calender start week with Lundi
// }

// short day_in_week(info self) // overload (strong way from teacher)
// {
//     return day_in_week(self.day, self.month, self.year);
// }

// string short_day(short day)
// {
//     string ray[7] = {"Dim", "Lun", "Mar", "Mer", "Jeu", "Van", "Sam"};
//     return ray[day];
// }

// bool similar_day(info self)
// {
//     return (self.day == days_in_month(self.month, self.year) ? true : false);
// }

// bool similar_month(short number)
// {
//     return (number == 12);
// }

// info increase_one_day(info self)
// {
//     if (similar_day(self))
//     {
//         if (similar_month(self.month))
//         {
//             self.day = 1;
//             self.month = 1;
//             self.year++;
//         }
//         else
//         {
//             self.day = 1;
//             self.month++;
//         }
//     }
//     else
//         self.day++;
//     return self;
// }

// bool is_it_equal_date(info self_1, info self_2)
// {
//     return (self_1.year < self_2.year) ? true : ((self_1.year == self_2.year && self_1.month < self_2.month) ? true : ((self_1.month == self_2.month && self_1.day < self_2.day) ? true : false));
// }

// void print_today_now(info self)
// {
//     short today = day_in_week(self);
//     cout << "Today is " << short_day(today) << " , " << self.day << "/" << self.month << "/" << self.year << endl;
// }

// void print_vacation_days()
// {
//     cout << "Vacation Starts on: \n";
//     info date_from = read_data();
//     cout << "Vacation Ends on: \n";
//     info date_to = read_data();
//     cout << endl;
//     print_today_now(date_from);
//     print_today_now(date_to);
//     short vacation = actucal_vacation_day(date_from, date_to);
//     cout << "Total Actucal Vacation is: " << vacation << " Days" << endl;
// }

// int main()
// {
//     print_vacation_days();
//     return 0;
// }
