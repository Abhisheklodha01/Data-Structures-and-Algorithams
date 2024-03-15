#include <iostream>
using namespace std;

void PrintWave(int arr[3][3], int rows, int cols)
{
    for (int col = 0; col < cols; col++)
    {
        if (col & 1)
        {
            for (int row = rows - 1; row >= 0; row--)
            {
                cout << arr[row][col] << " ";
            }
            cout << endl;
            
        }
        else
        {
            for (int row = 0; row < rows; row++)
            {
                cout << arr[row][col] << " ";
            }
            cout << endl;
        }
    }
}

int main()
{
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

    cout << "Printing wave matrics" << endl;
    PrintWave(array, 3, 3);
    return 0;
}
