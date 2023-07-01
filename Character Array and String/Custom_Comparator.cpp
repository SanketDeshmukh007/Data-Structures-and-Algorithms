#include<bits/stdc++.h>
using namespace std;

bool compare(char first, char second)
{
    // return first < second;
    return first > second;
}

bool cmp(int first, int second)
{
    // return first < second;
    return first > second;
}

int main()
{
    string s = "sanket";
    sort(s.begin(),s.end(),compare);
    cout << s << endl;

    vector<int> v = {1,3,2,5,4};
    sort(v.begin(),v.end(),cmp);
    for(auto x : v)
    cout << x << " ";

    return 0;
}