#include<bits/stdc++.h>
using namespace std;


int main()
{
    // Max Heap
    /*priority_queue<int> p;
    p.push(3);
    p.push(6);
    p.push(9);
    p.push(4);
    p.push(8);

    cout << p.top() << endl;
    p.pop();
    cout << p.top() << endl;
    p.pop();
    cout << p.top() << endl;
    p.pop();
    cout << p.top() << endl;
    p.pop();
    cout << p.top() << endl;
    p.pop();
    cout << p.size() << endl;

    cout << p.empty() << endl;*/

    // Min Heap
    priority_queue<int,vector<int>,greater<int>> p;
    p.push(3);
    p.push(6);
    p.push(4);
    p.push(8);
    p.push(9);
    cout << p.top() << endl;
    p.pop();
    cout << p.top() << endl;
    cout << p.size() << endl;
    return 0;
}