
#include <iostream>

using namespace std;

int genric_number(string massage)
{
    int number = 0;
    cout << massage;
    cin >> number;
    return number;
}

int proces(int num_1, int num_2, int num_3)
{
    return num_1 + num_2 + num_3;
}

float average(int sum)
{
    return (float) sum / 3;
}

void print(float result)
{
    if(result >= 50)
        cout << endl << "Hierd " << result << endl << endl;
    else
        cout << endl << "Rejected " << result << endl << endl;
}

int main()

{
    int number_1 = genric_number("Please enter a mark one: ");
    int number_2 = genric_number("Please enter a mark tow: ");
    int number_3 = genric_number("Please enter a mark three: ");
    print(average(proces(number_1,number_2,number_3)));
    return 0;
}
