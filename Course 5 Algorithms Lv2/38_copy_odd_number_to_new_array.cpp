
#include <iostream>
#include <cstdlib>

using namespace std;

int random(int from, int to)
{
    int random = rand() % (to - from + 1) + from;
    return random ;
}

void fill_array_randomly(int ray[100], int &lenth)
{
    cout << "Enter number how many: ";
    cin >> lenth;

    for(int i = 0; i < lenth; i++)
    {
        ray[i] = random(1, 100);
    }
}

void print_array(int ray[100], int lenth)
{
    for(int i = 0; i < lenth; i++)
    {
        cout << ray[i] << " ";
    }
    cout << endl ;
}

void fill_array(int ray[100], int number, int &lent)
{
    lent++;
    ray[lent -1] = number;
}

void odd_or_even_array(int ray_1[100], int ray_2[100], int lenth, int &lont)
{
    for(int i = 0; i < lenth; i++)
    {
        if(ray_1[i] % 2 != 0)
        {
            fill_array(ray_2, ray_1[i], lont);
        }
    }
}



int main()
{
    srand((unsigned)time(NULL));
    int ray_1[100];
    int lenth = 0, lont = 0;
    fill_array_randomly(ray_1, lenth);

    int ray_2[100];
    odd_or_even_array(ray_1, ray_2, lenth, lont);

    print_array(ray_1, lenth);
    print_array(ray_2, lont);
    return 0;
}






// #include <iostream>
// #include <cstdlib>

// using namespace std;

// enum eninfo {odd = 1, even = 2};

// int positiv_number(string massage)
// {
//     int number = 0;
//     do
//     {
//         cout << massage;
//         cin >> number;
//     } while (number < 0);
//     return number;
// }

// eninfo check(int number)
// {
//     if(number % 2 == 0)
//         return eninfo::even;
//     else {
//         return eninfo::odd ;
//     }
// }

// int random(int from, int to)
// {
//     int random = rand() % (to - from + 1) + from;
//     return random ;
// }

// void fill_array_randomly(int ray[100], int &lenth)
// {
//     cout << "Enter number how many: ";
//     cin >> lenth;

//     for(int i = 0; i < lenth; i++)
//     {
//         ray[i] = random(1, 100);
//     }
// }

// void print_array(int ray[100], int lenth)
// {
//     for(int i = 0; i < lenth; i++)
//     {
//         cout << ray[i] << " ";
//     }
//     cout << endl ;
// }

// void fill_array(int ray[100], int number, int &lent)
// {
//     lent++;
//     ray[lent -1] = number;
// }

// void odd_or_even_array(int ray_1[100], int ray_2[100], int lenth, int &lont)
// {
//     for(int i = 0; i < lenth; i++)
//     {
//         if(check(ray_1[i]) == eninfo::odd)
//         {
//             fill_array(ray_2, ray_1[i], lont);
//         }
//     }
// }


// int main()
// {
//     srand((unsigned)time(NULL));
//     int ray_1[100];
//     int lenth = 0, lont = 0;
//     fill_array_randomly(ray_1, lenth);

//     int ray_2[100];
//     odd_or_even_array(ray_1, ray_2, lenth, lont);

//     print_array(ray_1, lenth);
//     print_array(ray_2, lont);
//     return 0;
// }
