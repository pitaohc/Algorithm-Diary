#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class Solution {
private:
    vector<vector<int>> result;
    vector<int> stack;
    void search(vector<int>& nums, int pos=0) {
        int n = nums.size();
        if (pos >= n - 1) {
            stack.emplace_back(nums[pos]);
            result.emplace_back(stack);
            stack.pop_back();
            return;
        }

        for (size_t i = pos; i < n; i++)
        {
            if (i > 0 && i>pos && nums[i] == nums[i - 1]) continue;
            swap(nums[i], nums[pos]);
            stack.emplace_back(nums[pos]);
            search(nums, pos + 1);
            stack.pop_back();
            swap(nums[i], nums[pos]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        result.clear();
        stack.clear();
        sort(nums.begin(), nums.end());
        search(nums);
        return result;
    }
};

