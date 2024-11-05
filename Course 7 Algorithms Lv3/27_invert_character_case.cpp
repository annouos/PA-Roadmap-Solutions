
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

char read_text(string massage)
{
    char text;
    cout << massage;
    cin >> text;
    return text;    
}

char invert_letter(char letter)
{
    return isupper(letter) ? tolower(letter) : toupper(letter);
}

int main()
{
    char letter = read_text("Please Enter a Letter: ");
    cout << invert_letter(letter) << endl;
    return 0;
}
