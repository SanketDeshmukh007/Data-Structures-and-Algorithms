#include<bits/stdc++.h>
using namespace std;

/*void isPresent(string s,int i,int n,char key)
{
    // 1. Base Case
    if(i >= n)
    {
        cout << "Absent" << endl;
        return;
    }

    // 2. Processing
    if(s[i] == key)
    {
        cout << "Present" << endl;
        return;
    }

    // 3. Recursive Relation
    isPresent(s,i+1,n,key);
}*/

bool isPresent(string s,int i,int n,char key)
{
    // 1. Base Case
    if(i >= n)
    {
        return false;;
    }

    // 2. Processing
    if(s[i] == key)
    {
        return true;
    }

    // 3. Recursive Relation
    return isPresent(s,i+1,n,key);
}

int main()
{
    string s = "Love Babbar";
    int n = s.length();
    char key = 'r';
    int i = 0;

    // isPresent(s,i,n,key);

    if(isPresent(s,i,n,key))
    cout << "Present" << endl;
    else cout << "Absent" << endl;


    return 0;
}