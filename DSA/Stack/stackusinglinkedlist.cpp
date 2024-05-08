#include <iostream>
using namespace std;


class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};


class Stack
{
private:
    Node *top;

public:
    Stack()
    {
        top = NULL;
    }

    bool isEmpty()
    {
        return top == NULL;
    }

    void push(int value)
    {
        Node *newNode = new Node(value);
        if (isEmpty())
        {
            top = newNode;
        }
        else
        {
            newNode->next = top;
            top = newNode;
        }
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return;
        }
        Node *temp = top;
        top = top->next;
        delete temp;
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return top->data;
    }
};

int main()
{
    Stack stack;

    stack.push(5);
    stack.push(10);
    stack.push(15);

    cout << "Top element: " << stack.peek() << endl;

    stack.pop();
    cout << "Top element after pop: " << stack.peek() << endl;

    return 0;
}
