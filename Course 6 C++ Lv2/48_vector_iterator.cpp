
#include <iostream>
#include <vector>

using namespace std;

int main()
{

    vector <int> num {7, 14, 21, 28, 35};

    vector <int> ::iterator iter;

    for (iter = num.begin(); iter != num.end(); iter++)
    {
        cout << * iter << endl;
    }

    return 0;
}
