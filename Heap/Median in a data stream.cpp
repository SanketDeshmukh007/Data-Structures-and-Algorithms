#include <bits/stdc++.h>
using namespace std;

class MedianFinder
{
public:
    MedianFinder()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    }
    priority_queue<int> maxi;
    priority_queue<int, vector<int>, greater<int>> mini;

    void addNum(int num)
    {
        if (maxi.size() == 0 or maxi.top() >= num)
            maxi.push(num);
        else
            mini.push(num);

        if (maxi.size() > mini.size() + 1)
        {
            int temp = maxi.top();
            maxi.pop();
            mini.push(temp);
        }
        else if (maxi.size() < mini.size())
        {
            int temp = mini.top();
            mini.pop();
            maxi.push(temp);
        }
    }

    double findMedian()
    {
        if (maxi.size() == mini.size())
        {
            return maxi.top() / 2.0 + mini.top() / 2.0;
        }
        else
            return maxi.top();
    }
};

int main()
{
    //

    return 0;
}