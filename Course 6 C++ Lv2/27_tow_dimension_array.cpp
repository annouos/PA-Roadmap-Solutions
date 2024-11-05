
#include <iostream>
#include <iomanip>
#include <cstdio>

using namespace std;


int main()
{
    int x[10][10];

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            x[i][j] = (i + 1) * (j + 1);
        }
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%0*d ", 2, x[i][j]);
        }
        cout << endl;
    }

    return 0;
}




// #include <iostream>
// #include <iomanip>
// #include <cstdio>

// using namespace std;

// void print_multiple()
// {
//     for (int i = 1; i <= 10; i++)
//     {
//         for (int j = 1; j <= 10; j++)
//         {
//             printf("%0*d ", 2, i*j);
//         }
//         cout << endl;
//     }
// }

// int main()
// {
//     print_multiple();
//     return 0;
// }






// #include <iostream>
// #include <iomanip>
// #include <cstdio>

// using namespace std;

// void zero(int num)
// {
//     if (num < 10)
//         printf("0%d  ", num);
//     else
//         printf("%d  ", num);
// }

// void print_multiple()
// {
//     for (int i = 1; i <= 10; i++)
//     {
//         for (int j = 1; j <= 10; j++)
//         {
//             zero(i*j);
//         }
//         cout << endl;
//     }
// }

// int main()
// {
//     print_multiple();
//     return 0;
// }
