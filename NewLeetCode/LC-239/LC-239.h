#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class Solution {
#ifdef _DEBUG
private:
    void print(const deque<int>& que, vector<int>& nums) {
        auto it = que.begin();
        while (it != que.end()) {
            fmt::print("[{}]={}, ", *it, nums[*it]);
            ++it;
        }
        fmt::print("\n");
    }

#endif // _DEBUG

public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        if (k == 1) {
            return nums;
        }
        const int n = nums.size();
        deque<int> que; //存放下标
        vector<int> result;
        result.reserve(n - k + 1);
        for (int i = 0; i < n; ++i) {
            if (!que.empty() && que.front() == i - k) { //取出将要出窗口的元素
                que.pop_front();
            }
            while (!que.empty() && nums[que.back()] < nums[i]) { //维持单调递减
                que.pop_back();
            }
            que.push_back(i);
            if (i >= k - 1) { //已经扫描了k个元素
                result.push_back(nums[que.front()]);
            }
        }
        return result;
    }
};
