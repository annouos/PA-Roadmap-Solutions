
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

bool check_vowel(char letter)
{
    letter = tolower(letter);
    return ((letter == 'a') || (letter == 'e') || (letter == 'i') || (letter == 'o') || (letter == 'u'));
}

void print_vowels(string text)
{
    for (int i = 0; i < text.length(); i++)
    {
        if (check_vowel(text[i]))
        {
            printf("%*c", 3, text[i]);
        }
    }
    cout << endl;
}

int main()
{
    string text = read_string("Please Enter a massage: ");
    print_vowels(text);
    return 0;
}