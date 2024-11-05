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

string date_to_string(info self)
{
    return to_string(self.day) + "/" + to_string(self.month) + "/" + to_string(self.year);
}

void print_string_date_opesit()
{
    string text = read_string("Please enter a date dd/mm/yyyy: ");
    info self = string_to_date(text);

    cout << "Day: " << self.day << endl;
    cout << "Month: " << self.month << endl;
    cout << "Year: " << self.year << endl;

    cout << "You Entered: " << date_to_string(self) << endl;
}

int main()
{
    print_string_date_opesit();
    return 0;
}