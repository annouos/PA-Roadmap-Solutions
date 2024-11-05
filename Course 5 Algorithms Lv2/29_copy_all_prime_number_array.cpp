
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

enum eninfo {prime = 1, not_prime = 2};

eninfo checking(int number)
{
    int remainder = round(number / 2);
    for(int i = 2; i <= remainder; i++)
    {
        if(number % i == 0)
            return eninfo::not_prime;
    }
    return eninfo::prime;
}

int random(int from, int to)
{
    int random = rand() % (to - from + 1) + from;
    return random ;
}

void fill_array_randomly(int ray[100], int &lenth_1)
{
    cout << "Enter number how many: ";
    cin >> lenth_1;

    for(int i = 0; i < lenth_1; i++)
    {
        ray[i] = random(1, 100);
    }
}


void copy_array(int ray_first[100], int ray_tow[100], int lenth, int &lenth_2)
{
    int counter = 0;
    for(int i = 0; i < lenth; i++)
    {
        if(checking(ray_first[i]) == eninfo::prime)
        {
            ray_tow[counter] = ray_first[i];
            counter++;
        }
    }
    lenth_2 = counter;
}

void print_array(int ray[100], int lenth)
{
    for(int i = 0; i < lenth; i++)
    {
        cout << ray[i] << " ";
    }
    cout << endl ;
}


int main()
{
    srand((unsigned)time(NULL));
    
    int ray_1[100], lenth_1;
    fill_array_randomly(ray_1, lenth_1);

    int ray_2[100], lenth_2 = 0;
    copy_array(ray_1, ray_2, lenth_1, lenth_2);

    print_array(ray_1, lenth_1);
    print_array(ray_2, lenth_2);
    return 0;
}
