
#include <iostream>

using namespace std;

void head_table()
{
    cout << "\n\n\t\t\t Multiplications Table \n\n";
    cout << "| #   |\t";
    for(int i = 1; i <= 10; i++)
    {
        cout << i << "\t";
    }
    cout << "\n------------------------------------------------------------------------------------------\n";
}

string checking(int i)
{
    if(i < 10)
        return "  |";
    else
        return " |";
}

void body_table()
{
    head_table();
    for(int i = 1; i <= 10; i++)
    {
        cout << "| 0" << i << checking(i) << "\t";
        for(int j = 1; j <= 10; j++)
        {
            cout << i*j << "\t";
        }
        cout << "-" << endl;
    }
    cout << "------------------------------------------------------------------------------------------\n";
}

int main()

{
    body_table();
    return 0;
}
