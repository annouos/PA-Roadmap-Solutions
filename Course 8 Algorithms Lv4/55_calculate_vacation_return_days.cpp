#include <iostream>
#include <limits>
#include "#library_8_date.h"

using namespace std;
using namespace confidate;


info return_vacation_date(info date_from, short vacation)
{
    short weekend_counter = 0;

    while (is_it_weekend(date_from))
    {
        date_from = increase_one_day(date_from);
    }

    for (short i = 1; i <= vacation + weekend_counter; i++)
    {
        if (is_it_weekend(date_from))
            weekend_counter++;
        
        date_from = increase_one_day(date_from);
    }

    while (is_it_weekend(date_from))
    {
        date_from = increase_one_day(date_from);
    }
    return date_from;
}

void print_today_now(info self)
{
    short today = day_in_week(self);
    cout << "Today is " << short_day(today) << " , " << self.day << "/" << self.month << "/" << self.year << endl;
}

void print_vacation_return_days()
{
    cout << "Vacation Starts on: \n";
    info date_from = read_data();
    short days = positive_number("Please Enter Vacation Days: ");

    info date_to = confidate::return_vacation_date(date_from, days); // confidate:: here, to do not disruption or ruplica with function on library.

    cout << endl;
    print_today_now(date_to);
}

int main()
{
    print_vacation_return_days();
    return 0;
}


// without namespace confidate but use confidate:: for any varible or struct on library.


// #include <iostream>
// #include <limits>
// #include "#library_8_date.h"

// using namespace std;


// confidate::info return__vacation_date(confidate::info date_from, short vacation)
// {
//     short weekend_counter = 0;

//     while (confidate::is_it_weekend(date_from))
//     {
//         date_from = confidate::increase_one_day(date_from);
//     }

//     for (short i = 1; i <= vacation + weekend_counter; i++)
//     {
//         if (confidate::is_it_weekend(date_from))
//             weekend_counter++;
        
//         date_from = confidate::increase_one_day(date_from);
//     }

//     while (confidate::is_it_weekend(date_from))
//     {
//         date_from = confidate::increase_one_day(date_from);
//     }
//     return date_from;
// }

// void print_today_now(confidate::info self)
// {
//     short today = confidate::day_in_week(self);
//     cout << "Today is " << confidate::short_day(today) << " , " << self.day << "/" << self.month << "/" << self.year << endl;
// }

// void print_vacation_return_days()
// {
//     cout << "Vacation Starts on: \n";
//     confidate::info date_from = confidate::read_data();
//     short days = confidate::positive_number("Please Enter Vacation Days: ");

//     confidate::info date_to = confidate::return__vacation_date(date_from, days);

//     cout << endl;
//     print_today_now(date_to);
// }

// int main()
// {
//     print_vacation_return_days();
//     return 0;
// }
