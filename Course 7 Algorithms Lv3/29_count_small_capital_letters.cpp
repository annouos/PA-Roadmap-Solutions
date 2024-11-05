
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

int count_capital(string text)
{
    int counter = 0;
    for (short i = 0; i <= text.length(); i++)
    {
        if (isupper(text[i]))
        {
            counter++;
        }
    }
    return counter;
}

int count_small(string text)
{
    int counter = 0;
    for (short i = 0; i <= text.length(); i++)
    {
        if (islower(text[i]))
        {
            counter++;
        }
    }
    return counter;
}

int main()
{
    string text = read_text("Please Enter a massage: ");
    cout << "The Length of string = " << text.length() << endl;
    cout << "The count Capital = " << count_capital(text) << endl;
    cout << "The count Small = " << count_small(text) << endl;
    return 0;
}
