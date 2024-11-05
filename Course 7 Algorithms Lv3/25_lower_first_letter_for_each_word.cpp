
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string read_text(string massage)
{
    string text;
    cout << massage;
    getline(cin, text);
    return text;    
}

string lower_first(string text)
{
    bool is_first = true;
    for (short i = 0; i < text.length(); i++)
    {
        if (text[i] != ' ' && is_first)
        {
            text[i] = tolower(text[i]);
        }
        is_first = (text[i] == ' ' ? true : false);
    }
    return text;
}

int main()
{
    string name = read_text("Please Enter Your Name: ");
    name = lower_first(name);
    cout << name << endl;
    return 0;
}
