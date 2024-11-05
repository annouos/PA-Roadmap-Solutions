
#include <iostream>

using namespace std;

int main()
{
    int number = 0;

    cout << "Enter a number to check: "; cin >> number;
    
    (number < 0) ? cout << "Fuck" << endl : cout << "Hot" << endl;

    (number == 0) ? cout << "Zero" << endl : (number < 0) ? cout << "Sexy" << endl : cout << "Yum" << endl;

    return 0;
}
