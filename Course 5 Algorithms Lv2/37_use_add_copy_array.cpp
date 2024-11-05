
#include <iostream>
#include <cstdlib>

using namespace std;

int random(int from, int to)
{
    int random = rand() % (to - from + 1) + from;
    return random ;
}

void fill_array_randomly(int ray[100], int &lenth)
{
    cout << "Enter number how many: ";
    cin >> lenth;

    for(int i = 0; i < lenth; i++)
    {
        ray[i] = random(1, 100);
    }
}

void print_array(int ray[100], int lenth)
{
    for(int i = 0; i < lenth; i++)
    {
        cout << ray[i] << " ";
    }
    cout << endl ;
}

void fill_array(int ray[100], int number, int &lenth)
{
    lenth++;
    ray[lenth -1] = number;
}

void copy_array(int ray_1[100], int ray_2[100], int lenth, int lont)
{
    for(int i = 0; i < lenth; i++)
    {
        fill_array(ray_2, ray_1[i], lont);
    }
}


int main()
{
    srand((unsigned)time(NULL));
    int ray_1[100];
    int lenth = 0;
    fill_array_randomly(ray_1, lenth);

    int ray_2[100];
    int lont = 0;
    copy_array(ray_1, ray_2, lenth, lont);

    print_array(ray_1, lenth);
    print_array(ray_2, lenth);
    return 0;
}
