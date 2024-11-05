
#include <iostream>
#include <cmath>

using namespace std;

void recursion(float n, float m)
{
    if (n <= m)
    {
        cout << pow(n, m) << endl;
        recursion(n + 1, m);
    }
}

int main()
{
    recursion(1, 7);
    return 0;
}



// m to down n

// #include <iostream>

// using namespace std;

// void recursion(int n, int m)
// {
//     if (n <= m)
//     {
//         cout << m << endl;
//         recursion(n, m - 1);
//     }
// }

// int main()
// {
//     recursion(1, 7);
//     return 0;
// }



// n to up m

// #include <iostream>

// using namespace std;

// void recursion(int n, int m)
// {
//     if (n <= m)
//     {
//         cout << n << endl;
//         recursion(n + 1, m);
//     }
// }

// int main()
// {
//     recursion(1, 7);
//     return 0;
// }