#include <iostream>
#include <limits>
#include "#library_8_date.h"

using namespace std;
using namespace confidate;

bool is_date_after_other(info self_1, info self_2)
{
    return (!is_date_less_than_other(self_1, self_2) && !is_it_equal_date(self_1, self_2));
}

void print_date(info self_1, info self_2)
{
    if (confidate::is_date_after_other(self_1, self_2))
        cout << "The date one after the date tow";
    else
        cout << "The date one is not after the date tow, It's before";
}

int main()
{
    info date_one = read_data();
    info date_tow = read_data();
    print_date(date_one, date_tow);
    return 0;
}