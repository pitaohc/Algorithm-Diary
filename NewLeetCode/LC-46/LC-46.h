#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        dfs(nums, ans, 0);
        return ans;
    }
private:
    void dfs(vector<int>& nums, vector<vector<int>>& ans, int depth) {
        if (depth + 1 == nums.size()) {
            ans.emplace_back(nums);
            //ans.push_back(nums);
            return;
        }

        for (size_t i = depth; i < nums.size(); i++){
            swap(nums[depth], nums[i]);
            dfs(nums, ans, depth+1);
            swap(nums[depth], nums[i]);
        }
    }
};
