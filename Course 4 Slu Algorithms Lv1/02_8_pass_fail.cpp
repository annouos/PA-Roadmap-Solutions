
#include <iostream>

using namespace std;

enum info {pass = 1, fail = 2};

int read()
{
    int mark;
    cout << "Please enter your mark: ";
    cin >> mark;

    return mark;
}

info checking(int mark)
{
    if(mark >= 50)
        return info::pass;
    else
        return info::fail;
}

void print(int mark)
{
    cout << "You are :";
    if(checking(mark) == info::pass)
        cout << " Pass";
    else
        cout << " Fail";
}

int main()

{
    print(read());
    return 0;
}
