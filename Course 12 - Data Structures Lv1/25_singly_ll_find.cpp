
#include <iostream>
using namespace std;


class Node
{
    public:
    int Value;
    Node * Nexto;
};


void InsertAtBeginning(Node * & Head, int Value)
{
    Node * New_Node = new Node();

    New_Node->Value = Value;
    New_Node->Nexto = Head;

    Head = New_Node;
}

Node * Find(Node * Head, int Value)
{
    while (Head != nullptr)
    {
        if (Head->Value == Value)
            return Head;

        Head = Head->Nexto;
    }

    return Head = nullptr;
}

void PrintLinkedList(Node * Head)
{
    while (Head != nullptr)
    {
        cout << Head->Value << "\n" << Head->Nexto << "\n";
        Head = Head->Nexto;
    }
    cout << endl;
}



int main()
{
    Node * Head = nullptr;

    InsertAtBeginning(Head, 1);
    InsertAtBeginning(Head, 2);
    InsertAtBeginning(Head, 3);
    InsertAtBeginning(Head, 4);
    InsertAtBeginning(Head, 5);
    InsertAtBeginning(Head, 6);
    InsertAtBeginning(Head, 7);

    PrintLinkedList(Head);

    Node * N = Find(Head,6);

    if (N != nullptr)
        cout << "Node Found :-)\n" << endl;
    else
        cout << "Node Not Found :-(\n" << endl;

    return 0;
}
