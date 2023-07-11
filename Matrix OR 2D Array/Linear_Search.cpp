#include<bits/stdc++.h>
using namespace std;

bool LinearSearch(int a[][3],int target)
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(target == a[i][j])
            return true;
        }
    }
    return false;
}

int main()
{
    int a[3][3] = {{5,7,9},{12,4,2},{1,6,7}};
    int target = 6;
    bool ans = LinearSearch(a,target);
    if(ans)
    cout << "Present" << endl;
    else cout << "Absent" << endl;

    return 0;
}