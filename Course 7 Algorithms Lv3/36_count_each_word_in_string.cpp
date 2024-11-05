
#include <iostream>
#include <string>

using namespace std;

string read_string(string massage)
{
    string text;
    cout << massage;
    getline(cin, text);
    return text;
}

int count_word(string text)
{
    string delimiter = " ";
    short pos = 0, counter = 0;
    string word;

    while ((pos = text.find(delimiter)) != std::string::npos)
    {
        word = text.substr(0, pos);
        if (word != "")
        {
            counter++;
        }
        text.erase(0, pos + delimiter.length());
    }
    if (text != "")
    {
        counter++;
    }
    return counter;
}

int main()
{
    string text = read_string("Please Enter a massage: ");
    cout << "The count word is = " << count_word(text) << endl;
    return 0;
}