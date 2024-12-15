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

void InsertAfter(Node * Current, int Value)
{
    /*  1 - Create a new node with the desired value.
        2-Set the next pointer of the new node to the next node of the current node.
        3-Set the previous pointer of the new node to the current node.
        4-Set the next pointer of the current node to the new node.
        5-Set the previous pointer of the next node to the new node(if it exists).
    */

    Node * New_Node = new Node();
    New_Node->Value = Value;
    New_Node->Nexto = Current->Nexto;
    New_Node->Previouse = Current;

    if (Current->Nexto != nullptr)
    {
        Current->Nexto->Previouse = New_Node;
    }
    
    Current->Nexto = New_Node;
}

void InsertAtEnd(Node * Head, int Value) {
    
    /*
        1-Create a new node with the desired value.
        2-Traverse the list to find the last node.
        3-Set the next pointer of the last node to the new node.
        4-Set the previous pointer of the new node to the last node.
    */

    Node* New_Node = new Node();
    New_Node->Value = Value;
    New_Node->Nexto = nullptr;

    if (Head == nullptr)
    {
        New_Node->Previouse = nullptr;
        Head = New_Node;
    }
    else
    {
        Node * Current = Head;
        while (Current->Nexto != nullptr)
        {
            Current = Current->Nexto;
        }

        New_Node->Previouse = Current;
        Current->Nexto = New_Node;
    }
}

void DeleteFirstNode(Node * & Head)
{   
    /*
        1-Store a reference to the head node in a temporary variable.
        2-Update the head pointer to point to the next node in the list.
        3-Set the previous pointer of the new head to NULL.
        4-Delete the temporary reference to the old head node.
    */

    if (Head == nullptr)
    {
        return;
    }

    Node * Temp = Head;
    Head = Head->Nexto;

    if (Head != nullptr)
    {
        Head->Previouse = nullptr;
    }

    delete Temp;
}

void DeleteNode(Node * & head, Node * & NodeToDelete)
{
    /*
        1-Set the next pointer of the previous node to the next pointer of the current node.
        2-Set the previous pointer of the next node to the previous pointer of the current node.
        3-Delete the current node.
    */

    if (head == nullptr || NodeToDelete == nullptr) {
        return;
    }
    if (head == NodeToDelete) {
        head = NodeToDelete->Nexto;
    }
    if (NodeToDelete->Nexto != nullptr) {
        NodeToDelete->Nexto->Previouse = NodeToDelete->Previouse;
    }
    if (NodeToDelete->Previouse != nullptr) {
        NodeToDelete->Previouse->Nexto = NodeToDelete->Nexto;
    }

    delete NodeToDelete;
}

void DeleteLastNode(Node * & Head)
{    
    /*
        1-Traverse the list to find the last node.
        2-Set the next pointer of the second-to-last node to NULL.
        3-Delete the last node.
    */
    
    if (Head == nullptr) {
        return;
    }
    if (Head->Nexto == nullptr) {
        delete Head;
        Head = nullptr;
        return;
    }

    Node * Current = Head;

    while (Current->Nexto->Nexto != nullptr)
    {
        Current = Current->Nexto;
    }

    Node * Temp = Current->Nexto;
    Current->Nexto = nullptr;
    delete Temp;
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

    InsertAfter(N, 500);

    cout << "\n\n\nLinked List Contenet after InsertAfter:\n";
    PrintList(Head);
    PrintListDetails(Head);

    InsertAtEnd(Head, 500);

    cout << "\n\n\nLinked List Contenet after InsertAtEnd:\n";
    PrintList(Head);
    PrintListDetails(Head);

    DeleteFirstNode(Head);

    cout << "\n\n\nLinked List Contenet after delete:\n";
    PrintList(Head);
    PrintListDetails(Head);

    DeleteNode(Head, N);

    cout << "\n\n\nLinked List Contenet after delete:\n";
    PrintList(Head);
    PrintListDetails(Head);

    DeleteLastNode(Head);

    cout << "\n\n\nLinked List Contenet after delete last node:\n";
    PrintList(Head);
    PrintListDetails(Head);
    
    return 0;
}