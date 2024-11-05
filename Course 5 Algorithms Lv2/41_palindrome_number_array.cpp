
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

void fill_array(int ray[100], int &lenth)
{
    lenth = 6;
    ray[0] = 10; 
    ray[1] = 20; 
    ray[2] = 30; 
    ray[3] = 30; 
    ray[4] = 20; 
    ray[5] = 10; 
}

void print_array(int ray[100], int lenth)
{
    for(int i = 0; i < lenth; i++)
    {
        cout << ray[i] << " ";
    }
    cout << endl ;
}

bool palindrome_check(int ray[100], int lenth)
{
    for(int i = 0; i < lenth; i++)
    {
        if(ray[i] != ray[lenth-i-1] )
        {
            return false;
        }
    }
    return true;
}

void palindrome_array(int ray[100], int lenth)
{
    if(palindrome_check(ray, lenth))
        cout << " It's palindrome array" << endl;
    else
        cout << " It's NOT palindrome array" << endl;
}

int main()
{
    srand((unsigned)time(NULL));

    int ray[100], lenth = 0;
    fill_array(ray, lenth);

    print_array(ray, lenth);
    palindrome_array(ray, lenth);
    return 0;
}
