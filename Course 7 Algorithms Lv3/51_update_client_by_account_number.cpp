
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

int positiv_number(string massage)
{
    int number = 0;
    do
    {
        cout << massage;
        cin >> number;
    } while (number < 0);
    return number;
}

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
    bool mark_delete = false;
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

string struct_to_line(info self, string seperator = "#//#")
{
    string line = "";
    line += self.acount + seperator;
    line += self.name + seperator;
    line += self.pin_code + seperator;
    line += self.phone_number + seperator;
    line += to_string(self.balance);
    return line;
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
    cout << "| " << "Account Number: " << self.acount << endl;
    cout << "| " << "Pin Code      : " << self.pin_code << endl;
    cout << "| " << "Client Name   : " << self.name << endl;
    cout << "| " << "Phone         : " << self.phone_number << endl;
    cout << "| " << "Balance       : " << self.balance << endl;
}

bool search_account(string wanted, vector <info> favorita, info &self)
{
    for (info &x : favorita)
    {
        if (x.acount == wanted)
        {
            self = x;
            return true;
        }
    }
    return false;
}

void print_search(string wanted, vector <info> favorite)
{
    info self;
    if (search_account(wanted, favorite, self))
    {
        print_client(self);
    }
    else
    {
        cout << "Sorry, We can't found " << wanted << " from data." << endl;
    }
}

vector <info > save_to_file(string location, vector <info> favority)
{
    fstream my_file;
    my_file.open(location, ios::out);
    string line = "";
    if (my_file.is_open())
    {
        for (info &x : favority)
        {
            if (x.mark_delete == false)
            {
                line = struct_to_line(x);
                my_file << line << endl;
            }
        }
        my_file.close();
    }
    return favority;
}

info change_client(string wanted)
{
    info self;
    self.acount = wanted;
    self.name = read_string("Please enter your Name: ");
    self.pin_code = read_string("Please enter your Pin Code: ");
    self.phone_number = read_string("Please enter your Phone: ");
    self.balance = (float) positiv_number("Please enter your Blance: ");
    return self;
}

bool update_account(string wanted, vector <info> &favorito)
{
    info self;
    char answer = 'Y';

    if (search_account(wanted, favorito, self))
    {
        print_search(wanted, favorito);
        cout << "\n\nAre you sure you want to update this client? Y/N: ";
        cin >> answer;
        if (toupper(answer) == 'Y')
        {
            for (info &x : favorito)
            {
                if (x.acount == wanted)
                {
                    x = change_client(wanted);
                    break;
                }
            }

            save_to_file(location, favorito);

            favorito = load_data(location);
            cout << "\n\nClient Updated Successfully." << endl;
            return true;
        }
    }
    else
    {
        cout << "\nClient with Account Number (" << wanted << ") doesn't exist." << endl;
    }
    return false;
}

int main()
{   
    vector <info> favorite = load_data(location);
    update_account(read_string("For whome account do you want to update ? "), favorite);
    return 0;
}
