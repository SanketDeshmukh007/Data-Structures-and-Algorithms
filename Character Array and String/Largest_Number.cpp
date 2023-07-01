#include<bits/stdc++.h>
using namespace std;

static bool cmp(string a, string b)
{
    string t1 = a + b;
    string t2 = b + a;
    return t1 > t2;
}

string largestNumber(vector<int>& nums)
{
    vector<string> s;
    for(auto x : nums)
    s.push_back(to_string(x));

    sort(s.begin(),s.end(),cmp);

    string ans = "";
    for(auto x : s)
    ans += x;

    if(ans[0] == '0')
    return "0";

    return ans;
}

int main()
{
    vector<int> nums = {3,30,34,5,9};
    string ans = largestNumber(nums);
    cout << ans << endl;

    return 0;
}