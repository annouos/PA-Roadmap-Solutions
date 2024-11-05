
#include <iostream>

using namespace std;

int main() 

{

    short a;
    short b;

    cout << endl << "Please enter the first number A: "; cin >> a;
    cout << endl << "Please enter the first number B: "; cin >> b;

    cout << endl << a << " = " << b << " = " << (a == b);
    cout << endl << a << " != " << b << " = " << (a != b);
    cout << endl << a << " > " << b << " = " << (a > b);
    cout << endl << a << " < " << b << " = " << (a < b);
    cout << endl << a << " >= " << b << " = " << (a >= b);
    cout << endl << a << " <= " << b << " = " << (a <= b)<< endl << endl;

    return 0;
    
}
