#include<bits/stdc++.h>
using namespace std;

void Sort(vector<int> &a)
{
    int countZero = 0;
    int countOne = 0;
    int countTwo = 0;
    
    int n = a.size();

    for(int i = 0; i < n; i++)
    {
        if(a[i] == 0)
        countZero++;
        else if(a[i] == 1)
        countOne++;
        else
        countTwo++;
    }

    for(int i = 0; i < countZero; i++)
    a[i] = 0;

    for(int i = countZero; i < countZero + countOne; i++)
    a[i] = 1;

    for(int i = countZero + countOne; i < n; i++)
    a[i] = 2;
}

int main()
{
    vector<int> a = {2,2,1,1,0,0,0,0,1,1,2,1};
    Sort(a);

    for(auto x : a)
    cout << x << " ";

    return 0;
}