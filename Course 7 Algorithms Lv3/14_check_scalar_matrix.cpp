
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

string is_it_scalar(int ray[3][3], short row, short col)
{
    int first_cell = ray[0][0];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i == j && ray[i][j] != first_cell)
            {
                return "Not Scalar";
            }
            else if (i != j && ray[i][j] != 0)
            {
                return "Not Scalar";
            }
        }
    }
    return "Scalar";
}

int main()
{
    srand((unsigned)time(nullptr));
    int ray[3][3] = { {8,0,0}, {0,8,0}, {0,0,8} };
    // int ray[3][3];
    // fill_ray(ray, 3, 3);
    print_ray(ray, 3, 3);
    cout << "-----------------" << endl;
    cout << "The Matrices is: " << is_it_scalar(ray, 3, 3) << endl;
    return 0;
}



int random_number(int from, int to)
{
    int rand_num = rand() % (to - from + 1) + from;
    return rand_num;
}

