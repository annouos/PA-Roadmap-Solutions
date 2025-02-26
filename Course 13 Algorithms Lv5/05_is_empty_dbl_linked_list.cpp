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

    MydblLinkedList.InsertAtBeginning(5);
    MydblLinkedList.InsertAtBeginning(4);
    MydblLinkedList.InsertAtBeginning(3);
    MydblLinkedList.InsertAtBeginning(2);
    MydblLinkedList.InsertAtBeginning(1);

    cout << "\nLinked List Contenet:\n";
    MydblLinkedList.PrintList();

    clsDblLinkedList<int>::CheckNode(MydblLinkedList);

    // if (MydblLinkedList.IsEmpty())
    //     cout << "\nYes, List is empty" << endl;
    // else
    //     cout << "\nNo, List is not empty" << endl;

    return 0;
}