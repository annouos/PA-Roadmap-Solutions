
#include <iostream>

using namespace std;

string genric_text(string massage)
{
    int number = 0;
    cout << massage;
    cin >> number;
    return "number";
}

void print(string massage)
{
    cout << endl << massage << endl << endl;
}

int main()

{
    string name = genric_text("Anas");
    print(name);
    return 0;
}
