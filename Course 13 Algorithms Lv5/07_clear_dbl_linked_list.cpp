#include <iostream>
#include "clsDblLinkedList.h"

using namespace std;


int main()
{

    clsDblLinkedList <int> MydblLinkedList;

    MydblLinkedList.InsertAtBeginning(5);
    MydblLinkedList.InsertAtBeginning(4);
    MydblLinkedList.InsertAtBeginning(3);
    MydblLinkedList.InsertAtBeginning(2);
    MydblLinkedList.InsertAtBeginning(1);

    cout << "\nLinked List Contenet:\n";
    MydblLinkedList.PrintList();

    cout << "\nNumber of items in the linked list = " << MydblLinkedList.Size() << endl;

    MydblLinkedList.Clear();
    cout << "\nAfter Excuting Clear: ";
    cout << "\nNumber of items in the linked list = " << MydblLinkedList.Size() << endl;
    return 0;
}