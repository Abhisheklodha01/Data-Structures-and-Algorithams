#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }

    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }

        cout << "Memory free for node with data: " << value << endl;
    }
};

void insertNode(Node *&tail, int element, int d)
{

    if (tail == NULL)
    {
        Node *temp = new Node(d);
        tail = temp;
        temp->next = temp;
    }
    else
    {
        // non-empty list
        // assuming that the element present in the list

        Node *curr = tail;
        while (curr->data != element)
        {
            curr = curr->next;
        }
        // element found
        // curr representing the element

        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

// deleting node according to value
void deleteNode(Node *&tail, int value)
{
    if (tail == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    else
    {
        // assuming the given value is present in the ll
        Node *prev = tail;
        Node *curr = prev->next;

        while (curr->data != value)
        {
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;
        // single node case
        if (curr == prev)
        {
            tail = NULL;
        }

        // more than 1 node present in linked list

        else if (tail == curr)
        {
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}

void printLinkedList(Node *tail)
{
    if (tail == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    Node *temp = tail;
    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);
    cout << endl;
}

int main()
{
    Node *tail = NULL;
    insertNode(tail, 5, 3);
    insertNode(tail, 3, 7);
    insertNode(tail, 3, 4);
    insertNode(tail, 4, 5);
    insertNode(tail, 5, 6);
    insertNode(tail, 7, 8);
    deleteNode(tail, 3);
    deleteNode(tail, 8);
    deleteNode(tail, 3);
    printLinkedList(tail);
    return 0;
}