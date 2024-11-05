
#include <iostream>

using namespace std;

int main()
{

    int * ptr_x;
    float * ptr_y;

    ptr_x = new int;
    ptr_y = new float;

    * ptr_x = 35;
    * ptr_y = 42.1;

    cout << * ptr_x << endl;
    cout << * ptr_y << endl;

    delete ptr_x;
    delete ptr_y;

    cout << endl;

    return 0;
}
