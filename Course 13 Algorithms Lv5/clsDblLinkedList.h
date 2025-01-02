
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

    Node * head = nullptr;

    void PrintList()
    {
        Node * Current = head;

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
        NewNode->next = head;
        NewNode->prev = nullptr;

        if (head != nullptr)
        {
            head->prev = NewNode;
        }
        head = NewNode;
        _size++;
    }

    Node * Find (T value)
    {
        Node * Current = head;
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

        if (head == nullptr)
        {
            NewNode->prev = nullptr;
            head = NewNode;
        }
        else
        {
            Node * Current = head;
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
        if (head == nullptr)
        {
            return;
        }

        Node * Temp = head;
        head = head->next;

        if (head != nullptr)
        {
            head->prev = nullptr;
        }

        delete Temp;
        _size--;
    }

    void DeleteNode(Node * & NodeToDelete)
    {
        if (head == nullptr || NodeToDelete == nullptr) {
            return;
        }
        if (head == NodeToDelete) {
            head = NodeToDelete->next;
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
        if (head == nullptr) {
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        Node * Current = head;

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
        // return head == nullptr;
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

};


