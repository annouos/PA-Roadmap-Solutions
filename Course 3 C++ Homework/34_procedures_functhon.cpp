
#include <iostream>

using namespace std;

void procedure_nums() {

    string line = "\n______________________\n";
    int num_1;
    int num_2;

    cout << endl << " Please enter the first number: "; cin >> num_1;
    cout << endl << " Please enter the tow number: "; cin >> num_2;

    cout << line;
    cout << endl << " The calculate of numbers is: " << num_1 + num_2;
    cout << line << endl;

}

int function_nums() {

    string line = "\n______________________\n";
    int num_1;
    int num_2;

    cout << line;
    cout << endl << " Please enter the first number: "; cin >> num_1;
    cout << endl << " Please enter the tow number: "; cin >> num_2;

    return num_1 + num_2;

}

int main() 

{
    procedure_nums();
    cout << function_nums() << endl;
    cout << "\n_______________________________";

    return 0;

}
