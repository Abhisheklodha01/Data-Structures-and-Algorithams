// Queue implementation in C++

#include <iostream>
#define SIZE 5

using namespace std;

class Queue
{
private:
  int arr[SIZE], front, rear;

public:
  Queue()
  {
    front = -1;
    rear = -1;
  }

  bool isFull()
  {
    if (front == 0 && rear == SIZE - 1)
    {
      return true;
    }
    return false;
  }

  bool isEmpty()
  {
    if (front == -1)
      return true;
    else
      return false;
  }

  void enQueue(int element)
  {
    if (isFull())
    {
      cout << "Queue is full";
    }
    else
    {
      if (front == -1)
        front = 0;
      rear++;
      arr[rear] = element;
      cout << endl
           << "Inserted " << element << endl;
    }
  }

  int deQueue()
  {
    int element;
    if (isEmpty())
    {
      cout << "Queue is empty" << endl;
      return (-1);
    }
    else
    {
      element = arr[front];
      if (front >= rear)
      {
        front = -1;
        rear = -1;
      } 
      else
      {
        front++;
      }
      cout << endl
           << "Deleted -> " << element << endl;
      return (element);
    }
  }

  void display()
  {
    int i;
    if (isEmpty())
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
        cout <<  arr[i] << "  ";
      cout << endl
           << "Rear value-> " << arr[rear] << endl;
    }
  }
};

int main()
{
  Queue q;
 
  q.deQueue();
  q.enQueue(1);
  q.enQueue(2);
  q.enQueue(3);
  q.enQueue(4);
  q.enQueue(5);
  q.enQueue(6);
  q.display();
  q.deQueue();
  q.display();

  return 0;
}