
#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

short positiv_number(string massage)
{
    short number = 0;
    do
    {
        cout << massage;
        cin >> number;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            cout << "Please Tray Again: ";
            cin >> number;
        }
    } while (number < 0);
    return number;
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

short days_in_week(short day, short month, short year)
{
    short a, y, m;
    a = (14 - month) / 12;
    y = year - a;
    m = month + (12 * a) - 2;
    return (day + y + (y/4) - (y/100) + (y/400) + ((31 * m) / 12)) % 7; // Gregorian Calender start week wiht Dimanch
    // return (5 + day + y + (y/4) + ((31 * m) / 12)) % 7; // Julian Calender start week with Lundi
}

string short_month(short month)
{
    string ray[12] = {"Jan", "Feb", "Mar", "Apr", "Mai", "Jun", "Jui", "Aou", "Sep", "Oct", "Nov", "Dec"};
    return ray[month-1];
}

string short_day(short day)
{
    string ray[7] = {"Dim", "Lun", "Mar", "Mer", "Jeu", "Van", "Sam"};
    return ray[day];
}

void print_month_calender(short month, short year)
{
    short num_day = days_in_month(month, year);
    short current = days_in_week(1, month, year);

    printf("\n _______________%s__________________\n\n", short_month(month).c_str());
    cout << "  Dim  Lun  Mar  Mer  Jeu  Van  Sam" << endl;

    short i;

    for (i = 0; i < current; i++)
    {
        printf("     ");
    }

    for (short j = 1; j <= num_day; j++)
    {
        printf("%5d", j);

        if (++i == 7)
        {
            i = 0;
            printf("\n");
        }
    }
    printf("\n ____________________________________\n");
}

void print_year_calender(short year)
{
    cout << "\n ------------------------------------\n";
    cout << "          Calender - " << year << endl;
    cout << " ------------------------------------\n";
    for (short i = 1; i <= 12; i++)
    {
        print_month_calender(i, year);
        cout << endl;
    }
}

int main()
{
    short year = positiv_number("Please Enter a Year: ");
    print_year_calender(year);
    return 0;
}
