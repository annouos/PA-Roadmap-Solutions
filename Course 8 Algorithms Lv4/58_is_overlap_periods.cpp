
#include <iostream>
#include "#library_8_date.h"

using namespace std;
using namespace confidate;

// struct period
// {
//     info start;
//     info end;
// };

period read_data_period()
{
    period self;
    cout << "Enter Start Date: \n";
    self.start = read_data();
    cout << "Enter End Date: \n";
    self.end = read_data();
    return self;
}

bool is_over_lap(period self_1, period self_2)
{
    if (
        compare_dates(self_2.end, self_1.start) == eninfo::before
        ||
        compare_dates(self_2.start, self_1.end) == eninfo::after
        )
        return false;
    else
        return true; 
}

void print_period()
{
    cout << "Enter a Period One: \n";
    period perio_1 = confidate::read_data_period();
    cout << "Enter a Period Tow: \n";
    period perio_2 = confidate::read_data_period();

    if (confidate::is_over_lap(perio_1, perio_2))
        cout << "Yes, Periods Over Lap \n";
    else
        cout << "No, Periods Not Over Lap \n";
}


int main()
{
    print_period();
    return 0;
}
