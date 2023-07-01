#include <bits/stdc++.h>
using namespace std;

bool Palindrome(string s, int st, int e)
{
    while (st <= e)
    {
        if (s[st] != s[e])
            return false;

        st++;
        e--;
    }
    return true;
}
string longestPalindrome(string s)
{
    string ans = "";
    int n = s.length();

    for (int i = 0; i < n; i++)
    {
        int k = i;
        for (int j = 1; j <= n - i; j++)
        {
            if (Palindrome(s, i, k++))
            {
                string temp = s.substr(i, j);
                if (temp.length() > ans.length())
                    ans = temp;
            }
        }
    }
    return ans;
}
string valid(string s)
{
    string ans;
    for(int i = 0; i < s.length(); i++)
    {
        for(int j = i; j < s.length(); j++)
        {
            if(Palindrome(s,i,j))
            {
                string temp = s.substr(i,j-i+1);
                if(temp.length() > ans.length())
                ans = temp;
            }
        }
    }
    return ans;
}

int main()
{
    string s = "babad";
    string ans = longestPalindrome(s);
    cout << ans << endl;

    return 0;
}