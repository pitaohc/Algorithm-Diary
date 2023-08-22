//
// Created by devcpp on 23-8-15.
//

#ifndef LC_540_SOLUTION_H
#define LC_540_SOLUTION_H
#define DEBUG
#include<cmath>
#include<vector>
#include<fmt/core.h>
#include<map>
using namespace std;
class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        int n = nums.size();
        map<int, int> buckets;
        for (int i = x; i < n; i++) { //放入统计桶
            buckets[nums[i]]++;
        }
        int result = INT_MAX;
        for (int i = 0; i < n - x; i++) {
            auto it = buckets.lower_bound(nums[i]); // >=
            if (it == buckets.end()) { //说明nums[i]大于任何一个数字
                result = min(result, abs(nums[i] - (--it)->first));
            }
            else if (it->first == nums[i]) { //说明存在相等
                return 0;
            }
            else {//it->first > nums[i]
                result = min(result, abs(nums[i] - it->first)); //计算大于的数
                if ((--it) != buckets.end()) {//计算小于的数
                    result = min(result, abs(nums[i] - it->first));
                }
            }

            if (buckets[nums[i + x]] > 1) {
                buckets[nums[i + x]]--;
            }
            else {
                buckets.erase(nums[i + x]);
            }
        }
        return result;
    }
};
#endif //LC_540_SOLUTION_H
