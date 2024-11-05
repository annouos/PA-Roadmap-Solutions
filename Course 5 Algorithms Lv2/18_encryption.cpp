
#include <iostream>

using namespace std;

string read_text(string massage)
{
    string text;
    cout << massage;
    cin >> text;
    return text;
}

string encrypt(string text, short key)
{
    for(int i = 0; i <= text.length(); i++)
    {
        text[i] = char((int) text[i] + key);
    }
    return text;
}

string dencrypt(string text, int key)
{
    for(int i = 0; i <= text.length(); i++)
    {
        text[i] = char((int) text[i] - key);
    }
    return text;
}

int main()
{
    const short key = 7;

    string name = read_text("Please enter oyur name: ");
    string text_e = encrypt(name, key);
    string text_d = dencrypt(text_e, key);

    cout << "That's your name: " << name << endl;
    cout << "Your name ENCRYPTION !! " << text_e << endl;
    cout << "Your name DENCRYPTION !! " << text_d << endl;
    
    return 0;
}
