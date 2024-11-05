
#include <iostream>

using namespace std;

int positiv_number(string massage)
{
    int number = 0;
    do
    {
        cout << massage;
        cin >> number;
    } while (!(number > 18 && number < 45));
    return number;
}

// bool checking(int number)
// {
//     return number > 18 && number < 45;
// }

void print(int number)
{
    cout << endl << number << " Valid Age " << endl << endl;
    // if(checking(number))
    //     cout << endl << "Valid Age " << endl << endl;
    // else
    //     cout << endl << "Invalid Age " << endl << endl;
}

int main()

{
    int Age = positiv_number("Please enter your Age: ");
    print(Age);
    return 0;
}
