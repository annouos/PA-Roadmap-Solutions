
#include <iostream>

using namespace std;


char GetLastCharacter(string S1)
{
    return S1[ S1.length() -1 ];
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
