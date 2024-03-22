#include <iostream>
using namespace std;

int main()
{

    int n, m;
    cout << "Enter the size of matrics" << endl;
    cin >> n >> m;

    int matrics[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrics[i][j];
        }
    }
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrics[i][j] << " ";
        }
        cout << endl;
    }

    int transpose_matrics[m][n];

    for (int i = m-1; i >= 0; i--)
    {
        for (int j = n-1; j >= 0; j--)
        {
            transpose_matrics[i][j] = matrics[j][i];
        }
    }
    cout << endl;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << transpose_matrics[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}