
#include <iostream>

using namespace std;

enum eninfo { odd = 1, even = 2 };

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

eninfo checking(int number)
{
    if(number % 2 == 0)
        return eninfo::even;
    else
        return eninfo::odd;
}

int loop(int number)
{
    int sum = 0;
    for(int counter = 2; counter <= number; counter += 2)
    {
        if(checking(counter) == eninfo::even)
        {
            cout << counter << endl ;
            sum += counter; 
        }
    }
    return sum;
}

void print(int number)
{
    cout << "The total of Even is: " << number << endl;
}

int main()
{
    int even = positiv_number("Please enter a number: ");
    print(loop(even));
    return 0;
}
