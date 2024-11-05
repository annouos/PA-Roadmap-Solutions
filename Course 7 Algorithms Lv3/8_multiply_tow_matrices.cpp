
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

int random_number(int from, int to)
{
    int num_random = rand() % (to - from +1) + from;
    return num_random;
}

void fill_ray(int ray[3][3], short row, short col)
{
    for (short i = 0; i < row; i++)
    {
        for (short j = 0; j < col; j++)
        {
            ray[i][j] = random_number(1, 10);
        }
    }
}

void fill_ray_three(int ray_1[3][3], int ray_2[3][3], int ray_3[3][3], short row, short col)
{
    for (short i = 0; i < row; i++)
    {
        for (short j = 0; j < col; j++)
        {
            ray_3[i][j] = ray_1[i][j] * ray_2[i][j];
        }
    }
}

void print_ray(int ray[3][3],short row, short col)
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

int main()
{
    srand((unsigned)time(nullptr));
    int ray_one[3][3];
    int ray_tow[3][3];
    int ray_three[3][3];

    fill_ray(ray_one, 3, 3);
    fill_ray(ray_tow, 3, 3);
    fill_ray_three(ray_one, ray_tow, ray_three, 3, 3);
    print_ray(ray_one, 3, 3);
    cout << "------------------" << endl;
    print_ray(ray_tow, 3, 3);
    cout << "------------------" << endl;
    print_ray(ray_three, 3, 3);
    return 0;
}
