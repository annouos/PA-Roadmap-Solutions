
#include <iostream>
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

short day_in_week(short day, short month, short year)
{
    short a, y, m;
    a = (14 - month) / 12;
    y = year - a;
    m = month + (12 * a) - 2;
    return (day + y + (y/4) - (y/100) + (y/400) + ((31 * m) / 12)) % 7; // Gregorian Calender start week wiht Dimanch
    // return (5 + day + y + (y/4) + ((31 * m) / 12)) % 7; // Julian Calender start week with Lundi
}

string short_day(short day)
{
    string ray[7] = {"Dim", "Lun", "Mar", "Mer", "Jeu", "Van", "Sam"};
    return ray[day];
}

void print_date(short day, short month, short year)
{
    short today = day_in_week(day, month, year);
    cout << "Date       : " << day << "/" << month << "/" << year << endl;
    cout << "Day Order  : " << today + 1 << endl;
    cout << "Day Name   : " << short_day(today) << endl;
}

int main()
{
    short year = positiv_number("Please Enter a Year: ");
    short month = positiv_number("Please Enter a Month: ");
    short day = positiv_number("Please Enter a Day: ");
    print_date(day, month, year);
    return 0;
}
