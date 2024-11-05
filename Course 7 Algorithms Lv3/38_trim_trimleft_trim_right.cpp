
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

string read_string(string massage)
{
    string text;
    cout << massage;
    getline(cin, text);
    return text;
}

string trim_left(string text)
{
    for (short i = 0; i < text.length(); i++)
    {
        if (text[i] != ' ')
        {
            return text.substr(i, text.length() - i);
        }
    }
    return "";
}

string trim_right(string text)
{
    for (short i = text.length() -1; i >= 0; i--)
    {
        if (text[i] != ' ')
        {
            return text.substr(0, i + 1);
        }
    }
    return "";
}

string trim_all(string text)
{
    return  trim_left(trim_right(text));
}

int main()
{
    string text = read_string("Please enter a massage: ");
    cout << "The left: " << trim_left(text) << "|" << endl;
    cout << "The right: " << trim_right(text) << "|" << endl;
    cout << "The all: " << trim_all(text) << "|" << endl;
    return 0;
}
