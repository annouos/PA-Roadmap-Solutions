
#include <iostream>

using namespace std;

int main()
{

    void * ptr; // in General

    float pi = 3.14;
    ptr = &pi;

    cout << "Address PI is: " << ptr << endl;

    // wrong to print or edit like this:
    // cout << * ptr << endl;
    // * ptr = 49.1;

    cout << * (static_cast <float *> (ptr)) << endl;
    * (static_cast <float *> (ptr)) = 49.1;
    cout << * (static_cast <float *> (ptr)) << endl;

    int x = 7;
    ptr = &x;

    cout << "Address X is: " << ptr << endl;

    * (static_cast <int *> (ptr)) = 16;
    cout << * (static_cast <int *> (ptr)) << endl;

    return 0;
}
