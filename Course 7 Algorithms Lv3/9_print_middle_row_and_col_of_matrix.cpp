
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
            ray[i][j] = random_number(1, 100);
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
            // cout << setw(5) << ray[i][j];
        }
        cout << endl;
    }
}

void print_middle_row(int ray[3][3], short row, short col)
{
    short mid = row / 2;
    for (int j = 0; j < col; j++)
    {
        printf("%0*d   ", 2, ray[mid][j]);
    }
    cout << endl;
}

void print_middle_col(int ray[3][3], short row, short col)
{
    short mid = col / 2;
    for (int j = 0; j < row; j++)
    {
        printf("%0*d   ", 2, ray[j][mid]);
    }
    cout << endl;
}

int main()
{
    srand((unsigned)time(nullptr));
    int ray[3][3];
    fill_ray(ray, 3, 3);
    print_ray(ray, 3, 3);
    cout << "---------------" << endl;
    print_middle_row(ray, 3, 3);
    cout << "---------------" << endl;
    print_middle_col(ray, 3, 3);
    return 0;
}



int random_number(int from, int to)
{
    int rand_num = rand() % (to - from + 1) + from;
    return rand_num;
}
