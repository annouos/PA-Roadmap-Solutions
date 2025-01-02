
#include <iostream>
#include "clsDblLinkedList.h"

using namespace std;

int main()
{
    clsDblLinkedList <int> MydblLinkedList;

    clsDblLinkedList<int>::CheckNode(MydblLinkedList);

    // if (MydblLinkedList.IsEmpty())
    //     cout << "\nYes, List is empty" << endl;
    // else
    //     cout << "\nNo, List is not empty" << endl;

    cout << "\nNumber of items in the linked list = " << MydblLinkedList.Size() << endl;

    MydblLinkedList.InsertAtBeginning(7);
    MydblLinkedList.InsertAtBeginning(6);
    MydblLinkedList.InsertAtBeginning(5);

    cout << "\nLinked List Content: \n";
    MydblLinkedList.PrintList();

    clsDblLinkedList<int>::CheckNode(MydblLinkedList);

    // if (MydblLinkedList.IsEmpty())
    //     cout << "\nYes, List is empty" << endl;
    // else
    //     cout << "\nNo, List is not empty" << endl;

    MydblLinkedList.Clear();
    cout << "\nAfter Excuting Clear: ";
    cout << "\nNumber of items in the linked list = " << MydblLinkedList.Size() << endl;

    MydblLinkedList.InsertAtBeginning(4);
    MydblLinkedList.InsertAtBeginning(3);
    MydblLinkedList.InsertAtBeginning(2);
    MydblLinkedList.InsertAtBeginning(1);

    clsDblLinkedList <int>::Node * N_1 = MydblLinkedList.Find(2);

    if (N_1 != nullptr)
        cout << "\nNode with value 2 is Found :-)\n";
    else
        cout << "\nNode Is not found :-(\n";

    MydblLinkedList.InsertAfter(N_1, 500);
    cout << "\nAfter Inserting 500 after 2:\n";
    MydblLinkedList.PrintList();

    MydblLinkedList.InsertAtEnd(700);
    cout << "\nAfter Inserting 700 at end:\n";
    MydblLinkedList.PrintList();

    clsDblLinkedList <int>::Node * N_2 = MydblLinkedList.Find(4);
    
    MydblLinkedList.DeleteNode(N_2);
    cout << "\nAfter Deleting 4:\n";
    MydblLinkedList.PrintList();

    MydblLinkedList.DeleteFirstNode();
    cout << "\nAfter Deleting First Node:\n";
    MydblLinkedList.PrintList();

    cout << "\nAfter Deleting Last Node:\n";
    MydblLinkedList.DeleteLastNode();
    MydblLinkedList.PrintList();

    return 0;
}
