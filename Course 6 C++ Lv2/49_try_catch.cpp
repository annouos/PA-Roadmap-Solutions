
#include <iostream>
#include <vector>

using namespace std;

int main()
{

    vector <int> num {7, 14, 21, 28, 35};

    try
    {
        cout << num.at(8);
    }

    catch (...)
    {
        cout << "out of bound" << endl;;
    }

    return 0;
}
