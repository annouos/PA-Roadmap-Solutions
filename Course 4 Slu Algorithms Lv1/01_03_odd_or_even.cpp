
#include <iostream>

using namespace std;

enum ooo { even = 1, odd = 2};

int read()
{
    int num;
    cout << "Please enter a number: ";
    cin >> num;

    return num;
}

ooo lool(int num)
{
    int result = num % 2;
    if(result == 0)
        return ooo::even;
    else
        return ooo::odd;
}

void print(ooo rino)
{
    if (rino == ooo::even)
        cout << "\n number is EVEN \n";
    else
        cout << "\n number is ODD \n";        
}

int main() 

{
    print(lool(read()));
    return 0;
}
