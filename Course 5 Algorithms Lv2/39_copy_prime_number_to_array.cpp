
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

enum eninfo {prime = 1, not_prime = 2};

eninfo checking(int num)
{
    int devide = round(num / 2);
    for(int counter = 2; counter <= devide; counter++)
    {
        if(num % counter == 0)
            return eninfo::not_prime ;
    }
    return eninfo::prime;
}

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

void fill_array(int ray[100], int number, int &lent)
{
    lent++;
    ray[lent -1] = number;
}

void prime_in_array(int ray_1[100], int ray_2[100], int lenth, int &lont)
{
    for(int i = 0; i < lenth; i++)
    {
        if(checking(ray_1[i]) == eninfo::prime)
        {
            fill_array(ray_2, ray_1[i], lont);
        }
    }
}



int main()
{
    srand((unsigned)time(NULL));
    int ray_1[100];
    int lenth = 0, lont = 0;
    fill_array_randomly(ray_1, lenth);

    int ray_2[100];
    prime_in_array(ray_1, ray_2, lenth, lont);

    print_array(ray_1, lenth);
    print_array(ray_2, lont);
    return 0;
}
