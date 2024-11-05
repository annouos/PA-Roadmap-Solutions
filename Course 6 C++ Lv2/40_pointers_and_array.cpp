
#include <iostream>

using namespace std;



int main()
{

    int ray[4] = {7, 14, 21, 28};

    int * ptr = ray;

    cout << "Address array: " << endl;

    cout << ptr << endl;
    cout << ptr + 1 << endl;
    cout << ptr + 2 << endl;
    cout << ptr + 3 << endl;

    cout << "\nValue array: " << endl;

    cout << * (ptr) << endl;
    cout << * (ptr + 1) << endl;
    cout << * (ptr + 2) << endl;
    cout << * (ptr + 3) << endl;

    return 0;
}
