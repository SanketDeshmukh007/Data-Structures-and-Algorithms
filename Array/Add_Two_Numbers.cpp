#include<bits/stdc++.h>
using namespace std;

vector<int> AddTwoNumbers(int a[],int b[],int n1,int n2)
{
    int i = n1 - 1;
    int j = n2 - 1;
    int carry = 0;
    vector<int> ans;

    while(i >= 0 and j >= 0)
    {
        int sum = a[i--] + b[j--] + carry;
        int digit = sum % 10;
        ans.push_back(digit);
        carry = sum / 10;
    }

    while(i >= 0)
    {
        int sum = a[i--] + carry;
        int digit = sum % 10;
        ans.push_back(digit);
        carry = sum / 10;
    }

    while(j >= 0)
    {
        int sum = b[j--] + carry;
        int digit = sum % 10;
        ans.push_back(digit);
        carry = sum / 10;
    }

    while(carry != 0)
    {
        int digit = carry % 10;
        ans.push_back(digit);
        carry = carry / 10;
    }

    reverse(ans.begin(),ans.end());

    while(ans[0] == 0)
    ans.erase(ans.begin(),ans.begin()+1);

    return ans;
}

int main()
{
    int a[] = {9,5,4,9};
    int b[] = {2,1,4};
    vector<int> ans = AddTwoNumbers(a,b,4,3);
    for(auto x : ans)
    cout << x << " ";

    return 0;
}