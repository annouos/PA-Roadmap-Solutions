
#include <iostream>
#include <vector>

using namespace std;

vector <int> favorite;

void read_number(vector <int> &favorite)
{
    string input = "Y"; int number = 0;
    while (input == "Y" || input == "y")
    {
        cout << "Plaese enter a number: ";
        cin >> number;

        favorite.push_back(number);

        cout << "Do you want a enter number? Y/N? ";
        cin >> input;
    }
}

void print_vectors()
{
    for (int &i : favorite)
    {
        cout << i << endl;
    }
}

int main()
{
    read_number(favorite);
    print_vectors();
    return 0;
}
