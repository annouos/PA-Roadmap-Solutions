
#include <iostream>

using namespace std;

int main()
{

    int num = 0;

    cout << "How many total ranking of players: ";
    cin >> num;

    float * ptr;

    ptr = new float[num];

    cout << "Enter ranking of players: " << endl;;

    for (int i = 0; i < num; i++)
    {
        cout << "Player [" << i + 1 << "] is: " << endl;
        cin >> * (ptr + i);
    }

    cout << "Show The Final Result: " << endl;

    for (int i = 0; i < num; i++)
    {
        
        cout << "Player [" << i + 1 << "] is: " << * (ptr + i) << endl;
    }

    delete [] ptr;

    return 0;
}
