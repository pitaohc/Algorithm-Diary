#include "Solution.h"
#include"Solution.h"
#include<vector>
using namespace std;

int Solution::rob(vector<int>& nums)
{
    int n = nums.size();
    if (n == 1) return nums[0];
    vector<int> money(n + 1, 0);
    money[0] = 0;
    money[1] = nums[0];
    for (size_t i = 2; i <= n; i++)
    {
        money[i] = max(money[i - 1], money[i - 2] + nums[i - 1]);
    }
    return money[n];
}
