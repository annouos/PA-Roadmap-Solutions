
#include <iostream>
#include <fstream>
#include <iomanip>
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

void print_client(info self)
{
    cout << "| " << setw(15) << left << self.acount;
    cout << "| " << setw(10) << left << self.pin_code;
    cout << "| " << setw(40) << left << self.name;
    cout << "| " << setw(12) << left << self.phone_number;
    cout << "| " << setw(12) << left << self.balance;
}

void print_data(vector <info> favorite)
{
    cout << "\n\t\t\t\t\tClient List (" << favorite.size() << ") Client(s)";
    cout << "\n--------------------------------------------------------------";
    cout << "----------------------------------------------\n" << endl;
    cout << "| " << left << setw(15) << "Account Number";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n--------------------------------------------------------------";
    cout << "----------------------------------------------\n" << endl;

    for (info &self : favorite)
    {
        print_client(self);
        cout << endl;
    }
    cout << "\n--------------------------------------------------------------";
    cout << "----------------------------------------------\n" << endl;
}



int main()
{
    vector <info> favorite = load_data(location);
    print_data(favorite);
    return 0;
}
