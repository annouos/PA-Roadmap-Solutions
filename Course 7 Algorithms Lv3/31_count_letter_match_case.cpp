
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

char read_char(string massage)
{
    char letter;
    cout << massage;
    cin >> letter;
    return letter;    
}

int count_letter(string text, char letter, bool match_case = true)
{
    int counter = 0;
    for (int i = 0; i < text.length(); i++)
    {
        if (match_case)
        {
            if (text[i] == letter)
                counter++;
        }
        else
        {
            if (tolower(text[i]) == towlower(letter))
                counter++;
        }
    }
    return counter;
}

char invert_letter(char letter)
{
    return isupper(letter) ? tolower(letter) : toupper(letter);
}

int main()
{
    string text = read_string("Please Enter a massage: ");
    char letter = read_char("Please Enter a letter: ");
    cout << "The letter " << letter << "repeated = " << count_letter(text, letter) << endl;
    cout << "The letter " << letter << "Or " << invert_letter(letter);
    cout << " The count = " << count_letter(text, letter, false) << endl;
    return 0;
}
