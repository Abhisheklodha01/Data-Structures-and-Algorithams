#include <iostream>
using namespace std;

bool checkPalindrome(string str, int i, int j)
{
    if (i > j)
        return true;

    if (str[i] != str[j])
        return false;

    else
        return checkPalindrome(str, i + 1, j - 1);
}

int main()
{
    string str = "abaaba";
    cout << endl;

    bool isPalidrome = checkPalindrome(str, 0, str.length()-1);
    if(isPalidrome) {
        cout<<"String is Palindrome"<<endl;
    } else {
        cout<<"String is not Palindrome"<<endl;
    }


    return 0;
}