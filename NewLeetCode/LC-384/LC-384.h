#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class Solution {
public:
    Solution(vector<int>& nums) {
        this->nums = nums;
    }

    vector<int> reset() {
        return this->nums;
    }

    vector<int> shuffle() {
        vector<int> shuffled(nums);
        int n = shuffled.size();
        for (size_t i = 0; i < n; i++)
        {
            int randPos = rand() % n;
            swap(shuffled[i], shuffled[randPos]);
        }
        return shuffled;
    }
private:
    vector<int> nums;

};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */