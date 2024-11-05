
#include <iostream>
#include <string>

using namespace std;

string read_text(string massage)
{
    string text;
    cout << massage;
    getline(cin, text);
    return text;
}

void first_letter()
{
    string name = read_text("Please Enter Your Name: ");
    bool is_first = true;
    for (short i = 0; i < name.length(); i++)
    {
        if (name[i] != ' ' && is_first)
        {
            cout << "- " << name[i] << endl;
        }
        is_first = (name[i] == ' ' ? true : false);
    }
}

int main()
{
    first_letter();
    return 0;
}
