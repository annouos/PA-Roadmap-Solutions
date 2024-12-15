
#include <iostream>

using namespace std;


int MultiplicationSum(short N)
{
    int Sum = 0;

    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            Sum += (i * j);
        }
    }

    return Sum;
}

int main()
{
    // string GetLastCharacter(string S1)
    // {
    //     string S2 = "88";
    //     return S1 + S2;
    // };

    cout << MultiplicationSum(7) << endl;

    return 0;
}
