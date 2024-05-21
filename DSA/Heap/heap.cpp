#include <iostream>
using namespace std;

class heap
{
public:
    int arr[100];
    int size = 0;

    heap()
    {
        arr[0] = -1;
        size = 0;
    }

    void insert(int value)
    {
        size = size + 1;
        int index = size;
        arr[index] = value;

        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    void deletion()
    {
        // check is empty or not
        if (size == 0)
        {
            cout << "nothing to delete" << endl;
            return;
        }

        // replace first node with last node
        arr[1] = arr[size];
        // remove last element
        size--;

        // place first node to its correct position

        int i = 1;
        while (i < size)
        {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;

            if (leftIndex < size && arr[i] < arr[leftIndex])
            {
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }

            else if (rightIndex < size && arr[i] < arr[rightIndex])
            {
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left < n && arr[largest] < arr[left])
        largest = left;

    if (right < n && arr[largest] < arr[right])
        largest = right;

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

int main()
{
    heap h;
    h.insert(55);
    h.insert(65);
    h.insert(32);
    h.insert(70);
    h.print();
    h.deletion();
    h.deletion();
    h.deletion();
    h.deletion();

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }

    cout << "Printing the element" << endl;

    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}