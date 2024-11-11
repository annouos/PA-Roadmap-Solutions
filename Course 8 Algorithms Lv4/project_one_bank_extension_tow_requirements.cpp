
#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

string location = "Bank's Customeres.txt";
string users = "Bank's Users.txt";

enum screen_one {show = 1, add = 2, find = 3, update = 4, del = 5, trans = 6, mng = 7, exito = 8};

enum screen_tow {deposit = 1, with_draw = 2, total_balance = 3, main_screen = 4};

enum screen_manage {list = 1, add_usr = 2, del_usr = 3, updt_usr = 4, fnd_usr = 5, mainu = 6};

enum authorization {all = -1, auth_list = 1, auth_add = 2, auth_delete = 4, auth_update = 8, auth_find = 16, auth_trans = 32, auth_manage = 64};

void back_main_menu();
void back_next_menu();
void back_manage_menu();
void login();

screen_one read_screen_one(string massage)
{
    int number = 0;
    do
    {
        cout << massage;
        cin >> number;
    } while (number < 0 && number > 8);
    return (screen_one) number;
}

screen_tow read_screen_tow(string massage)
{
    int number = 0;
    do
    {
        cout << massage;
        cin >> number;
    } while (number < 0 && number > 4);
    return (screen_tow) number;
}

screen_manage read_screen_manage(string massage)
{
    int number = 0;
    do
    {
        cout << massage;
        cin >> number;
    } while (number < 0 && number > 6);
    return (screen_manage) number;
}

int positiv_number(string massage)
{
    int number = 0;
    do
    {
        cout << massage;
        cin >> number;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            back_main_menu();
            // cout << "Please Tray Again: ";
            // cin >> number;
        }
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

struct admins
{
    string name = "";
    string password = "";
    int permission;
    bool mark_delete = false;
};

admins selfo;

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

string users_to_line(admins self, string seperator = "#//#")
{
    string line = "";
    line += self.name + seperator;
    line += self.password + seperator;
    line += to_string(self.permission);
    return line;
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

void admins_to_file(string users, admins &self)
{
    fstream my_file;
    my_file.open(users, ios::out | ios::app);

    if (my_file.is_open())
    {
        my_file << users_to_line(self) << endl;
        my_file.close();
    }
} 

void client_to_file(string location, info &self)
{
    fstream my_file;
    my_file.open(location, ios::out | ios::app);

    if (my_file.is_open())
    {
        my_file << struct_to_line(self) << endl;
        my_file.close();
    }
}

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

admins vector_to_users (string deta, string seperator = "#//#") // repeted function .. you have to optimise
{
    admins self;
    vector <string> favorite = split_word(deta, seperator);

    self.name = favorite[0];
    self.password = favorite[1];
    self.permission = stoi(favorite[2]);
    return self;
}

info vector_to_struct (string deta, string seperator = "#//#")
{
    info self;
    vector <string> favorite = split_word(deta, seperator);

    self.acount = favorite[0];
    self.name = favorite[1];
    self.pin_code = favorite[2];
    self.phone_number = favorite[3];
    self.balance = stod(favorite[4]);
    return self;
}

bool user_exists(string users, string name)
{
    vector <admins> favorite;
    fstream my_file;
    my_file.open(users, ios::in);

    if (my_file.is_open())
    {
        string line = "";
        admins self;

        while (getline(my_file, line))
        {
            self = vector_to_users(line);
            if (self.name == name)
            {
                my_file.close();
                return true;
            }
            favorite.push_back(self);
        }
        my_file.close();
    }
    return false;
}

bool client_exists(string location, string account_number)
{
    vector <info> favorite;
    fstream my_file;
    my_file.open(location, ios::in);

    if (my_file.is_open())
    {
        string line = "";
        info self;

        while (getline(my_file, line))
        {
            self = vector_to_struct(line);
            if (self.acount == account_number)
            {
                my_file.close();
                return true;
            }
            favorite.push_back(self);
        }
        my_file.close();
    }
    return false;
}

int authintecation()
{
    int permissions = 0;
    char answer = 'n';

    cout << "Do you want to give full access ? n/y: ";
    cin >> answer;

    if (answer == 'y' || answer == 'Y')
    {
        return -1;
    }

    cout << "Do you want to give access to: \n";

    cout << "Show List Client? y/n: ";
    cin >> answer;
    if (answer == 'y' || answer == 'Y')
    {
        permissions += authorization::auth_list;
    }

    cout << "Add New Client? y/n: ";
    cin >> answer;
    if (answer == 'y' || answer == 'Y')
    {
        permissions += authorization::auth_add;
    }
    cout << "Delete Client? y/n: ";
    cin >> answer;
    if (answer == 'y' || answer == 'Y')
    {
        permissions += authorization::auth_delete;
    }
    cout << "Update Client? y/n: ";
    cin >> answer;
    if (answer == 'y' || answer == 'Y')
    {
        permissions += authorization::auth_update;
    }
    cout << "Find Client? y/n: ";
    cin >> answer;
    if (answer == 'y' || answer == 'Y')
    {
        permissions += authorization::auth_find;
    }
    cout << "Transactions? y/n: ";
    cin >> answer;
    if (answer == 'y' || answer == 'Y')
    {
        permissions += authorization::auth_trans;
    }
    cout << "Manage Users? y/n: ";
    cin >> answer;
    if (answer == 'y' || answer == 'Y')
    {
        permissions += authorization::auth_manage;
    }

    return permissions;
}

admins change_user(string wanted)
{
    admins self;
    self.name = wanted;
    self.password = read_string("Please enter a password: ");
    self.permission = authintecation();
    return self;
}

admins read_new_users()
{
    admins self;
    self.name = read_string("Please enter a the user: ");

    while (user_exists(users, self.name))
    {
        cout << "User with [" << self.name << "] already exists, Enter another Account Number: ";
        getline(cin >> ws, self.name);
    }

    self.password = read_string("Please enter the password: ");
    self.permission = authintecation();
    return self;
}

info read_login_client()
{
    info self;
    self.acount = read_string("Please enter your Account: ");

    while (client_exists(location, self.acount))
    {
        cout << "\nClient with [" << self.acount << "] already exists, Enter another Account Number: ";
        getline(cin >> ws, self.acount);
    }

    self.name = read_string("Please enter your Name: ");
    self.pin_code = read_string("Please enter your Pin Code: ");
    self.phone_number = read_string("Please enter your Phone: ");
    self.balance = (float) positiv_number("Please enter your Blance: ");
    return self;
}

void new_user()
{
        admins self = read_new_users();
        admins_to_file(users, self);
}

void new_client()
{
        info self = read_login_client();
        client_to_file(location, self);
}

void add_user()
{
    char more = 'Y';
    do
    {
        new_user();
        cout << "User added succesfully, Do you want add again Y/N? ";
        cin >> more;
        // cin.ignore(1, '\n');
    } while (toupper(more) == 'Y');
}

void add_client()
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

vector <admins> load_users(string location)
{
    vector <admins> favorite;
    fstream my_file;
    my_file.open(location, ios::in);

    if (my_file.is_open())
    {
        string line = "";
        admins self;
        while (getline(my_file, line))
        {
            self = vector_to_users(line);
            favorite.push_back(self); 
        }
        my_file.close();
    }
    return favorite;
}

vector <info> load_data(string location)
{
    vector <info> favorite;
    fstream my_file;
    my_file.open(location, ios::in);

    if (my_file.is_open())
    {
        string line = "";
        info self;
        while (getline(my_file, line))
        {
            self = vector_to_struct(line);
            favorite.push_back(self); 
        }
        my_file.close();
    }
    return favorite;
}

vector <admins > users_to_file(string location, vector <admins> favorite)
{
    fstream my_file;
    my_file.open(users, ios::out);
    string line = "";
    if (my_file.is_open())
    {
        for (admins &x : favorite)
        {
            if (x.mark_delete == false)
            {
                line = users_to_line(x);
                my_file << line << endl;
            }
        }
        my_file.close();
    }
    return favorite;
}

vector <info > save_to_file(string location, vector <info> favorite)
{
    fstream my_file;
    my_file.open(location, ios::out);
    string line = "";
    if (my_file.is_open())
    {
        for (info &x : favorite)
        {
            if (x.mark_delete == false)
            {
                line = struct_to_line(x);
                my_file << line << endl;
            }
        }
        my_file.close();
    }
    return favorite;
}

bool auth_users(string wanted, string pass, vector <admins> favorite, admins &self)
{
    for (admins &x : favorite)
    {
        if (x.name == wanted && x.password == pass)
        {
            self = x;
            return true;
        }
    }
    return false;
}

bool search_users(string wanted, vector <admins> favorite, admins &self)
{
    for (admins &x : favorite)
    {
        if (x.name == wanted)
        {
            self = x;
            return true;
        }
    }
    return false;
}

bool search_account(string wanted, vector <info> favorite, info &self)
{
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

void print_card_users(admins self)
{
    cout << "| " << "Username     : " << self.name << endl;
    // cout << "| " << "Password     : " << self.password << endl; // for security
    cout << "| " << "Premisions   : " << self.permission << endl;
}

void print_card(info self)
{
    cout << "| " << "Account Number: " << self.acount << endl;
    cout << "| " << "Pin Code      : " << self.pin_code << endl;
    cout << "| " << "Client Name   : " << self.name << endl;
    cout << "| " << "Phone         : " << self.phone_number << endl;
    cout << "| " << "Balance       : " << self.balance << endl;
}

void print_search_users(string wanted, vector <admins> favorite)
{
    admins self;
    if (search_users(wanted, favorite, self))
    {
        cout << endl;
        print_card_users(self);
    }
    else
    {
        cout << "Sorry, We can't found " << wanted << " from data." << endl;
    }
}

void print_search(string wanted, vector <info> favorite)
{
    info self;
    if (search_account(wanted, favorite, self))
    {
        cout << endl;
        print_card(self);
    }
    else
    {
        cout << "Sorry, We can't found " << wanted << " from data." << endl;
    }
}

bool update_users(string wanted, vector <admins> &favorite)
{
    admins self;
    char answer = 'Y';

    if (search_users(wanted, favorite, self))
    {
        print_search_users(wanted, favorite);
        cout << "\n\nAre you sure you want to update this user? Y/N: ";
        cin >> answer;
        if (toupper(answer) == 'Y')
        {
            for (admins &x : favorite)
            {
                if (x.name == wanted)
                {
                    x = change_user(wanted);
                    break;
                }
            }

            users_to_file(users, favorite);

            favorite = load_users(users);
            cout << "User Updated Successfully." << endl;
            return true;
        }
    }
    else
    {
        cout << "User with this name (" << wanted << ") doesn't exist." << endl;
    }
    return false;
}

bool update_account(string wanted, vector <info> &favorite)
{
    info self;
    char answer = 'Y';

    if (search_account(wanted, favorite, self))
    {
        print_search(wanted, favorite);
        cout << "\n\nAre you sure you want to update this client? Y/N: ";
        cin >> answer;
        if (toupper(answer) == 'Y')
        {
            for (info &x : favorite)
            {
                if (x.acount == wanted)
                {
                    x = change_client(wanted);
                    break;
                }
            }

            save_to_file(location, favorite);

            favorite = load_data(location);
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

bool switch_to_delete_user(string wanted, vector <admins> &favorite)
{
    for (admins &x : favorite)
    {
        if (x.name == wanted)
        {
            x.mark_delete = true;
            return true;
        }
    }
    return false;
}

bool delete_users(string wanted, vector <admins> &favorite)
{
    admins self;
    char answer = 'Y';

    if (search_users(wanted, favorite, self))
    {
        print_search_users(wanted, favorite);
        cout << "\n\nAre you sure you want to delete this user? Y/N: ";
        cin >> answer;
        if (toupper(answer) == 'Y')
        {
            switch_to_delete_user(wanted, favorite);
            users_to_file(location, favorite);

            favorite = load_users(users);
            cout << "User Deleted Successfully." << endl;
            return true;
        }
    }
    else
    {
        cout << "Users with this name (" << wanted << ") doesn't exist." << endl;
    }
    return false;
}

bool switch_to_delete(string wanted, vector <info> &favorite)
{
    for (info &x : favorite)
    {
        if (x.acount == wanted)
        {
            x.mark_delete = true;
            return true;
        }
    }
    return false;
}

bool delete_account(string wanted, vector <info> &favorite)
{
    info self;
    char answer = 'Y';

    if (search_account(wanted, favorite, self))
    {
        print_search(wanted, favorite);
        cout << "\n\nAre you sure you want to delete this client? Y/N: ";
        cin >> answer;
        if (toupper(answer) == 'Y')
        {
            switch_to_delete(wanted, favorite);
            save_to_file(location, favorite);

            favorite = load_data(location);
            cout << "\n\nClient Deleted Successfully." << endl;
            return true;
        }
    }
    else
    {
        cout << "\nClient with Account Number (" << wanted << ") doesn't exist." << endl;
    }
    return false;
}

bool deposit_for_client(string wanted, vector <info> &favorite)
{
    info self;
    int money = 0;;
    char answer = 'Y';

    if (search_account(wanted, favorite, self))
    {
        print_search(wanted, favorite);
        cout << "How many do you want add it: ";
        cin >> money;
        cout << "\n\nAre you sure you want to deposit for this client? Y/N: ";
        cin >> answer;
        if (toupper(answer) == 'Y')
        {
            for (info &x : favorite)
            {
                if (x.acount == wanted)
                {
                    x.balance += money;
                    break;
                }
            }

            save_to_file(location, favorite);

            favorite = load_data(location);
            cout << "\n\nClient Deposited Successfully." << endl;
            return true;
        }
    }
    else
    {
        cout << "\nClient with Account Number (" << wanted << ") doesn't exist." << endl;
    }
    return false;
}

bool withdraw_from_client(string wanted, vector <info> &favorite)
{
    info self;
    int money = 0;;
    char answer = 'Y';

    if (search_account(wanted, favorite, self))
    {
        print_search(wanted, favorite);
        cout << "How many do you want withdraw it: ";
        cin >> money;
        cout << "\n\nAre you sure you want to withdraw for this client? Y/N: ";
        cin >> answer;
        if (toupper(answer) == 'Y')
        {
            for (info &x : favorite)
            {
                if (x.acount == wanted)
                {
                    x.balance -= money;
                    break;
                }
            }

            save_to_file(location, favorite);

            favorite = load_data(location);
            cout << "\n\nClient Withdraw Successfully." << endl;
            return true;
        }
    }
    else
    {
        cout << "\nClient with Account Number (" << wanted << ") doesn't exist." << endl;
    }
    return false;
}

bool check_login()
{
    vector <admins> favorite = load_users(users);
    string username = read_string("Enter username: ");
    string password = read_string("Enter password: ");
    return auth_users(username, password, favorite, selfo);
}

bool check_permission(authorization enautho)
{
    if (selfo.permission == authorization::all)
        return true;
    else if ((enautho & selfo.permission) == enautho)
        return true;
    else
        return false;
}

void print_access_denied()
{
    cout << "\n------------------------------------\n";
    cout << "Access Denied, \nYou dont Have Permission To Do this,\nPlease Conact Your Admin.";
    cout << "\n------------------------------------\n";
}

void print_users(admins self)
{
    cout << "| " << setw(41) << left << self.name;
    cout << "| " << setw(12) << left << self.password;
    cout << "| " << setw(12) << left << self.permission;
}

void print_client(info self)
{
    cout << "| " << setw(15) << left << self.acount;
    cout << "| " << setw(10) << left << self.pin_code;
    cout << "| " << setw(40) << left << self.name;
    cout << "| " << setw(12) << left << self.phone_number;
    cout << "| " << setw(12) << left << self.balance;
}

void print_amins()
{
    vector <admins> favorite = load_users(users);

    cout << "\n\t\t\t\t\tClient List (" << favorite.size() << ") Client(s)";
    cout << "\n--------------------------------------------------------------";
    cout << "--------------------------------------------\n" << endl;
    cout << "| " << left << setw(41) << "User Name";
    cout << "| " << left << setw(12) << "Password";
    cout << "| " << left << setw(12) << "Premisions";
    cout << "\n--------------------------------------------------------------";
    cout << "--------------------------------------------\n" << endl;

    if (favorite.size() == 0)
        cout << "\tNo User Available In The System!";
    else
    {
        for (admins &self : favorite)
        {
            print_users(self);
            cout << " |" << endl;
        }
    }
    cout << "\n--------------------------------------------------------------";
    cout << "--------------------------------------------\n" << endl;
}

void print_data()
{
    if (!check_permission(authorization::auth_list))
    {
        print_access_denied();
        return;
    }

    vector <info> favorite = load_data(location);

    cout << "\n\t\t\t\t\tClient List (" << favorite.size() << ") Client(s)";
    cout << "\n--------------------------------------------------------------";
    cout << "--------------------------------------------\n" << endl;
    cout << "| " << left << setw(15) << "Account Number";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n--------------------------------------------------------------";
    cout << "--------------------------------------------\n" << endl;

    if (favorite.size() == 0)
        cout << "\tNo Client Available In The System!";
    else
    {
        for (info &self : favorite)
        {
            print_client(self);
            cout << " |" << endl;
        }
    }
    cout << "\n--------------------------------------------------------------";
    cout << "--------------------------------------------\n" << endl;
}

void print_client_sumarry(info self)
{
    cout << "| " << setw(15) << left << self.acount;
    cout << "| " << setw(40) << left << self.name;
    cout << "| " << setw(12) << left << self.balance;
}

void print_data_sumarry()
{
    vector <info> favorite = load_data(location);

    cout << "\n\t\t\t\t\tClient List (" << favorite.size() << ") Client(s)";
    cout << "\n--------------------------------------------------------------";
    cout << "--------------------------------------------\n" << endl;
    cout << "| " << left << setw(15) << "Account Number";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n--------------------------------------------------------------";
    cout << "--------------------------------------------\n" << endl;

    if (favorite.size() == 0)
        cout << "\tNo Client Available In The System!";
    else
    {
        int sum = 0;
        for (info &self : favorite)
        {
            print_client_sumarry(self);
            cout << " |" << endl;
            sum += self.balance;
        }
        cout << "\n\t\t\t\t\tTotal Balance: ( " << sum << "$ ) Dollar";
    }
    cout << "\n--------------------------------------------------------------";
    cout << "--------------------------------------------\n" << endl;
}

void print_login_screen()
{
    cout << "=================================================" << endl;
    cout << "                Login Screen" << endl;
    cout << "=================================================" << endl;
}

void print_screen_one()
{
    cout << "=================================================" << endl;
    cout << "                The Main Menu Screen" << endl;
    cout << "=================================================" << endl;
    cout << "        [1] Show Client List" << endl;
    cout << "        [2] Add New Client" << endl;
    cout << "        [3] Find Client" << endl;
    cout << "        [4] Update Client Info" << endl;
    cout << "        [5] Delete Client" << endl;
    cout << "        [6] Transaction To Client" << endl;
    cout << "        [7] Manage Users" << endl;
    cout << "        [8] Logout" << endl;
    cout << "=================================================" << endl;
}

void print_screen_tow()
{
    if (!check_permission(authorization::auth_trans))
    {
        print_access_denied();
        return;
    }

    cout << "=================================================" << endl;
    cout << "            The Next Menu Screen (Tow)" << endl;
    cout << "=================================================" << endl;
    cout << "        [1] Deposit" << endl;
    cout << "        [2] Withdraw" << endl;
    cout << "        [3] Total Balance" << endl;
    cout << "        [4] Main Menu" << endl;
    cout << "=================================================" << endl;
}

void print_screen_manage()
{
    if (!check_permission(authorization::auth_manage))
    {
        print_access_denied();
        return;
    }

    cout << "=================================================" << endl;
    cout << "            Manage Users Menu Screen" << endl;
    cout << "=================================================" << endl;
    cout << "        [1] List Users" << endl;
    cout << "        [2] Add New User" << endl;
    cout << "        [3] Delete User" << endl;
    cout << "        [4] Update User" << endl;
    cout << "        [5] Find User" << endl;
    cout << "        [6] Main Menu" << endl;
    cout << "=================================================" << endl;
}

void show_add_users()
{
    cout << "-------------------------------------------------" << endl;
    cout << "\t Add New Users Screen" << endl;
    cout << "-------------------------------------------------" << endl;
    add_user();
}

void show_add()
{
    if (!check_permission(authorization::auth_add))
    {
        print_access_denied();
        return;
    }

    cout << "-------------------------------------------------" << endl;
    cout << "\t Add New Client Screen" << endl;
    cout << "-------------------------------------------------" << endl;
    add_client();
}

void show_find_users()
{
    cout << "-------------------------------------------------" << endl;
    cout << "\t Find User Screen" << endl;
    cout << "-------------------------------------------------" << endl;

    vector <admins> favorite = load_users(users);
    admins self;
    string username = read_string("For whome user do you want found ? ");
    print_search_users(username, favorite);
}

void show_find()
{
    if (!check_permission(authorization::auth_find))
    {
        print_access_denied();
        return;
    }

    cout << "-------------------------------------------------" << endl;
    cout << "\t Find Client Screen" << endl;
    cout << "-------------------------------------------------" << endl;

    vector <info> favorite = load_data(location);
    info self;
    string account_number = read_string("For whome account do you want found ? ");
    print_search(account_number, favorite);
}

void show_update_users()
{
    cout << "-------------------------------------------------" << endl;
    cout << "\t Update User Info Screen" << endl;
    cout << "-------------------------------------------------" << endl;

    vector <admins> favorite = load_users(users);
    string username = read_string("For whome account do you want update ? ");
    update_users(username, favorite);
}

void show_update()
{
    if (!check_permission(authorization::auth_update))
    {
        print_access_denied();
        return;
    }

    cout << "-------------------------------------------------" << endl;
    cout << "\t Update Client Info Screen" << endl;
    cout << "-------------------------------------------------" << endl;

    vector <info> favorite = load_data(location);
    string account_number = read_string("For whome account do you want update ? ");
    update_account(account_number, favorite);
}

void show_delete_users()
{
    cout << "-------------------------------------------------" << endl;
    cout << "\t Delete User Screen" << endl;
    cout << "-------------------------------------------------" << endl;
    vector <admins> favorite = load_users(users);
    string username = read_string("For whome users do you want delete ? ");
    delete_users(username, favorite);
}

void show_delete()
{
    if (!check_permission(authorization::auth_delete))
    {
        print_access_denied();
        return;
    }

    cout << "-------------------------------------------------" << endl;
    cout << "\t Delete Client Screen" << endl;
    cout << "-------------------------------------------------" << endl;
    vector <info> favorite = load_data(location);
    string account_number = read_string("For whome account do you want delete ? ");
    delete_account(account_number, favorite);
}

void show_deposit()
{
    cout << "-------------------------------------------------" << endl;
    cout << "\t Deposit For Client Screen" << endl;
    cout << "-------------------------------------------------" << endl;
    vector <info> favorite = load_data(location);
    string account_number = read_string("For whome account do you want deposit ? ");
    deposit_for_client(account_number, favorite);
}

void show_withdraw()
{
    cout << "-------------------------------------------------" << endl;
    cout << "\t Withdraw From Client Screen" << endl;
    cout << "-------------------------------------------------" << endl;
    vector <info> favorite = load_data(location);
    string account_number = read_string("For whome account do you want withdraw ? ");
    withdraw_from_client(account_number, favorite);
}

void show_end()
{
    cout << "-------------------------------------------------" << endl;
    cout << "\t End Program :-)" << endl;
    cout << "-------------------------------------------------" << endl;
}

void manage_menu(screen_manage eninfo)
{
    system("clear");    
    switch (eninfo)
    {
        case screen_manage::list :
        print_amins();
        back_manage_menu();
        break;
        case screen_manage::add_usr :
        show_add_users();
        back_manage_menu();
        break;
        case screen_manage::del_usr :
        show_delete_users();
        back_manage_menu();
        break;
        case screen_manage::updt_usr :
        show_update_users();
        back_manage_menu();
        break;
        case screen_manage::fnd_usr :
        show_find_users();
        back_manage_menu();
        break;
        case screen_manage::mainu :
        back_main_menu();
        break;
    }
}

void Manage()
{
    system("clear");
    print_screen_manage();
    screen_manage eninfo = read_screen_manage("Please chose from options 1-6 : ");
    manage_menu(eninfo);
}

void next_main(screen_tow eninfo)
{
    system("clear");
    switch (eninfo)
    {
        case screen_tow::deposit :
        show_deposit();
        back_next_menu();
        break;
        case screen_tow::with_draw :
        show_withdraw();
        back_next_menu();
        break;
        case screen_tow::total_balance :
        print_data_sumarry();
        back_next_menu();
        break;
        case screen_tow::main_screen :
        back_main_menu();
        break;
    }
}

void Nextow()
{
    system("clear");
    print_screen_tow();
    screen_tow eninfo = read_screen_tow("Please chose from options 1-4 : ");
    next_main(eninfo);
}

void main_menu(screen_one eninfo)
{
    system("clear");    
    switch (eninfo)
    {
        case screen_one::show :
        print_data();
        back_main_menu();
        break;
        case screen_one::add :
        show_add();
        back_main_menu();
        break;
        case screen_one::find :
        show_find();
        back_main_menu();
        break;
        case screen_one::update :
        show_update();
        back_main_menu();
        break;
        case screen_one::del :
        show_delete();
        back_main_menu();
        break;
        case screen_one::trans :
        Nextow();
        break;
        case screen_one::mng :
        Manage();
        break;
        case screen_one::exito :
        // show_end();
        login();
        break;
    }
}

void welcom()
{
    system("clear");
    print_screen_one();
    screen_one eninfo = read_screen_one("Please chose from options 1-7 : ");
    main_menu(eninfo);
}

void login()
{
    system("clear");
    print_login_screen();
    while (!check_login())
    {
        cout << "Invalid Username/Password!" << endl;
    }
    welcom();
}

void back_manage_menu()
{
    string blank = "";
    cout << endl << "\nPress any key and enter to back Main Menu ...";
    cin >> blank;
    Manage();
}

void back_next_menu()
{
    string blank = "";
    cout << endl << "\nPress any key and enter to back Main Menu ...";
    cin >> blank;
    Nextow();
}

void back_main_menu()
{
    string blank = "";
    cout << endl << "\nPress any key and enter to back Main Menu ...";
    cin >> blank;
    welcom();
}

int main()
{
    login();
    return 0;
}
