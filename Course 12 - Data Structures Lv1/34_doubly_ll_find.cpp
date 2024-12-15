//ProgrammingAdvices.com
//Mohammed Abu-Hadhoud

#include <iostream>
using namespace std;

// Create a node
class Node
{
    public:

    int Value;
    Node * Nexto;
    Node * Previouse;
};

Node * Find(Node * Head, int Value)
{
    while (Head != nullptr)
    {
        if (Head->Value == Value)
            return Head;
        Head = Head->Nexto;
    }

    return nullptr;
}

void InsertAtBeginning(Node * & Head, int Value)
{
    /*
        1-Create a new node with the desired Value.
        2-Set the Nexto pointer of the new node to the current Head of the list.
        3-Set the Previouseious pointer of the current Head to the new node.
        4-Set the new node as the new Head of the list.
    */

    Node * New_Node = new Node();
    New_Node->Value = Value;
    New_Node->Nexto = Head;
    New_Node->Previouse = nullptr;

    if (Head != nullptr)
    {
        Head->Previouse = New_Node;
    }
    Head = New_Node;
}

void PrintNodeDetails(Node * Head)
{

    if (Head->Previouse != nullptr)
        cout << Head->Previouse->Value;
    else
        cout << "NULL";

    cout << " <--> " << Head->Value << " <--> ";

    if (Head->Nexto != nullptr)
        cout << Head->Nexto->Value << "\n";
    else
        cout << "NULL";
}

// Print the linked list
void PrintListDetails(Node* Head)
{
    cout << "\n\n";

    while (Head != nullptr)
    {
        PrintNodeDetails(Head);
        Head = Head->Nexto;
    }
}


// Print the linked list
void PrintList(Node* Head)
{
    cout << "NULL <--> ";
    while (Head != nullptr)
    {
        cout << Head->Value << " <--> ";
        Head = Head->Nexto;
    }
    cout << "NULL";
}

int main()
{
    Node * Head = nullptr;

    InsertAtBeginning(Head, 5);
    InsertAtBeginning(Head, 4);
    InsertAtBeginning(Head, 3);
    InsertAtBeginning(Head, 2);
    InsertAtBeginning(Head, 1);

    cout << "\nLinked List Contenet:\n";
    PrintList(Head);
    PrintListDetails(Head);
    cout << endl;

    Node * N = Find(Head, 2);

    if (N != nullptr)
        cout << "\nNode Found :-)\n" << endl;
    else
        cout << "\nNode Is not found :-(\n" << endl;    
    
    return 0;
}