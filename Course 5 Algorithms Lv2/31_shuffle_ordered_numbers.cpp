
#include <iostream>
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

void swap(int &A, int &B)
{
    int Temp = 0;

    Temp = A;
    A = B;
    B = Temp;
}

int random(int from, int to)
{
    int random = rand() % (to - from + 1) + from;
    return random ;
}

void ordered(int ray[100], int lenth)
{
        for(int i = 0; i < lenth; i++)
    {
        ray[i] = i+1;
    }
}

void shuffle(int ray[100], int lenth)
{
        for(int i = 0; i < lenth; i++)
    {
        swap(ray[random(1, lenth)-1], ray[random(1, lenth)-1]);
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


int main()
{
    srand((unsigned)time(NULL));
    int lenth = positiv_number("Please enter number to what: ");
    int ray[100];

    ordered(ray, lenth);
    print_array(ray, lenth);
    shuffle(ray, lenth);
    print_array(ray, lenth);
    return 0;
}
