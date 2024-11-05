
#include <iostream>
#include <vector>

using namespace std;

int main()
{

    vector <int> num {7, 14, 21, 28, 35};

    for (const int &i : num)
    {
        cout << i << "  ";
    }

    cout << "\nUpdate vector: ";

    for ( int &i : num)
    {
        i = 7;
        cout << i << "  ";
    }

    num[1] = 16;
    num.at(2) = 25;
    num.at(4) = 31;

    cout << "\nUpdate vector: ";

    for (const int &i : num)
    {
        cout << i << "  ";
    }

    cout << endl;

    return 0;
}
