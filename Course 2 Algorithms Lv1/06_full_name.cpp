
#include <iostream>

using namespace std;

string read_text(string massage)
{
    string text;
    cout << massage;
    cin >> text;
    return text;
}

void print(string first, string last)
{
    cout << "\n Welcom " + first << " " + last << endl << endl;
}

int main()

{
    string first_name = read_text("\n Please enter your first name: ");
    string last_name = read_text("\n Please enter your last name: ");
    print(first_name, last_name);
    return 0;
}
