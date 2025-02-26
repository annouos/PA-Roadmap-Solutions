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
    
    MydblLinkedList.InsertAfter(3, 214);

    cout << "\nAfter Inserting: \n";
    MydblLinkedList.PrintList();
    
    return 0;
}