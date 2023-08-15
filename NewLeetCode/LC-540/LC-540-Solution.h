//
// Created by devcpp on 23-8-15.
//

#ifndef LC_540_SOLUTION_H
#define LC_540_SOLUTION_H
#define DEBUG
#include<cmath>
#include<vector>
#include<fmt/core.h>
using namespace std;
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int left = 0, right = nums.size() - 1, n = nums.size();

        if (n == 1) return nums[0];

        while (left < right)
        {
            int mid = (right - left) / 2 + left;

            //判断当前元素是否有重复的
            if ((mid != 0 && nums[mid - 1] != nums[mid]) &&
                (mid != n - 1 && nums[mid] != nums[mid + 1]))
            {
                return nums[mid];
            }
            else if (mid != 0 && nums[mid - 1] == nums[mid])
            {
                //和左边元素重复
                //判断右边区间长度是否为2的倍数
                if ((right - mid) % 2 == 0)
                {
                    right = mid - 2; //单个元素出现在左区间
                }
                else
                {
                    left = mid + 1;
                }
            }
            else
            {
                if ((mid - left) % 2 == 0)
                {
                    left = mid + 2;
                }
                else
                {
                    right = mid - 1;
                }
            }

        }
        return nums[left];
    }
};
#endif //LC_540_SOLUTION_H
