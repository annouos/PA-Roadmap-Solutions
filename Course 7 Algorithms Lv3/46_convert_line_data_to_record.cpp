
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct info
{
    string acount = "";
    string name ="";
    string pin_code = "";
    string phone_number = "";
    float balance = 0;
};

vector <string> split_word(string text, string delimiter)
{
    short pos = 0;
    string word;
    vector <string> favorite;

    while ((pos = text.find(delimiter)) != std::string::npos)
    {
        word = text.substr(0, pos);
        if (word != "")
        {
            favorite.push_back(word);
        }
        text.erase(0, pos + delimiter.length());
    }
    if (text != "")
    {
        favorite.push_back(text);
    }
    return favorite;
}

info vector_to_struct(string deta, string seperator = "#//#")
{
    info self;
    vector <string> favorite;

    favorite = split_word(deta, seperator);

    self.acount = favorite[0];
    self.name = favorite[1];
    self.pin_code = favorite[2];
    self.phone_number = favorite[3];
    self.balance = stod(favorite[4]);
    return self;
}

void print_struct(info self)
{
    cout << "Your Account: " << self.acount << endl;
    cout << "Your Name: " << self.name << endl;
    cout << "Your Pin Code: " << self.pin_code << endl;
    cout << "Your Phone: " << self.phone_number << endl;
    cout << "Your Balance: " << self.balance << endl;
}

int main()
{
    string text = "A149#//#Sara Alex#//#1024#//#733375444#//#16000.000";
    cout << text << endl;
    info self = vector_to_struct(text);
    print_struct(self);
    return 0;
}