
#include <iostream>

using namespace std;

string read(string massage)
{
    string text;
    cout << massage;
    cin >> text;
    return text;
}

bool login()
{
    string pin; int counter = 0;
    do
    {
        pin = read("Please enter your PIN: ");
        if(pin == "1234")
            return 1;
        counter++;
    } while (pin != "1234" && counter < 3);
    return 0;
}

void print()
{
    if(login())
        cout << "Your Balance is: 7000" << endl;
    else
        cout << "You are Theefir !! " << endl;
}

int main()
{
    print();
    return 0;
}
