#include<bits/stdc++.h>
using namespace std;

bool palindrome(string& s,int i,int j)
{
    // 1. Base Case
    if(i > j)
    {
        return true;
    }

    // 2. Processing
    if(s[i] != s[j])
    return false;

    // 3. Recursive Relation
    return palindrome(s,i+1,j-1);
}

int main()
{
    string s = "abca";
    int i = 0;
    int j = s.length() - 1;

    if(palindrome(s,i,j))
    cout << "Palindrome" << endl;
    else cout << "Not Palindrome" << endl;

    return 0;
}