
#include <iostream>

using namespace std;

string read_text(string massage)
{
    string text;
    cout << massage;
    cin >> text;
    return text;
}

void loop() {
    for (int i = 64; i <= 90; i++)

    {
    cout << " --- " << char(i) << " --- ";
    cout << "\n______________________\n\n";
    }
}

int main()
{
    loop();
    return 0;
}
