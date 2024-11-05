
#include <iostream>

using namespace std;

int genric_number(string massage)
{
    int number = 0;
    cout << massage;
    cin >> number;
    return number;
}

int my_floor(float number)
{
    if(number > 0)
        return int(number);
    else
        return int(number);
}

int main()

{

    float number = genric_number("Please enter a number: ");
    cout << "In my round the number: " << my_floor(number) << endl;
    return 0;
}





// #include <iostream>

// using namespace std;

// float genric_number(string massage)
// {
//     float number = 0;
//     cout << massage;
//     cin >> number;
//     return number;
// }

// float get_fraction(float number)
// {
//     return number - int(number);
// }

// float my_floor(float number)
// {
//     int int_part = int(number);
//     float fraction_part = get_fraction(number);

//     if(abs(fraction_part) >= .1)
//         return int_part;
//     else
//         return 0;

// }

// int main()

// {
//     float number = genric_number("Please enter a number: ");
//     cout << "In my round the number: " << my_floor(number) << endl;
//     return 0;
// }
