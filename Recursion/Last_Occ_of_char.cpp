#include<bits/stdc++.h>
using namespace std;

void LastOccRToL(string s,int i,char target,int& ans)
{
    // 1. Base Case
    if(i < 0)
    return;

    // 2. Processing
    if(target == s[i])
    {
        ans = i;
        return;
    }

    // 3. Recursive Relation
    LastOccRToL(s,i-1,target,ans);
}

void LastOccLToR(string s,int i,char target,int& ans)
{
    // 1. Base Case
    if(i >= int(s.length()))
    return;

    // 2. Processing
    if(s[i] == target)
    {
        ans = i;
    }

    // 3. Recursive Relation
    LastOccLToR(s,i+1,target,ans);
}

int main()
{
    string s = "abcddedgd";
    int ans = -1;
    char target = 'd';
    LastOccLToR(s,0,target,ans);
    cout << "Last Occurence: " << ans << endl;
    ans = -1;
    LastOccRToL(s,s.length()-1,target,ans);
    cout << "Last Occurence: " << ans << endl;

    return 0;
}