
#include <iostream>

using namespace std;

class Node
{
    public:
    int Value;
    Node * Nexto;
};

int main()
{
    Node * Head;

    Node * Node_1 = new Node();
    Node * Node_2 = new Node();
    Node * Node_3 = new Node();

    Node_1->Value = 1;
    Node_2->Value = 2;
    Node_3->Value = 3;

    Node_1->Nexto = Node_2;
    Node_2->Nexto = Node_3;
    Node_3->Nexto = nullptr;

    Head = Node_1;

    while (Head != nullptr)
    {
        cout << Head->Value << endl;
        Head = Head->Nexto;
    }

    delete Node_1;
    delete Node_2;
    delete Node_3;

    return 0;
}
