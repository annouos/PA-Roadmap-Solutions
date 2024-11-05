
#include <iostream>

using namespace std;

void fibonacci(short number)
{
    int pre = 1, current = 0, next = 0;
    cout << "1   ";
    for (int i = 2; i <= number; i++)
    {
        next = pre + current;
        cout << next << "   ";
        current = pre;
        pre = next;
    }
}

int main()
{
    fibonacci(10);
    return 0;
}
