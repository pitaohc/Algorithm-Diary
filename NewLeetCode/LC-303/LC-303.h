#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class NumArray {
private:
    vector<int> nums;
public:
    NumArray(vector<int>& nums):nums(nums) {
        int sum = 0;
        for (auto& num : this->nums) {
            sum += num;
            num = sum;
        }
#ifdef _DEBUG
        fmt::print("sums: {}\n", this->nums);
#endif // _DEBUG

    }

    int sumRange(int left, int right) {
        int leftSum = (left == 0) ? 0 : nums[left-1];
        int rightSum = nums[right];
        return rightSum - leftSum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
