#include<bits/stdc++.h>
using namespace std;

bool Palindrome(string s, int start, int end)
{
    while(start <= end)
    {
        if(s[start] != s[end])
        return false;
    }
    return true;
}

bool ValidPalindrome(string s)
{
    int start = 0;
    int end = s.length()-1;

    while(start <= end)
    {
        if(s[start] == s[end])
        {
            start++;
            end--;
        }
        else
        {
            return Palindrome(s,start,end-1) || Palindrome(s,start+1,end);
        }
    }  
    return false;
}

int main()
{
    string s = "abca";
    bool ans = ValidPalindrome(s);
    if(ans)
    cout << "Valid" << endl;
    else cout << "Not Valid" << endl;

    return 0;
}