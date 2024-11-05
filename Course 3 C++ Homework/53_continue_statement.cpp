
#include <iostream>

using namespace std;

struct info {
    int num;
    int j = 0;
    string line = "\n______________________\n";
};

void loop(info vib) {
    for (int i = 1; i <= 5; i++)
    {
        cout << endl << " Please enter number " << i << " : ";
        cin >> vib.num; cout << vib.line << endl;
        if (vib.num > 10) {
            continue;
        }
        vib.j += vib.num;
    }
    cout << endl << vib.j << vib.line << endl;
}

// void read(info &vib)

// {

//     cout << endl << " Please enter five number: ";
//     cin >> vib.num; cout << vib.line << endl;

// }

// void print(info vib)

// {

//     cout << vib.line;
//     cout << endl << " XXX ";
//     cout << vib.line << endl;

// }

int main() 

{

    info ignor;

    loop(ignor);
    // print();

    return 0;

}
