#pragma once
#define DEBUG
#include<cmath>
#include<stdc++.h>
#include<fmt/core.h>

using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        int cur = 0, prev = 0;
        for (int num : nums) {
            int temp = max(prev + num, cur);
            prev = cur;
            cur = temp;
        }
        return cur;
    }
};

