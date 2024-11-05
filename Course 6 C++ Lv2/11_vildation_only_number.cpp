
#include <iostream>
#include <limits>

using namespace std;

int read_number()
{
    int number = 0;
    cout << "Please enter a number, nothing else: ";
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

int main()
{
    cout << "The Number is: " << read_number() << endl;
    return 0;
}
