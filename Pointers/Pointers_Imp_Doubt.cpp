#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[10] = {0};
    int (*ptr)[10] = &arr;
    cout << arr << endl << endl;

    for(int i = 0; i < 10; i++)
    {
        cout << (*ptr)[i] << endl;
    }

    return 0;
}