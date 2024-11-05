
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

int random_number(int, int);

void fill_ray(int ray[3][4],short row, short col)
{
    for (short i = 0; i < row; i++)
    {
        for (short j = 0; j < col; j++)
        {
            ray[i][j] = random_number(1, 100);
        }
    }
}

int sum_ray(int ray[3][4],short row_number, short col)
{
    int sum = 0;
    for (short j = 0; j < col; j++)
    {
        sum += ray[row_number][j];
    }
    return sum;
}

void print_ray(int ray[3][4],short row, short col)
{
    for (short i = 0; i < row; i++)
    {
        for (short j = 0; j < col; j++)
        {
            printf("%0*d   ", 2, ray[i][j]);
            // cout << setw(5) << ray[i][j];
        }
        cout << endl;
    }
}

void print_sum(int ray[3][4],short row, short col)
{
    cout << "\nThe sum of matrix is: \n";
    for (short i = 0; i < row; i++)
    {
        cout << "\nRow in " << i+1 << " sum = " << sum_ray(ray,i,col) << endl;
    }
}

int main()
{
    srand((unsigned)time(nullptr));
    int ray[3][4];
    fill_ray(ray, 3, 4);
    print_ray(ray, 3, 4);
    print_sum(ray, 3, 4);
    return 0;
}



int random_number(int from, int to)
{
    int rand_num = rand() % (to - from + 1) + from;
    return rand_num;
}



// best way:

// #include <iostream>
// #include <iomanip>
// #include <cstdlib>

// using namespace std;

// int random_number(int, int);

// void fill_ray(int ray[3][4],short row, short col)
// {
//     for (int i = 0; i < row; i++)
//     {
//         for (int j = 0; j < col; j++)
//         {
//             ray[i][j] = random_number(1, 100);
//         }
//     }
// }

// void print_ray(int ray[3][4],short row, short col)
// {
//     for (int i = 0; i < row; i++)
//     {
//         for (int j = 0; j < col; j++)
//         {
//             printf("%0*d   ", 2, ray[i][j]);
//             // cout << setw(5) << ray[i][j];
//         }
//         cout << endl;
//     }
// }

// void sum_ray(int ray[3][4],short row, short col)
// {
//     int sum = 0;
//     for (int i = 0; i < row; i++)
//     {
//         for (int j = 0; j < col; j++)
//         {
//             sum += ray[i][j];
//         }
//         cout << "\nRow in " << i+1 << " sum = " << sum << endl;
//         sum -= sum;
//     }
// }

// int main()
// {
//     srand((unsigned)time(nullptr));
//     int ray[3][4];
//     fill_ray(ray, 3, 4);
//     print_ray(ray, 3, 4);
//     sum_ray(ray, 3, 4);
//     return 0;
// }



// int random_number(int from, int to)
// {
//     int rand_num = rand() % (to - from + 1) + from;
//     return rand_num;
// }
