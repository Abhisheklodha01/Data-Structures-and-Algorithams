#include <iostream>
using namespace std;

bool Search(int arr[3][3], int row, int col, int target)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] == target)
            {
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    int arr[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int arr1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    int array[3][3];
    cout << "Enter the elements" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> array[i][j];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    if (Search(array, 7, 3, 3))
        cout << "Element found" << endl;

    else
        cout << "Element not found";
}