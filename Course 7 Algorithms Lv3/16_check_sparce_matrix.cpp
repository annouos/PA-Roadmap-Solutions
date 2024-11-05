
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

short count_matrix(int ray[3][3], short row, short col, int number)
{
    int sum = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (ray[i][j] == number)
            {
                sum++;
            }
        }
    }
    return sum;
}

bool is_it_sparce(int ray[3][3], short row, short col)
{
    short siza = row * col;
    return (count_matrix(ray, row, col, 0) >= siza / 2);
}

void print_result(int ray[3][3], short row, short col)
{
    if (is_it_sparce(ray, 3,3))
        cout << "Yes, it is: Sparce" << endl;
    else
        cout << "No, it is: Not Sparce" << endl;
}


int main()
{
    srand((unsigned)time(nullptr));
    int ray[3][3] = { {0,7,0}, {0,16,0}, {21,34,0} };
    // int ray[3][3];
    // fill_ray(ray, 3, 3);
    print_ray(ray, 3, 3);
    cout << "-----------------" << endl;
    print_result(ray, 3, 3);
    return 0;
}



int random_number(int from, int to)
{
    int rand_num = rand() % (to - from + 1) + from;
    return rand_num;
}



// string is_it_sparce(int ray[3][3], short row, short col)
// {
//     int zero = 0, digit = 0;
//     for (int i = 0; i < row; i++)
//     {
//         for (int j = 0; j < col; j++)
//         {
//             (ray[i][j] == 0) ? zero++ : digit++;
//         }
//     }
//     return (zero > digit) ? "Sparce" : "Not Sparce";
// }