
#include <iostream>

using namespace std;

struct info
{
    string first_name;
    string last_name;
};

info read()
{
    info self;
    cout << "Please enter your name: ";
    cin >> self.first_name;

    cout << "Please enter your name: ";
    cin >> self.last_name;

    return self;
}

void print(info self)
{
    cout << "Your full name is: " << self.first_name << " " + self.last_name << endl;
}

int main()

{
    print(read());
    return 0;
}
