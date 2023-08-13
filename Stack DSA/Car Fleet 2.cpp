#include <bits/stdc++.h>
using namespace std;

vector<double> getCollisionTimes(vector<vector<int>> &cars)
{

    vector<double> ans(cars.size(), -1);
    stack<int> s;

    for (int i = cars.size() - 1; i >= 0; i--)
    {
        // Check if car ahead from current has greater speed
        while (!s.empty() and cars[s.top()][1] >= cars[i][1])
        {
            s.pop();
        }

        while (!s.empty())
        {
            double colTime = (double)(cars[s.top()][0] - cars[i][0]) / (cars[i][1] - cars[s.top()][1]);
            if (ans[s.top()] == -1 or colTime <= ans[s.top()])
            {
                ans[i] = colTime;
                break;
            }
            s.pop();
        }

        s.push(i);
    }
    return ans;
}

int main()
{
    // Initialize input cars vector
    vector<vector<int>> cars = {
        {0, 2},
        {3, 1},
        {5, 3},
        {8, 2}};

    // Call the getCollisionTimes function
    vector<double> collisionTimes = getCollisionTimes(cars);

    // Print the collision times
    cout << "Collision Times:" << endl;
    for (double time : collisionTimes)
    {
        cout << time << " ";
    }

    return 0;
}