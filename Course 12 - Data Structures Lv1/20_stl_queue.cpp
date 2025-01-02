// ProgrammingAdvices.com
// Mohammed Abu-Hadhoud

#include <queue>
#include <iostream>
using namespace std;

int main()
{
    // Queue container declaration
    queue<int> MyQueue;

    // pushing elements into first stack
    MyQueue.push(10);
    MyQueue.push(20);
    MyQueue.push(30);
    MyQueue.push(40);

    cout << "\nCount: " << MyQueue.size();
    cout << "\nFront: " << MyQueue.front();
    cout << "\nBack: " << MyQueue.back() << endl;

    cout << "\nMyQueue = ";
    while (!MyQueue.empty())
    {
        cout << MyQueue.front() << " ";
        MyQueue.pop();
    }

    cout << endl;

    return 0;
}

