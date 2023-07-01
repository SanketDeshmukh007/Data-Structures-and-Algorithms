#include<bits/stdc++.h>
using namespace std;

int findMinDifference(vector<string>& timePoints) 
{
    vector<int> Minutes;
    int n = timePoints.size();

    for(int i = 0; i < n; i++)
    {
        string current = timePoints[i];
        int hours = stoi(current.substr(0,2));
        int min = stoi(current.substr(3,2));
        int TotalMin = hours * 60 + min;
        Minutes.push_back(TotalMin);
    }  

    sort(Minutes.begin(),Minutes.end());
    int MinDiff = INT_MAX;
    int m = Minutes.size();
    for(int i = 0; i < m; i++)
    { 
        int diff;
        if(i+1 < m)
        {
            diff = Minutes[i+1] - Minutes[i];
        }
        MinDiff = min(MinDiff,diff);
    }  

    int diff1 = Minutes[m-1] - Minutes[0];
    int diff2 = Minutes[0] + 1440 - Minutes[m-1];
    int diff = min(diff1,diff2);
    MinDiff = min(MinDiff,diff);

    return MinDiff;
}

int main()
{
    // vector<string> timePoints = {"23:59","00:00"};
    vector<string> timePoints = {"00:00","23:59","00:00"};
    int ans = findMinDifference(timePoints);
    cout << ans << endl;

    return 0;
}