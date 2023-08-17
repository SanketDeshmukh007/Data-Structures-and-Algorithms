#include<bits/stdc++.h>
using namespace std;


int main()
{
    // Queue Creation
    queue<int> q;

    // Insertion
    q.push(5);
    q.push(15);
    q.push(25);
    q.push(55);

    // Size
    cout << q.size() << endl;

    // Removal
    q.pop();
    cout << q.size() << endl;

    // Empty
    if(q.empty()) cout << "Empty" << endl;
    else cout << "Not Empty" << endl;

    // front
    cout << q.front() << endl;

    return 0;
}