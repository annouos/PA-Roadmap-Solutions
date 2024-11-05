
#include <iostream>
#include <vector>

using namespace std;

struct info
{
    string name = "";
    short age = 0;
    string country = "";
    float salary = 0;
};

// void print_info(info &self)
// {
//     cout << "\nName: " << self.name << endl;
//     cout << "Age: " << self.age << endl;
//     cout << "Country: " << self.country << endl;
//     cout << "Salary: " << self.salary << endl;
// }

vector <info> favorite;

void read_struct(vector <info> &favorite)
{
    string input = "Y"; info self;
    while (input == "Y" || input == "y")
    {
        cout << "What's the name: ";
        cin >> self.name;
        cout << "How old the age: ";
        cin >> self.age;
        cout << "From where country: ";
        cin >> self.country;
        cout << "How mutch salary: ";
        cin >> self.salary;

        favorite.push_back(self);

        cout << "Do you want a enter number? Y/N? ";
        cin >> input;
    }
}

void print_vectors()
{
    for (info &i : favorite)
    {
        // print_info(i);
        cout << "\nName: " << i.name << endl;
        cout << "Age: " << i.age << endl;
        cout << "Country: " << i.country << endl;
        cout << "Salary: " << i.salary << endl;
    }
    cout << endl;
}

int main()
{
    read_struct(favorite);
    print_vectors();
    return 0;
}
