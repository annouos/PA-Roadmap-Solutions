
#include <iostream>

using namespace std;

struct info {
    int days, hours, minute, second;
};

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

info times()
{
    info self;
    self.days = read("Please enter the days: ");
    self.hours = read("Please enter the hours: ");
    self.minute = read("Please enter the minutees: ");
    self.second = read("Please enter the seconds: ");
    return self;
}

float proces(info self)
{
    int total_seconds = 0;
    total_seconds = self.days * 24 * 60 * 60;
    total_seconds += self.hours * 60 * 60;
    total_seconds += self.minute * 60;
    total_seconds += self.second;

    return (float) total_seconds;
}

void print(float seconds)
{
    cout << "Task in duration in seconds: " << seconds << endl;
}

int main()

{
    print(proces(times()));
    return 0;
}
