
#include <iostream>
#include <string>

using namespace std;

int main() 

{

    string line = "\n______________________\n";
    string string1, string2, string3;

    cout << line;
    cout << endl << "Please enter string one: "; getline(cin, string1);
    cout << endl << "Please enter string tow: "; cin >> string2;
    cout << endl << "Please enter string three: "; cin >> string3;
    cout << line;
    
    int int_string2 = stoi(string2);
    int int_string3 = stoi(string3);

    cout << line;
    cout << endl << "The lenght of string one is: " << string1.length();
    cout << endl << "Charchter position at 0 2 4 7 is: " << string1[7];
    cout << endl << "Concatenating string tow and string three: " << string2 + string3;
    cout << endl << " 5 * 10 = " << int_string2 * int_string3;
    cout << line;

    return 0;

}
