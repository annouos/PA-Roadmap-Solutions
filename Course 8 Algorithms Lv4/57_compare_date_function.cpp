#include <iostream>
#include <limits>
#include "#library_8_date.h"

using namespace std;
using namespace confidate;

// enum eninfo {before = -1, equal = 0, after = 1};

eninfo compare_dates(info self_1, info self_2)
{
    if (is_date_less_than_other(self_1, self_2))
        return eninfo::before;
    else if (is_it_equal_date(self_1, self_2))
        return eninfo::equal;
    else
        return eninfo::after;
    
    // return eninfo::after;                    // this is faster like teacher sayed.
}

// i don't need a switch to show the result of enum.. imagin that.

// short result_compare_dates(info self_1, info self_2)
// {
//     eninfo self = compare_dates(self_1, self_2);

//     switch (self)
//     {
//         case eninfo::before :
//         return -1;
//         case eninfo::equal :
//         return 0;
//         case eninfo::after :
//         return 1;
//         default:
//         return 0.000007;
//     }
// }

int main()
{
    info date_one = read_data();
    info date_tow = read_data();
    cout << "Compare Result dates is: " << confidate::compare_dates(date_one, date_tow) << endl;
    // cout << "Compare Result dates is: " << result_compare_dates(date_one, date_tow);
    return 0;
}