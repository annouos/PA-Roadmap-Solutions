
#include <iostream>

using namespace std;

struct info {
    int ray[100];
    int lenght;
    int temp = 0;
    string line = "\n______________________\n";
};

void loop(info &vib) {
    for (int i = 0; i <= vib.lenght-1; i++)
    {
        cout << "Please enter the number: " << i+1 << endl;
        cout << "--- "; cin >> vib.ray[i];
    } 
}

float calc(info vib) {
    for (int i = 0; i <= vib.lenght-1; i++)
    {
        vib.temp += vib.ray[i];
    }
    return vib.temp;
}

void read(info &vib)

{

    cout << endl << "Please enter how many do you want number \n";
    cin >> vib.lenght;

}

void print(info vib)

{
    for (int i = 0; i <= vib.lenght-1; i++)
    {

    cout << endl << "Number [" << i+1 << "] : " << vib.ray[i];
    cout << vib.line << endl;
    }
    cout << "Total is: "<< calc(vib) << endl;
    cout << endl << "Average is: " << calc(vib) / vib.lenght;
    cout << vib.line << endl;
}

int main() 

{

    info count;

    read(count);
    loop(count);
    print(count);

    return 0;

}
