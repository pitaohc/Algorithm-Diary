#include "Solution.h"
#include"Solution.h"
#include<vector>
using namespace std;

int Solution::minCostClimbingStairs(std::vector<int>& cost)
{
    int n = cost.size();
    vector<int> pay(n, 0);
    pay[0] = cost[0];
    pay[1] = cost[1];
    for (size_t i = 2; i < n; i++)
    {
        pay[i] = cost[i] + min(pay[i - 1], pay[i - 2]);
    }
    return min(pay[n - 1], pay[n - 2]);
}
