#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    char data;
    int count;

    node(char d, int c)
    {
        data = d;
        count = c;
    }
};

class compare
{
public:
    bool operator()(node a, node b)
    {
        return a.count < b.count;
    }
};

class Solution
{
public:
    string longestDiverseString(int a, int b, int c)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);

        priority_queue<node, vector<node>, compare> p; // maxHeap

        if (a > 0)
        {
            node n('a', a);
            p.push(n);
        }
        if (b > 0)
        {
            node n('b', b);
            p.push(n);
        }
        if (c > 0)
        {
            node n('c', c);
            p.push(n);
        }

        string ans = "";
        while (p.size() > 1)
        {
            node first = p.top();
            p.pop();
            node second = p.top();
            p.pop();

            if (first.count >= 2)
            {
                ans += first.data;
                ans += first.data;
                first.count -= 2;
            }
            else
            {
                ans += first.data;
                first.count -= 1;
            }

            if (second.count >= 2 and second.count >= first.count)
            {
                ans += second.data;
                ans += second.data;
                second.count -= 2;
            }
            else
            {
                ans += second.data;
                second.count -= 1;
            }

            if (first.count > 0)
                p.push(first);
            if (second.count > 0)
                p.push(second);
        }

        if (p.size() == 1)
        {
            node temp = p.top();
            p.pop();
            if (temp.count >= 2)
            {
                ans += temp.data;
                ans += temp.data;
                temp.count -= 2;
            }
            else
            {
                ans += temp.data;
                temp.count -= 1;
            }
        }
        return ans;
    }
};

int main()
{
    //

    return 0;
}