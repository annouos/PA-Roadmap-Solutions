
#include <iostream>
#include <cmath>

using namespace std;

float positiv_number(string massage)
{
    float number = 0;
    do
    {
        cout << massage;
        cin >> number;
    } while (number < 0);
    return number;
}

float area(float num)
{
    float pi = 3.14;
    float result = pow(num, 2) / (4 * pi);
    return result;
}

void print(float result)
{
    cout << endl << result << endl << endl;
}

int main() 
{
    float circumference = positiv_number("Please enter a circumference number: ");
    print(area(circumference));
    return 0;
}
