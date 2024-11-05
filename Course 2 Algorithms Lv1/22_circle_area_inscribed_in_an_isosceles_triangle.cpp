
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

float area(float num_1, float num_2)
{
    float pi = 3.14;
    float result = pi * (pow(num_2, 2) / 4) * ((2*num_1-num_2)/(2*num_1+num_2));
    return result;
}

void print(float result)
{
    cout << endl << result << endl << endl;
}

int main() 
{
    float inscribed = positiv_number("Please enter a inscribed number: ");
    float isosceles = positiv_number("Please enter a isosceles number: ");
    print(area(inscribed, isosceles));
    return 0;
}

