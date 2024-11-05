
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

int positiv_number(string massage)
{
    int number = 0;
    do
    {
        cout << massage;
        cin >> number;
    } while (number < 0);
    return number;
}

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

int main()
{
    srand((unsigned)time(nullptr));
    int ray[3][3];
    fill_ray(ray, 3, 3);
    print_ray(ray, 3, 3);
    cout << "-----------------" << endl;
    int number = positiv_number("What do you want found? Enter a number: ");
    cout << "The Number is: " << is_it_found(ray, 3, 3, number) << endl;
    return 0;
}



int random_number(int from, int to)
{
    int rand_num = rand() % (to - from + 1) + from;
    return rand_num;
}

