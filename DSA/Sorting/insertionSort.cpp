#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int> &arr, int n)
{

    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        for (; j >= 0; j--)
        {

            if (arr[j] > temp)
            {
                // shift
                arr[j + 1] = arr[j];
            }
            else
            { // ruk jao
                break;
            }
        }
        // copy temp value
        arr[j + 1] = temp;
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
    insertionSort(arr, n);
    cout << "sorted array are :" << endl;
    PrintArray(arr, n);

    return 0;
}