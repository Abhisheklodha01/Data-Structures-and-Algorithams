#include <iostream>
using namespace std;

void merge(int *arr, int start, int end)
{
    int mid = start + (end - start) / 2;
    int length1 = mid - start + 1;
    int length2 = end - mid;

    int *arr1 = new int[length1];
    int *arr2 = new int[length2];

    // copying values in new array
    int mainArrayIndex = start;
    for (int i = 0; i < length1; i++)
    {
        arr1[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid + 1;
    for (int i = 0; i < length2; i++)
    {
        arr2[i] = arr[mainArrayIndex++];
    }

    // merge these arrays

    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = start;

    while (index1 < length1 && index2 < length2)
    {
        if (arr1[index1] < arr2[index2])
            arr[mainArrayIndex++] = arr1[index1++];
        else
            arr[mainArrayIndex++] = arr2[index2++];
    }

    while (index1 < length1)
    {
        arr[mainArrayIndex++] = arr1[index1++];
    }

    while (index2 < length2)
    {
        arr[mainArrayIndex++] = arr2[index2++];
    }
}

void mergeSort(int *arr, int start, int end)
{
    if (start >= end)
        return;
    int mid = start + (end - start) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, end);
}

int main()
{
    int arr[7] = {9, 2, 8, 3, 1, 4, 5};
    int n = 7;
    mergeSort(arr, 0, n - 1);

    for(int i = 0; i < n; i++) 
    {
        cout<<arr[i] << " ";
    }
    return 0;
}