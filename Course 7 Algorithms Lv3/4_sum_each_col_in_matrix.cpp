
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

int sum_ray(int ray[3][4],short row, short col_number)
{
    int sum = 0;
    for (short j = 0; j < row; j++)
    {
        sum += ray[j][col_number];
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
    for (short i = 0; i < col; i++)
    {
        cout << "\nCol in " << i+1 << " sum = " << sum_ray(ray,row,i) << endl;
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
