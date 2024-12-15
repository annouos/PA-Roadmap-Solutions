
#include <iostream>

using namespace std;


char GetLastCharacter(string S1)
{
    int n = S1.length() -1;

    for (int i = 0; i <= n; i++)
    {
        if (i == n)
        {
            return S1[n];
        }
    }

    return 'F';
}

int main()
{
    // string GetLastCharacter(string S1)
    // {
    //     string S2 = "88";
    //     return S1 + S2;
    // };

    cout << GetLastCharacter("How are you my love") << endl;

    return 0;
}
