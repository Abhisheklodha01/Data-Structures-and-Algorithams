#include<iostream>
using namespace std; 

void reverse(int i, int j, string &s) 
{
    if (i > j)
    {
        return;
    }

    swap(s[i], s[j]);
    i++;
    j--;
    reverse(i, j, s);
    
}


int main()
{
    string str = "abhishek";
    reverse(0, str.length()-1, str);
    cout<<str<<endl;
    return 0;
}