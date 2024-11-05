
#include <iostream>
#include <fstream>
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
    float balance = 0;
};

info read_login()
{
    info self;
    self.acount = read_string("Please enter your Account: ");
    self.name = read_string("Please enter your Name: ");
    self.pin_code = read_string("Please enter your Pin Code: ");
    self.phone_number = read_string("Please enter your Phone: ");
    self.balance = (float) positiv_number("Please enter your Blance: ");
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

void data_to_file(string location, info &self)
{
    fstream my_file;
    my_file.open(location, ios::out | ios::app);

    if (my_file.is_open())
    {
        my_file << struct_to_line(self) << endl;
        my_file.close();
    }
}

void new_client()
{
        info self = read_login();
        data_to_file("47_clients.txt", self);
}

void start_add()
{
    char more = 'Y';
    do
    {
        new_client();
        cout << "Client added succesfully, Do you want add again Y/N? ";
        cin >> more ;
        // cin.ignore(1, '\n');
    } while (toupper(more) == 'Y');
}

int main()
{
    start_add();
    return 0;
}
