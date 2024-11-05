
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

void hard_core_add(int ray[100], int &lenth)
{
    lenth = 10;
    ray[0] = 10; 
    ray[1] = 10; 
    ray[2] = 10; 
    ray[3] = 50; 
    ray[4] = 50; 
    ray[5] = 70; 
    ray[6] = 70; 
    ray[7] = 70; 
    ray[8] = 70; 
    ray[9] = 90;  
}

short search_array(int ray[100], int number, int lenth)
{
    for(int i = 0; i < lenth; i++)
    {
        if(number == ray[i])
        {
            return i;
        }
    }
    return -1;
}

bool number_in_array(int ray[100], int number, int lenth)
{
    return search_array(ray, number, lenth) != -1;
}

void fill_array(int ray[100], int number, int &lent)
{
    lent++;
    ray[lent -1] = number;
}

void print_array(int ray[100], int lenth)
{
    for(int i = 0; i < lenth; i++)
    {
        cout << ray[i] << " ";
    }
    cout << endl ;
}

void distinct_in_array(int ray_1[100], int ray_2[100], int lenth, int &lont)
{
    for(int i = 0; i < lenth; i++)
    {
        if(!number_in_array(ray_2, ray_1[i], lont))
        {
            fill_array(ray_2, ray_1[i], lont);
        }
    }
}


int main()
{
    srand((unsigned)time(NULL));

    int ray_1[100], ray_2[100], lenth = 0, lont = 0;

    hard_core_add(ray_1, lenth);
    print_array(ray_1, lenth);

    distinct_in_array(ray_1, ray_2, lenth, lont);
    print_array(ray_2, lont);

    return 0;
}
