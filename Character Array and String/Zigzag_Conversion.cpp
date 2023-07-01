#include<bits/stdc++.h>
using namespace std;

string convert(string s, int numRows)
{
    if(numRows == 1)
    return s;

    vector<string> zigzag(numRows);
    int i = 0;
    int row = 0;
    bool direction = true; // for top to bottom

    while(true)
    {
        if(direction)
        {
            while(row < numRows and i < int(s.size()))
            {
                zigzag[row++].push_back(s[i++]);
            }
            row = row - 2; 
            // row = numRows - 2;
        }
        else
        {
            while(row >= 0 and i < int(s.size()))
            {
                zigzag[row--].push_back(s[i++]);
            }
            row = 1;
        }

        direction = !direction;
        if(i == int(s.size()))
        break;
    }

    string ans = "";
    for(auto x : zigzag)
    ans += x;

    return ans;
}

int main()
{
    string s = "PAYPALISHIRING";
    int numRows = 3;
    string ans = convert(s,numRows);
    cout << ans << endl; //PAHNAPLSIIGYIR

    return 0;
}