
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

string read_string(string massage)
{
    string text;
    cout << massage;
    getline(cin >> ws, text);
    return text;
}

struct info
{
    string acount = "";
    string name ="";
    string pin_code = "";
    string phone_number = "";
    float balance = 0;
};

string location = "47_clients.txt";

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

info vector_to_struct (string deta, string seperator = "#//#")
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

vector <info> load_data(string location)
{
    vector <info> favorito;
    fstream my_file;
    my_file.open(location, ios::in);

    if (my_file.is_open())
    {
        string line = "";
        info self;
        while (getline(my_file, line))
        {
            self = vector_to_struct(line);
            favorito.push_back(self); 
        }
        my_file.close();
    }
    return favorito;
}

bool search_account(string wanted, info &self)
{
    vector <info> favorite = load_data(location);

    for (info &x : favorite)
    {
        if (x.acount == wanted)
        {
            self = x;
            return true;
        }
    }
    return false;
}

void print_client(info self)
{
    cout << "| " << "Account Number: " << self.acount << endl;
    cout << "| " << "Pin Code      : " << self.pin_code << endl;
    cout << "| " << "Client Name   : " << self.name << endl;
    cout << "| " << "Phone         : " << self.phone_number << endl;
    cout << "| " << "Balance       : " << self.balance << endl;
}

void print_search(string wanted)
{
    info self;
    if (search_account(wanted, self))
    {
        print_client(self);
    }
    else
    {
        cout << "Sorry, We can't found " << wanted << " from data." << endl;
    }
}

int main()
{
    print_search(read_string("For whome account do you want found ? "));
    return 0;
}
