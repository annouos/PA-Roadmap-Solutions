
#include <iostream>
#include <cstdlib>
#include <cmath>

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
        ray[i] = random(-100, 100);
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

int count_even(int ray[100], int lenth)
{
    int counter = 0;
    for(int i = 0; i < lenth; i++)
    {
        if(ray[i] >= 0)
            counter++;
    }
    return counter;
}



int main()
{
    srand((unsigned)time(NULL));

    int ray[100], lenth = 0;
    fill_array_randomly(ray, lenth);
    print_array(ray, lenth);
    cout << count_even(ray, lenth) << endl;
    return 0;
}
