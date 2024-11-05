
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

int main()
{
    cout << join_word(favorite, " - ") << endl;
    return 0;
}