
#include <iostream>

using namespace std;

struct info {
    int ray[10] = {10,20,30,40,50,60,70,80,90,100};
    string line = "\n______________________\n";
};

void loop(info vib) {
    for (int i = 0; i < 10; i++)
    {
        cout << "   " << vib.ray[i] << endl;
        if (vib.ray[i] == 40) {
            cout << "Found it at: " << i+1 << vib.line << endl;
            break;
        }
    }
}

// void read(info &vib)

// {

//     cout << endl << " XXX ";

// }

// void print(info vib)

// {

//     cout << vib.line;
//     cout << endl << " XXX ";
//     cout << vib.line << endl;

// }

int main() 

{

    info raaay;

    loop(raaay);

    return 0;

}
