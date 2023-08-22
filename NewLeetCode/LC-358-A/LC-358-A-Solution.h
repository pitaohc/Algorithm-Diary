//
// Created by devcpp on 23-8-15.
//

#ifndef LC_540_SOLUTION_H
#define LC_540_SOLUTION_H
#define DEBUG
#include<cmath>
#include<vector>
#include<fmt/core.h>
#include<queue>
#include<array>
using namespace std;
class Solution {
public:
    int maxSum(vector<int>& nums) {
        array<priority_queue<int>, 10> buckets;
        for (auto num : nums) {
            int original = num;
            int biggestNum = 0;
            while (num > 0) {
                biggestNum = std::max(biggestNum, num % 10);
                num /= 10;
            }
            buckets[biggestNum].push(original);
        }
        int res = -1;
        for (int i = 0; i < buckets.size(); ++i) {
            if (buckets[i].size() >= 2)
            {
                int temp = 0;
                temp += buckets[i].top();
                buckets[i].pop();
                temp += buckets[i].top();
                res = std::max(res, temp);
            }
        }
        return res;
    }
};
#endif //LC_540_SOLUTION_H
