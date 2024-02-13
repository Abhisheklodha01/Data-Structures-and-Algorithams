#include <iostream>
#include <vector>
using namespace std;
void selectionSort(vector<int> &arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < n; j++)
        {

            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[minIndex], arr[i]);
    }
}

void PrintArray(vector<int> &arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    vector<int> arr;
    arr = {19, 2, 5, 1, 11, 7, 6};
    int n = arr.size();
    selectionSort(arr, n);
    cout << "sorted array are :" << endl;
    PrintArray(arr, n);

    return 0;
}