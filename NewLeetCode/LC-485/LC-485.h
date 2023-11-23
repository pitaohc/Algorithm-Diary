#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxResult = 0;
        int cnt = 0;
        for (const auto& num : nums) {
            switch (num)
            {
            case 0:
                maxResult = max(maxResult, cnt);
                cnt = 0;
                break;
            case 1:
                ++cnt;
                break;
            }
        }
        return max(maxResult, cnt);
    }
};
