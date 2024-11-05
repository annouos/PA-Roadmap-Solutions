
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

float area(float num_1, float num_2, float num_3)
{
    float pi = 3.14;

    float p = (num_1 + num_2 + num_3) / 2;
    float total = (num_1 * num_2 * num_3) / (4 * sqrt(p * (p - num_1) * (p - num_2) * (p - num_3)));
    float result = pi * pow(total, 2);
    return result;
}

void print(float result)
{
    cout << endl << result << endl << endl;
}

int main() 
{
    float a = positiv_number("Please enter a A number: ");
    float b = positiv_number("Please enter a B number: ");
    float c = positiv_number("Please enter a C number: ");
    print(area(a, b, c));
    return 0;
}
