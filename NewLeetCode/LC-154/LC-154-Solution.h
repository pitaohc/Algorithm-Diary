//
// Created by devcpp on 23-8-14.
//

#ifndef LC_154_SOLUTION_H
#define LC_154_SOLUTION_H
#define DEBUG
#include<cmath>
#include<vector>
#include<fmt/core.h>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int left = 0, right = nums.size() - 1;
        int result = nums[0];
        while (left <= right)
        {
            int mid = (right - left) / 2 + left;


            if (nums[left] < nums[mid])
            {
                //左侧区间有序，那么只需要比较左侧的最小值，并排除整个区间
                result = min(result, nums[left]);
                left = mid + 1;
            }
            else if (nums[mid] < nums[right])
            {
                //右侧区间有序，那么只需要比较右侧的最小值，并排除整个区间
                result = min(result, nums[mid]);
                right = mid - 1;
            }
            else
            {
                result = min(result, nums[left]);
                ++left;
            }
        }
        return result;

    }
};
#endif //LC_154_SOLUTION_H
