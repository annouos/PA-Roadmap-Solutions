
#include <iostream>

using namespace std;

enum Gender {male, famle};
enum isMarried {single, married};

struct Soucial {
    int Phone;
    string Telegram;
};

struct Adress {
    string City;
    string Country;
    short StreetNo;
    Soucial soucial;
};

struct Info {
    string Name;
    short Age;
    int Salary;
    Adress Path;
    string Stars = "\n____________________________\n";

    Gender sex;
    isMarried status;
};

void read_profile(Info &vib) {

    cout << endl << "What's your name ? "; getline(cin, vib.Name); 
    cout << endl << "How old are you ? "; cin >> vib.Age;
    // cout << endl << "What's your gender ? "; cin >> sex;
    cout << endl << "Where are you from country ? "; cin >> vib.Path.Country;
    cout << endl << "Where are you from city ? "; cin >> vib.Path.City;
    cout << endl << "What's your street NO. ? "; cin >> vib.Path.StreetNo;
    cout << endl << "How much your salary per month ? "; cin >> vib.Salary;
    // cout << endl << "Are you married ? "; cin >> status;
    cout << endl << "What's your phone number ? "; cin >> vib.Path.soucial.Phone;
    cout << endl << "What's your adrees on Telegram ? "; cin >> vib.Path.soucial.Telegram;

}

void print_profile(Info vib) {

    vib.sex = Gender::famle;
    vib.status = isMarried::single;

    cout << vib.Stars << endl;
    cout << "Name: " << vib.Name << endl;
    cout << "Age: " << vib.Age << endl;
    cout << "Gender: " << vib.sex << endl;
    cout << "Married: " << vib.status << endl;
    cout << "Street NO: " << vib.Path.StreetNo << " , ";
    cout << "City: " << vib.Path.City << " , ";
    cout << "Country: " << vib.Path.Country << endl;
    cout << "Month Salary: " << vib.Salary << endl;
    cout << "Yearly Salary: " << vib.Salary * 12 << endl;
    cout << "Phone Number: " << vib.Path.soucial.Phone << endl;
    cout << "Telegram: " << vib.Path.soucial.Telegram;
    cout << vib.Stars << endl;

}


int main()

{

    Info client_1;

    read_profile(client_1);
    print_profile(client_1);

    return 0;

}

