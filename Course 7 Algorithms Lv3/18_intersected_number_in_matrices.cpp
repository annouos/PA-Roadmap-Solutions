
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

string is_it_found(int ray[3][3], short row, short col, int number)
{
    int first_cell = ray[0][0];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (ray[i][j] == number)
            {
                return "Found it";
            }
        }
    }
    return "Not Found";
}

void is_it_repeate(int ray_1[3][3], int ray_2[3][3], short row, short col)
{
    int number = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            number = ray_1[i][j];
            if (is_it_found(ray_2, row, col, number) == "Found it")
            {
                printf("%*d", 4, number);
            }
        }
    }
    cout << endl;
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
    cout << "-----------------" << endl;
    cout << "The intersected numbers are: ";
    is_it_repeate(ray_one, ray_tow, 3, 3);
    return 0;
}



int random_number(int from, int to)
{
    int rand_num = rand() % (to - from + 1) + from;
    return rand_num;
}
