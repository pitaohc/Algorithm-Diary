#include "Solution.h"
#include"Solution.h"
#include<vector>
using namespace std;

int Solution::maxProfit(vector<int>& prices)
{
    int res = 0, n = prices.size();
    vector<int> buy_days = vector<int>(n, -1);
    buy_days[0] = 0;
    for (size_t i = 1; i < n; i++) //在第i天卖出
    {
        if (prices[i] < prices[buy_days[i - 1]])
        {
            buy_days[i] = i;
        }
        else
        {
            buy_days[i] = buy_days[i - 1];
        }
    }
    for (size_t i = 0; i < n; i++)
    {
        res = max(res, prices[i] - prices[buy_days[i]]);
    }
    return res;
}
