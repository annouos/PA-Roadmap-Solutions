#include <iostream>
#include "#library_8_date.h"

using namespace std;
using namespace confidate;

bool is_valid_date(info self)
{
    if (self.day < 1 || self.day > 31)
        return false;
    else if (self.month < 1 || self.month > 12)
        return false;
    else if (self.month == 2)
    {
        if (is_leap_year(self.year))
        {
            if (self.day > 29)
                return false;
        }
        else
        {
            if (self.day > 28)
                false;
        }
    }
    short days_month = days_in_month(self.month, self.year);
    if (self.day > days_month)
        return false;
    
    return true;
}

void print_valid_date()
{
    info self = read_data();
    if (confidate::is_valid_date(self))
        cout << "Yes, is valid date" << endl;
    else
        cout << "No, is NOT valid date" << endl;
}

int main()
{
    print_valid_date();
    return 0;
}