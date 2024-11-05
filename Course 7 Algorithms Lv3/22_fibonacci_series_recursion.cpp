
#include <iostream>

using namespace std;

void fibonacci(short number, int pre, int current)
{
    int next = 0;
    if (number > 0)
    {
        next = pre + current;
        current = pre;
        pre = next;
        cout << next << "   ";
        fibonacci(number-1, pre, current);
    }
}

int main()
{
    fibonacci(10, 0, 1);
    cout << endl;
    return 0;
}
