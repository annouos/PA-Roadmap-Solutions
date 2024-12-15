
#include <iostream>

using namespace std;


class Node
{
    public:

    int Value;
    Node * Nexto;
    Node * Previouse;
};

int main()
{
    Node * Head;

    Node * Node_1 = nullptr;
    Node * Node_2 = nullptr;
    Node * Node_3 = nullptr;

    Node_1 = new Node();
    Node_2 = new Node();
    Node_3 = new Node();

    Node_1->Value = 1;
    Node_1->Previouse = nullptr;
    Node_1->Nexto = Node_2;

    Node_2->Value = 2;
    Node_2->Previouse = Node_1;
    Node_2->Nexto = Node_3;

    Node_3->Value = 3;
    Node_3->Nexto = nullptr;
    Node_3->Previouse = Node_2;

    Head = Node_1;

    while (Head != nullptr)
    {
        cout << Head->Value << " ";
        Head = Head->Nexto;
    }
    cout << endl;

    return 0;
}
