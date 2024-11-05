
#include <iostream>
#include <vector>
#include <string>
#include "#library_8_date.h"

using namespace std;
using namespace confidate;

vector <string> favorite;

vector <string> split_word(string text, string delimiter)
{
    short pos = 0;
    string word;
    vector <string> * self = &favorite; // big boss hahaha 

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

info string_to_date(string text)
{
    info self;
    vector <string> veto;

    veto = split_word(text, "/");
    self.day = stoi(veto[0]);
    self.month = stoi(veto[1]);
    self.year = stoi(veto[2]);

    return self;
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

string format_date(info self, string date = "dd/mm/yyyy")
{
    string format_data_string = "";

    format_data_string = replace_word(date, "dd", to_string(self.day));
    format_data_string = replace_word(format_data_string, "mm", to_string(self.month));
    format_data_string = replace_word(format_data_string, "yyyy", to_string(self.year));

    return format_data_string;
}

void print_string_date_opesit()
{
    string text = read_string("Please enter a date dd/mm/yyyy: ");
    info self = string_to_date(text);

    cout << format_date(self) << endl;
    cout << format_date(self, "yyyy/dd/mm") << endl;
    cout << format_date(self, "mm/dd/yyyy") << endl;
    cout << format_date(self, "mm-dd-yyyy") << endl;
    cout << format_date(self, "dd-mm-yyyy") << endl;

    cout << format_date(self, "Day: dd, Month: mm, Year: yyyy") << endl;
}

int main()
{
    print_string_date_opesit();
    return 0;
}
