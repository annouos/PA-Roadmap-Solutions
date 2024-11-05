
#include <iostream>

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
    float result = (num_1 * num_2) / 2;
    return result;
}

void print(float result)
{
    cout << endl << result << endl << endl;
}

int main() 
{
    float high = positiv_number("Please enter a high number: ");
    float width = positiv_number("Please enter a width number: ");
    print(area(high, width));
    return 0;
}

