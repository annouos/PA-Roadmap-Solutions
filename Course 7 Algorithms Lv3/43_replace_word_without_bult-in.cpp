
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

string lower_all(string text)
{
    for (short i = 0; i < text.length(); i++)
    {
        text[i] = tolower(text[i]);
    }
    return text;
}

vector <string> split_word(string text, string delimiter)
{
    vector <string> favorite;

    short pos = 0;
    string word;

    while ((pos = text.find(delimiter)) != std::string::npos)
    {
        word = text.substr(0, pos);
        if (word != "")
        {
            favorite.push_back(word);
        }
        text.erase(0, pos + delimiter.length());
    }
    if (text != "")
    {
        favorite.push_back(text);
    }
    return favorite;
}

string join_word(vector <string> self, string delimiter)
{
    string text;
    for (string &x : self)
    {
        text += x + delimiter;
    }

    return text.substr(0, text.length() - delimiter.length());
}

string replace_custom(string text, string orgi, string repl, bool match_case = true)
{
    vector <string> self = split_word(text, " ");

    for (string &x : self)
    {
        if (match_case)
        {
            if (x == orgi)
            {
                x = repl;
            }
        }
        else
        {
            if (lower_all(x) == lower_all(orgi))
            {
                x = repl;
            }
        }
    }
    return join_word(self, " ");
}

int main()
{
    string welcom = "Welcom to Yemen, Yemen it's a nice country";
    cout << welcom << endl;
    string orginal = read_string("Please Enter the orginal: ");
    string replace = read_string("Please Enter the replace: ");
    cout << replace_custom(welcom, orginal, replace) << endl;
    cout << replace_custom(welcom, orginal, replace, false) << endl;
    return 0;
}
