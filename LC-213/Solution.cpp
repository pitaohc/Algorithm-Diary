#include "Solution.h"
#include"Solution.h"
#include<vector>
using namespace std;

int Solution::rob(vector<int>& nums)
{
    if (nums.size() == 1) return nums[0];
    else if (nums.size() == 2) return max(nums[0], nums[1]);
    else return max(
        rob(nums, 0, nums.size() - 1), //前闭后开区间
        rob(nums, 1, nums.size())
    );
}

int Solution::rob(vector<int>& nums, int begin, int end)
{
    int n = end - begin;
    vector<int> money(n + 1, 0);
    money[0] = 0;
    money[1] = nums[begin];
    for (size_t i = 2; i <= n; i++)
    {
        money[i] = max(money[i - 1], money[i - 2] + nums[i - 1 + begin]);
    }
    return money[n];
}
