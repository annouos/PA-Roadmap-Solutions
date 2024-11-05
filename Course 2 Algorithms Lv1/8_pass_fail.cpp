
#include <iostream>

using namespace std;

enum eninfo { pass = 1, fail = 2};

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

eninfo proces(int mark)
{
    if(mark >= 50)
        return eninfo::pass;
    else
        return eninfo::fail;
}

void print(int mark)
{
    switch(proces(mark))
    {
        case eninfo::pass :
        cout << endl << "You are Great !" << endl << endl;
        break;
        case eninfo::fail :
        cout << endl << "You are Fail !" << endl << endl;
        break;

    }
}

int main()

{
    int mark = positiv_number("Please enter your mark: ");
    print(mark);
    return 0;
}
