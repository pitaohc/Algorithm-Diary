//
// Created by devcpp on 23-8-3.
//

#ifndef LC_34_LC_34_SOLUTION_H
#define LC_34_LC_34_SOLUTION_H

#include"stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        int left, right, mid;
        left = 0, right = nums.size() - 1;
        int target_first = -1;
        int target_last = -1;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                target_first = mid;
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        left = 0, right = nums.size() - 1;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                target_last = mid;
                left = mid + 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return {target_first, target_last};
    }
};

#endif //LC_34_LC_34_SOLUTION_H
