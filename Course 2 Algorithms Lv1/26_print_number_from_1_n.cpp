
#include <iostream>

using namespace std;

int positiv_number(string massage)
{
    int number = 0;
    do
    {
        cout << massage;
        cin >> number;
    } while (number < 0);
    return number;
}

void print(int number)
{
    for(int counter = 1; counter <= number; counter++)
    {
        cout << endl << "Sob7an Allah " << counter << endl;
    }
}

int main()
{
    int N = positiv_number("Please enter to count up: ");
    print(N);
    return 0;
}
