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

bool is_it_equal_date(info self_1, info self_2)
{
    return (self_1.year == self_2.year && self_1.month == self_2.month && self_1.day == self_2.day) ? true : false;
}

void print_date(info self_1, info self_2)
{
    if (is_it_equal_date(self_1, self_2))
        cout << "The date one equal date tow";
    else
        cout << "The date one is not equal date tow";
}

int main()
{
    info Dat_one = read_data();
    info Dat_tow = read_data();
    print_date(Dat_one, Dat_tow);
    return 0;
}
