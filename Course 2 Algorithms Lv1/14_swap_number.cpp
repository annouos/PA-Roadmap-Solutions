
#include <iostream>

using namespace std;

int genric_number(string massage)
{
    int number = 0;
    cout << massage;
    cin >> number;
    return number;
}

struct info
{
    int number_1 = genric_number("Please enter a first number: ");
    int number_2 = genric_number("Please enter a second number: ");
};

info swap()
{
    info self;
    int temp = self.number_1;
    self.number_1 = self.number_2;
    self.number_2 = temp;
    return self;
}

void print(info self)
{
    cout << endl << self.number_1 << endl;
    cout << endl << self.number_2 << endl << endl;
}

int main()
{
    print(swap());
    return 0;
}
