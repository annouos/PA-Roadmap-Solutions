#pragma once
#include <iostream>

using namespace std;


template <class T> class clsDblLinkedList
{
    protected:
    
    int _size = 0;

    public:

    class Node
    {
        public:

        T value;
        Node * next;
        Node * prev;
    };

    Node * Head = nullptr;

    void PrintList()
    {
        Node * Current = Head;

        while (Current != nullptr)
        {
            cout << Current->value << " ";
            Current = Current->next;
        }
        cout << "\n";
    }

    void InsertAtBeginning (T value)
    {
        Node * NewNode = new Node();
        NewNode->value = value;
        NewNode->next = Head;
        NewNode->prev = nullptr;

        if (Head != nullptr)
        {
            Head->prev = NewNode;
        }
        Head = NewNode;
        _size++;
    }

    Node * Find (T value)
    {
        Node * Current = Head;
        while (Current != nullptr)
        {
            if (Current->value == value)
            {
                return Current;
            }
            Current = Current->next;
        }
        return nullptr;
    }

    void InsertAfter(Node * Current, T value)
    {
        Node * NewNode = new Node();
        NewNode->value = value;
        NewNode->next = Current->next;
        NewNode->prev = Current;

        if (Current->next != nullptr)
        {
            Current->next->prev = NewNode;
        }
        Current->next = NewNode;
        _size++;
    }

    void InsertAtEnd(T value)
    {
        Node * NewNode = new Node();
        NewNode->value = value;
        NewNode->next = nullptr;

        if (Head == nullptr)
        {
            NewNode->prev = nullptr;
            Head = NewNode;
        }
        else
        {
            Node * Current = Head;
            while (Current->next != nullptr)
            {
                Current = Current->next;
            }
            Current->next = NewNode;
            NewNode->prev = Current;
        }
        _size++;
    }

    void DeleteFirstNode()
    {   
        if (Head == nullptr)
        {
            return;
        }

        Node * Temp = Head;
        Head = Head->next;

        if (Head != nullptr)
        {
            Head->prev = nullptr;
        }

        delete Temp;
        _size--;
    }

    void DeleteNode(Node * & NodeToDelete)
    {
        if (Head == nullptr || NodeToDelete == nullptr) {
            return;
        }
        if (Head == NodeToDelete) {
            Head = NodeToDelete->next;
        }
        if (NodeToDelete->next != nullptr) {
            NodeToDelete->next->prev = NodeToDelete->prev;
        }
        if (NodeToDelete->prev != nullptr) {
            NodeToDelete->prev->next = NodeToDelete->next;
        }

        delete NodeToDelete;
        _size--;
    }

    void DeleteLastNode()
    {    
        if (Head == nullptr) {
            return;
        }
        if (Head->next == nullptr) {
            delete Head;
            Head = nullptr;
            return;
        }

        Node * Current = Head;

        while (Current->next->next != nullptr)
        {
            Current = Current->next;
        }

        Node * Temp = Current->next;
        Current->next = nullptr;
        delete Temp;
        _size--;
    }

    int Size()
    {
        return _size;
    }

    bool IsEmpty()
    {
        return (_size == 0 ? true : false);
        // return Head == nullptr;
    }

    static void CheckNode(clsDblLinkedList <T> Node)
    {
        if (Node.IsEmpty())
            cout << "\nYes, List is empty" << endl;
        else
            cout << "\nNo, List is not empty" << endl;
    }

    void Clear()
    {
        while (_size > 0)
        {
            DeleteFirstNode();
        }
    }

    void Reverse()
    {
        Node * Current = Head;
        Node * Temp = nullptr;
        while(Current != nullptr)
        {
            Temp = Current->prev;
            Current->prev = Current->next;
            Current->next = Temp;
            Current = Current->prev;
        }
        
        if (Temp != nullptr)
        {
            Head = Temp->prev;
        }
    }

    Node * GetNode(int index)
    {
        int Counter = 0;
        if (index > _size -1 || index < 0)
        {
            return nullptr;
        }

        Node * Current = Head;
        while(Current != nullptr && (Current->next != nullptr))
        {
            if (Counter == index)
                break;
            Current = Current->next;
            Counter++;
        }
        return Current;
    }

    T GetItem(int index)
    {
        Node * ItemNode = GetNode(index);

        if (ItemNode == nullptr)
            return 0;
        else
            return ItemNode->value;
    }

    bool UpdateItem(int index, T NewValue)
    {
        Node * ItemNode = GetNode(index);

        if (ItemNode != nullptr)
        {
            ItemNode->value = NewValue;
            return true;
        }
        else
            return false;
    }

    bool InsertAfter(int index, T value)
    {
        Node * ItemNode = GetNode(index);

        if (ItemNode != nullptr)
        {
            InsertAfter(ItemNode, value);
            return true;
        }
        else
            return false;
    }

};


