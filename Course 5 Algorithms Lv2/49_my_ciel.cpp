
#include <iostream>

using namespace std;

float genric_number(string massage)
{
    float number = 0;
    cout << massage;
    cin >> number;
    return number;
}

float get_fraction(float number)
{
    return number - int(number);
}

float my_ciel(float number)
{
    if(abs(get_fraction(number)) > 0)
    {
        if(number > 0)
            return int(number) + 1;
        else
            return int(number);
    }
    else
    {
        return number;
    }

}
int main()

{
    float number = genric_number("Please enter a number: ");
    cout << "In my round the number: " << my_ciel(number) << endl;
    return 0;
}
