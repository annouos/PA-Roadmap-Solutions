
#include <iostream>
#include <iomanip>

using namespace std;

void fill_ray(int ray[3][4],short row, short col)
{
    short counter;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            counter++;
            ray[i][j] = counter;
        }
    }
}

void print_ray(int ray[3][4],short row, short col)
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

int main()
{
    int ray[3][4];
    fill_ray(ray, 3, 4);
    print_ray(ray, 3, 4);
    return 0;
}
