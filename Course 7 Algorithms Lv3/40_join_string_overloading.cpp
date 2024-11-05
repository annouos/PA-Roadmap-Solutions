
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

vector <string> favorite = {"Sara", "Lolita", "Kathy", "Alan", "Tom"};

string join_word(vector <string> self, string delimiter)
{
    string text;
    for (string &x : self)
    {
        text += x + delimiter;
    }

    return text.substr(0, text.length() - delimiter.length());
}

string join_word(string ray[], short length, string delimiter)
{
    string text;
    for (short i = 0; i < length; i++)
    {
        text += ray[i] + delimiter;
    }

    return text.substr(0, text.length() - delimiter.length());
}

int main()
{
    string ray[] = {"Sara", "Lolita", "Kathy", "Alan", "Tom"};
    cout << join_word(favorite, " - ") << endl;
    cout << join_word(ray, 5, " / ") << endl;
    return 0;
}