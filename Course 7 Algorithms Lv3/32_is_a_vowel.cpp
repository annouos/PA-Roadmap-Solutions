
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

char read_char(string massage)
{
    char letter;
    cout << massage;
    cin >> letter;
    return letter;    
}

bool check_vowel(char letter)
{
    letter = tolower(letter);
    return ((letter == 'a') || (letter == 'e') || (letter == 'i') || (letter == 'o') || (letter == 'u'));
}

void print_vowel(char letter)
{
    if (check_vowel(letter))
        cout << letter << "\nYes, is it Vowel" << endl;
    else
        cout << letter << "\nNo, isn't Vowel" << endl;
}

int main()
{
    char letter = read_char("Please Enter a letter: ");
    print_vowel(letter);
    return 0;
}





// #include <iostream>
// #include <string>
// #include <cctype>

// using namespace std;

// char read_char(string massage)
// {
//     char letter;
//     cout << massage;
//     cin >> letter;
//     return letter;    
// }

// string check_vowel(char ray[5], short length, char letter)
// {
//     for (int i = 0; i < length; i++)
//     {
//         if (ray[i] == tolower(letter))
//         {
//             return "\nYes, is it Vowel";
//         }
//     }
//     return "\nNo, isn't Vowel";
// }

// int main()
// {
//     char ray[5] = {'a', 'e', 'i', 'o', 'u'};
//     char letter = read_char("Please Enter a letter: ");
//     cout << letter << check_vowel(ray, 5, letter) << endl;
//     return 0;
// }
