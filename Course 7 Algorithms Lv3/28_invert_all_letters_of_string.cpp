
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string read_text(string massage)
{
    string text;
    cout << massage;
    getline(cin, text);
    return text;    
}

char invert_letter(char letter)
{
    return isupper(letter) ? tolower(letter) : toupper(letter);
}

string invert_string(string text)
{
    for (short i = 0; i <= text.length(); i++)
    {
        text[i] = invert_letter(text[i]);
    }
    return text;
}

int main()
{
    string letter = read_text("Please Enter a massage: ");
    letter = invert_string(letter);
    cout << letter << endl;
    return 0;
}
