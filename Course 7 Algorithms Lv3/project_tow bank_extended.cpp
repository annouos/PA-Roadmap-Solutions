
#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

string location = "Bank's Cutomeres.txt";

enum screen_one {show = 1, add = 2, find = 3, update = 4, del = 5, trans = 6, exito = 7};

enum screen_tow {deposit = 1, with_draw = 2, total_balance = 3, main_screen = 4};

void back_main_menu();
void back_next_menu();

screen_one read_screen_one(string massage)
{
    int number = 0;
    do
    {
        cout << massage;
        cin >> number;
    } while (number < 0 && number > 6);
    return (screen_one) number;
}

screen_tow read_screen_tow(string massage)
{
    int number = 0;
    do
    {
        cout << massage;
        cin >> number;
    } while (number < 0 && number > 6);
    return (screen_tow) number;
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

info read_login()
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

void new_client()
{
        info self = read_login();
        data_to_file("Bank's Cutomeres.txt", self);
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

void print_card(info self)
{
    cout << "| " << "Account Number: " << self.acount << endl;
    cout << "| " << "Pin Code      : " << self.pin_code << endl;
    cout << "| " << "Client Name   : " << self.name << endl;
    cout << "| " << "Phone         : " << self.phone_number << endl;
    cout << "| " << "Balance       : " << self.balance << endl;
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

void print_client(info self)
{
    cout << "| " << setw(15) << left << self.acount;
    cout << "| " << setw(10) << left << self.pin_code;
    cout << "| " << setw(40) << left << self.name;
    cout << "| " << setw(12) << left << self.phone_number;
    cout << "| " << setw(12) << left << self.balance;
}

void print_data()
{
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
    cout << "        [7] Exit" << endl;
    cout << "=================================================" << endl;
}

void print_screen_tow()
{
    cout << "=================================================" << endl;
    cout << "            The Next Menu Screen (Tow)" << endl;
    cout << "=================================================" << endl;
    cout << "        [1] Deposit" << endl;
    cout << "        [2] Withdraw" << endl;
    cout << "        [3] Total Balance" << endl;
    cout << "        [4] Main Menu" << endl;
    cout << "=================================================" << endl;
}

void show_add()
{
    cout << "-------------------------------------------------" << endl;
    cout << "\t Add New Client Screen" << endl;
    cout << "-------------------------------------------------" << endl;
    start_add();
}

void show_find()
{
    cout << "-------------------------------------------------" << endl;
    cout << "\t Find Client Screen" << endl;
    cout << "-------------------------------------------------" << endl;

    vector <info> favorite = load_data(location);
    string account_number = read_string("For whome account do you want found ? ");
    print_search(account_number, favorite);
}

void show_update()
{
    cout << "-------------------------------------------------" << endl;
    cout << "\t Update Client Info Screen" << endl;
    cout << "-------------------------------------------------" << endl;
    vector <info> favorite = load_data(location);
    string account_number = read_string("For whome account do you want update ? ");
    update_account(account_number, favorite);
}

void show_delete()
{
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
        case screen_one::exito :
        show_end();
        cout << endl;
        break;
    }
}

void Welcom()
{
    system("clear");
    print_screen_one();
    screen_one eninfo = read_screen_one("Please chose from options 1-7 : ");
    main_menu(eninfo);
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
    Welcom();
}

int main()
{
    Welcom();
    return 0;
}






// #include <iostream>
// #include <fstream>
// #include <iomanip>
// #include <string>
// #include <vector>
// #include <cstdio>

// using namespace std;

// string location = "Bank's Cutomeres.txt";

// enum screen_one {show = 1, add = 2, find = 3, update = 4, del = 5, trans = 6, exito = 7};

// enum screen_tow {deposit = 1, with_draw = 2, total_balance = 3, main_screen = 4};

// void back_main_menu();
// void back_next_menu();

// screen_one read_screen_one(string massage)
// {
//     int number = 0;
//     do
//     {
//         cout << massage;
//         cin >> number;
//     } while (number < 0 && number > 6);
//     return (screen_one) number;
// }

// screen_tow read_screen_tow(string massage)
// {
//     int number = 0;
//     do
//     {
//         cout << massage;
//         cin >> number;
//     } while (number < 0 && number > 6);
//     return (screen_tow) number;
// }

// int positiv_number(string massage)
// {
//     int number = 0;
//     do
//     {
//         cout << massage;
//         cin >> number;
//     } while (number < 0);
//     return number;
// }

// string read_string(string massage)
// {
//     string text;
//     cout << massage;
//     getline(cin >> ws, text);
//     return text;
// }

// struct info
// {
//     string acount = "";
//     string name ="";
//     string pin_code = "";
//     string phone_number = "";
//     bool mark_delete = false;
//     float balance = 0;
// };

// info change_client(string wanted)
// {
//     info self;
//     self.acount = wanted;
//     self.name = read_string("Please enter your Name: ");
//     self.pin_code = read_string("Please enter your Pin Code: ");
//     self.phone_number = read_string("Please enter your Phone: ");
//     self.balance = (float) positiv_number("Please enter your Blance: ");
//     return self;
// }

// string struct_to_line(info self, string seperator = "#//#")
// {
//     string line = "";
//     line += self.acount + seperator;
//     line += self.name + seperator;
//     line += self.pin_code + seperator;
//     line += self.phone_number + seperator;
//     line += to_string(self.balance);
//     return line;
// }

// void data_to_file(string location, info &self)
// {
//     fstream my_file;
//     my_file.open(location, ios::out | ios::app);

//     if (my_file.is_open())
//     {
//         my_file << struct_to_line(self) << endl;
//         my_file.close();
//     }
// }

// vector <string> split_word(string text, string delimiter)
// {
//     short pos = 0;
//     string word;
//     vector <string> favorite;

//     while ((pos = text.find(delimiter)) != std::string::npos)
//     {
//         word = text.substr(0, pos);
//         if (word != "")
//         {
//             favorite.push_back(word);
//         }
//         text.erase(0, pos + delimiter.length());
//     }
//     if (text != "")
//     {
//         favorite.push_back(text);
//     }
//     return favorite;
// }

// info vector_to_struct (string deta, string seperator = "#//#")
// {
//     info self;
//     vector <string> favorite;

//     favorite = split_word(deta, seperator);

//     self.acount = favorite[0];
//     self.name = favorite[1];
//     self.pin_code = favorite[2];
//     self.phone_number = favorite[3];
//     self.balance = stod(favorite[4]);
//     return self;
// }

// bool client_exists(string location, string account_number)
// {
//     vector <info> favorite;
//     fstream my_file;
//     my_file.open(location, ios::in);

//     if (my_file.is_open())
//     {
//         string line = "";
//         info self;

//         while (getline(my_file, line))
//         {
//             self = vector_to_struct(line);
//             if (self.acount == account_number)
//             {
//                 my_file.close();
//                 return true;
//             }
//             favorite.push_back(self);
//         }
//         my_file.close();
//     }
//     return false;
// }

// info read_login()
// {
//     info self;
//     self.acount = read_string("Please enter your Account: ");

//     while (client_exists(location, self.acount))
//     {
//         cout << "\nClient with [" << self.acount << "] already exists, Enter another Account Number: ";
//         getline(cin >> ws, self.acount);
//     }

//     self.name = read_string("Please enter your Name: ");
//     self.pin_code = read_string("Please enter your Pin Code: ");
//     self.phone_number = read_string("Please enter your Phone: ");
//     self.balance = (float) positiv_number("Please enter your Blance: ");
//     return self;
// }

// void new_client()
// {
//         info self = read_login();
//         data_to_file("Bank's Cutomeres.txt", self);
// }

// void start_add()
// {
//     char more = 'Y';
//     do
//     {
//         new_client();
//         cout << "Client added succesfully, Do you want add again Y/N? ";
//         cin >> more ;
//         // cin.ignore(1, '\n');
//     } while (toupper(more) == 'Y');
// }

// vector <info> load_data(string location)
// {
//     vector <info> favorite;
//     fstream my_file;
//     my_file.open(location, ios::in);

//     if (my_file.is_open())
//     {
//         string line = "";
//         info self;
//         while (getline(my_file, line))
//         {
//             self = vector_to_struct(line);
//             favorite.push_back(self); 
//         }
//         my_file.close();
//     }
//     return favorite;
// }

// vector <info > save_to_file(string location, vector <info> favorite)
// {
//     fstream my_file;
//     my_file.open(location, ios::out);
//     string line = "";
//     if (my_file.is_open())
//     {
//         for (info &x : favorite)
//         {
//             if (x.mark_delete == false)
//             {
//                 line = struct_to_line(x);
//                 my_file << line << endl;
//             }
//         }
//         my_file.close();
//     }
//     return favorite;
// }

// bool search_account(string wanted, vector <info> favorite, info &self)
// {
//     for (info &x : favorite)
//     {
//         if (x.acount == wanted)
//         {
//             self = x;
//             return true;
//         }
//     }
//     return false;
// }

// void print_card(info self)
// {
//     cout << "| " << "Account Number: " << self.acount << endl;
//     cout << "| " << "Pin Code      : " << self.pin_code << endl;
//     cout << "| " << "Client Name   : " << self.name << endl;
//     cout << "| " << "Phone         : " << self.phone_number << endl;
//     cout << "| " << "Balance       : " << self.balance << endl;
// }

// void print_search(string wanted, vector <info> favorite)
// {
//     info self;
//     if (search_account(wanted, favorite, self))
//     {
//         cout << endl;
//         print_card(self);
//     }
//     else
//     {
//         cout << "Sorry, We can't found " << wanted << " from data." << endl;
//     }
// }

// bool update_account(string wanted, vector <info> &favorite)
// {
//     info self;
//     char answer = 'Y';

//     if (search_account(wanted, favorite, self))
//     {
//         print_search(wanted, favorite);
//         cout << "\n\nAre you sure you want to update this client? Y/N: ";
//         cin >> answer;
//         if (toupper(answer) == 'Y')
//         {
//             for (info &x : favorite)
//             {
//                 if (x.acount == wanted)
//                 {
//                     x = change_client(wanted);
//                     break;
//                 }
//             }

//             save_to_file(location, favorite);

//             favorite = load_data(location);
//             cout << "\n\nClient Updated Successfully." << endl;
//             return true;
//         }
//     }
//     else
//     {
//         cout << "\nClient with Account Number (" << wanted << ") doesn't exist." << endl;
//     }
//     return false;
// }

// bool switch_to_delete(string wanted, vector <info> &favorite)
// {
//     for (info &x : favorite)
//     {
//         if (x.acount == wanted)
//         {
//             x.mark_delete = true;
//             return true;
//         }
//     }
//     return false;
// }

// bool delete_account(string wanted, vector <info> &favorite)
// {
//     info self;
//     char answer = 'Y';

//     if (search_account(wanted, favorite, self))
//     {
//         print_search(wanted, favorite);
//         cout << "\n\nAre you sure you want to delete this client? Y/N: ";
//         cin >> answer;
//         if (toupper(answer) == 'Y')
//         {
//             switch_to_delete(wanted, favorite);
//             save_to_file(location, favorite);

//             favorite = load_data(location);
//             cout << "\n\nClient Deleted Successfully." << endl;
//             return true;
//         }
//     }
//     else
//     {
//         cout << "\nClient with Account Number (" << wanted << ") doesn't exist." << endl;
//     }
//     return false;
// }

// bool deposit_for_client(string wanted, vector <info> &favorite)
// {
//     info self;
//     int money = 0;;
//     char answer = 'Y';

//     if (search_account(wanted, favorite, self))
//     {
//         print_search(wanted, favorite);
//         cout << "How many do you want add it: ";
//         cin >> money;
//         cout << "\n\nAre you sure you want to deposit for this client? Y/N: ";
//         cin >> answer;
//         if (toupper(answer) == 'Y')
//         {
//             for (info &x : favorite)
//             {
//                 if (x.acount == wanted)
//                 {
//                     x.balance += money;
//                     break;
//                 }
//             }

//             save_to_file(location, favorite);

//             favorite = load_data(location);
//             cout << "\n\nClient Deposited Successfully." << endl;
//             return true;
//         }
//     }
//     else
//     {
//         cout << "\nClient with Account Number (" << wanted << ") doesn't exist." << endl;
//     }
//     return false;
// }

// bool withdraw_from_client(string wanted, vector <info> &favorite)
// {
//     info self;
//     int money = 0;;
//     char answer = 'Y';

//     if (search_account(wanted, favorite, self))
//     {
//         print_search(wanted, favorite);
//         cout << "How many do you want withdraw it: ";
//         cin >> money;
//         cout << "\n\nAre you sure you want to withdraw for this client? Y/N: ";
//         cin >> answer;
//         if (toupper(answer) == 'Y')
//         {
//             for (info &x : favorite)
//             {
//                 if (x.acount == wanted)
//                 {
//                     x.balance -= money;
//                     break;
//                 }
//             }

//             save_to_file(location, favorite);

//             favorite = load_data(location);
//             cout << "\n\nClient Withdraw Successfully." << endl;
//             return true;
//         }
//     }
//     else
//     {
//         cout << "\nClient with Account Number (" << wanted << ") doesn't exist." << endl;
//     }
//     return false;
// }

// void print_client(info self)
// {
//     cout << "| " << setw(15) << left << self.acount;
//     cout << "| " << setw(10) << left << self.pin_code;
//     cout << "| " << setw(40) << left << self.name;
//     cout << "| " << setw(12) << left << self.phone_number;
//     cout << "| " << setw(12) << left << self.balance;
// }

// void print_data(vector <info> favorite)
// {
//     cout << "\n\t\t\t\t\tClient List (" << favorite.size() << ") Client(s)";
//     cout << "\n--------------------------------------------------------------";
//     cout << "--------------------------------------------\n" << endl;
//     cout << "| " << left << setw(15) << "Account Number";
//     cout << "| " << left << setw(10) << "Pin Code";
//     cout << "| " << left << setw(40) << "Client Name";
//     cout << "| " << left << setw(12) << "Phone";
//     cout << "| " << left << setw(12) << "Balance";
//     cout << "\n--------------------------------------------------------------";
//     cout << "--------------------------------------------\n" << endl;

//     for (info &self : favorite)
//     {
//         print_client(self);
//         cout << " |" << endl;
//     }
//     cout << "\n--------------------------------------------------------------";
//     cout << "--------------------------------------------\n" << endl;
// }

// void print_client_sumarry(info self)
// {
//     cout << "| " << setw(15) << left << self.acount;
//     cout << "| " << setw(40) << left << self.name;
//     cout << "| " << setw(12) << left << self.balance;
// }

// void print_data_sumarry(vector <info> favorite)
// {
//     cout << "\n\t\t\t\t\tClient List (" << favorite.size() << ") Client(s)";
//     cout << "\n--------------------------------------------------------------";
//     cout << "--------------------------------------------\n" << endl;
//     cout << "| " << left << setw(15) << "Account Number";
//     cout << "| " << left << setw(40) << "Client Name";
//     cout << "| " << left << setw(12) << "Balance";
//     cout << "\n--------------------------------------------------------------";
//     cout << "--------------------------------------------\n" << endl;

//     for (info &self : favorite)
//     {
//         print_client_sumarry(self);
//         cout << " |" << endl;
//     }
//     cout << "\n--------------------------------------------------------------";
//     cout << "--------------------------------------------\n" << endl;
// }

// void print_screen_one()
// {
//     cout << "=================================================" << endl;
//     cout << "                The Main Menu Screen" << endl;
//     cout << "=================================================" << endl;
//     cout << "        [1] Show Client List" << endl;
//     cout << "        [2] Add New Client" << endl;
//     cout << "        [3] Find Client" << endl;
//     cout << "        [4] Update Client Info" << endl;
//     cout << "        [5] Delete Client" << endl;
//     cout << "        [6] Transaction To Client" << endl;
//     cout << "        [7] Exit" << endl;
//     cout << "=================================================" << endl;
// }

// void print_screen_tow()
// {
//     cout << "=================================================" << endl;
//     cout << "            The Next Menu Screen (Tow)" << endl;
//     cout << "=================================================" << endl;
//     cout << "        [1] Deposit" << endl;
//     cout << "        [2] Withdraw" << endl;
//     cout << "        [3] Total Balance" << endl;
//     cout << "        [4] Main Menu" << endl;
//     cout << "=================================================" << endl;
// }

// void show_add()
// {
//     cout << "-------------------------------------------------" << endl;
//     cout << "\t Add New Client Screen" << endl;
//     cout << "-------------------------------------------------" << endl;
// }
// void show_find()
// {
//     cout << "-------------------------------------------------" << endl;
//     cout << "\t Find Client Screen" << endl;
//     cout << "-------------------------------------------------" << endl;
// }
// void show_update()
// {
//     cout << "-------------------------------------------------" << endl;
//     cout << "\t Update Client Info Screen" << endl;
//     cout << "-------------------------------------------------" << endl;
// }
// void show_delete()
// {
//     cout << "-------------------------------------------------" << endl;
//     cout << "\t Delete Client Screen" << endl;
//     cout << "-------------------------------------------------" << endl;
// }
// void show_deposit()
// {
//     cout << "-------------------------------------------------" << endl;
//     cout << "\t Deposit For Client Screen" << endl;
//     cout << "-------------------------------------------------" << endl;
// }
// void show_withdraw()
// {
//     cout << "-------------------------------------------------" << endl;
//     cout << "\t Withdraw From Client Screen" << endl;
//     cout << "-------------------------------------------------" << endl;
// }
// void show_end()
// {
//     cout << "-------------------------------------------------" << endl;
//     cout << "\t End Program :-)" << endl;
//     cout << "-------------------------------------------------" << endl;
// }

// void next_main(vector <info> favorite, screen_tow eninfo)
// {
//     system("clear");    
//     switch (eninfo)
//     {
//         case screen_tow::deposit :
//         show_deposit();
//         deposit_for_client(read_string("For whome account do you want found ? "), favorite);
//         back_next_menu();
//         break;
//         case screen_tow::with_draw :
//         show_withdraw();
//         withdraw_from_client(read_string("For whome account do you want found ? "), favorite);
//         back_next_menu();
//         break;
//         case screen_tow::total_balance :
//         print_data_sumarry(favorite);
//         back_next_menu();
//         break;
//         case screen_tow::main_screen :
//         back_main_menu();
//         break;
//     }
// }

// void main_menu(vector <info> favorite, screen_one eninfo)
// {
//     system("clear");    
//     switch (eninfo)
//     {
//         case screen_one::show :
//         print_data(favorite);
//         back_main_menu();
//         break;
//         case screen_one::add :
//         show_add();
//         start_add();
//         back_main_menu();
//         break;
//         case screen_one::find :
//         show_find();
//         print_search(read_string("For whome account do you want found ? "), favorite);
//         back_main_menu();
//         break;
//         case screen_one::update :
//         show_update();
//         update_account(read_string("For whome account do you want found ? "), favorite);
//         back_main_menu();
//         break;
//         case screen_one::del :
//         show_delete();
//         delete_account(read_string("For whome account do you want found ? "), favorite);
//         back_main_menu();
//         break;
//         case screen_one::trans :
//         back_next_menu();
//         break;
//         case screen_one::exito :
//         show_end();
//         cout << endl;
//         break;
//     }
// }

// void Nextow()
// {
//     vector <info> favorite = load_data(location);
//     system("clear");
//     print_screen_tow();
//     screen_tow eninfo = read_screen_tow("Please chose from options 1-4 : ");
//     next_main(favorite, eninfo);
// }

// void Welcom()
// {
//     vector <info> favorite = load_data(location);
//     system("clear");
//     print_screen_one();
//     screen_one eninfo = read_screen_one("Please chose from options 1-7 : ");
//     main_menu(favorite, eninfo);
// }

// void back_next_menu()
// {
//     string blank = "";
//     cout << endl << "\nPress any key and enter to back Main Menu ...";
//     cin >> blank;
//     Nextow();
// }

// void back_main_menu()
// {
//     string blank = "";
//     cout << endl << "\nPress any key and enter to back Main Menu ...";
//     cin >> blank;
//     Welcom();
// }

// int main()
// {
//     Welcom();
//     return 0;
// }






// void screen_one_menu()
// {
//     cout << "=================================================" << endl;
//     cout << printf("%*s", 10, "The Main Menu Screen") << endl;
//     cout << "=================================================" << endl;
//     cout << printf("%*s", 4, "[1] Show Client List") << endl;
//     cout << printf("%*s", 4, "[2] Add New Client") << endl;
//     cout << printf("%*s", 4, "[3] Find Client") << endl;
//     cout << printf("%*s", 4, "[4] Update Client Info") << endl;
//     cout << printf("%*s", 4, "[5] Delete Client") << endl;
//     cout << printf("%*s", 4, "[6] Exit") << endl;
//     cout << "=================================================" << endl;
// }