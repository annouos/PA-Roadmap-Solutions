
#include <iostream>

using namespace std;


short Devide(short N)
{
    short x = N;

    while (x > 0)
    {
        x /= 2;
    }

    return x;
}

int main()
{
    // string GetLastCharacter(string S1)
    // {
    //     string S2 = "88";
    //     return S1 + S2;
    // };

    cout << Devide(16) << endl;

    return 0;
}
