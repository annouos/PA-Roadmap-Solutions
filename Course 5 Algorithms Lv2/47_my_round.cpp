
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

float my_round(float number)
{
    int int_part = int(number);
    float fraction_part = get_fraction(number);

    if(abs(fraction_part) >= .5)
    {
        if(number > 0)
            return ++int_part;
        else
            return --int_part;
    }
    else
    {
        return int_part;
    }

}

int main()

{
    float number = genric_number("Please enter a number: ");
    cout << "In my round the number: " << my_round(number) << endl;
    return 0;
}
