#include<iostream>
#include"Solution.h"
using namespace std;

void print(vector<vector<int>> vect)
{
    for each (vector<int> row in vect)
    {

        for each (int num in row)
        {
            cout << num << " ";
        }
        cout << endl;
    }
}
int main()
{
    Solution sol;
    vector<int> cost = { 10,15,20 };
    auto res = sol.minCostClimbingStairs(cost);
    cout << res << endl;
    cost = { 1,100,1,1,1,100,1,1,100,1 };
    res = sol.minCostClimbingStairs(cost);
    cout << res << endl;
    return 0;
}