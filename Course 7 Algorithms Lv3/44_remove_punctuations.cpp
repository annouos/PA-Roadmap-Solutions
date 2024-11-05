
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string read_string(string massage)
{
    string text;
    cout << massage;
    getline(cin, text);
    return text;    
}

string remove_punctuations(string text)
{
    string statement = "";
    for (int i = 0; i < text.length(); i++)
    {
        if (!ispunct(text[i]))
        {
            statement += text[i];
        }
    }
    return statement;
}

int main()
{
    string text = read_string("Please Enter a letter: ");
    cout << remove_punctuations(text) << endl;
    return 0;
}
