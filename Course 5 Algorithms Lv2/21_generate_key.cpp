
#include <iostream>
#include <cstdlib>

using namespace std;

enum eninfo {capital = 1, smuol = 2, spaciel = 3, number = 4};

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

int random(int from, int to)
{
    int random = rand() % (to - from + 1) + from;
    return random ;
}

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

string parts(eninfo self, int letter)
{
    string part = "";
    for(int i = 1; i <= 1; i++)
    {
        for(int j = 1; j <= letter; j++)
        {
            part += checking(eninfo::capital);
        }
    }
    return part;
}

string key(int colom)
{
    string key = "";
    for(int i = 1; i <= colom; i++)
    {
        key += parts(eninfo::capital, 8);
        if(i< colom)
            key += "-";
    }
    return key;
}

void print(int number)
{
    for(int i = 1; i <= number; i++)
    {
        cout << "Key [" << i << "] " << key(4) << endl;
    }
}


int main()
{
    srand((unsigned)time(NULL));
    print(positiv_number("Please enter how many generate: "));
    return 0;
}
