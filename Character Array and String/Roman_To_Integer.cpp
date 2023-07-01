#include <bits/stdc++.h>
using namespace std;

int romanToInt(string s)
{
    unordered_map<string, int> m1;
    unordered_map<string, int> m2;
    m1["I"] = 1;
    m1["V"] = 5;
    m1["X"] = 10;
    m1["L"] = 50;
    m1["C"] = 100;
    m1["D"] = 500;
    m1["M"] = 1000;
    m2["IV"] = 4;
    m2["IX"] = 9;
    m2["XL"] = 40;
    m2["XC"] = 90;
    m2["CD"] = 400;
    m2["CM"] = 900;

    int ans = 0;
    while (s.length())
    {
        string part = s.substr(0, 2);
        if (m2[part])
        {
            ans += m2[part];
            s.erase(0, 2);
        }
        else
        {
            string part = s.substr(0, 1);
            ans += m1[part];
            s.erase(0, 1);
        }
    }
    return ans;
}

int main()
{
    string s = "MCMXCIV";
    int ans = romanToInt(s);
    cout << ans << endl;

    return 0;
}