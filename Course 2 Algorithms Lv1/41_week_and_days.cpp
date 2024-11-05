
#include <iostream>

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

float to_days(float num)
{
    return num / 24;
}

float days_to_week(float num)
{
    return num / 7;
}

float hours_to_week(float num)
{
    return num / 24 / 7;
}

void print(int number_1, int number_2)
{
    cout << "Total of days: " << number_1 << " days." << "\nTotal of weeks: " << number_2 << " weeks." << endl;
}


int main()

{
    float hours = read("Enter the hours: ");
    print(to_days(hours), hours_to_week(hours));
    return 0;
}
