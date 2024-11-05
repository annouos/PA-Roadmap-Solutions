
#include <iostream>
#include <string>

using namespace std;

int read(string massage)
{
    int number;
    cout << massage;
    cin >> number;
    return number;
}

int calc()
{
    int sum = 0; int counter = 1; int number = 0;
    do
    {
        number = read("Please enter a number " + to_string(counter) + " > ");
        if(number == -99)
            break;
        counter++;
        sum += number;
    } while (number != -99);
    return sum;
}

int main()

{
    cout << calc() << endl;
    return 0;
}
