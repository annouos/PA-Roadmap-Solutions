
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

int random_number(int, int);

void fill_ray(int ray[3][3],short row, short col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            ray[i][j] = random_number(1, 10);
        }
    }
}

int sum_matrix(int ray[3][3], int row, int col)
{
    int sum = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            sum += ray[i][j];
        }
    }
    return sum;
}

void print_ray(int ray[3][3],short row, short col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%0*d   ", 2, ray[i][j]);
            // cout << setw(5) << ray_one[i][j];
        }
        cout << endl;
    }
}

string is_it_equal(int ray_1[3][3], int ray_2[3][3], short row, short col)
{
    if (sum_matrix(ray_1, row, col) == sum_matrix(ray_2, row, col))
        return "Equal";
    else
        return "Not Equal";
}

int main()
{
    srand((unsigned)time(nullptr));
    int ray_one[3][3];
    int ray_tow[3][3];
    fill_ray(ray_one, 3, 3);
    fill_ray(ray_tow, 3, 3);
    print_ray(ray_one, 3, 3);
    cout << "-----------------" << endl;
    print_ray(ray_tow, 3, 3);
    cout << "---------------- \nThe Matrix One is: ";
    cout << sum_matrix(ray_one, 3, 3);
    cout << " & The Matrix Tow is: ";
    cout << sum_matrix(ray_tow, 3, 3) << endl;
    cout << "The Matrices is: " << is_it_equal(ray_one, ray_tow, 3, 3) << endl;
    return 0;
}



int random_number(int from, int to)
{
    int rand_num = rand() % (to - from + 1) + from;
    return rand_num;
}
