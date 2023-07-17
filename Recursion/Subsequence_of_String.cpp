#include<bits/stdc++.h>
using namespace std;

void PrintSubsequence(string Input,string Output,int i,vector<string>& ans)
{
    // 1. Base Case
    if(i >= int(Input.length()))
    {
        ans.push_back(Output);
        return;
    }

    // 2. Processing and Recursive Relation

    // exclude
    PrintSubsequence(Input,Output,i+1,ans);
    // include
    Output.push_back(Input[i]);
    PrintSubsequence(Input,Output,i+1,ans);
}
int main()
{
    string Input = "abc";
    int i = 0;
    string Output = "";
    vector<string> ans;
    PrintSubsequence(Input,Output,i,ans);
    for(auto x : ans)
    cout << x << endl;

    cout << "Size: " << ans.size() << endl;

    return 0;
}