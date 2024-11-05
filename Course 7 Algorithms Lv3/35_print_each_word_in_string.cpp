
#include <iostream>
#include <string>

using namespace std;

string read_string(string massage)
{
    string text;
    cout << massage;
    getline(cin, text);
    return text;
}

void print_word(string text)
{
    string delimiter = " ";
    cout << "\nYour string words are: \n\n";
    short pos = 0;
    string word;

    while ((pos = text.find(delimiter)) != std::string::npos)
    {
        word = text.substr(0, pos);
        if (word != "") // why put if statement ?
        {
            cout << word << endl;
        }
        text.erase(0, pos + delimiter.length());
    }
    if (text != "")
    {
        cout << text << endl;
    }
}

int main()
{
    string text = read_string("Please Enter a massage: ");
    print_word(text);
    return 0;
}