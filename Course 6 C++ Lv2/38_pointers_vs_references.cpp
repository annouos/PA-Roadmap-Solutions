
#include <iostream>

using namespace std;



int main()
{
    int a = 7;
    int &x = a;

    // print address
    cout << &a << endl;
    cout << &x << endl;

    // print value
    cout << a << endl;
    cout << x << endl;

    int * p = &a;

    cout << p << endl;
    cout << *p << endl;

    int z = 21;

    p = &z;

    cout << p << endl;
    cout << *p << endl;

    // &x = z; // WRONG

    return 0;
}
