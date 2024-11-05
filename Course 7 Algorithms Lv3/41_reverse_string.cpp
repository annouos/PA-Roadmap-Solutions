
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

string reverse_word(string text)
{
    vector <string> self;
    string jumlah = "";
    self = split_word(text, " ");

    vector <string> ::iterator iter = self.end();

    while (iter != self.begin())
    {
        --iter;
        jumlah += * iter + " ";
    }
    jumlah = jumlah.substr(0, jumlah.length() - 1);
    return jumlah;
}

int main()
{
    string text = read_string("Please Enter a massage: ");
    cout << reverse_word(text) << endl;
    return 0;
}
