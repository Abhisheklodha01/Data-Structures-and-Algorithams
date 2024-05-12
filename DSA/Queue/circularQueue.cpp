#include <iostream>
using namespace std;
#define SIZE 10

class circularQueue
{
public:
    int arr[SIZE];
    int front, rear;

    circularQueue()
    {
        front = -1;
        rear = -1;
    }

    void enQueue(int element)
    {
        // check is full
        if ((front == 0 && rear == SIZE - 1) || (rear == (front - 1) % (SIZE - 1)))
        {
            cout << "Queue is full" << endl;
            return;
        }
        // first element to push
        else if (front == -1)
        {
            front = rear = 0;
        }
        // maintain cyclic nature
        else if (rear == SIZE - 1 && front != 0)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = element;
    }

    void deQueue()
    {
        // check is empty
        if (front == -1)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        // single element
        else if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        // maintain cyclic nature
        else if (front == SIZE - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
    }

    void display()
    {
        int i;
        if (front == -1)
        {
            cout << endl
                 << "Empty Queue" << endl;
        }
        else
        {
            cout << endl
                 << "Front value-> " << arr[front];
            cout << endl
                 << "Items -> ";
            for (i = front; i <= rear; i++)
                cout << arr[i] << "  ";
            cout << endl
                 << "Rear value-> " << arr[rear] << endl;
        }
    }
};


int main()
{
    circularQueue q;
    q.deQueue();
    q.enQueue(10);
    q.enQueue(11);
    q.enQueue(12);
    q.enQueue(13);
    q.enQueue(14);
    q.enQueue(15);
    q.enQueue(16);
    q.enQueue(17);
    q.enQueue(18);
    q.enQueue(19);
    q.enQueue(20);
    q.display();
    q.deQueue();
    q.display();
    return 0;
}