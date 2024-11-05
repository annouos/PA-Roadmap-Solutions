
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

string lower_all(string text)
{
    bool is_first = true;
    for (short i = 0; i < text.length(); i++)
    {
        text[i] = tolower(text[i]);
    }
    return text;
}

string upper_all(string text)
{
    bool is_first = true;
    for (short i = 0; i < text.length(); i++)
    {
        text[i] = toupper(text[i]);
    }
    return text;
}

int main()
{
    string name = read_text("Please Enter Your Name: ");
    name = lower_all(name);
    cout << name << endl;
    name = upper_all(name);
    cout << name << endl;
    system("pause>0");
}
