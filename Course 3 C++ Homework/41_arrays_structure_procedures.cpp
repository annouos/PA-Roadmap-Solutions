
#include <iostream>

using namespace std;

struct info {

    int lenght;
    string full_name;
    short age;
    string knowldge;
    string telegram;
    string city;
    string country;
    int phone;

    string line = "\n______________________\n";

};


void read(info &vib)

{
    cout << endl << "Your name: "; cin.ignore(1,'\n'); getline(cin, vib.full_name);
    cout << endl << "Your age: "; cin >> vib.age;
    cout << endl << "Your study: "; cin.ignore(1,'\n'); getline(cin, vib.knowldge);
    cout << endl << "Your telegram: "; cin >> vib.telegram;
    cout << endl << "Your city: "; cin >> vib.city;
    cout << endl << "Your country: "; cin >> vib.country;
    cout << endl << "Your phone: "; cin >> vib.phone;
    cout << vib.line;
}

void print(info vib)

{
    cout << endl << "Name: " << vib.full_name;
    cout << endl << "Age: " << vib.age;
    cout << endl << "Study: " << vib.knowldge;
    cout << endl << "Telegram: " << vib.telegram;
    cout << endl << "City: " << vib.city;
    cout << endl << "Country: " << vib.country;
    cout << endl << "Phone: " << vib.phone;
    cout << vib.line << endl;
}

void loop(info vib[100]) {
    cout << endl << "Please enter how many person: ";
    cout << "--- "; cin >> vib->lenght;
    for (int i = 0; i < vib->lenght; i++)
    {
        read(vib[i]);
    }
    for (int i = 0; i < vib->lenght; i++)
    {
        print(vib[i]);
    }

}

int main() 

{

    info person[100];
    loop(person);

    return 0;

}



// #include <iostream>

// using namespace std;

// enum favorite {Black, White, Red, Yellow, Blue, Green, Vantage};

// struct info {

//     string full_name;
//     short age;
//     string country;
//     string knowlge;
//     int phone;

//     string line = "\n______________________\n";

//     favorite color = favorite::Yellow;

// };

// void read(info &vib)

// {

//     cout << endl << "Please enter your Full name: "; cin.ignore(1, '\n'); getline(cin, vib.full_name);
//     cout << endl << "Please enter your age: "; cin >> vib.age;
//     cout << endl << "Please enter where are you from: "; cin >> vib.country;
//     cout << endl << "Please enter What are you study: "; cin.ignore(1, '\n'); getline(cin, vib.knowlge) ;
//     cout << endl << "Please enter your phone number: "; cin >> vib.phone;
//     cout << vib.line;

// }

// void print(info vib)

// {

//     string line = "\n______________________\n";

//     cout << endl << "Your Name is: " << vib.full_name;
//     cout << endl << "Your Age is: " << vib.age;
//     cout << endl << "Your Country is: " << vib.country;
//     cout << endl << "Your Studies is: " << vib.knowlge;
//     cout << endl << "Your Color Favorite is: " << vib.color;
//     cout << endl << "Your Number is: " << vib.phone;
//     cout << line << endl;

// }

// void read_more(info profile[2])

// {

//     read(profile[0]);
//     read(profile[1]);

// }

// void print_more(info profile[2])

// {

//     print(profile[0]);
//     print(profile[1]);

// }



// int main() 

// {

//     info profile[2];

//     read_more(profile);    
//     print_more(profile);

//     return 0;

// }
