#include <iostream>
using namespace std;
#define SIZE 10

class deQueue
{
private:
    int arr[SIZE];
    int front, rear;

public:
    deQueue()
    {
        front = -1;
        rear = 1;
    }

    void push_front(int value)
    {
        // check full
        if ((front == 0 && rear == SIZE - 1) ||
            (front != 0 && rear == (front - 1) % (SIZE - 1)))
        {
            cout << "Queue is full" << endl;
            return;
        }
        // first element
        else if (front == -1)
        {
            front = rear = 0;
        }
        // maintain cyclic nature
        else if (front == 0 && rear != SIZE - 1)
        {
            front = SIZE - 1;
        }
        else
        {
            front--;
        }

        arr[front] = value;
    }

    void push_rear(int value)
    {
        // check full
        // check is full
        if ((front == 0 && rear == SIZE - 1) ||
            (front != 0 && rear == (front - 1) % (SIZE - 1)))
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
        arr[rear] = value;
    }

    void pop_front()
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

    void pop_rear()
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
        else if (rear == 0)
        {
            rear = SIZE - 1;
        }
        else
        {
            rear--;
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
    deQueue dq;
    dq.push_rear(10);
    dq.push_rear(11);
    dq.push_rear(12);
    dq.push_rear(13);
    dq.push_front(14);
    dq.push_front(15);
    dq.push_front(16);
    dq.push_rear(17);
    dq.push_front(18);
    dq.push_rear(19);
    dq.display();
    dq.pop_front();
    dq.display();
    dq.pop_rear();
    dq.display();

    return 0;
}