
#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

string clients = "ATM's Clients.txt";

enum atm_screen {quick_draw = 1, normal_draw = 2, deposit = 3, total_balance = 4, main_screen = 5};

enum quick_screen {twenty = 1, fifty = 2, one_handred = 3, tow_handred = 4, four_handred = 5, six_handred = 6, eight_handred = 7, one_thousend = 8, exito = 9};

void back_main_menu();
void login();

atm_screen read_atm_screen(string massage)
{
    int number = 0;
    do
    {
        cout << massage;
        cin >> number;
    } while (number < 0 && number > 8);
    return (atm_screen) number;
}

quick_screen read_quick_screen(string massage)
{
    int number = 0;
    do
    {
        cout << massage;
        cin >> number;
    } while (number < 0 && number > 4);
    return (quick_screen) number;
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
            cout << "Please Tray Again: ";
            cin >> number;
        }
    } while (number < 0 || number % 5);
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

info current_user;

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

vector <info> load_data(string location)
{
    vector <info> favorite;
    info self;
    fstream my_file;
    my_file.open(location, ios::in);

    if (my_file.is_open())
    {
        string line = "";
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

bool withdraw(int money)
{
    vector <info> favorite = load_data(clients);

    char answer = 'Y';

    if (money > current_user.balance)
    {
        cout << "\nYour don't have enugh on your account";
        return false;
    }

    cout << "\n\nAre you sure you want to discount from your account? Y/N: ";
    cin >> answer;

    if (toupper(answer) == 'Y')
    {
        current_user.balance -= money;

        for (info &x : favorite)
        {
            if (x.acount == current_user.acount)
            {
                x.balance = current_user.balance;
                break;
            }
        }

        save_to_file(clients, favorite);
        favorite = load_data(clients);
        cout << "\nYour Balance Is: " << current_user.balance << endl;
        cout << "\nThe Withdraw Successfully." << endl;
        return true;
    }
    return false;
}

bool deposito(short money)
{
    vector <info> favorite = load_data(clients);
    char answer = 'Y';

    cout << "\n\nAre you sure you want to diposit from your account? Y/N: ";
    cin >> answer;

    if (toupper(answer) == 'Y')
    {
        current_user.balance += money;

        for (info &x : favorite)
        {
            if (x.acount == current_user.acount)
            {
                x.balance = current_user.balance;
                break;
            }
        }

        save_to_file(clients, favorite);
        favorite = load_data(clients);
        cout << "\nYour Balance Is: " << current_user.balance << endl;
        cout << "\nThe Diposit Successfully." << endl;
        return true;
    }
    return false;
}

bool check_login()
{
    vector <info> favorite = load_data(clients);
    string username = read_string("Enter username: ");
    string password = read_string("Enter password: ");

    for (const info &client : favorite)
    {
        if (client.name == username && client.pin_code == password)
        {
            current_user = client;
            cout << "\nLogin successful.\n";
            return true;
        }
    }
    return false;
}

void print_login_screen()
{
    cout << "=================================================" << endl;
    cout << "                Login Screen" << endl;
    cout << "=================================================" << endl;
}

void print_atm_screen()
{
    cout << "=================================================" << endl;
    cout << "                ATM Menu Screen" << endl;
    cout << "=================================================" << endl;
    cout << "        [1] Quick Withdraw" << endl;
    cout << "        [2] Normal Withdraw" << endl;
    cout << "        [3] Deposit" << endl;
    cout << "        [4] Check Balance" << endl;
    cout << "        [5] Logout" << endl;
    cout << "=================================================" << endl;
}

void print_quick_screen()
{

    cout << "=================================================" << endl;
    cout << "            Quick Withdraw Screen" << endl;
    cout << "=================================================" << endl;
    cout << "        [1] 20          [2] 50" << endl;
    cout << "        [3] 100         [4] 200" << endl;
    cout << "        [5] 400         [6] 600" << endl;
    cout << "        [7] 800         [8] 1000" << endl;
    cout << "        [9] Exit " << endl;
    cout << "=================================================" << endl;

    cout << "Your Balance Is: " << current_user.balance << endl;
}

void show_withdraw()
{
    cout << "-------------------------------------------------" << endl;
    cout << "\t Normal Withdraw Screen" << endl;
    cout << "-------------------------------------------------" << endl;

    cout << "Your Balance Is: " << current_user.balance << endl;
    int withdraw_amount = positiv_number("\nEnter amount multiple 5 to withdraw: ");
    withdraw(withdraw_amount);
}

void show_deposit()
{
    cout << "-------------------------------------------------" << endl;
    cout << "\t Deposit For Client Screen" << endl;
    cout << "-------------------------------------------------" << endl;

    cout << "Your Balance Is: " << current_user.balance << endl;
    short deposit_amount = positiv_number("\nEnter amount multiple 5 to deposit: ");
    deposito(deposit_amount);
}

void show_balance()
{
    cout << "-------------------------------------------------" << endl;
    cout << "\t Check Blance Screen" << endl;
    cout << "-------------------------------------------------" << endl;

    cout << "\nThe Balance: " << current_user.balance << endl;
}

void quick_main(quick_screen eninfo)
{
    switch (eninfo)
    {
        case quick_screen::twenty :
        withdraw(20);
        cout << "\nYour Balance is: " << current_user.balance << endl;
        break;
        case quick_screen::fifty :
        withdraw(50);
        cout << "\nYour Balance is: " << current_user.balance << endl;
        break;
        case quick_screen::one_handred :
        withdraw(100);
        cout << "\nYour Balance is: " << current_user.balance << endl;
        break;
        case quick_screen::tow_handred :
        withdraw(200);
        cout << "\nYour Balance is: " << current_user.balance << endl;
        break;
        case quick_screen::four_handred :
        withdraw(400);
        cout << "\nYour Balance is: " << current_user.balance << endl;
        break;
        case quick_screen::six_handred :
        withdraw(600);
        cout << "\nYour Balance is: " << current_user.balance << endl;
        break;
        case quick_screen::eight_handred :
        withdraw(800);
        cout << "\nYour Balance is: " << current_user.balance << endl;
        break;
        case quick_screen::one_thousend :
        withdraw(1000);
        cout << "\nYour Balance is: " << current_user.balance << endl;
        break;
        case quick_screen::exito :
        back_main_menu();
        break;
    }
}

void Quick()
{
    system("clear");
    print_quick_screen();
    quick_screen eninfo = read_quick_screen("\nPlease chose from options 1-9 : ");
    quick_main(eninfo);
}

void main_menu(atm_screen eninfo)
{
    system("clear");    
    switch (eninfo)
    {
        case atm_screen::quick_draw :
        Quick();
        back_main_menu();
        break;
        case atm_screen::normal_draw :
        show_withdraw();
        back_main_menu();
        break;
        case atm_screen::deposit :
        show_deposit();
        back_main_menu();
        break;
        case atm_screen::total_balance :
        show_balance();
        back_main_menu();
        break;
        case atm_screen::main_screen :
        // show_end();
        login();
        break;
    }
}

void welcom()
{
    system("clear");
    print_atm_screen();
    atm_screen eninfo = read_atm_screen("\nPlease chose from options 1-5 : ");
    main_menu(eninfo);
}

void login()
{
    system("clear");
    print_login_screen();
    while (!check_login())
    {
        cout << "\nInvalid Username/Password!\n" << endl;
    }
    welcom();
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
