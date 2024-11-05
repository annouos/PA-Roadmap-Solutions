#include <iostream>
#include <limits>
#include "#library_8_date.h"

using namespace std;
using namespace confidate;


int overlap_days(period perio_1, period perio_2) // This Fun Sulotion By Teacher Sadly
{
    int peri_length_1 = period_lenght(perio_1, true);
    int peri_length_2 = period_lenght(perio_2, true);
    int count_days = 0;

    if (!is_over_lap(perio_1, perio_2))
        return 0;

    if (peri_length_1 < peri_length_2)
    {
        while (is_date_less_than_other(perio_1.start, perio_1.end))
        {
            if (is_date_within_period(perio_1.start, perio_2))
                count_days++;
            perio_1.start = increase_one_day(perio_1.start);
        }
    }
    else
    {
        while (is_date_less_than_other(perio_2.start, perio_2.end))
        {
            if (is_date_within_period(perio_2.start, perio_1))
                count_days++;
            perio_2.start = increase_one_day(perio_2.start);
        }
    }
    return count_days;
}

// int overlap_days(period perio_1, period perio_2) // if the period one is the longest days? 
// {
//     int count_days = 0;
//     while (is_date_within_period(perio_2.start, perio_1))
//     {
//         count_days++;
//         perio_2.start = increase_one_day(perio_2.start);
//     }
//     return count_days;
// }

void print_overlap_days()
{
    cout << "Enter Period One: \n";
    period perio_1 = read_data_period();
    cout << "Enter Period Tow: \n";
    period perio_2 = read_data_period();

    cout << "Overlap Days Count is: " << confidate::overlap_days(perio_1, perio_2) << endl;
}


int main()
{
    print_overlap_days();
    return 0;
}
