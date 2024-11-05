
#include <iostream>

using namespace std;

string read(string massage)
{
    string text;
    cout << massage;
    cin >> text;
    return text;
}

bool login()
{
    string pin;
    do
    {
        pin = read("Please enter your PIN: ");
        if(pin == "1234")
            return 1;
        else
            {
               cout << "You Bitch,, Tray Again !! " << endl;
            }
    } while (pin != "1234");
    return 0;
}

void print()
{
    if(login())
        cout << "Your Balance is: 7000";
}

int main()
{
    print();
    return 0;
}





// #include <iostream>

// using namespace std;

// struct info {

//     int code_pin;
//     string line = "\n______________________\n";
// };

// string checking(int rino) {

//     if (rino == 1234) {
//         return "Correct.. Your balance is : 7000";
//     }
//     else {
//         return "Wrong Code PIN !!";
//     }

// }

// void read(info &vib)

// {

//     cout << endl << "Please enter your PIN: "; cin >> vib.code_pin;

// }

// void print(info vib)

// {

//     cout << vib.line;
//     cout << endl << checking(vib.code_pin);
//     cout << vib.line << endl;

// }

// int main() 

// {

//     info atm;

//     read(atm);
//     print(atm);

//     return 0;

// }
