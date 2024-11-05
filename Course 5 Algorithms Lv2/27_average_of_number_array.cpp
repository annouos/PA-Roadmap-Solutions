
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

int addtional(int ray[100], int lenth)
{
    int sum = 0;
    for(int i = 0; i < lenth; i++)
    {
        sum += ray[i];
    }
    return sum;
}

float average(int ray[100], int lenth)
{
    return (float) addtional(ray, lenth) / lenth;
}


int main()
{
    srand((unsigned)time(NULL));
    int ray[100];
    int lenth = 0;

    fill_array_randomly(ray, lenth);
    print_array(ray, lenth);
    cout << "The average is: " << average(ray, lenth) << endl;
    return 0;
}
