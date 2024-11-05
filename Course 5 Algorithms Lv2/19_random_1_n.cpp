
#include <iostream>
#include <cstdlib>

using namespace std;

int random(int from, int to)
{
    int random = rand() % (to - from + 1) + from;
    return random ;
}

void print (int from, int to)
{
    cout << random(from, to) << endl ;
    cout << random(from, to) << endl ;
    cout << random(from, to) << endl ;
}

int main()
{
    srand((unsigned)time(NULL));

    print(1, 10);

    // cout << random(1,10) << endl ;
    // cout << random(1,10) << endl ;
    // cout << random(1,10) << endl ;
    return 0;
}
