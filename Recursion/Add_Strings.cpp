#include<bits/stdc++.h>
using namespace std;

string addString(string& num1,string& num2,string& ans,int i,int j,int& carry)
{
    // 1. Base Case
    if(carry == 0 and i < 0 and j < 0)
    {
        reverse(ans.begin(),ans.end());
        return ans;
    }

    // 2. Processing
    if(i >= 0)
    {
        carry += num1[i] - '0';
        i--;
    }
    if(j >= 0)
    {
        carry += num2[j] - '0';
        j--;
    }
    ans += (carry % 10 + '0');
    carry /= 10;

    // 3. Recursive Relation
    return addString(num1,num2,ans,i,j,carry);
}

string AddStrings(string num1,string num2)
{
    int carry = 0;
    int i = num1.length() - 1;
    int j = num2.length() - 1;
    string ans = "";
    return addString(num1,num2,ans,i,j,carry);
}

int main()
{
    string num1 = "456";
    string num2 = "77";

    cout << AddStrings(num1,num2) << endl;

    return 0;
}