#include <iostream>
#include<limits.h>
using namespace std;

void RowSum(int arr[3][3])
{
    int sum = 0;
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            sum += arr[row][col];
        }
        cout<<sum<<" ";
        sum = 0;
    }
}

void colSum(int arr[3][3])
{
    int sum = 0;
    for (int col = 0; col < 3; col++)
    {
        for (int row = 0; row < 3; row++)
        {
            sum += arr[row][col];
        }
        cout<<sum<<" ";
        sum = 0;
    }
}

int largestRowSum(int arr[3][3]) {
    int sum = 0;
    int maxi = INT_MIN;
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            sum += arr[row][col];
            if(sum > maxi) 
               maxi = sum;
        }
        sum = 0;
    }
    return maxi;
}

int largestColSum(int arr[3][3]) {
    int sum = 0;
    int maxi = INT_MIN;
    for (int col = 0; col < 3; col++)
    {
        for (int row = 0; row < 3; row++)
        {
            sum += arr[row][col];
            if(sum > maxi) 
               maxi = sum;
        }
        sum = 0;
    }
    return maxi;
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

    cout<<"Printing the row sum: "<< endl;
    RowSum(array);
    cout<<endl;

    cout<<"Printing the col sum: "<< endl;
    colSum(array);
    cout<<endl;
    
    int RowMaxSum = largestRowSum(array);
    cout<<"Largest RowSum is: " <<RowMaxSum<<endl;

    int colMaxSum = largestColSum(array);
    cout<<"Largest RowSum is: " <<colMaxSum<<endl;


    return 0;
}