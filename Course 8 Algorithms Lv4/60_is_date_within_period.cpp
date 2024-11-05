
#include <iostream>
#include <limits>
#include "#library_8_date.h"

using namespace std;
using namespace confidate;

bool is_date_within_period(info self, period perio)
{
    return !(compare_dates(self, perio.start) == eninfo::before || compare_dates(self, perio.end) == eninfo::after);
}

void print_date_within_period()
{
    cout << "Enter The Period: \n";
    period perio = confidate::read_data_period();
    cout << "Enter a date to check: \n";
    info self = read_data();

    if (confidate::is_date_within_period(self, perio))
        cout << "Yes, Date within a period \n";
    else
        cout << "No, Date is not within a period \n";
}

int main()
{
    print_date_within_period();
    return 0;
}
