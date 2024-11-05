
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

string read_string(string massage)
{
    string text;
    cout << massage;
    getline(cin, text);
    return text;
}

string replace_word(string text, string orgi, string repl)
{
    short pos = text.find(orgi);
    while (pos != std::string::npos)
    {
        text = text.replace(pos, orgi.length(), repl);
        pos = text.find(orgi);
    }
    return text;
}

int main()
{
    string welcom = "Welcom to Yemen, Yemen it's a nice country";
    cout << welcom << endl;
    string orginal = read_string("Please Enter the orginal: ");
    string replace = read_string("Please Enter the replace: ");
    cout << replace_word(welcom, orginal, replace) << endl;
    return 0;
}
