#include <iostream>
using namespace std;

class Node
{

public:
    int data;
    Node *prev;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }

    ~Node()
    {
        int value = this->data;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "Memory is free for: " << value <<endl;
    }
};

// inserting at first position
void insertAtHead(Node *&head, Node *&tail, int d)
{
    if (head == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

// inserting at last position
void insertAtTail(Node *&head, Node *&tail, int d)
{
    if (tail == NULL)
    {
        Node *temp = new Node(d);
        tail = temp;
        head = temp;
    }
    else
    {
        Node *temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertAtPosition(Node *&head, Node *&tail, int pos, int d)
{

    // inserting at first position
    if (pos == 1)
    {
        insertAtHead(head, tail, d);
        return;
    }

    // inserting at given position or in middle
    Node *temp = head;
    int cnt = 1;
    while (cnt < pos - 1)
    {
        temp = temp->next;
        cnt++;
    }

    // inserting at last position
    if (temp->next == NULL)
    {
        insertAtTail(head, tail, d);
        return;
    }
    // creating node for inserting at given position or in middle
    Node *nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}

// deleting node according to position
void deleteNode(Node *&head, int position)
{
    // assuming the given position within the range
    // deleting first node
    if (position == 1)
    {
        Node *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        // deleting any or last node
        Node *curr = head;
        Node *prev = NULL;
        int cnt = 1;

        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

       curr->prev = NULL;
       prev->next = curr->next;
       curr->next = NULL;
       delete curr;
    }
}

void printLinkedList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int getLength(Node *head)
{
    int len = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

int main()
{

    Node *head = NULL;
    Node *tail = NULL;
    insertAtHead(head, tail, 12);
    printLinkedList(head);
    insertAtHead(head, tail, 11);
    printLinkedList(head);
    insertAtHead(head, tail, 10);
    printLinkedList(head);
    insertAtTail(head, tail, 13);
    printLinkedList(head);
    insertAtPosition(head, tail, 5, 14);
    printLinkedList(head);
    insertAtPosition(head, tail, 6, 15);
    insertAtTail(head, tail, 16);
    printLinkedList(head);
    deleteNode(head, 7);
    printLinkedList(head);
    int length = getLength(head);
    cout << "Length of Linked List is: " << length << endl;
    return 0;
}