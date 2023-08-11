//
// Created by devcpp on 23-8-3.
//

#ifndef LC_81_LC_81_SOLUTION_H
#define LC_81_LC_81_SOLUTION_H

#include"stdc++.h"

using namespace std;

class Solution {
public:
    bool search(vector<int> &nums, int target) {
        int left = 0, right = nums.size() - 1, mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return true;
            } else if (nums[left] == nums[mid]) { //无法区分有序区间
                ++left;
            } else if (nums[left] < nums[mid]) { //左区间有序
                if (nums[left] <= target and target < nums[mid]) { //哪个区间有序就选择那个区间作为判断
                    //目标在左区间
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else { //右区间有序
                if (nums[mid] < target and target <= nums[right]) {
                    //目标在右区间
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return false;
    }
};

#endif //LC_81_LC_81_SOLUTION_H
