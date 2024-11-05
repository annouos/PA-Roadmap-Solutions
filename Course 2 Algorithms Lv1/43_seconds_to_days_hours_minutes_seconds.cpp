
#include <iostream>
#include <cmath>

using namespace std;

int read(string massage)
{
    int number;
    do
    {
        cout << massage;
        cin >> number;
    } while (number <= 0);
    return number;
}

struct info {
    int day, hour, minute, second;
};

info proces(int seconds)
{
    info self;
    const int seconds_in_day = 24 * 60 * 60;
    const int seconds_in_hour = 60 * 60;
    const int seconds_in_minute = 60;

    int remainder = 0;
    self.day = floor(seconds / seconds_in_day);
    remainder = seconds % seconds_in_day;
    self.hour = floor(remainder / seconds_in_hour);
    remainder = seconds % seconds_in_hour;
    self.minute = floor(remainder / seconds_in_minute);
    remainder = seconds % seconds_in_minute;
    self.second = remainder;
    return self;
}

void print(info self)
{
    cout << "Details in per second: "
    << self.day << ","
    << self.hour << ":"
    << self.minute << ":"
    << self.second << endl ;
}

int main()

{
    int total_seconds = read("Please enter the all time in seconds: ");
    print(proces(total_seconds));
    return 0;
}
