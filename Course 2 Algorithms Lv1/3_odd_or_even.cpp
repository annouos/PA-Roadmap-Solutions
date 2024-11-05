
#include <iostream>

using namespace std;

enum eninfo {odd = 1, even = 2};

int genric_number(string massage)
{
    int number = 0;
    cout << massage;
    cin >> number;
    return number;
}

eninfo check(int number)
{
    if(number % 2 == 0)
        return eninfo::even;
    else {
        return eninfo::odd ;
    }
}

void print(eninfo self)
{
    switch(self)
    {
        case eninfo::even:
        cout << "This is an even " << endl << endl;
        break;
        case eninfo::odd :
        cout << "This is an odd " << endl << endl;
        break;
    }
}


int main() 
{
    int number = genric_number("Please enter a number: ");
    print(check(number));
    return 0;
}

// void print(int number) // best way !
// {
//     if(check(number))
//         cout << "This is an even number" << endl << endl;
//     else
//         cout << "This is an odd number" << endl << endl;
// }