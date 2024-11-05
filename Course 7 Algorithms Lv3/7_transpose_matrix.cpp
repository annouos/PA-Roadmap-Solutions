
#include <iostream>
#include <iomanip>

using namespace std;

void fill_ray(int ray[3][3],short row, short col)
{
    short counter = 0;
    for (short i = 0; i < row; i++)
    {
        for (short j = 0; j < col; j++)
        {
            counter++;
            ray[i][j] = counter;
        }
    }
}

void fill_ray_transpose(int ray[3][3], int ray_transpose[3][3], short row, short col)
{
    for (short i = 0; i < row; i++)
    {
        for (short j = 0; j < col; j++)
        {
            ray_transpose[i][j] = ray[j][i];
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
    int ray[3][3];
    int ray_transpose[3][3];
    fill_ray(ray, 3, 3);
    fill_ray_transpose(ray, ray_transpose, 3, 3);
    print_ray(ray, 3, 3);
    cout << "-------------------------" << endl;
    print_ray(ray_transpose, 3, 3);
    return 0;
}
