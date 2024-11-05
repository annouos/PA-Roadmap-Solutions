
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

int count_letter(string text, char letter)
{
    int counter = 0;
    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] == letter)
        {
            counter++;
        }
    }
    return counter;
}

int main()
{
    string text = read_string("Please Enter a massage: ");
    char letter = read_char("Please Enter a letter: ");
    cout << "The letter repeated = " << count_letter(text, letter) << endl;
    return 0;
}
