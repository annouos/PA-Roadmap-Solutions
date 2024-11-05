
#include <iostream>

using namespace std;

string genric_number(string massage)
{
    string name;
    cout << massage;
    getline(cin, name);
    return name;
}

void print(string name)
{
    cout << endl << name << endl << endl;
}

int main() 
{
    string name = genric_number("Please enter your name: ");
    print(name);
    return 0;
}
