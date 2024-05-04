#include <iostream>
using namespace std;

bool checkPalindrome(string str, int i)
{
    int j = str.length();
    if (i > j / 2)
        return true;

    if (str[i] != str[j-1-i])
        return false;
        
    else
        return checkPalindrome(str, i + 1);
}

int main()
{
    string str = "abaaba";
    cout << endl;

    bool isPalidrome = checkPalindrome(str, 0);
    if(isPalidrome) {
        cout<<"String is Palindrome"<<endl;
    } else {
        cout<<"String is not Palindrome"<<endl;
    }


    return 0;
}