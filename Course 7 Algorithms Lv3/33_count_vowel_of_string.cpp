
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

int count_vowel(string text)
{
    int counter = 0;
    for (int i = 0; i < text.length(); i++)
    {
        if (check_vowel(text[i]))
        {
            counter++;
        }
    }
    return counter;
}

int main()
{
    string text = read_string("Please Enter a massage: ");
    cout << "The count of vowels in = " << count_vowel(text) << endl;
    return 0;
}






// #include <iostream>
// #include <string>
// #include <cctype>

// using namespace std;

// string read_string(string massage)
// {
//     string text;
//     cout << massage;
//     getline(cin, text);
//     return text;
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

// int count_vowel(char ray[5], short length, string text)
// {
//     int counter = 0;
//     for (int i = 0; i < text.length(); i++)
//     {
//         if (check_vowel(ray, length, text[i]) == "\nYes, is it Vowel")
//         {
//             counter++;
//         }
//     }
//     return counter;
// }

// int main()
// {
//     char ray[5] = {'a', 'e', 'i', 'o', 'u'};
//     string text = read_string("Please Enter a massage: ");
//     cout << "The count of vowels in = " << count_vowel(ray, 5, text) << endl;
//     return 0;
// }
