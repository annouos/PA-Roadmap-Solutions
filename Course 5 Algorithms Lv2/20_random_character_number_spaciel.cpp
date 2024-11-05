
#include <iostream>
#include <cstdlib>

using namespace std;

int random(int from, int to)
{
    int random = rand() % (to - from + 1) + from;
    return random ;
}

enum eninfo {capital = 1, smuol = 2, spaciel = 3, number = 4};

char checking(eninfo self)
{
    switch(self)
    {
        case eninfo::smuol:
            return char(random(97, 122));

        case eninfo::capital:
            return char(random(65, 90));
        
        case eninfo::spaciel:
            return char(random(33, 47));
        
        case eninfo::number:
            return char(random(48, 57));

        default:
            return '\0';
    }
}

void print()
{
    cout << checking(eninfo::smuol) << endl ;
    cout << checking(eninfo::capital) << endl ;
    cout << checking(eninfo::spaciel) << endl ;
    cout << checking(eninfo::number) << endl ;
}

int main()
{
    srand((unsigned)time(NULL));

    print();
    return 0;
}
