
#include <iostream>

using namespace std;

struct info
{
    string name = "";
    short age = 0;
    bool married = false;
    int number = 0;
};

int main()
{
    info self, * ptr;

    self.name = "anas";
    self.age = 34;
    self.married = true;
    self.number = 700707007;

    cout << self.name << endl;
    cout << self.age << endl;
    cout << self.married << endl;
    cout << self.number << endl;

    ptr = &self;

    cout <<"\nThe address: " << ptr << endl;

    cout << "\nusing pointers: \n";
    cout << ptr->name << endl;
    cout << ptr->age << endl;
    cout << ptr->married << endl;
    cout << ptr->number << endl;

    return 0;
}
