#include <bits/stdc++.h>
using namespace std;

class Car
{
public:
    int pos;
    int speed;

    Car(int p, int s)
    {
        pos = p;
        speed = s;
    }
};

static bool cmp(Car &a, Car &b)
{
    return a.pos < b.pos;
}

int carFleet(int target, vector<int> &position, vector<int> &speed)
{

    vector<Car> cars;
    int n = speed.size();

    for (int i = 0; i < n; i++)
    {
        Car car(position[i], speed[i]);
        cars.push_back(car);
    }

    sort(cars.begin(), cars.end(), cmp);
    stack<float> s;
    for (auto car : cars)
    {
        float time = (target - car.pos) / float(car.speed);
        cout << time << endl;

        while (!s.empty() and s.top() <= time)
        {
            s.pop();
        }

        s.push(time);
    }
    return s.size();
}

int main()
{
    // int target = 12;                   // Target position
    // vector<int> position = {10, 8, 0}; // Positions of cars
    // vector<int> speed = {2, 4, 1};     // Speeds of cars
    int target = 10;                   // Target position
    vector<int> position = {6, 8}; // Positions of cars
    vector<int> speed = {3,2};     // Speeds of cars

    int result = carFleet(target, position, speed);
    cout << "Number of Car Fleets: " << result << endl;

    return 0;
}