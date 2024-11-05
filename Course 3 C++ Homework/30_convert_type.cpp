
#include <iostream>
#include <string>

using namespace std;

int main() 

{

    string line = "\n_______________________________\n";

    string st1 = "43.22";             //to double, float, and int
    double st_double = stod(st1);
    float st_float = stof(st1);
    int st_int = stoi(st1);

    cout << line;
    cout << endl << "st_double = " << st_double;
    cout << endl << "st_float = " << st_float;
    cout << endl << "st_int = " << st_int;
    cout << line;

    int n1 = 20;                      //to string
    string n1_string = to_string(n1);

    cout << endl << "n1_string = " << n1_string;
    cout << line;

    double n2 = 33.5;                 //to string
    string n2_string = to_string(n2);

    cout << endl << "n2_string = " << n2_string;
    cout << line;

    float n3 = 55.23;                 //to string, and integer (3 ways)
    string n3_string = to_string(n3);

    cout << endl << "n3_string = " << n3_string;
    cout << line;

    int n3_int1 = n3; //way one
    int n3_int2 = (int) n3; //way tow
    int n3_int3 = int(n3); //way three

    cout << endl << "n3_int1 = " << n3_int1;
    cout << endl << "n3_int2 = " << n3_int2;
    cout << endl << "n3_int3 = " << n3_int3;
    cout << line;

    return 0;

}
