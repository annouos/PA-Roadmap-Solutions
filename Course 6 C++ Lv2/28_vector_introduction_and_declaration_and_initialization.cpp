
#include <iostream>
#include <vector>

using namespace std;

vector <string> ray = {"Hot", "Sexy", "Beauty", "Handsome"};

int main()
{
    for (string &X : ray)
    {
        cout << X << endl;
    }
    return 0;
}
