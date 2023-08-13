#include <bits/stdc++.h>
using namespace std;

class StockSpanner
{
public:
    stack<pair<int, int>> s;

    StockSpanner()
    {
    }

    int next(int price)
    {
        int span = 1;

        while (!s.empty() and s.top().first <= price)
        {
            span += s.top().second;
            s.pop();
        }

        s.push({price, span});

        return span;
    }
};

int main() {
    StockSpanner stockSpanner;

    cout << stockSpanner.next(100) << endl; // Output: 1
    cout << stockSpanner.next(80) << endl;  // Output: 1
    cout << stockSpanner.next(60) << endl;  // Output: 1
    cout << stockSpanner.next(70) << endl;  // Output: 2
    cout << stockSpanner.next(60) << endl;  // Output: 1
    cout << stockSpanner.next(75) << endl;  // Output: 4
    cout << stockSpanner.next(85) << endl;  // Output: 6

    return 0;
}