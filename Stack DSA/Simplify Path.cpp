#include <bits/stdc++.h>
using namespace std;

void buildAns(stack<string> &s, string &ans)
{
    if (s.empty())
        return;

    string minpath = s.top();
    s.pop();
    buildAns(s, ans);
    ans += minpath;
}

string simplifyPath(string path)
{
    stack<string> s;
    int i = 0;
    int n = path.length();
    while (i < n)
    {
        int start = i;
        int end = i + 1;

        while (end < n and path[end] != '/')
        {
            end++;
        }

        string minpath = path.substr(start, end - start);
        i = end;

        if (minpath == "/" or minpath == "/.")
            continue;

        if (minpath != "/..")
            s.push(minpath);
        else if (!s.empty())
            s.pop();
    }

    string ans = s.empty() ? "/" : "";

    buildAns(s, ans);

    return ans;
}

int main()
{
    string inputPath = "/a/./b/../../c/";
    string simplifiedPath = simplifyPath(inputPath);
    cout << "Original Path: " << inputPath << endl;
    cout << "Simplified Path: " << simplifiedPath << endl;

    return 0;
}