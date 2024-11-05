
#include <iostream>

using namespace std;

int sum(int a, int b, int c = 0, int d = 0)
{
    return (a + b + c + d);
}

int main()
{
    cout << sum(7, 49) << endl;
    cout << sum(7, 49, 16) << endl;
    cout << sum(7, 49, 16, 21) << endl;
    return 0;
}
