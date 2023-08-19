//
// Created by devcpp on 23-8-15.
//

#ifndef LC_75_SOLUTION_H
#define LC_75_SOLUTION_H
#define DEBUG
#include<cmath>
#include<vector>
#include<fmt/core.h>
#include<array>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cur = 0, p0 = 0, p2 = nums.size() - 1;
        while (cur <= p2) {
            int& p0num = nums[p0], & p2num = nums[p2], & curnum = nums[cur];
            if (curnum == 0) {
                swap(p0num, curnum);
                ++p0;
                ++cur;
            }
            else if (curnum == 2) {
                swap(p2num, curnum);

                --p2;
            }
            else {
                ++cur;
            }
        }
    }
};
#endif //LC_540_SOLUTION_H
