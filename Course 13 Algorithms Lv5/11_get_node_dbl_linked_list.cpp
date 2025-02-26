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

    clsDblLinkedList <int> ::Node * N;

    N = MydblLinkedList.GetNode(2);

    cout << "\nNode Value is: " << N->value << endl;
    
    return 0;
}