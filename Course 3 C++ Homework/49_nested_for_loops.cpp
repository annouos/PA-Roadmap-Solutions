
#include <iostream>

using namespace std;

struct info {
    string line = "\n______________________\n";
};

// void loop(info vib) // AA > EF > ZZ ;

// {
//     for (int i = 65; i <= 90; i++)
//     {
//         for (int j = 65; j <= 90; j++)
//         {
//             cout << endl << char(i) << " " << char(j);
//             cout << vib.line;
//         }
//     }
// }

// void loop(info vib) // * stars low to high ;

// {
//     for (int i = 0; i <= 10; i--)
//     {
//         for (int j = 0; j <= i; j++)
//         {
//             cout << "*";
//         }
//         cout << endl;
//     }
// }

// void loop(info vib) // * stars high to low ;

// {
//     for (int i = 10; i >= 0; i--)
//     {
//         for (int j = 0; j <= i; j++)
//         {
//             cout << "*";
//         }
//         cout << endl;
//     }
// }

// void loop(info vib) // 123 high to low ;

// {
//     for (int i = 10; i >= 1; i--)
//     {
//         for (int j = 1; j <= i; j++)
//         {
//             cout << j;
//         }
//         cout << endl;
//     }
// }

// void loop(info vib) // 123 low to high ;

// {
//     for (int i = 1; i <= 10; i++)
//     {
//         for (int j = 1; j <= i; j++)
//         {
//             cout << j;
//         }
//         cout << endl;
//     }
// }

// void loop(info vib) // ABC low to high ;

// {
//     for (int i = 1; i <= 6; i++)
//     {
//         for (int j = 1; j <= i; j++)
//         {
//             cout << char(j+64);
//         }
//         cout << endl;
//     }
// }

// void loop(info vib) // 1 x 2 x 3 ;

// {
//     for (int i = 1; i <= 10; i++)
//     {   
//         for (int j = 1; j <= 10; j++)
//         {
//             cout << i << " X " << j << endl;
//         }
//         cout << endl;
//     }
// }

void loop(info vib) // 10 09 08 low to high  deficult;

{
    for (int i = 1; i <= 10; i++)
    {
        for (int j = i; j <= 10; j++)
        {
            cout << j;
        }
        cout << endl;
    }
}


int main() 

{
    info nested;
    loop(nested);

    return 0;

}
