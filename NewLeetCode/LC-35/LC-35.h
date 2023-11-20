#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        //实际上就是二分查找
        int left = 0, right = nums.size()-1;
        while (left <= right) {
            int mid = (right - left) / 2 + left;
            const int num = nums[mid];
            if (num == target) {
                return mid;
            }
            else if (target < num) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return left;
    }
};
