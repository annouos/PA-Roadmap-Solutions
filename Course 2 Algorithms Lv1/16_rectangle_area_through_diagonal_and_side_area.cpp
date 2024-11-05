
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
    float result = num_1 * sqrt(pow(num_2, 2) - pow(num_1, 2));
    return result;
}

void print(float result)
{
    cout << endl << result << endl << endl;
}

int main() 
{
    float side_area = positiv_number("Please enter a side area number: ");
    float diagonal = positiv_number("Please enter a diagonal number: ");
    print(area(side_area, diagonal));
    return 0;
}
