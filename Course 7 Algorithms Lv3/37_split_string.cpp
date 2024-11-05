
#include <iostream>
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

void print_split()
{
    cout << "Token = " << favorite.size() << endl;
    for (string &x : favorite)
    {
        cout << x << endl;
    }
}

int main()
{
    string text = read_string("Please Enter a massage: ");
    split_word(text, " ");
    print_split();
    return 0;
}