#include<bits/stdc++.h>
using namespace std;

void moveNumbers(int a[],int n)
{
    int start = 0;
    int end = n-1;

    while(start <= end)
    {
        if(a[start] < 0)
        start++;
        else if(a[end] > 0)
        end--;
        else
        {
            swap(a[start],a[end]);
            start++;
            end--;
        }
    }
}

int main()
{
    int a[] = {2,3,-1,-4,45,12,-8,-12};
    int n = sizeof(a)/sizeof(int);
    moveNumbers(a,n);

    for(int i = 0; i < n; i++)
    cout << a[i] << " ";

    return 0;
}